#include<iostream>
#include<cmath>
using namespace std;

int calc_a(int x) // Função para calcular a
{
	int a;
	
	a = ((2 * pow(x, 2)) + (3 * x) - 1);

	return a; // retornando valor de a
}
int calc_b(int x) // Função para calcular b
{
	int b;
	
	b = pow(x, 3);

	return b; // retornando valor de b
}
int calc_c(int y) // Função para calcular c
{
	int c;
	
	c = pow(y, 3);

	return c; // retornando valor de c
}
int main()
{
	int a, b, c, x, y;

	cin >> x >> y; // fazendo a leitura de 2 numeros

	a = calc_a (x); // chamando a função a
	cout << "a = " << a << endl;

	b = calc_b(x); // chamando a função b
	cout << "b = " << b << endl;

	c = calc_c (y); // chamando a função c
	cout << "c = " << c << endl;

	return 0;
}
