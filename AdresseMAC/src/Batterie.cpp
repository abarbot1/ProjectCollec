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

void Batterie::acquerirNiveau() {
	float v_mes = analogRead(BATTERY_LEVEL_PIN);
 	tension = 1.435*(v_mes/4095)*3.3;
 	delay(100);
}

int Batterie::calculerNiveau(float tension) {

}
