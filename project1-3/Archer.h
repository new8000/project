#ifndef ARCHER_H
#define ARCHER_H
#include <string>
#include "Player.h"

class Archer :
	public Player
{
public:
	Archer(std::string name, int hp, int mp, int power, int defence);
		
	void attack() override;
	void heroATK(Monster* monster);
};

#endif