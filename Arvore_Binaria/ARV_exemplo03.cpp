#include<iostream>
using namespace std;

int main()
{
	int i = 1, j; //contadores
	int n; // tamanho do problema
	int x; //var aux
	int cont = 0; // quantidade de vezes o for foi executado

	cin >> n;

	while(i < n)
	{
		x = i * i;
		i = i * 2;
		cont++;
	}

	// número de vezes que o for foi executado:
	cout << cont << endl;

	return 0;
}
