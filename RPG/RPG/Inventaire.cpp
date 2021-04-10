#include "Inventaire.h"

Inventaire::Inventaire()
{
	this->nbMax = 5;
	this->nbItems = 0;
	this->Array = new Items*[nbMax];
	this->initialize();
}

Inventaire::~Inventaire()
{
	for (size_t i = 0; i < this->nbItems; i++) {
		delete this->Array[i];
	}
	delete[] this->Array;
}

Inventaire::Inventaire(const Inventaire &obj)
{
	this->nbMax = obj.nbMax;
	this->nbItems = obj.nbItems;
	this->Array = new Items * [this->nbMax];

	for (size_t i = 0; i < this->nbItems; i++) {
		this->Array[i] = obj.Array[i]->clone();
	}
	initialize(this->nbItems);
}

void Inventaire::expand() {
	this->nbMax++;
	Items **newArray = new Items *[this->nbMax];
	for (size_t i = 0; i < nbItems; i++) {
		newArray[i] = this->Array[i];
	}
	delete[] this->Array;
	this->Array = newArray;
	this->initialize(this->nbItems);
}
void Inventaire::initialize(const int from) {
	for (size_t i = from; i < nbMax; i++) {
		this->Array[i] = nullptr;
	}
}
Items& Inventaire::operator[](const int index)
{
	if (index < 0 || index >= this->nbItems)
		throw("Erreur");
	return *this->Array[index];
}
void Inventaire::ajouterItem(const Items &item)
{
	this->Array[this->nbItems++] = item.clone();
}

void Inventaire::removeItem(int index)
{

}
