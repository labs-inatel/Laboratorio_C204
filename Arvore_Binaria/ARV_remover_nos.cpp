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
	if (p == NULL) // insere na arvore
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
void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}
void emOrdem (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << " ";
		emOrdem(arvore->dir);
	}
}
treenodeptr tMenor(treenodeptr &arvore)
{
	treenodeptr t;
	t = arvore;
	if (t->esq == NULL) // encontrou o menor valor
	{
		arvore = arvore->dir;
		return t;
	}
	else // continua a busca na sub ´arvore esquerda
		return tMenor(arvore->esq);
}
int tRemove(treenodeptr &arvore, int procurado)
{
	treenodeptr p;
	if (arvore == NULL) //  ´arvore vazia
		return 1;
	if (procurado == arvore->info)
	{
		p = arvore;
		if (arvore->esq == NULL)  // a arvore n~ao tem filho esquerdo
			arvore = arvore->dir;

		else if (arvore->dir == NULL) // a arvore n~ao tem filho direito
			arvore = arvore->esq;

		else // a arvore tem ambos os filhos
		{
			p = tMenor(arvore->dir);
			arvore->info = p->info;
		}

		delete p;
		return 0;
	}
	else if (procurado < arvore->info)
		return tRemove(arvore->esq, procurado);
	else
		return tRemove(arvore->dir, procurado);
}
int main()
{
	treenodeptr arvore = NULL;
	int n; // numeros de elementos inseridos
	int procurado;
	int m = 0;

	cin >> n;

	while(n != 0)
	{
		tInsere(arvore, n);
		cin >> n;
	}
	cin >> procurado;

	while(m == 0)
		m = tRemove (arvore, procurado);

	emOrdem(arvore);

	tDestruir(arvore);

	return 0;
}
