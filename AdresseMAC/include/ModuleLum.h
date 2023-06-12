#ifndef MODULELUM_H
#define MODULELUM_H

#include "CapteurLum.h"
#include "ModuleAcquisition.h"

class ModuleLum : public ModuleAcquisition {

private:
	CapteurLum* capteurLum;
	
public:
	ModuleLum();

	~ModuleLum();

	void acquerirDonneeUtile();

	void transmettreDonnees();
};

#endif
