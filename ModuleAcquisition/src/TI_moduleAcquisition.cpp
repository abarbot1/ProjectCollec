#include <Arduino.h>
#include "ModuleTemp.h"

#define TAILLE_TRAME 9

ModuleTemp* moduleTemp;
unsigned long debut;
unsigned long fin;
unsigned long duree;

void setup() {
  moduleTemp = new ModuleTemp();
  Serial.begin(115200);
  Serial.println("#########################################################");
  Serial.println("# Programme de test integration du Module d'acquisition #");
  Serial.println("#########################################################");
  Serial.println("");
}

void loop() {
  debut=millis();
  Serial.println("______________________________________________________");
  moduleTemp->acquerirDonneeUtile();
  Serial.print("Récupération des données utiles : ");
  Serial.print(moduleTemp->getDonneeUtile());
  Serial.println("°C");
  Serial.println("______________________________________________________");
  moduleTemp->acquerirDonneesSecondaires();
  Serial.println("Récupération des données secondaires : ");
  Serial.print(moduleTemp->getNiveauBatterie());
  Serial.println(" %");
  Serial.print(moduleTemp->getRSSI());
  Serial.println(" dbm");
  Serial.println("______________________________________________________");
  Serial.print("Trame : ");
  char* laTrame = (char*)moduleTemp->getTrame();
  for (int i = 0; i < TAILLE_TRAME; i++) {
    Serial.print(laTrame[i],HEX);Serial.print(' ');
  }
  Serial.println("");
  moduleTemp->transmettreDonnees();
  fin=millis();
  //duree de sommeil en millisecondes
  moduleTemp->dormir(20000-fin+debut);
}
