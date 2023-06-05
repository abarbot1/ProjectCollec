#include <Arduino.h>
#include "ModuleLum.h"

#define TAILLE_TRAME 9

ModuleLum* moduleLum;
unsigned long debut;
unsigned long fin;
unsigned long duree;

void setup() {
  moduleLum = new ModuleLum();
  Serial.begin(115200);
  Serial.println("#########################################################");
  Serial.println("# Programme de test integration du Module d'acquisition #");
  Serial.println("#########################################################");
  Serial.println("");
}

void loop() {
  debut=millis();
  Serial.println("______________________________________________________");
  moduleLum->acquerirDonneeUtile();
  Serial.print("Récupération des données utiles : ");
  Serial.println(moduleLum->getDonneeUtile());
  Serial.println("______________________________________________________");
  Serial.println("");
  Serial.println("______________________________________________________");
  moduleLum->acquerirDonneesSecondaires();
  Serial.println("Récupération des données secondaires : ");
  Serial.println(moduleLum->getNiveauBatterie());
  Serial.println(moduleLum->getRSSI());
  Serial.println("______________________________________________________");
  Serial.print("Trame : ");
  char* laTrame = (char*)moduleLum->getTrame();
  for (int i = 0; i < TAILLE_TRAME; i++) {
    Serial.print(laTrame[i],HEX);Serial.print(' ');
  }
  Serial.println("");
  moduleLum->transmettreDonnees();
  fin=millis();
  //duree de sommeil en millisecondes
  moduleLum->dormir(20000-fin+debut);
}
