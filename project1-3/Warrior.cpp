#include "Warrior.h"
#include <iostream>
#include <string>
#include "Monster.h"

using namespace std;

Warrior::Warrior(std::string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence + 30)
{
	job = "전사";
	cout << "* 전사로 전직하였습니다. (방어력+ 30)" << endl;
}
void Warrior::attack()
{
	cout << "강력한 검 공격을 한다!" << endl;
}

void Warrior::heroATK(Monster* monster)
{
	cout << "강력한 검 공격을 한다!" << endl;
	int damage = power - monster->getDefence();
	if (damage <= 0)
		damage = 1;
	int monsterHp = monster->getHP();
		monster->setHP(monsterHp - damage);
	cout << "슬라임에게" << damage << "데미지!" << endl;
	cout << "슬라임 HP :" << monsterHp << "->" << monster->getHP() << " (사망)" << endl;
}
