#include <iostream>
#include <list>
using namespace std;
struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode *treenodeptr;

void tInsert(treenodeptr &p, int x)
{
	if (p == NULL)
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info)
		tInsert(p->esq, x);
	else if (x >= p->info)
		tInsert(p->dir, x);
}
void preOrdem(treenodeptr arvore)
{
	if (arvore != NULL)
	{
		cout << arvore->info << endl;
		preOrdem(arvore->esq);
		preOrdem(arvore->dir);
	}
}
void emOrdem(treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << endl;
		emOrdem(arvore->dir);
	}
}
void posOrdem(treenodeptr arvore)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq);
		posOrdem(arvore->dir);
		cout << arvore->info << endl;
	}
}
void preOrdemList(treenodeptr arvore, list<int> &l)
{
	if (arvore != NULL)
	{
		l.push_back(arvore->info);
		preOrdemList(arvore->esq, l);
		preOrdemList(arvore->dir, l);
	}
}
void emOrdemList(treenodeptr arvore, list<int> &l)
{
	if (arvore != NULL)
	{
		emOrdemList(arvore->esq, l);
		l.push_back(arvore->info);
		emOrdemList(arvore->dir, l);
	}
}
void posOrdemList(treenodeptr arvore, list<int> &l)
{
	if (arvore != NULL)
	{
		posOrdemList(arvore->esq, l);
		posOrdemList(arvore->dir, l);
		l.push_back(arvore->info);
	}
}
void contaPreOrdem(treenodeptr arvore, int &n)
{
	if (arvore != NULL)
	{
		n++;
		contaPreOrdem(arvore->esq, n);
		contaPreOrdem(arvore->dir, n);
	}
}
int main()
{
	treenodeptr arvore = NULL; // Ponteiro para a raiz da árvore
	int n = 0;                 // Valor a ser inserido
	int cidade;                // Cidade a ser buscada
	int distPosOrdem = 0;      // Distância entre os nós da posOrdem
	int distEmOrdem = 0;       // Distância entre os nós da emOrdem
	int distPreOrdem = 0;      // Distância entre os nós da preOrdem
	
	// realizar preOrdem, emOrdem e posOrdem e verificar qual é a cidade mais próxima
	list<int> pOList;
	list<int> eOList;
	list<int> posOList;
	list<int>::iterator m;
	
	while (n != -1)
	{
		cin >> n;
		if (n != -1)
			tInsert(arvore, n);
	}

	cin >> cidade;
	
	preOrdemList(arvore, pOList);
	emOrdemList(arvore, eOList);
	posOrdemList(arvore, posOList);
	
	for (m = pOList.begin(); m != pOList.end(); m++)
	{
		distPreOrdem++;
		if (*m == cidade)
			break;
	}
	for (m = eOList.begin(); m != eOList.end(); m++)
	{
		distEmOrdem++;
		if (*m == cidade)
			break;
	}
	for (m = posOList.begin(); m != posOList.end(); m++)
	{
		distPosOrdem++;
		if (*m == cidade)
			break;
	}
	// imprimir qual método de busca foi mais rápido
	if (distPreOrdem < distEmOrdem && distPreOrdem < distPosOrdem)
		cout << "Pre" << endl;
	else if (distEmOrdem < distPreOrdem && distEmOrdem < distPosOrdem)
		cout << "Em" << endl;
	else
		cout << "Pos" << endl;
	return 0;
}
