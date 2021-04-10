#pragma once
#include "Personnage.h"
#include "Ennemi.h"
class Evenement
{

private:
	int nbEvent;
public:
	Evenement();
	virtual ~Evenement();
	void newEvent(Personnage &personnage);

	void Combat(Personnage &personnage);
	void Enigme(Personnage &personnage);
	void Gamble(Personnage &personnage);
};

