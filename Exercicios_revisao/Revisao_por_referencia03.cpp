#include<iostream>
using namespace std;

void troca(int &X, int &Y) // Função para troca os valores de x e y
{
	int aux = 0; // var aux para realizar a troca
	
	aux = X; // armazenando valor de x em aux
	X = Y; // armazenando valor de y em x
	Y = aux; // armazenando valor de aux em y 
}
int main()
{
	int X,Y; // numeros a serem inseridos
	
	cin >> X >> Y; // fazendo leitura dos números
	
	troca(X,Y); // chamando a função
	
	cout << X << " " << Y << endl; // apresentando x e y

	return 0;
}
