#include "Armure.h"

Armure::Armure(int type, int defense, string name, int level, int prix) : Items(name, level, prix)
{
	this->type = type;
	this->defense = defense;
}

Armure::~Armure()
{
}

Armure* Armure::clone() const
{
	return new Armure(*this);
}

string Armure::toString()
{
	string str = to_string(this->type) + " " + to_string(this->defense);
	return str;
}
