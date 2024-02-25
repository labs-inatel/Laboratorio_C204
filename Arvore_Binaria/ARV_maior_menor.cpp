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
void emOrdem (treenodeptr arvore, int &maior, int &menor)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq, maior, menor);
		if(arvore->info < menor)
			menor = arvore->info;
		if (arvore->info > maior)
			maior = arvore->info;
		emOrdem(arvore->dir, maior, menor);
	}
}
int main()
{
	treenodeptr arvore = NULL;
	int n; // numeros de elementos inseridos
	int i = 0;
	int maior = -100;
	int menor = 100;
	
	cin >> n;

	while(n != -1)
	{
		tInsere(arvore, n);
		cin >> n;
		i++;
	}
	emOrdem(arvore, maior, menor);
	
	cout << menor << " e " << maior << endl;
	
	return 0;
}
