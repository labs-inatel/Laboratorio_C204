#include<iostream>
#include<iomanip> // biblioteca de precisão de casas decimais

using namespace std;

struct dado // struct para armazenar 4 notas e a media destas notas
{
	int n1; // nota 1
	int n2; // nota 2
	int n3; // nota 3 
	int n4; // nota 4
	float media; // media das notas
};
int main()
{
	dado *total = NULL; // ponteiro para a struct
	int soma; // variavel para armazenar a soma das notas
	
	total = new dado; // alocando memória
	
	// Realizando a leitura das notas:
	cin >> total->n1 >> total->n2 >> total->n3 >> total->n4;
	
	soma = total->n1 + total->n2 + total->n3 + total->n4; // somando as notas
	
	// Realizando a media das notas e armazenando na var media
	total->media = 1.0 * soma/ 4.0;
	
	// Apresentando o resultado obtido com duas casas decimais:
	cout << fixed << setprecision(2);
	cout << total->media << endl;
	
	delete total; // desalocando memória

	return 0;
}