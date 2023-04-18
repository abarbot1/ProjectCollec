#include <iostream>
#include <thread>
#include <mutex>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

using namespace std;

mutex SPIMutex; // déclaration du mutex pour protéger l'accès aux données de la voie SPI

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
void SPIAnalyzeThread()
{
    while (true)
    {
        lock_guard<mutex> lock(SPIMutex); // verrouillage du mutex
        // TODO: Ajouter du code pour analyser les données de la voie SPI
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
