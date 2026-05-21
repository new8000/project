#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
#include "Player.h"

class Warrior : 
	public Player
{
public:
	Warrior(std::string name, int hp, int mp, int power, int defence);
	
	void attack() override;
	void heroATK(Monster* monster);
};
#endif