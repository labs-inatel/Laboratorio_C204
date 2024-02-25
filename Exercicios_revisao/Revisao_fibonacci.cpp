#include<iostream>
using namespace std; //Código O(2^N)

int fib (int n)
{
	if(n == 0 || n == 1) //condição de parada
		return 1;
	else if (n > 1)
		return fib(n - 1) + fib (n - 2); // Chamando a função novamente
}
int main()
{
	int n;

	cin >> n;

	cout <<	fib (n) << " "; // chamando a função e apresentando o fibonacci

	return 0;
}
