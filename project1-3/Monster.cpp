#include "Monster.h"
#include "Player.h"


Monster::Monster(string name, int hp, int power, int defence, Item dropItem)
{
	this->name = name;
	this->hp = hp;
	this->power = power;
	this->defence = defence;
	this->dropItem = dropItem;
	

}
void Monster::attack(Player* hero)
{
	cout << "* 산성용액 발사!" << endl;
	int damage = power - hero->getDefence();
	if (damage <= 0)
		damage = 1;
	int playerHp = hero->getHP();
	string playerName = hero->getName();
	hero->setHP(playerHp - damage);
	cout << playerName << "에게" << damage << "데미지!" << endl;
	cout << playerName << " HP :" << playerHp << "->" << hero->getHP() << " (사망)" << endl;
}