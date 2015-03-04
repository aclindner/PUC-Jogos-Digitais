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

private:
	string nome;
	string som;
	int peso;

};