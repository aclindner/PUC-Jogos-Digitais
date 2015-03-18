#include <iostream>
#include <string>
#include "GameManager.h"

using namespace std;

int main()
{
	GameManager * gm1, * gm2;

	gm1 = GameManager::getInstance();
	cout << "Value 1:  " << gm1->getValue() << endl;
	gm1->setValue(4);
	cout << "Value 2:  " << gm1->getValue() << endl;

	system("PAUSE");
	return 0;
}