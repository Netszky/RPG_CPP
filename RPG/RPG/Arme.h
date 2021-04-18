#pragma once
#include"Items.h"
class Arme : 
	public Items
{
private:
	int damageMin;
	int damageMax;
	int critChance;
public:
	Arme(int damageMin = 0, int damageMax = 0, int critChance = 0, string name = "None", int level = 0, int prix = 0);
	virtual ~Arme();
	const int& getDmg() const { return this->damageMin; };
	virtual Arme* clone() const;

	string toString();
};

