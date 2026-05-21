#include <iostream>
#include <vector>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
#include "Item.h"

using namespace std;

void printStatus(string name, int stat[])
{
	cout << "====================================" << endl;
	cout << name << "의 현재 능력치" << endl;
	cout << "====================================" << endl;
	cout << "HP: " << stat[0] << " MP: " << stat[1] << endl;
	cout << "공격력: " << stat[2] << " 방어력: " << stat[3] << endl;
	cout << "====================================" << endl;
}
int main(void)
{

	string name;
	int stat[4];
	cout << "===========================================" << endl;
	cout << "         [ 던전 탈출 텍스트 RPG ]" << endl;
	cout << "===========================================" << endl;
	cout << "용사의 이름을 입력해주세요:";
	cin >> name;
	cout << endl;
	cout << "HP와 MP를 입력해주세요:";

	while (true)
	{
		cin >> stat[0] >> stat[1];
		if (stat[0] > 50 && stat[1] > 50)
		{
			break;
		}
		cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
	}
	cout << "공격력과 방어력을 입력해주세요:";
	while (true)
	{
		cin >> stat[2] >> stat[3];
		if (stat[2] > 50 && stat[3] > 50)
		{
			break;
		}
		cout << "공격력이나 방어력이 너무 작습니다. 다시 입력해주세요." << endl;
	}
	cout << endl;
	printStatus(name, stat);
	cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다." << endl;
	cout << "============================================" << endl;
	cout << "< 캐릭터 강화 >" << endl;
	cout << "1. HP UP    2. MP UP    3. 공격력 2배" << endl;
	cout << "4. 방어력 2배  5. 현재 능력치  0. 게임 시작" << endl;
	cout << "============================================" << endl;

	int HPpotion = 5;
	int MPpotion = 5;
	bool isGameStart = false;

	while (!isGameStart)
	{
		int choice;
		cout << "번호를 선택해주세요:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			if (HPpotion > 0)
			{
				HPpotion -= 1;
				stat[0] += 20;
				cout << "* HP가 20 증가했습니다. (HP 포션 차감: 남은 포션 " << HPpotion << "개)" << endl;
			}
			else
			{
				cout << "HP포션 부족" << endl;
			}
			break;
		}
		case 2:
		{
			if (MPpotion > 0)
			{
				MPpotion -= 1;
				stat[1] += 20;
				cout << "* MP가 20 증가했습니다. (HP 포션 차감: 남은 포션 " << MPpotion << "개)" << endl;
			}
			else
			{
				cout << "MP포션 부족" << endl;
			}

			break;
		}
		case 3:
		{
			cout << "공격력 2배" << endl;
			stat[2] *= 2;
			break;
		}
		case 4:
		{
			cout << "방어력 2배" << endl;
			stat[3] *= 2;
			break;
		}
		case 5:
		{
			cout << "현재 능력치 출력" << endl;
			printStatus(name, stat);
			break;
		}
		case 0:
		{
			cout << "게임을 시작합니다!" << endl;
			isGameStart = true;
			break;
		}

		default:
			cout << "0~5사이의 숫자를 선택해주세요.";
			break;
		}

	}

	int choice;
	cout << "< 전직 시스템 >" << endl;
	cout << name <<"님, 직업을 선택해주세요!" << endl;
	cout << "1. 전사   2. 마법사   3. 도적   4. 궁수" << endl;
	cout << "선택:" << endl;
	cin >> choice;

	Player* hero = nullptr;
	//Warrior* hero = nullptr;

	switch (choice)
	{
	case 1:
	{
		hero = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
		hero->attack();
		hero->printPlayerStatus();

		break;
	}
	case 2:
	{
		hero = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
		hero->attack();
		hero->printPlayerStatus();
		break;
	}
	case 3:
	{
		hero = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
		hero->attack();
		hero->printPlayerStatus();
		break;
	}
	case 4:
	{
		hero = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
		hero->attack();
		hero->printPlayerStatus();
		break;
	}
	default:
	{
		cout << "1~4 사이의 숫자를 입력해주세요." << endl;
	}

	}
	string job = hero->getjob();
	vector<Item> inventory;
	bool isRunning = true;

	while (isRunning)
	{
		cout << endl;
		cout << "=== 메인 메뉴 ===" << endl;
		cout << "1. 던전 입장" << endl;
		cout << "2. 인벤토리 확인" << endl;
		cout << "0. 게임 종료" << endl;
		cout << endl;
		cout << "선택: ";
		cin >> choice;
	switch (choice)
	{
	
	case 1 :
	{
		Item slimItem;
		slimItem.name =	"슬라임의 끈적한 젤리";
		slimItem.price = 30;

		Monster* monster = new Monster("슬라임", 30, 20, 10, slimItem);
		
		cout << "[ 전투 시작! ] " << name << "(" << job << ") vs " << monster->getName() << endl;
		cout << endl;

		while (hero->getHP() > 0 && monster->getHP() > 0)
		{
			cout << "--- 플레이어 턴 ---" << endl;

			// 플레이어 공격
			hero->heroATK(monster);

			// 몬스터 사망 체크
			if (monster->getHP() <= 0)
			{
				break;
			}

			cout << "--- 몬스터 턴 ---" << endl;

			// 몬스터 공격
			monster->attack(hero);

			// 플레이어 사망 체크
			if (hero->getHP() <= 0)
			{
				break;
			}
			
		}
		cout << endl;
		if (hero->getHP() > 0)
		{

			Item droppedItem = monster->getdropItem();

			cout << "★ 전투 승리!" << endl;
			cout << "  -> " << droppedItem.name << " 획득!" << endl;

			inventory.push_back(droppedItem);

			cout << "  -> 인벤토리에 저장되었습니다." << endl;
		}
		else
		{
			cout << "전투 패배" << endl;
		}
		break;
		}
	case 2:
	{
		cout << "[ 인벤토리 (" << inventory.size()	<< "/10) ]" << endl;

		int index = 1;

		for (const Item& item : inventory)
		{
			cout << index << ". ";

			item.PrintInfo();

			index++;
		}

		if (inventory.empty())
		{
			cout << "아이템이 없습니다."
				<< endl;
		}

		break;
	}

	case 0:
	{
		cout << "게임을 종료합니다."
			<< endl;

		isRunning = false;

		break;
	}

	default:
	{
		cout << "잘못된 입력입니다."
			<< endl;

		break;
	}
	}
	}
	
	delete hero;
	return 0;
}