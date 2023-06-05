#include "CapteurTemp.h"

CapteurTemp::CapteurTemp() {
	Wire.begin();
	sts35.address(STS35_I2C_ADDRESS);
	// TODO - implement CapteurTemp::CapteurTemp
}

CapteurTemp::CapteurTemp(uint8_t adresse) {
	Wire.begin();
	sts35.address(adresse);
	// TODO - implement CapteurTemp::CapteurTemp
}

float CapteurTemp::getTemperature() {
	return this->temperature;
}

void CapteurTemp::aquerirTemperature() {
	this->temperature = sts35.readTemperature();// TODO - implement CapteurTemp::aquerirTemperature
	
}

CapteurTemp::~CapteurTemp() {
	// TODO - implement CapteurTemp::~CapteurTemp
	
}