#ifndef TRANSMETTEUR_HPP
#define TRANSMETTEUR_HPP

#define TAILLE_TRAME 9

#include "Radio.hpp" 

class Transmetteur{

public:
    void transmettreTrame();
    Transmetteur(Radio* moduleRadio);
    void genererTrame(  unsigned int adresse, 
                        unsigned char type, 
                        int payload,
                        unsigned int batterie);
    ~Transmetteur();

protected : 
    unsigned char calculerChecksum();
    unsigned char trame[TAILLE_TRAME];

private : 
    Radio* moduleRadio;
};


#endif