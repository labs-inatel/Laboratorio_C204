#include<iostream>
#include<list>

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
//Realiza um percurso em nível na árvore
void emNivel(treenodeptr t)
{
	treenodeptr n;
	list<treenodeptr> q;

	if (t != NULL)
	{
		q.push_back (t);
		while (!q.empty())
		{
			n = *q.begin();
			q.pop_front();
			if (n->esq != NULL)
				q.push_back(n->esq);
			if (n->dir != NULL)
				q.push_back(n->dir);
			cout << n->info << " ";
		}
	}
}
int main ()
{
	treenodeptr arvore = NULL;

	int n; // numeros de elementos inseridos

	cin >> n;
	while(n != -1)
	{
		tInsere(arvore, n);
		cin >> n;
	}

	emNivel(arvore);

	return 0;
}

8 3 10 14 6 4 13 7 1 - 1
