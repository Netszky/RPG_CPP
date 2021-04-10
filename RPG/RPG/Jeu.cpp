#include "Jeu.h"
Jeu::Jeu()
{
	
	choix = 0;
	running = true;
	choixPersonnage = 1;
	fichier = "save.txt";
	
}

Jeu::~Jeu() {

}

void Jeu::Start() {
	createPersonnage();
	Ennemi e(10);
	cout << e.getInfo() << endl;
	Arme Arme1(2, 10, 0.25, "BOTRK", 1, 100);
	cout << Arme1.toString() << endl;
	Armure A1(1, 10, "WARMOG", 1, 100);
	cout << A1.toString() << endl;
}

void Jeu::mainMenu()
{
	cout << "Menu Principal" << endl << endl;

	cout << "1. Info Personnage" << endl;
	cout << "2. Voyager" << endl;
	cout << "3. Acheter" << endl;
	cout << "4. Exp" << endl;
	cout << "5. Se Reposer" << endl;
	cout << "6. Créer Personnage" << endl;
	cout << "7. Sauvegarder Personnage" << endl;
	cout << "8. Charger Personnage" << endl;
	cout << "9. Quitter" << endl;
	
	cin >> choix;

	switch (choix) {
	case 1:
		personnages[choixPersonnage].getInfo();
		break;
	case 2:
		Voyager();
		break;
	case 3:
		cout << "Vous commandez sur Amazon et avec Amazon Prime vous êtes livré instantanément !" << endl;
		break;
	case 4:
		cout << "Exp Avant prochain niveau : " <<   personnages[choixPersonnage].getExp()  << " / "  << personnages[choixPersonnage].getLevel() * 200 << endl;;
		break;
	case 5:

	case 6:
		cin.ignore();
		createPersonnage();
		break;
	case 7:
		savePersonnage();
		break;
	case 8:
		loadPersonnage();
		break;
	case 9:
		running = false;
		break;

	default:
		break;
	}
}

void Jeu::createPersonnage() {
	string name;
	cout << "Entrez le nom de votre personnage" << endl;
	getline(cin, name);

	personnages.push_back(Personnage());
	choixPersonnage = personnages.size() - 1;
	personnages[choixPersonnage].initialize(name);
}
void Jeu::savePersonnage() {
	std::ofstream outFile(fichier);
	if (outFile.is_open()) {
		for (size_t i = 0; i < personnages.size(); i++) {
			outFile << personnages[i].getString();
		}
	}
	outFile.close();
}
void Jeu::loadPersonnage() {
	//TODO
}

void Jeu::Voyager() {
	Evenement e;
	e.newEvent(this->personnages[choixPersonnage]);
}
