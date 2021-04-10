#include "Arme.h"

Arme::Arme(int damageMin, int damageMax, int critChance, string name, int level, int prix):Items(name,level,prix)
{
	this->damageMin = damageMin;
	this->damageMax = damageMax;
	this->critChance = critChance;
}

Arme::~Arme()
{

}

Arme* Arme::clone() const
{
	return new Arme(*this);
}

string Arme::toString()
{
	string str = to_string(this->damageMin) + " " + to_string(this->damageMax);
	return str;
}
