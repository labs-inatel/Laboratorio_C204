#include<iostream>
using namespace std;

int main()
{
	int i, j; //contadores
	int n; // tamanho do problema
	int x; //var aux
	int cont = 0; // quantidade de vezes o for foi executado

	cin >> n;

	for(i = 0; i < n; i++)
	{
		j = 1;
		while(j < n)
		{
			x = i * i;
			j = j * 2;
			cont++;
		}
	}
	// número de vezes que o for foi executado:
	cout << cont << endl;

	return 0;
}
