#include "Recepteur.hpp"
#include <iostream>

using namespace std;

Recepteur::Recepteur(Radio *moduleRadioo)
{
    this->moduleRadio = moduleRadioo;
}

unsigned int Recepteur::recevoirTrame()
{
    unsigned int nbreOctets = this->moduleRadio->recevoir(this->trame, sizeof(this->trame));
    return nbreOctets;
    cout << "Trame reçu" << endl;
}

bool Recepteur::verifierChecksum() {
    bool trameValide = true;
    if (trame[8] != this->calculerChecksum())
        trameValide = false;
    return trameValide;

}

bool Recepteur::extraireDonnees(Mesure *data)
{
    bool trameValide = true;
    if (this->verifierChecksum())
    {
        data->setIdCapteur(this->trame[0] * 256 * 256 + this->trame[1] * 256 + trame[2]);
        data->setType(this->trame[3]);
        switch (data->getType())
        {
        case 'T':
            /* code */
            data->setPayload((float)(trame[4] * 256 + trame[5]) / 10.0);
            break;
        case 'L':
            data->setPayload(trame[4] * 256 + trame[5]);
            break;
        default:
            trameValide = false;
            break;
        }
        data->setBatterie(trame[6]);
        data->setRssi(trame[7]);
    }
    else trameValide = false;
    return trameValide;
}

unsigned char Recepteur::calculerChecksum(){
    unsigned char checksum = trame[0];
    for (int i = 1; i< TAILLE_TRAME-1; i++){
        checksum^=trame[i];//equivalent à checksum=checksum^trame[i]
        // ^ equivalent à ou exclusif
    }
    return checksum;
}

Recepteur::~Recepteur()
{
}