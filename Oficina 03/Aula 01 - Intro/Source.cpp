using namespace std;

#include <iostream>

#include "Cao.h"
#include "Galinha.h"
#include "Animal.h"

int main() {

	Animal arara;

	arara.SetNome("Arara Rara");
	arara.SetSom("Aaaahhh aaaaaaaahh");
	arara.SetPeso(400);

	cout << arara.GetSom() << endl;
	arara.GetInfo();

	system("PAUSE");

	return 0;
}