#ifndef MESURE_H
#define MESURE_H

#include <time.h>
#include <string>
#include <iostream>
class Mesure {

private:
	time_t date;
	float valeur;
	std::string ID_ESP32;
	char* temps;

public:
	Mesure();

	~Mesure();

	Mesure(time_t date, float valeur, std::string ID_ESP32);

	Mesure(float valeur, std::string ID_ESP32);

	void setdate();

	char* getdate();
};

#endif
