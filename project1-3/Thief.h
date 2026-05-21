#ifndef THIEF_H
#define THIEF_H
#include <string>
#include "Player.h"

class Thief :
	public Player
{
public:
	Thief(std::string name, int hp, int mp, int power, int defence);
	void attack() override;
	void heroATK(Monster* monster);
};
#endif