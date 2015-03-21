#include "DummyProduct.h"


DummyProduct::DummyProduct(string name) : ASubject(name)
{

}


DummyProduct::~DummyProduct()
{

}

void DummyProduct::changePrice(float price)
{
	cout << "Mudando o pre�o de " << this->getName() << " para " << price << endl;
	Notify(price);
}