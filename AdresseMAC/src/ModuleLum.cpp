#include "ModuleLum.h"

ModuleLum::ModuleLum() {
	this->capteurLum = new CapteurLum(0, 2);
	
}

ModuleLum::~ModuleLum(){
	delete this->capteurLum;
}

void ModuleLum::acquerirDonneeUtile() {
	this->capteurLum->setGain(0);
	this->capteurLum->setTempsMesure(2);
	this->capteurLum->allumerCapteur();
	delay(capteurLum->getTempsMesure());
	this->capteurLum->acquerirLuminosite();
	this->donneeUtile = this->capteurLum->getLuminosite();
	this->capteurLum->eteindreCapteur();
}

void ModuleLum::transmettreDonnees() {
	this->transmetteur->genererTrame(	this->id,
										'L',
										(int)donneeUtile, //Convertir donneeUtile de float vers int.
										this->niveauBatterie);
	this->transmetteur->transmettreTrame();
}
