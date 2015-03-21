#include "ASubject.h"


ASubject::ASubject(string name)
{
	this->name = name;
}


ASubject::~ASubject()
{
}


void ASubject::Attach(Shop *shop)
{
	cout << "Produto: " << this->name << " adicionado ao observer " << shop->getName() << endl;
	list.push_back(shop);
}

void ASubject::Detach(Shop *shop)
{
	cout << "Produto: " << this->name << " removido do observer " << shop->getName() << endl;
	list.remove(shop);
}

void ASubject::Notify(float price)
{
	cout << "Comunicando observers " << endl;
	for each(Shop *shop in list)
	{
		shop->UpdatePrice(price);
	}
}

string ASubject::getName()
{
	return this->name;
}