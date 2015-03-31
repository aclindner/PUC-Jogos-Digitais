#include <iostream>

#include "LStack.h"
#include "AStack.h"

int main() {

	LStack <int> p1;

	for (int i = 0; i <= 3; i++)
		p1.Push(i);

	p1.Pop();
	p1.Pop();

	std::cout << p1.Top() << std::endl;

	AStack<char> p2(3);
	p2.Push('a');
	p2.Push('b');
	p2.Push('c');

	return 0;
}