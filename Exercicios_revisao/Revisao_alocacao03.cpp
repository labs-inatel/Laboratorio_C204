#include<iostream>
using namespace std;

struct dado
{
	int info1;
	int info2;
};
int main()
{
	dado *pessoa = NULL;

	pessoa = new dado;

	pessoa->info1 = 2;
	pessoa->info2 = 3;

	cout << pessoa->info1 << endl;
	cout << pessoa->info2 << endl;
	
	delete pessoa;

	return 0;
}
