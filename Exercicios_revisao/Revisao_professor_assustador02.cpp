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

	res = soma / nAlunos; // calculando a media da turma

	return res; // retornando o valor da media
}
int nAbaixo(int notas[], int nAlunos, float media) // Função para verificar quant de alunos reprovados
{
	int i; // contador
	int reprovado = 0; // var para armazenar quant de alunos com nota abaixo da media

	for (i = 0; i < nAlunos; i++)
		if (notas[i] < media)
			reprovado++;

	return reprovado;
}
int nAcima(int notas[], int nAlunos, float media) // Função para verificar quant de alunos aprovados
{
	int i; // contador
	int aprovado = 0;  // var para armazenar quant de alunos com nota acima da media

	for (i = 0; i < nAlunos; i++)
		if (notas[i] > media)
			aprovado++;

	return aprovado;
}
int main()
{
	int notas[100]; //vetor para armazenar as notas dos alunos
	int n; // total de alunos
	int i; // contador
	float total; // var aux para armazenar o retorno da função
	int aprovados, reprovados; //vars auxs para armazenar a quantidade de alunos aprovados e reprovados

	cin >> n; // Fazendo a leitura da quantidade de alunos

	for (i = 0; i < n; i++)
		cin >> notas[i]; // lendo e armazenando as notas no vetor

	total = media (notas, n); // chamando a função e armazenando o seu retorno
	aprovados = nAcima(notas,n,total); // chamando a função e armazenando o seu retorno
	reprovados = nAbaixo(notas,n,total); // chamando a função e armazenando o seu retorno

	// apresentando a media da turma com duas casas decimais e a quant de aprovados e reprovados
	cout << fixed << setprecision(2); 
	cout << "Media da turma = " << total << endl;
	cout << "Alunos com nota abaixo da media: " << reprovados << endl;
	cout << "Alunos com nota acima da media: " << aprovados << endl;

	return 0;
}
