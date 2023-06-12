#include "CapteurLum.h"


CapteurLum::CapteurLum()
{
	this->gain = 0;
}

CapteurLum::~CapteurLum()
{
}

CapteurLum::CapteurLum(boolean gain, int tempsMesure)
{
	this->tsl2561 = new SFE_TSL2561();
	this->gain = gain;
	this->valMesure = tempsMesure;
	this->initialiserCapteur();
}

float CapteurLum::getLuminosite()
{
	return this->luminosite;
}

void CapteurLum::acquerirLuminosite()
{
	delay(this->tempsMesure);

	unsigned int data0, data1;
	if (this->tsl2561->getData(data0, data1))
	{
		tsl2561->getLux(this->gain, this->tempsMesure, data0, data1, luminosite);
		delay(5000);
	}
}

bool CapteurLum::getGain()
{
	return this->gain;
}

void CapteurLum::setGain(boolean gain)
{
	this->gain = gain;
	// If gain = false (0), device is set to low gain (1X)
	// If gain = high (1), device is set to high gain (16X)
}

int CapteurLum::getTempsMesure()
{
	return this->tempsMesure;
}

void CapteurLum::setTempsMesure(unsigned char valMesure)
{
	this->tsl2561->setTiming(this->gain, valMesure, this->tempsMesure);
	// If time = 0, integration will be 13.7ms
	// If time = 1, integration will be 101ms
	// If time = 2, integration will be 402ms
	// If time = 3, use manual start / stop to perform your own integration
}

void CapteurLum::initialiserCapteur()
{
	// TODO - implement CapteurLum::initialiserCapteur
	tsl2561->begin();
}

void CapteurLum::allumerCapteur()
{
	// TODO - implement CapteurLum::allumerCapteur
	tsl2561->setPowerUp();
}

void CapteurLum::eteindreCapteur()
{
	// TODO - implement CapteurLum::eteindreCapteur
	tsl2561->setPowerDown();
}
