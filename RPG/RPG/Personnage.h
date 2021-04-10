#pragma once
#include <string>
#include <iostream>
#include "Inventaire.h"
using namespace std;
class Personnage
{
public:
	Personnage();
	virtual ~Personnage();

	void initialize(string name);
	void getInfo() const;
	string getString() const;
	void levelUp();

	const std::string& getName() const { return this->name; };
	const int& getLevel() const { return this->niveau; };
	const int& getExp() const { return this->exp; };
	const double& getX() const { return this->x; };
	const double& getY() const { return this->y; };
	const int& getVie() const { return this->vie; };
	const int& getVieMax() const { return this->vie_max; };
	const int& getMana() const { return this->mana; };
	const int& getManaMax() const { return this->mana_max; };
	const int& getDef() const { return this->defense; };
	const int& getDgt() const { return this->degats; };
	const int& getCp() const { return this->cp; };
	const int& getSp() const { return this->sp; };
	const int& getAp() const { return this->ap; };
	const int& getPrecision() const { return this->precision; };
	const int& getArgent() const { return this->argent; };
	//const int& getDamageMax() const { return this->damageMax; };
	//const int& getDefense() const { return this->defense; };
	void setArgent(int gain){ this->argent += gain; };
	void setXp(int xp) { this->exp += xp; };
private:

	Inventaire inventaire;
	Arme arme;
	Armure Armure_Tete;
	Armure Armure_Torse;
	Armure Armure_Bras;
	Armure Armure_Pieds;
	//Armure Armure_Poignets;
	//Armure Armure_Bijou;
	//Armure Armure_Collier;
	//Armure Armure_Jambe;
	//Armure Armure_Poignets;
	//Armure Armure_Poignets;
	std::string name;
	int nextniveau;
	int  exp;
	int niveau;
	int argent;
	double x;
	double y;
	int vie;
	int vie_max;
	int mana;
	int defense;
	int degats;
	int cp;
	int precision;
	int sp;
	int mana_max;
	int ap;
};

