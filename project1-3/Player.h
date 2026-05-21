#ifndef PLAYER_H
#define PLAYER_H
#include <string>
//#include "Monster.h"
class Monster;

class Player
{
protected:
	std::string job;
	std::string name;
	int level;
	int hp;
	int mp;
	int power;
	int defence;
public:
	Player(std::string name, int hp, int mp, int power, int defence)
	{
		this->name = name;
		this->hp = hp;
		this->mp = mp;
		this->power = power;
		this->defence = defence;
		level = 1;
	}
	virtual void attack() = 0;
	virtual void heroATK(Monster* monster) = 0;
	virtual ~Player() {};
	//virtual void attack()
	//{
	//	cout << "공격을 시작합니다." << endl;
	//}
	
	void setName(std::string name)
	{
		this->name = name;
	}
	void setHP(int hp)
	{
		this->hp = hp;
	}
	void setMP(int mp)
	{
		this->mp = mp;
	}
	void setPower(int power)
	{
		this->power = power;
	}
	void setDefenc(int defence)
	{
		this->defence = defence;
	}
	std::string getName() { return name; }
	int getHP() { return hp; }
	int getMP() { return mp; }
	int getPower() { return power; }
	int getDefence() { return defence; }
	std::string getjob() { return job; }

	void printPlayerStatus();

};

#endif