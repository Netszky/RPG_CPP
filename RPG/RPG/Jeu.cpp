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
	Inventaire inv;
	Arme Arme1(2, 10, 0.25, "BOTRK", 1, 100);
	cout << Arme1.toString() << endl;
	Armure A1(1, 10, "WARMOG", 1, 100);
	cout << A1.toString() << endl;
	cout << (personnages[choixPersonnage].getNextExp()) << endl;
}

void Jeu::mainMenu()
{
	if (personnages[choixPersonnage].getExp() >= personnages[choixPersonnage].getNextExp()) {
		 cout << "Niveau "  << personnages[choixPersonnage].getLevel() + 1 << "!" << endl;
		 cout << "Vous avez Gagné 1 Point de compétences, Statistiques et d'aptitude !" << endl;;
		 personnages[choixPersonnage].levelUp();
	}
	cout << "Menu Principal" << endl << endl;

	cout << "1. Info Personnage" << endl;
	cout << "2. Voyager" << endl;
	cout << "3. Acheter" << endl;
	cout << "4. Niveau et Points de Stats" << endl;
	cout << "5. Se Reposer" << endl;
	cout << "6. Inventaire" << endl;
	cout << "7. Créer Personnage" << endl;
	cout << "8. Quitter" << endl;
	
	cin >> choix;
	int stats = 0;
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
		cout << "Exp Avant prochain niveau : " <<   personnages[choixPersonnage].getExp()  << " / "  << personnages[choixPersonnage].getLevel() * 200 << endl;
		while (personnages[choixPersonnage].getSp() > 0 ) {
			cout << "Vous avez des points à dépenser !"<<  endl;
			//cout << personnages[choixPersonnage].getAp() << "points de compétences";
			cout << personnages[choixPersonnage].getSp() << "points de statistiques" << endl;
			cout << "1. HpMax +100" << endl;
			cout << "2. Degats +5" << endl;
			cout << "3. Defense +5" << endl;
			cin >> (stats);
			switch (stats)
			{
			case 1:
				personnages[choixPersonnage].setHp(100);
				cout << " Vie Max = " << personnages[choixPersonnage].getVieMax() << endl;
				personnages[choixPersonnage].setSp(1);
				break;
			case 2:
				personnages[choixPersonnage].setDegats(5);
				cout << " Degats = " << personnages[choixPersonnage].getDgt() << endl;
				personnages[choixPersonnage].setSp(1);
				break;
			case 3:
				personnages[choixPersonnage].setDefense(100);
				cout << " Defense = " << personnages[choixPersonnage].getDef() << endl;
				personnages[choixPersonnage].setSp(1);
				break;
			default:
				break;
			}
		}
		break;
	case 5:

	case 6:
		break;

	case 7:
		cin.ignore();
		createPersonnage();
		break;
	case 8:
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
