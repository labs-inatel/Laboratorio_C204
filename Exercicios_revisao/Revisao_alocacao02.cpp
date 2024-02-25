#include<iostream>
using namespace std;

int main()
{
	int *vetor = NULL; // ponteiro p/ o vetor
	int n; // tamanho desejado p/ o vetor
	int i; //contador

	//lendo o tamanho do vetor
	cin >> n;

	//Alocando memoria
	vetor = new int[n];

	//Lendo elementos
	for(i = 0; i < n; n++)
		cin >> vetor[i];

	//Mostrando o vetor
	for(i = 0; i < n; n++)
		cout << vetor[i] << endl;

	//Liberando memória
	delete []vetor;


	return 0;
}
