#include "Evenement.h"
#include<stdlib.h>
Evenement::Evenement()
{
	this->nbEvent = 3;
}

Evenement::~Evenement()
{
}

void Evenement::newEvent(Personnage &personnage)
{
	//int i = rand() % this->nbEvent + 1;
	int i = 1;
	switch (i)
	{
	case 1:
		Combat(personnage);
		break; //Combat
	case 2:
		Enigme(personnage);
		break; //Enigme
	case 3:
		Gamble(personnage);
		break; //Gamble
	default:
		break; // Rien
	}
}

void Evenement::Combat(Personnage& personnage)
{
	Ennemi e1("Bob",personnage.getLevel());
	int choix = 0;
	bool turn = true;
	bool escape = false;
	bool playerdead = false;
	bool ennemidead = false;

	cout << e1.getName() << " Vous attaque !" << endl;
	cout << e1.getInfo() << endl;

	while (!escape && !playerdead && !ennemidead) {

		if (turn) {
			int escapechance = rand() % 3 + 1;
			int precision = rand() % 100 + 1;
			cout << "Actions : " << endl;
			cout << "1. Fuite" << endl;
			cout << "2. Attaque" << endl;
			cout << "3. Compétences" << endl;
			cout << "4. Objets" << endl;

			cin >> choix;

			switch (choix)
			{
			case 1:
				
				if (escapechance >= 2) {
					cout << "Vous n'arrivez pas a fuir !" << endl;
				}
				if (escapechance <= 2) {
					escape = true;
					cout << "Vous Prenez la fuite !" << endl;
				}
				break;
			case 2:
				
				if (precision > 10) {
					cout << "Vous Attaquez" << endl;
					e1.getHit(personnage.getDgt() - e1.getDefense());
					cout << "Vous infligez " << personnage.getDgt() - e1.getDefense() << " Points de dégats" << endl;
					cout << e1.getVie() << " / " << e1.getVieMax() << endl;
				}
				else {
					cout << e1.getName() << "Esquive !" << endl;
				}
				break;
			default:
				break;
			}
			turn = false;
		}
		else {
			personnage.getHit(e1.getDamage() - personnage.getDef());
			cout << e1.getName() << "Vous Inflige :" << e1.getDamage() - personnage.getDef() << " points de dégats" << endl;
			turn = true;
		}

		if (!personnage.enVie()) {
			playerdead = true;
			cout << "Vous avez été tué !" << endl;
			cout << "Game over" << endl;
		}
		if (!e1.enVie()) {
			ennemidead = true;
			cout << e1.getName() << " est mort !" << endl;
			personnage.setXp(e1.getExp());
			cout << "Vous gagnez " << e1.getExp() << " Point d'expériences" << endl;
			cout << personnage.getExp() << " / " << personnage.getNextExp() << endl;
		}
	}
}

void Evenement::Enigme(Personnage& personnage)
{
	bool passed = false;
	int numb; int rep; int essai = 3;
	numb = rand() % 100 + 1;
	cout << "Guess the Number !" << endl; 
	cout << numb << endl;
	cout << "3 Essais !" << endl;
	while (!passed) {
		cin >> rep;
		if (essai > 0) {
			if (rep > numb) {
				cout << "Plus Petit !" << endl;
				essai--;
				cout << "Encore " << essai << " Tentatives" << endl;
			}
			if (rep < numb) {
				cout << "Plus Grand !" << endl;
				essai--;
				cout << "Encore " << essai << " Tentatives" << endl;
			}
			if(rep == numb) {
				cout << "Vous avez gagnez" << endl;
				personnage.setArgent(50);
				passed = true;
			}
		}
		else {
			passed = true;
			cout << "Vous n'avez pas réussi" << endl;
		}
	}
}

void Evenement::Gamble(Personnage& personnage)
{
	int choiix = 0;
	cout << "Vous décidé de jouer aux dés avec un mystérieux inconnu" << endl;
	cout << "Règles du jeu : Vous avez 2 dés, et 3 lancés" << endl;
	cout << "Tentez de faire plus que votre adversaire" << endl;

	cout << "1. Jeter les dés" << endl;
	cout << "2. Ne prendre aucun risque" << endl;
	cin >> choiix;
	switch (choiix)
	{
	case 1: 
		int jetj;
		int jetia;
		jetj = rand() % 6 + 1;
		cout << jetj << endl;
		jetj += rand() % 6 + 1;
		cout << jetj << endl;
		jetia = rand() % 6 + 1;
		jetia += rand() % 6 + 1;
		if (jetj >= jetia){
			cout << "Vous avez: " << jetj << endl;
			cout << "L'adversaire: " << jetia << endl;
			cout << "Vous gagnez 100 gold ! " << endl;
			personnage.setArgent(100);
		}
		else {
			cout << "Vous avez: " + jetj << endl;
			cout << "L'adversaire: " + jetia << endl;
			cout << "Vous perdez 50 gold ! " << endl;
			personnage.setArgent(-50);
		}
		break;
		// TODO AJOUTER JEU DE YAMS
	case 2:
		break;
	default:
		break;
	}
}
