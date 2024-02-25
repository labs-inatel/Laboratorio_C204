#include<iostream>
#include<iomanip> // biblioteca de precisão de casas decimais

using namespace std;

struct dado // struct para armazenar 4 notas e a media destas notas
{
    float n1; // nota 1
	float n2; // nota 2
	float n3; // nota 3 
	float n4; // nota 4
	float media; // media das notas
};
int main()
{
	dado *total; // ponteiro para a struct
	int i; // contador
	int tam; // tamanho do vetor
	int soma[2]; // vetor para armazenar soma das notas
	int soma1 = 0; // var aux para soma das notas

	// Ler tamanho do vetor
	cin >> tam;

	//Alocar memoria para a struct
	total = new dado[tam];

	// Realizar a leitura e soma das notas obtidas:
	for(i = 0; i < tam; i++)
	{
		cin >> total[i].n1 >> total[i].n2 >> total[i].n3 >> total[i].n4;

		soma[i] = total[i].n1 + total[i].n2 + total[i].n3 + total[i].n4;
		
		soma1 = soma1 + soma[i];
	}

	total[i].media = soma1 * 1.0 / (tam *4.0); // realizar media das notas
	
	// Apresentar o resultado com duas casas de precisao
	cout << fixed << setprecision(2);
	cout << total[i].media;

	// Desalocar memoria
	delete [] total;

	return 0;
}