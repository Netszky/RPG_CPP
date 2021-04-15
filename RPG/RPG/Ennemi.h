#pragma once
#include <stdlib.h>
#include<string>
class Ennemi
{
private:
	std::string name;
	int level;
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	float loot;
	int defense;
	int precision;

public:
	Ennemi(std::string name, int level = 0);
	virtual ~Ennemi();
	const std::string& getName() const { return this->name; };
	inline bool enVie() { return this->hp > 0; }
	std::string getInfo()const;
	inline void getHit(int damage){ this->hp -= damage; };
	inline int Hit()const { return rand() % this->damageMax - this->damageMin; };
	inline int getExp()const { return this->level * 200; };
	inline int getVie()const { return this->hp; }
	inline int getVieMax()const { return this->hpMax; }
	inline int getDefense()const { return this->defense; }
	inline int getDamage()const { return this->damageMax; }
};

