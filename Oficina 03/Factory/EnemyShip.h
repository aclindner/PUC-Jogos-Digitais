#pragma once

using namespace std;

#include <iostream>

class EnemyShip {

public:
	EnemyShip() {};
	~EnemyShip() {};

	virtual void followHero() = 0;
	virtual void enterScreen() = 0;
	virtual void shoot() = 0;

protected:
	float damage = 100.0f;
	float velocity = 100.0f;

};