#include <iostream>
#include "Player.h"
#include <string>

using namespace std;

void Player::printPlayerStatus()
{
	cout << "------------------------------------" << endl;
	cout << "닉네임" << name << " | 직업: " << job << " | Lv." << level << endl;
	cout << "HP: " << hp << "| MP: " << mp << "| 공격력: " << power << "| 방어력: " << defence << endl;
	cout << "------------------------------------" << endl;
}
//test