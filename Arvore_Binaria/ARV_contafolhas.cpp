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
void contfolha (treenodeptr arvore, int &folha, int &aux) // Função para realizar contagem das folhas da arvore
{
	if (arvore != NULL)
	{
		aux = 0; 
		contfolha(arvore->esq, folha, aux);
		contfolha(arvore->dir, folha, aux);
		if(aux == 2)
		{
			folha++;
			aux = 0;
		}
	}
	else
		aux++;
}
int main()
{
	treenodeptr arvore = NULL; // ponteiro para a raíz da arvore
	int n; // quantidade de elementos
	int folha = 0; // var para armazenar a quantidade de folhas presentes na arvore
	int aux = 0; // var pra auxiliar na contagem de folhas da arvore

	// Realizando a leitura da quantidade de elementos a serem inseridos na arvore
	cin >> n;

	while(n != -1) // Inserindo elementos diferentes de -1 na arvore
	{
		tInsere(arvore, n);
		cin >> n;
	}
	contfolha (arvore,folha,aux); // chamando a função que irá contar a quantidade de folhas
	
	// Apresentando a quantidade de folhas
	cout << folha << endl;

	return 0;
}