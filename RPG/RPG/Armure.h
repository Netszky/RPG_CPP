#pragma once
#include"Items.h"
class Armure : public Items
{
private:
	int type;
	int defense;
public:
	Armure(int type = 0, int defense = 0, string name = "None", int level = 0, int prix = 0);
	virtual ~Armure();

	virtual Armure* clone() const;
	string toString();
};

