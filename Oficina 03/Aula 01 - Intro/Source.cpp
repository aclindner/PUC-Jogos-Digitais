using namespace std;

#include <iostream>

#include "Cao.h"
#include "Galinha.h"
#include "Animal.h"

int main() {

	Galinha pintadinha;

	pintadinha.SetNome("Galinha Pintadinha");
	pintadinha.SetPeso(400);

	cout << pintadinha.GetSom() << endl;
	pintadinha.GetInfo();

	system("PAUSE");

	return 0;
}