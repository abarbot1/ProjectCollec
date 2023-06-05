#include "ModuleAcquisition.h"
#include "ModuleTemp.h"
#include "Batterie.h"
#include "Radio.hpp"
#include "WiFi.h"

ModuleAcquisition::ModuleAcquisition() {
	this->batterie = new Batterie();
	this->radio = new RadioLora();
	this->transmetteur = new Transmetteur(this->radio);
	this->genererId();
}

ModuleAcquisition::~ModuleAcquisition() {
	delete this->batterie;
	delete this->radio;
	delete this->transmetteur;
}

void ModuleAcquisition::acquerirDonneesSecondaires() {
	this->batterie->acquerirNiveau();
	this->niveauBatterie = this->batterie->getNiveau();
	this->RSSI=this->radio->getLastRSSI();
}

void ModuleAcquisition::dormir(int duree) {
	delay(duree);
}

float ModuleAcquisition::getDonneeUtile() {
	return this->donneeUtile;
}

int ModuleAcquisition::getNiveauBatterie() {
	return this->niveauBatterie;
}

int ModuleAcquisition::getRSSI() {
	return this->radio->getLastRSSI();
}

void ModuleAcquisition::genererId()
{
	String macAddress = WiFi.macAddress();
	macAddress.replace(":", "");							  // Supprimer les deux-points 11:22:33:aa:bb:cc -> 112233aabbcc
	String derniersOctets = macAddress.substring(6);		  // Obtenir les trois derniers octets -> aabbcc
	this->id = (int)strtol(derniersOctets.c_str(), NULL, 16); // Convertir en entier à partir d'une valeur hexadécimale (base 16) -> 0xaabbcc
}

int ModuleAcquisition::getId()
{
	return this->id;
}