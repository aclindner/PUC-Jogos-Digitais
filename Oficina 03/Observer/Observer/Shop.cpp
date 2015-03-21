#include "Shop.h"


Shop::Shop(string name)
{
	this->name = name;
}


Shop::~Shop()
{
}

string Shop::getName()
{
	return this->name;
}

void Shop::UpdatePrice(float price)
{
	this->price = price;
	cout << "Preço no " << name << " agora é " << price << endl;
}