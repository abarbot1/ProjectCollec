#ifndef BATTERIE_H
#define BATTERIE_H

#include <Arduino.h>
#include <Wire.h>

#define BATTERY_LEVEL_PIN 35
#define TENSION_MIN 2.6
#define TENSION_MAX 4.7

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
	void acquerirTension();

	int calculerNiveau(float tension);
};

#endif
