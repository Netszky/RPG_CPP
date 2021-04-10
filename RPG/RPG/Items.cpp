#include "Items.h"

Items::Items(string name, int level, int prix)
{
	this->name = name;
	this->prix = prix;
	this->level = level;
}

Items::~Items()
{
}
