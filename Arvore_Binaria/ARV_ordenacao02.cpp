#include<iostream>
#include<iomanip>
using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode * treenodeptr;

void tInsere(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}

	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else             // insere na subarvore direita
		tInsere(p->dir, x);
}
treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento nao encontrado
		return NULL;
	else	if (x == p->info) // elemento encontrado na raiz
		return p;
	else if (x < p->info) // procura na sub ´arvore esquerda
		return tPesq(p->esq, x);
	else             // procura na sub ´arvore direita
		return tPesq(p->dir, x);
}
int contaPrimos(treenodeptr arvore, int m)
{
	int i;
	int div = 0;

	for(i = 1; i <= m; i++)
		if(arvore->info % i == 0)
			div++;
	if (div == 2)
		return 1; // n é primo
	else
		return 0; // n não é primo
}
int main()
{
	treenodeptr arvore = NULL;

	int n; // numeros de elementos inseridos
	int i = 0;
	int m;
	
	cin >> n;

	while(n != -1)
	{
		tInsere(arvore, n);
		cin >> n;
		i++;
	}
	m = i;
	n = contaPrimos(arvore,m);
	m = 0;
	
	if(n == 1)
		m++;
	cout << m << " numeros primos" << endl;

	return 0;
}
