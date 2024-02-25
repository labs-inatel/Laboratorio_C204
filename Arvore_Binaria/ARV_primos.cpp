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
void Ordemprim (treenodeptr arvore, int &n)
{
	if (arvore != NULL)
	{
		if (arvore->info % 2 != 0 && arvore->info % 3 != 0 && arvore->info % 5 != 0 && arvore->info % 7 != 0 )
			n++;

		else if (arvore->info == 1 || arvore->info == 2 || arvore->info == 3 || arvore->info == 5 || arvore->info == 7)
			n++;
		Ordemprim(arvore->esq, n);
		Ordemprim(arvore->dir, n);
	}
}
int contaPrimos(treenodeptr arvore)
{
	int n = 0;
	Ordemprim(arvore, n);

	return n;
}
int main()
{
	treenodeptr arvore = NULL;
	int n; // numeros de elementos inseridos
	int i = 0;

	cin >> n;

	while(n != -1)
	{
		tInsere(arvore, n);
		cin >> n;
		i++;
	}
	n = contaPrimos(arvore);

	cout << n << " numeros primos" << endl;

	return 0;
}
