#pragma once
#include "IObserver.h"
#include <iostream>
#include <string>
using namespace std;

class Shop :
	public IObserver
{
private:
	string name;
	float price;

public:
	Shop(string name);
	string getName();
	void UpdatePrice(float price);
	~Shop();
};

