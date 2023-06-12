#include <cstring>
#include "RadioLora.hpp"

RadioLora* radiolora;

void setup(){
    SPI.begin(SCK, MISO, MOSI, SS);
    radiolora = new RadioLora();
}

void loop(){
    
    unsigned char message[9];
    message[0] = 0xdd;
    message[1] = 0xee;
    message[2] = 0xff;
    message[3] = 'T';
    message[4] = 0x01;
    message[5] = 0x27;
    message[6] = 99;
    message[7] = 135;
    // checksum OK
    message[8] = 0x5A;
    // checksum erroné
    // data[8] = 0x51;

    radiolora->emettre(message, 9);
}