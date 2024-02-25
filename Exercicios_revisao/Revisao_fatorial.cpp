#include<iostream>
using namespace std; //Código O(n)

int fatorial (int n)
{
	if(n == 0) //condição de parada
		return 1;
	else
		return n * fatorial(n - 1); // Chamando a função novamente
}
int main()
{
	int n;

	cin >> n;

	cout <<	fatorial (n) << " "; // chamando a função e apresentando o fatorial

	return 0;
}
