#pragma once
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Items
{
private:
	string name;
	int prix;
	int level;
public:
	Items(string name = "None", int level = 0, int prix = 0);

	virtual ~Items();

	inline string Test() const { return this->name; }
	virtual Items* clone()const = 0;


	const string& getName() const { return this->name; }
	const int& getLevel() const { return this->level; }
	const int& getPrix() const { return this->prix; }

};

