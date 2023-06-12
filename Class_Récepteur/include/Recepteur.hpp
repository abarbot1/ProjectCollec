#ifndef RECEPTEUR_HPP
#define RECEPTEUR_HPP

#define TAILLE_TRAME 9

#include "Mesure.hpp"
#include "Radio.hpp"

class Recepteur{

public:
    Recepteur(Radio* moduleRadio);
    unsigned int recevoirTrame();
    bool verifierChecksum();
    bool extraireDonnees(Mesure* data);
    ~Recepteur();

protected :
    unsigned char trame[TAILLE_TRAME];
    unsigned char calculerChecksum();

private : 
    Radio* moduleRadio;
};

#endif