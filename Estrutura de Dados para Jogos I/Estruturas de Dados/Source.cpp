#include "Array.h"
#include <iostream>

using namespace std;

void MostrarArrayInteiro(int* p_array, int tam) {

	for (int i = 0; i < tam; i++)
		cout << "[" << i << "] = " << p_array[i] << endl;

}

int main()
{
	Array<int> meuarray(5);
	meuarray[0] = 99;
	meuarray[1] = 88;
	meuarray[2] = 77;
	meuarray[3] = 66;
	meuarray[4] = 55;

	MostrarArrayInteiro(meuarray, 5);

	system("PAUSE");
	return 0;
}