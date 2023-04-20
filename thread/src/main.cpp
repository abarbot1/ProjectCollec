#include <iostream>
#include <thread>
#include <mutex>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <string.h>
using namespace std;

mutex SPIMutex; // déclaration du mutex pour protéger l'accès aux données de la voie SPI
const int PACKET_HEADER_SIZE = 11;
// Fonction thread pour la lecture de données sur la voie SPI
void SPIReadThread(int spi_fd)
{
    while (true)
    {
        char buf[1024];
        int n = read(spi_fd, buf, sizeof(buf)); // lecture de données sur la voie SPI
        if (n > 0)
        {
            lock_guard<mutex> lock(SPIMutex); // verrouillage du mutex
            // affichage des données reçues
            cout << "Received " << n << " bytes: ";
            for (int i = 0; i < n; i++)
                cout << buf[i];
            cout << endl;
        }
    }
}

// Fonction thread pour l'analyse des données de la voie SPI
void SPIAnalyzeThread(int spi_fd)
{
    char buf[1024];
    int pos = 0;
    int len = 0;

    while (true)
    {
        lock_guard<mutex> lock(SPIMutex); // verrouillage du mutex

        // Lire les données de la voie SPI
        int n = read(spi_fd, buf+pos, sizeof(buf)-pos);

        if (n <= 0)
            continue;

        // Mettre à jour la position du curseur de lecture
        pos += n;

        // Vérifier si nous avons une en-tête de paquet complète
        if (pos >= PACKET_HEADER_SIZE)
        {
            // Analyser l'en-tête de paquet
            int packetLen = buf[0];
            int packetChecksum = buf[1];

            // Vérifier si nous avons un paquet complet
            if (pos >= packetLen)
            {
                // Vérifier le checksum
                int checksum = 0;
                for (int i = 0; i < packetLen; i++)
                    checksum += buf[i];

                if (checksum == packetChecksum)
                {
                    // Extraire le message du paquet
                    string message(buf + PACKET_HEADER_SIZE, packetLen - PACKET_HEADER_SIZE);
                    cout << "Received message: " << message << endl;

                    // Mettre à jour la position du curseur de lecture
                    pos -= packetLen;

                    // Décaler les données restantes vers le début du tampon
                    if (pos > 0)
                        memmove(buf, buf+packetLen, pos-packetLen);
                }
                else
                {
                    // Le checksum est incorrect, abandonner le paquet
                    pos = 0;
                }
            }
        }
    }
}

int main()
{
    // Ouverture de la voie SPI
    int spi_fd = open("/dev/spidev0.0", O_RDWR);
    if (spi_fd < 0)
    {
        cout << "Failed to open SPI device." << endl;
        return 1;
    }

    // Configuration de la voie SPI
    uint8_t mode = SPI_MODE_0;
    uint8_t bits = 8;
    uint32_t speed = 1000000;
    int ret = ioctl(spi_fd, SPI_IOC_WR_MODE, &mode);
    ret |= ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    ret |= ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    if (ret < 0)
    {
        cout << "Failed to configure SPI device." << endl;
        return 1;
    }

    // Démarrage des threads de lecture et d'analyse de données
    thread readThread(SPIReadThread, spi_fd);
    thread analyzeThread(SPIAnalyzeThread);

    // Attendre jusqu'à ce que l'utilisateur appuie sur une touche, puis terminer les threads et fermer la voie SPI
    cout << "Press ctrl+c to stop." << endl;
    getchar();
    close(spi_fd);
    readThread.join();
    analyzeThread.join();

    return 0;
}
