#include <iostream>
#include <string>
#include "Shop.h"
#include "DummyProduct.h"

using namespace std;

int main()
{
	DummyProduct product1("pao");

	Shop shop1("Padaria");
	Shop shop2("Mercado");

	product1.Attach(&shop1);
	product1.changePrice(10.0f); //CHANGE PRICE

	product1.Attach(&shop2);
	product1.changePrice(23.0f); //CHANGE PRICE
	product1.Detach(&shop1);

	product1.changePrice(45.0f); //CHANGE PRICE


	system("pause");
	return 0;
}