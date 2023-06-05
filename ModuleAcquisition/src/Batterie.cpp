#include "Batterie.h"


Batterie::Batterie() {
	pinMode(BATTERY_LEVEL_PIN, INPUT);
}

Batterie::~Batterie() {

}

float Batterie::getTension() {
	return this->tension;
}

int Batterie::getNiveau() {
	return this->niveau;
}

void Batterie::acquerirTension() {
	float v_mes = analogRead(BATTERY_LEVEL_PIN);
 	tension = 1.435*(v_mes/4095)*3.3;
 	delay(100);
}

void Batterie::acquerirNiveau() {
	acquerirTension();
	this->niveau = calculerNiveau(this->tension);
}

int Batterie::calculerNiveau(float tension) {
	int niveau = ((tension - TENSION_MIN)/(TENSION_MAX - TENSION_MIN))*100;
	if(niveau >= 100)
	{
		niveau = 100;
	}
	return niveau;
}
