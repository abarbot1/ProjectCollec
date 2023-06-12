#ifndef CAPTEURLUM_H
#define CAPTEURLUM_H

#include <SparkFunTSL2561.h>

class CapteurLum
{

private:
	double luminosite;
	int ID;
	boolean gain;
	unsigned int tempsMesure;
	unsigned char valMesure;
	SFE_TSL2561 *tsl2561;

public:
	CapteurLum();

	~CapteurLum();

	CapteurLum(boolean gain, int tempsMesure);

	float getLuminosite();

	void acquerirLuminosite();

	bool getGain();

	void setGain(boolean gain);

	int getTempsMesure();

	void setTempsMesure(unsigned char valMesure);

	void allumerCapteur();

	void eteindreCapteur();

private:
	void initialiserCapteur();
};

#endif

