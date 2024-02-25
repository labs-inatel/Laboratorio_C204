#include<iostream>
#include<iomanip>
using namespace std;

float media(int notas[], int nAlunos) // função para calcular a media de notas
{
	float soma = 0; // var para calcular a soma das notas
	float res; // var para armazenar o valor da media das notas
	int i; // contador
	
	for (i = 0; i < nAlunos; i++) 
		soma += notas[i]; // calculando a soma das notas
	
	res = soma/ nAlunos; // calculando a media da turma
	
	return res; // retornando o valor da media
}
int main()
{
	int notas[20]; //vetor para armazenar as notas dos alunos
	int n; // total de alunos
	int i; // contador
	float total; // var aux para armazenar o retorno da função
	
	cin >> n; // Fazendo a leitura da quantidade de alunos

	for (i = 0; i < n; i++)
		cin >> notas[i]; // lendo e armazenando as notas no vetor

	total = media (notas, n); // chamando a função e armazenando o seu retorno

	cout << fixed << setprecision(2); // apresentando a media da turma com duas casas decimais
	cout << "Media da turma = " << total << endl;

	return 0;
}
