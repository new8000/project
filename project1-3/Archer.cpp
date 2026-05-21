#include "Archer.h"
#include <iostream>
#include <string>
#include "Monster.h"
using namespace std;

Archer::Archer(std::string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp , power + 30, defence)
{
	job = "궁수";
	cout << "궁수로 전직하였습니다 (공격력+ 30)" << endl;
}

void Archer::attack()
{

	cout << "* 화살을 발사한다!" << endl;
}
void Archer::heroATK(Monster* monster)
{
	cout << "* 화살을 발사한다!" << endl;
	int damage = power - monster->getDefence();
	if (damage <= 0)
		damage = 1;
	int monsterHp = monster->getHP();
	monster->setHP(monsterHp - damage);
	cout << "슬라임에게" << damage << "데미지!" << endl;
	cout << "슬라임 HP :" << monsterHp << "->" << monster->getHP() << " (사망)" << endl;
}