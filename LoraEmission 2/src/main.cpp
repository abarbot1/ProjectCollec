#include <SPI.h>
#include <LoRa.h>

#define SCK 14    // GPI14  -- SX1278's SCK
#define MISO 12   // GPIO12 -- SX1278's MISO
#define MOSI 13   // GPIO13 -- SX1278's MOSI
#define SS 15     // GPIO15 -- SX1278's CS
#define RST 17    // GPIO17 -- SX1278's RESET
#define DI0 16    // GPIO16 -- SX1278's IRQ(Interrupt Request) 

void setup() {
  Serial.begin(115200);

  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DI0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed. Check your connections.");
    while (true);
  }
  LoRa.setSyncWord(0x12);
  LoRa.setPreambleLength(6);
  //Puissance d'émission de 2 à 17
  LoRa.setTxPower(20, PA_OUTPUT_PA_BOOST_PIN);
  
  //facteur d'étalement de 6 à 12
  LoRa.setSpreadingFactor(12);
  
  //Bande passante : 7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3, 41.7E3, 62.5E3, 125E3, and 250E3.
  LoRa.setSignalBandwidth(62.5E3);

  //Codage CR4/5 (5) à CR4/8 (8)
  LoRa.setCodingRate4(8);
}

void loop() {
  //const char* message = "Hello World";

    unsigned char data[9];
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

  LoRa.beginPacket();
  LoRa.print((char*)data);
  LoRa.endPacket();
  delay(5000);
}
