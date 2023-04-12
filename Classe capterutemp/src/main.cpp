#include <Arduino.h>
#include "CapteurTemp.h"
#define UART_BAUD 115200

CapteurTemp *capteur;

void setup() {
  Serial.begin(UART_BAUD);
  Serial.println("######################################################");
  Serial.println("# Programme de test unitaire de la classe Capteurtemp");
  Serial.println("######################################################");
  Serial.println("");
  Serial.println("instantiation de la classe");
  capteur = new CapteurTemp(STS35_I2C_ADDRESS);
  Serial.println("objet créer"); // put your setup code here, to run once:
}

void loop() {
  Serial.println("Acquistion de la température");
  capteur->aquerirTemperature();
  Serial.println("température acquise");
  Serial.print("température:");
  Serial.print(capteur->getTemperature());
  Serial.println("°C");
  delay(3000);// put your main code here, to run repeatedly:
}