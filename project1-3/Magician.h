#ifndef MAGICIAN_H
#define MAGICIAN_H
#include <string>
#include "Player.h"

class Magician :
	public Player
{
public:
	Magician(std::string name, int hp, int mp, int power, int defence);
	
	void attack() override;
	void heroATK(Monster* monster);
};
#endif