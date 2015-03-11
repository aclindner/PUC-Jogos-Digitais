#pragma once
#ifndef _ANIMAL_
#define _ANIMAL_

using namespace std;

#include <string>

class Animal {

public:
	Animal();
	~Animal();

	string GetNome();
	string GetSom();
	int GetPeso();
	void SetNome(string p_nome);
	void SetSom(string p_som);
	void SetPeso(int p_peso);

	void GetInfo();

	virtual string GetAttack() = 0;

private:
	string nome;
	string som;
	int peso;

};
#endif