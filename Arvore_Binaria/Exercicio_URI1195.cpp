#include<iostream>

using namespace std;

struct treenode // struct para armazenar a arvore
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode * treenodeptr;

void tInsere(treenodeptr &p, int x) // função para inserir os elementos na arvore
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode; // ponteiro para arvore
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}

	else if (x < p->info) // insere na subarvore esquerda, se o valor for menor que a raiz
		tInsere(p->esq, x);
	else             // insere na subarvore direita, se o valor for maior que a raiz
		tInsere(p->dir, x);
}
void tDestruir (treenodeptr &arvore) // Função para destruir a arvore
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}
void preordem(treenodeptr arvore)
{
	if (arvore != NULL)
	{
		cout << arvore->info << " ";
		preordem (arvore->esq);
		preordem (arvore->dir);
	}
}
void emordem(treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emordem (arvore->esq);
		cout << arvore->info << " ";
		emordem (arvore->dir);
	}
}
void posordem(treenodeptr arvore)
{
	if (arvore != NULL)
	{
		posordem (arvore->esq);
		posordem (arvore->dir);
		cout << arvore->info << " ";
	}
}
int main()
{
	treenodeptr arvore = NULL;
	int n, m, x;
	int i = 0;
	int j = 0;

	cin >> n;

	while(n != i)
	{
		cin >> m;

		while (m != j)
		{
			cin >> x;
			tInsere(arvore, x);
			j++;
		}
		j = 0;
		
		i++;
		
		cout << "Case " << i << " :" << endl;
		cout << "Pre.: ";
		preordem(arvore);
		cout << endl;
		cout << "In..: ";
		emordem(arvore);
		cout << endl;
		cout << "Post: ";
		posordem(arvore);
		cout << endl;
		
		tDestruir(arvore);
	}
	
	return 0;
}
