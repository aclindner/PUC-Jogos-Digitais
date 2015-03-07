#pragma once
#ifndef _GALINHA_
#define _GALINHA_

using namespace std;

#include "Animal.h"

class Galinha : public Animal {

public:
	Galinha();
	~Galinha();

	string GetAttack();

private:

};
#endif