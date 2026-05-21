#pragma once
#include <iostream>

using namespace std;

struct Item
{
	string name;
	int price;

	void PrintInfo() const;
};