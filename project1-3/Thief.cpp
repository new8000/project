#include "Thief.h"
#include <iostream>
#include <string>
#include "Monster.h"
using namespace std;
Thief::Thief(std::string name, int hp, int mp, int power, int defence)
	: Player(name, hp + 30, mp, power, defence)
{
	cout << "* 도적으로 전직하였습니다. (HP + 30)" << endl;
	job = "도적";
}
void Thief::attack()
{
	cout << "* 단검으로 공격한다!" << endl;
}
void Thief::heroATK(Monster* monster)
{
	cout << "* 단검으로 공격한다!" << endl;
	int damage = power - monster->getDefence();
	if (damage <= 0)
		damage = 1;
	int monsterHp = monster->getHP();
	monster->setHP(monsterHp - damage);
	cout << "슬라임에게" << damage << "데미지!" << endl;
	cout << "슬라임 HP :" << monsterHp << "->" << monster->getHP() << " (사망)" << endl;
}