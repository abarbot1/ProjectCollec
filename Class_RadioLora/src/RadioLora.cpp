#include "RadioLora.hpp"
#include <iostream>
#include <iomanip>

RadioLora::RadioLora()
{
    loRa = new LoRaClass();

    SPI.begin(SCK, MISO, MOSI, SS);
    loRa->setPins(SS, RST, DI0);

    if (!loRa->begin(433E6)) {
        Serial.println("LoRa init failed. Check your connections.");
        while (true);
    }
    loRa->setSyncWord(0x12);
    loRa->setPreambleLength(6);
    loRa->setTxPower(20, PA_OUTPUT_PA_BOOST_PIN);
    loRa->setSpreadingFactor(12);
    loRa->setSignalBandwidth(62.5E3);
    loRa->setCodingRate4(8);
}

//Puissance d'émission de 2 à 17
//facteur d'étalement de 6 à 12
//Bande passante : 7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3, 41.7E3, 62.5E3, 125E3, and 250E3.
//Codage CR4/5 (5) à CR4/8 (8)
RadioLora::RadioLora(long frequence,
                     int sw,
                     int puissance,
                     int sf,
                     int sbw,
                     int cr)
{
    loRa = new LoRaClass();
    SPI.begin(SCK, MISO, MOSI, SS);
    loRa->setPins(SS, RST, DI0);

    if (!loRa->begin(frequence)) {
        Serial.println("LoRa init failed. Check your connections.");
        while (true);
    }
    loRa->setSyncWord(sw);
    loRa->setPreambleLength(6);
    loRa->setTxPower(puissance, PA_OUTPUT_PA_BOOST_PIN);
    loRa->setSpreadingFactor(sf);
    loRa->setSignalBandwidth(sbw);
    loRa->setCodingRate4(cr);
}

void RadioLora::emettre(unsigned char *data, unsigned int taille)
{
    loRa->beginPacket();
    loRa->print((char*)data);
    loRa->endPacket();
}

int RadioLora::recevoir(unsigned char *data, unsigned int tailleMax)
{
}

RadioLora::~RadioLora()
{
    delete loRa;
}