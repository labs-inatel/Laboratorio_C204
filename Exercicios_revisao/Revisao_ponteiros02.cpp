#include<iostream>
using namespace std;

int main()
{
	int vetor[3];
	int *p;

	cout << vetor << endl;

	vetor[0] = 2;
	vetor[1] = 3;
	vetor[2] = 7;
	
	p = vetor;

	cout << *p << endl;
	p++;
	cout << *p << endl;
	p++;
	cout << *p << endl;
	p = *p;
	cout << *p << endl;
	
	return 0;
}
