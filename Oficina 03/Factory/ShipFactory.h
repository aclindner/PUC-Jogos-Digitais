#pragma once

#include "EnemyShip.h"
#include "Rocket.h"
#include "UFO.h"

class ShipFactory {

private:
	
	ShipFactory() {}

public:

	static EnemyShip* createShip(char type) {
		switch (type) {
			case 'R':
				return new Rocket();
			case 'U':
				return new UFO();
			case 'r':
				return new Rocket();
			case 'u':
				return new UFO();
			default:
				return 0;
		}
	}

};