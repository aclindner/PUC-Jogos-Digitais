#pragma once
#include <iostream>
#include <string>
#include <list> //estrutura de lista 
#include "Shop.h"

using namespace std;

class ASubject
{
	string name;
	list<Shop*> list;

public:
	ASubject(string name);
	~ASubject();

	void Attach(Shop *shop);
	void Detach(Shop *shop);
	void Notify(float price);
	string getName();
};

