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
void emOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->dir);
		cout << arvore->info << " ";
		emOrdem(arvore->esq);
	}
}
int main()
{
	treenodeptr arvore = NULL;
	int n; // numeros de elementos inseridos
	int i;

	i = 0;
	
	cin >> n;

	while(n != -1)
	{
		tInsere(arvore, n);
		cin >> n;
		i++;
	}
	emOrdem(arvore);

	return 0;
}