#pragma once

using namespace std;

#include <iostream>
#include "EnemyShip.h"

class UFO : public EnemyShip {

public:
	UFO() {

	}

	~UFO() {

	}

	void followHero() {
		cout << "UFO seguindo o Hero a " << velocity << endl;
	}

	void enterScreen() {
		cout << "UFO entrou na tela." << endl;
	}

	void shoot() {
		cout << "UFO atirou com dano " << damage << endl;
	}

};