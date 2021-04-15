#include "Ennemi.h"
#include <string>

Ennemi::Ennemi(std::string name, int level)
{
	this->name = name;
	this->level = level;
	this->hpMax = this->level*20;
	this->hp = this->hpMax;
	this->damageMin = this->level*5;
	this->damageMax = this->level*30;
	this->loot = rand() % 100;
	this->precision = rand() % 100;
	this->defense = this->level*3;
}

Ennemi::~Ennemi()
{
}

std::string Ennemi::getInfo() const
{
	return this->name + "\n" +
		"Level : " + std::to_string(this->level) + "\n" +
		"Vie: " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax) + "\n" +
		"D�gats Min: " + std::to_string(this->damageMin) + "\n" +
		"D�gats Max: " + std::to_string(this->damageMax) + "\n" +
		"Defense: " + std::to_string(this->defense) + "\n" +
		"Precision: " + std::to_string(this->precision) + "\n";
}
