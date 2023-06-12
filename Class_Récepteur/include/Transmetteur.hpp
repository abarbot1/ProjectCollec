#ifndef TRANSMETTEUR_HPP
#define TRANSMETTEUR_HPP

#define TAILLE_TRAME 9

#include "Radio.hpp"

class Transmetteur{

public:
    Transmetteur(Radio* moduleRadio);
    void genererTrame(  unsigned int adresse, 
                        unsigned char type, 
                        int payload,
                        unsigned int batterie);
    void transmettreTrame();
    ~Transmetteur();

protected : 
    unsigned char calculerChecksum();
    unsigned char trame[TAILLE_TRAME];

private : 
    Radio* moduleRadio;
};

#endif