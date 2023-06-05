#ifndef MODULETemp_H
#define MODULETemp_H

#include "CapteurTemp.h"
#include "ModuleAcquisition.h"

class ModuleTemp : public ModuleAcquisition {

private:
	CapteurTemp* capteurTemp;
	
public:
	ModuleTemp();

	~ModuleTemp();

	void acquerirDonneeUtile();

	void transmettreDonnees();

	unsigned char * getTrame();
};

#endif
