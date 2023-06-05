#include "ModuleTemp.h"

ModuleTemp::ModuleTemp() {
	this->capteurTemp = new CapteurTemp();
	
}

ModuleTemp::~ModuleTemp(){
	delete this->capteurTemp;
}

void ModuleTemp::acquerirDonneeUtile() {
	this->capteurTemp->aquerirTemperature();
	this->donneeUtile = this->capteurTemp->getTemperature();
}

void ModuleTemp::transmettreDonnees() {
	this->transmetteur->genererTrame(	this->id,
										'T',
										(unsigned int)donneeUtile *10, //Convertir donneeUtile de float vers int.
										this->niveauBatterie);
	this->transmetteur->transmettreTrame();
}
unsigned char* ModuleTemp::getTrame() {
	return transmetteur->getTrame();
}
