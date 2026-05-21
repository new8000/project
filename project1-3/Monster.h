#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include "Item.h"

using namespace std;
class Player;
class item;

class Monster
{
private:
	string name;

	int hp;
	int power;
	int defence;

	Item dropItem;
	

public:
	Monster(string name, int hp, int power, int defence, Item dropItem);

	void attack(Player* hero);

	void setHP(int hp)
	{
		this->hp = hp;
	}

	string getName() { return name; }

	int getHP() { return hp; }
	int getPower() { return power; }
	int getDefence() { return defence; }

	Item getdropItem() { return dropItem; }
	

};

#endif