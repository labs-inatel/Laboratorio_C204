#include<iostream>

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
void preOrdem (treenodeptr arvore, int procurado, int &m)
{
	if (arvore != NULL)
	{
		if(arvore->info == procurado)
			cout << arvore->info << " ";
			m++;
		preOrdem(arvore->esq, procurado);
		preOrdem(arvore->dir, procurado);

	}
}
void emOrdem (treenodeptr arvore, int procurado, int &m2)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq, procurado);
		if(arvore->info == procurado)
			m2++;
		emOrdem(arvore->dir, procurado);
	}
}
void posOrdem (treenodeptr arvore, int procurado, int &m3)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq, procurado);
		posOrdem(arvore->dir, procurado);
		if(arvore->info == procurado)
			m3++;
	}
}
int pos (treenodeptr arvore, m)

int main()
{
	treenodeptr arvore = NULL;
	treenodeptr p = NULL;
	int n;
	int i = 0;
	int procurado;

	cin >> n;

	while(n != -1)
	{
		tInsere(arvore, n);
		cin >> n;
		i++;
	}
	cin >> procurado;

	p = tPesq(arvore, procurado);

	if(p == NULL)
		cout << "Nao encontrado" << endl;
	else
	{
		preOrdem(arvore, procurado);
		cout << endl;
		emOrdem(arvore, procurado);
		cout << endl;
		posOrdem(arvore, procurado);
		cout << endl;
	}

	return 0;
}
