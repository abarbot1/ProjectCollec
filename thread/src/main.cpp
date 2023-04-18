#include <iostream>
#include <thread>
#include "serialib.h"
#include <mutex>

using namespace std;

serialib Serial; // déclaration de l'objet Serial de la bibliothèque serialib

mutex SerialMutex; // déclaration du mutex pour protéger l'accès aux données de la liaison série

// Fonction thread pour la lecture de données sur la liaison série
void SerialReadThread()
{
    while (true)
    {
        char buf[1024];
        int n = Serial.readBytes(buf, sizeof(buf)); // lecture de données sur la liaison série
        if (n > 0)
        {
            lock_guard<mutex> lock(SerialMutex); // verrouillage du mutex
            // affichage des données reçues
            cout << "Received " << n << " bytes: ";
            for (int i = 0; i < n; i++)
                cout << buf[i];
            cout << endl;
        }
    }
}

// Fonction thread pour l'analyse des données de la liaison série
void SerialAnalyzeThread()
{
    while (true)
    {
        lock_guard<mutex> lock(SerialMutex); // verrouillage du mutex
        // TODO: Ajouter du code pour analyser les données de la liaison série
    }
}

int main()
{
    // Ouverture de la liaison série
    if (Serial.openDevice("/dev/ttyAMA0", 115200) != 1)
    {
        cout << "Failed to open serial port." << endl;
        return 1;
    }

    // Démarrage des threads de lecture et d'analyse de données
    thread readThread(SerialReadThread);
    thread analyzeThread(SerialAnalyzeThread);

    // Attendre jusqu'à ce que l'utilisateur appuie sur une touche, puis terminer les threads et fermer la liaison série
    cout << "Press Enter to stop." << endl;
    getchar();
    Serial.closeDevice();
    readThread.join();
    analyzeThread.join();

    return 0;
}
