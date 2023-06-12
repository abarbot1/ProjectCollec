#include <iostream>
#include <cstring>
#include "Transmetteur.hpp"
#include "RadioLora.hpp"
#include "Recepteur.hpp"

using namespace std;

int main()
{
    Radio *moduleRadio = new RadioLora();

    cout << "Test unitaire de la classe Recepteur" << endl;
    Recepteur *recepteur = new Recepteur(moduleRadio);
    recepteur->recevoirTrame();
    Mesure donnees;
    if (recepteur->extraireDonnees(&donnees))
    {
        cout << "Identifiant capteur : " << std::hex << donnees.getIdCapteur() << endl;
        cout << "Type de mesure : " << donnees.getType() << endl;
        cout << "Valeur de la mesure : " << donnees.getPayload() << endl;
        cout << "Charge de la batterie : " << donnees.getBatterie() << endl;
        cout << "Niveau RSSI : -" << donnees.getRssi() << endl;
    }
    else
        cout << "Trame non valide" << endl;
}