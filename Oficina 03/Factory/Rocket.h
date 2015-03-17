#pragma once

using namespace std;

#include <iostream>
#include "EnemyShip.h"

class Rocket : public EnemyShip {

public:
	Rocket() {
		damage = 300.0f;
	}

	~Rocket() {

	}

	void followHero() {
		cout << "Rocket seguindo o Hero a " << velocity << endl;
	}

	void enterScreen() {
		cout << "Rocket entrou na tela." << endl;
	}

	void shoot() {
		cout << "Rocket atirou com dano " << damage << endl;
	}

};