/*#include <Arduino.h>
#include "ModuleLum.h"
#include <WiFi.h>

ModuleLum* moduleLum;

void setup() {
  moduleLum = new ModuleLum();
  Serial.begin(115200);
  Serial.println("######################################################");
  Serial.println("# Programme de test Module d'acquisition             #");
  Serial.println("######################################################");
  Serial.println("");
}

void loop() {
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
  moduleLum->transmettreDonnees();
  moduleLum->dormir(5);
}*/



#include <Arduino.h>
#include "ModuleLum.h"
#include <WiFi.h>

int genererID();

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.print("Adresse MAC : ");
  Serial.println(WiFi.macAddress());
  Serial.print("ID hexa : ");
  Serial.println(genererID(),HEX);
  Serial.print("ID dec : ");
  Serial.println(genererID());
}

void loop() {
}

int genererID()
{
	String macAddress = WiFi.macAddress();
	macAddress.replace(":", "");							  // Supprimer les deux-points 11:22:33:aa:bb:cc -> 112233aabbcc
	String derniersOctets = macAddress.substring(6);		  // Obtenir les trois derniers octets -> aabbcc
	return (int)strtol(derniersOctets.c_str(), NULL, 16); // Convertir en entier à partir d'une valeur hexadécimale (base 16) -> 0xaabbcc
}