#include<iostream>
using namespace std;

int sinal(int n) // Função para verificar se o número é positivo, negativo ou zero:
{
	// Verificação se o numero é positivo, negativo ou zero
	if(n > 0) 
		return 1; // retorna 1 = positivo
	else if (n < 0)
		return -1; // retorna -1 = negativo
	else 
		return 0; // retorna 0 = zero
}
int main()
{
	int n; // numero a ser verificado
	int res; // variavel para armazenar o retorno da função "sinal"

	//Fazer leitura do número:
	cin >> n;

	res = sinal(n); // Chamar a função "sinal"

	//Apresentar o resultado de acordo com o respectivo retorno da função:
	if (res == 1)
		cout << "Positivo" << endl;
	else if (res == -1)
		cout << "Negativo" << endl;
	else
		cout << "Zero" << endl;
	
	return 0;
}
