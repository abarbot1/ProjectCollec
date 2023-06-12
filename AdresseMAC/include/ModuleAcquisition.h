#ifndef MODULEACQUISITION_H
#define MODULEACQUISITION_H

#include "Batterie.h"
#include "Transmetteur.hpp"
#include "Radio.hpp"
#include "RadioLora.hpp"

class ModuleAcquisition {

protected:
	float donneeUtile;
	int niveauBatterie;
	int RSSI;
	int id;

	Batterie* batterie;
	Transmetteur* transmetteur;
	Radio* radio;

public:
	ModuleAcquisition();

	virtual ~ModuleAcquisition();

	virtual void acquerirDonneeUtile() = 0;

	void acquerirDonneesSecondaires();

	virtual void transmettreDonnees() = 0;

	void dormir(int duree);

	float getDonneeUtile();

	int getNiveauBatterie();

	int getRSSI();

	int getId();

private : 
	void genererId();
};

#endif
