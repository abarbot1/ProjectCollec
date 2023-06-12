#include <iostream>
#include <cstring>
#include "Transmetteur.hpp"
#include "RadioLora.hpp"

using namespace std;

int main()
{
    cout << "Test unitaire de la classe transmetteur" << endl;
    unsigned int mac = 0xaabbcc;
    // température en dixième de degrès celcius
    unsigned int temp = -10;
    // pourcentage de batterie restant
    unsigned batt = 99;

    Radio *moduleRadio = new RadioLora();

    Transmetteur *transmetteur = new Transmetteur(moduleRadio);
    transmetteur->genererTrame(mac, 'T', temp, batt);
    transmetteur->transmettreTrame();
}