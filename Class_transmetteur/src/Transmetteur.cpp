#include "Transmetteur.hpp"
#include <cstring>
#include <iostream>

using namespace std;

void Transmetteur::transmettreTrame()
{
    this->moduleRadio->emettre(this-> trame, TAILLE_TRAME);
    cout << "trame transmise" << endl;
}

Transmetteur::Transmetteur(Radio* moduleRadioo)
{
    this->moduleRadio = moduleRadioo;
}

void Transmetteur::genererTrame(unsigned int adresse, unsigned char type, int payload, unsigned int batterie)
{
    this->trame[2] = adresse;
    this->trame[1] = adresse >> 8;
    this->trame[0] = adresse >> 16;
    this->trame[3] = type;
    this->trame[4] = (0x0000FF00 & payload) >> 8;
    this->trame[5] = (0x000000FF & payload);
    this->trame[6] = (0x000000FF & batterie);
    this->trame[7] = (0x000000FF & this->moduleRadio->getLastRSSI());
    this->trame[8] = this->calculerChecksum();
}

unsigned char Transmetteur::calculerChecksum(){
    unsigned char checksum = trame[0];
    for (int i = 1; i< TAILLE_TRAME-1; i++){
        checksum^=trame[i];//equivalent à checksum=checksum^trame[i]
        // ^ equivalent à ou exclusif
    }
    return checksum;
}

Transmetteur::~Transmetteur()
{
}