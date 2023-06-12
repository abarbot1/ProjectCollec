#include "RadioLora.hpp"
#include <iostream>
#include <iomanip>

RadioLora::RadioLora()
{
}

void RadioLora::emettre(unsigned char *data, unsigned int taille)
{
    for (unsigned int i = 0; i < taille; i++)
    {
        // std::cout << std::hex << data[i] << '\t';
        printf("0x%x\t", data[i]);
    }
    std::cout << std::endl;
}

int RadioLora::recevoir(unsigned char *data, unsigned int tailleMax)
{
    // création d'une trame de test
    data[0] = 0xdd;
    data[1] = 0xee;
    data[2] = 0xff;
    data[3] = 'T';
    data[4] = 0x01;
    data[5] = 0x27;
    data[6] = 99;
    data[7] = 135;
    // checksum OK
    data[8] = 0x5A;
    // checksum erroné
    // data[8] = 0x51;
    return 0;
}

RadioLora::~RadioLora()
{
}