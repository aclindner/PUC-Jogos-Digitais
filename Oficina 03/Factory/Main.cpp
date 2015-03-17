using namespace std;

#include "ShipFactory.h"
#include <iostream>
#include <vector>

int main(char * args) {

	char type;
	vector<EnemyShip*> ships;

	while (true) {
		cout << "Choose your Ship:" << endl;
		cout << "R - Rocket" << endl;
		cout << "U - UFO" << endl;

		cin >> type;

		EnemyShip * ship = ShipFactory::createShip(type);

		if (ship != 0)
		{
			ships.push_back(ship);
			for each(EnemyShip* ship in ships) {
				ship->enterScreen();
				ship->followHero();
				ship->shoot();
				cout << endl << endl;
			}
		}
		else {
			cout << "Erro ao criar Ship, entre com um valor válido" << endl << endl;
			break;
		}
	}

	system("PAUSE");

}