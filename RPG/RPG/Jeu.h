#pragma once
#include "Personnage.h"
#include "Jeu.h"
#include"Map.h"
#include "Inventaire.h"
#include "Ennemi.h"
#include "Fonctions.h"
#include "Evenement.h"
#include"Armure.h"
#include"Arme.h"
#include"Items.h"
#include <string>
#include <iomanip>
#include <ctime>
#include <iostream>>
#include <vector>
#include <fstream>

using namespace std;
class Jeu
{
public:
	Jeu();
	virtual ~Jeu();

	//Méthode
	void mainMenu();
	void Start();
	void createPersonnage();
	void savePersonnage();
	void loadPersonnage();
	void Voyager();
	//Getter Setter
	bool getRunning() const { return this->running; };
// Attributs
private:
	int choix;
	bool running;
	int choixPersonnage;
	std::vector <Personnage> personnages;
	string fichier;
};

