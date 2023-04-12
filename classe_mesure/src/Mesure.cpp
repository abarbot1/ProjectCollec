#include "Mesure.h"

Mesure::Mesure() {
	
}

Mesure::~Mesure() {
	
}

Mesure::Mesure(time_t date, float valeur, std::string ID_ESP32) {
	this->date = date;
	this->valeur = valeur;
	this->ID_ESP32 = ID_ESP32;
}

Mesure::Mesure(float valeur, std::string ID_ESP32) {
	this->valeur = valeur;
	this->ID_ESP32 = ID_ESP32;
}

void Mesure::setdate() {
	date = time(0);
	this->temps = ctime(&date);
}

char* Mesure::getdate(){
	return this->temps;
}
