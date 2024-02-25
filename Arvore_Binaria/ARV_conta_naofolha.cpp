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
void contfolha (treenodeptr arvore, int &folha, int &aux, int &n) // Função para realizar contagem das folhas da arvore
{
	if (arvore != NULL)
	{
		n++;
		aux = 0; 
		contfolha(arvore->esq, folha, aux, n); 
		contfolha(arvore->dir, folha, aux, n);
		if(aux == 2) // se aux for igual de 2, ou seja, quando o elemento tiver filhos 
		{
			folha++; // conta quantidade de folhas
			aux = 0; 
		}
	}
	else
		aux++; // contador
}
int naoFolhas(treenodeptr arvore)
{
	int folha = 0; // var para armazenar a quantidade de nao folhas presentes na arvore
	int aux;  // var pra auxiliar na contagem de nao folhas da arvore
	int n = 0; // quantidade de elementos na arvore
	int naofolha; // calcula a quantidade de folhas da arvore
	
	contfolha (arvore,folha,aux, n); // chamando a função que irá contar a quantidade de nao folhas
	
	naofolha = n - folha;
	
	return naofolha;
}
int main()
{
	treenodeptr arvore = NULL; // ponteiro para a raíz da arvore
	int n; // quantidade de elementos
    int retorno; // var para armazenar retorno da função naoFolhas
    
	// Realizando a leitura da quantidade de elementos a serem inseridos na arvore
	cin >> n;

	while(n != -1) // Inserindo elementos diferentes de -1 na arvore
	{
		tInsere(arvore, n);
		cin >> n;
	}
    retorno = naoFolhas(arvore);
	
	// Apresentando a quantidade de nao folhas
	cout << retorno << endl;

	tDestruir(arvore); // chamando a função que irá destruir a arvore
	
	return 0;
}