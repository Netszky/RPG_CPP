#pragma once
#include "Items.h"
#include"Arme.h"
#include"Armure.h"
class Inventaire
{
private:
	int nbMax;
	int nbItems;
	void expand();
	void initialize(const int from = 0);
	Items **Array;
public:
	Inventaire();
	~Inventaire();
	Inventaire(const Inventaire &obj);
	inline int taille()const {
		return this->nbItems;
	};
	Items& operator[](const int index);
	void ajouterItem(const Items &item);
	void removeItem(int index);
	void Test() const {
		for (size_t i = 0; i < this->nbItems; i++) {
			cout << this->Array[i]->Test() << endl;
		}
	}
};

