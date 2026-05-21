#include "Magician.h"
#include <iostream>
#include <string>
#include "Monster.h"
using namespace std;
Magician::Magician(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp + 30, power, defence)
{
	cout << "* 마법사로 전직하였습니다. (MP + 30)" << endl;
	job = "마법사";

}
void Magician::attack() 
{
	cout << "* 파이어볼을 발사한다!" << endl;
}
void Magician::heroATK(Monster* monster)
{
	cout << "* 파이어볼을 발사한다!" << endl;
	int damage = power - monster->getDefence();
	if (damage <= 0)
		damage = 1;
	int monsterHp = monster->getHP();
	monster->setHP(monsterHp - damage);
	cout << "슬라임에게" << damage << "데미지!" << endl;
	cout << "슬라임 HP :" << monsterHp << "->" << monster->getHP() << " (사망)" << endl;
}