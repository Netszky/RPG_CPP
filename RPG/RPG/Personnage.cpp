#include "Personnage.h"
Personnage::Personnage()
{
	this->x = 0.0;
	this->y = 0.0;

	this->name = name;
	this->argent = 0;
	this->nextniveau = 0; // exp avant prochain niveau
	this->exp = 0; // exp du personnage
	this->niveau = 1; // niveau du personnage
	this->vie = 0; // vie du personnage
	this->vie_max = 0; // vie_max du personnage
	this->mana = 0; // Mana du personnage
	this->mana_max = 0;
	this->defense = 0; // Defense du personnage
	this->degats = 0; // Dégats du personnage
	this->cp = 0; // Point de compétences pour les améliorer
	this->sp = 0; // Point de stats pour les améliorer
	this->ap = 0; // Adaptative Power Statistiques qui augmentes la puissance des compétences
	this->precision = 0;
}

Personnage::~Personnage()
{
}

void Personnage::initialize(string name)
{
	this->x = 0.0;
	this->y = 0.0;

	this->name = name;
	this->argent = 100;
	
	this->exp = 0; // exp du personnage
	this->niveau = 1; // niveau du personnage
	this->nextniveau = this->niveau * 200; // exp avant prochain niveau
	this->vie = 100; // vie du personnage
	this->vie_max = 100; // vie_max du personnage
	this->mana = 100; // Mana du personnage
	this->mana_max = 100;
	this->defense = 10; // Defense du personnage
	this->degats = 10; // Dégats du personnage
	this->cp = 0; // Point de compétences pour les améliorer
	this->sp = 0; // Point de stats pour les améliorer
	this->ap = 0; // Adaptative Power Statistiques qui augmentes la puissance des compétences
	this->precision = 0.90;
	this->Armure_Bras = Armure(1, 10, "WARMOG", 1, 110);
}

void Personnage::getInfo() const
{
	cout << "Statistiques: " << endl;
	cout << "Gold: " << this->argent << endl;
	cout << "Nom : " << this->name << endl; 
	cout << "Experiences : " << this->exp << endl; 
	cout << "Prochain niveau dans : " << this->nextniveau << " Exp" << endl; 
	cout << "Niveau : " << this->niveau << endl; 
	cout << "Vie : " << this->vie << " / " << this->vie_max << endl; 
	cout << "Mana : " << this->mana << " / " << this-> mana_max << endl; 
	cout << "Precision : " << this->precision << endl;
	cout << "Defense : " << this->defense << endl; 
	cout << "Dégats : " << this->degats << endl; 
	cout << "CP Restants : " << this->cp << endl; 
	cout << "SP Restants : " << this->sp << endl; 
	cout << "AP Restants : " << this->ap << endl; 
	cout << "Bras " << this->Armure_Bras.getName() << endl;

}

string Personnage::getString() const {
	return std::to_string(x) + " "
		+ std::to_string(x) + " "
		+ std::to_string(y) + " "
		+ name + " "
		+ std::to_string(exp) + " "
		+ std::to_string(precision) + " "
		+ std::to_string(niveau) + " "
		+ std::to_string(vie) + " "
		+ std::to_string(mana) + " "
		+ std::to_string(defense) + " "
		+ std::to_string(degats) + " "
		+ std::to_string(cp) + " "
		+ std::to_string(sp) + " "
		+ std::to_string(ap) + " ";

}

void Personnage::levelUp()
{
	if (exp >= nextniveau) {
		niveau++;
		this->exp = 0;
		this->cp++;
		this->sp++;
		this->ap++;
	}
}
