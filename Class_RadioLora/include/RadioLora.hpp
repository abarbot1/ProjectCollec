#ifndef RADIOLORA_HPP
#define RADIOLORA_HPP

#include "Radio.hpp"
#include <LoRa.h>

#define SCK 14    // GPI14  -- SX1278's SCK
#define MISO 12   // GPIO12 -- SX1278's MISO
#define MOSI 13   // GPIO13 -- SX1278's MOSI
#define SS 15     // GPIO15 -- SX1278's CS
#define RST 17    // GPIO17 -- SX1278's RESET
#define DI0 16    // GPIO16 -- SX1278's IRQ(Interrupt Request) 


class RadioLora : public Radio
{

public:
    RadioLora();
    RadioLora(long frequence, int sw, int puissance, int sf, int sbw, int cr);
    virtual void emettre(unsigned char *data, unsigned int taille);
    virtual int recevoir(unsigned char* data, unsigned int taille);
    virtual ~RadioLora();

private : 
    LoRaClass* loRa;
};

#endif