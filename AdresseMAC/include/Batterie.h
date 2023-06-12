#ifndef BATTERIE_H
#define BATTERIE_H

#include <Arduino.h>
#include <Wire.h>

#define BATTERY_LEVEL_PIN 35

class Batterie {

private:
	float tension;
	int niveau;

public:
	Batterie();

	~Batterie();

	float getTension();

	int getNiveau();

	void acquerirNiveau();

private:
	int calculerNiveau(float tension);
};

#endif
