#include<iostream>
#include<list> // Biblioteca para listas
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
//Realiza um percurso em nível na árvore
void emNivel(treenodeptr arvore, int &soma)
{
	treenodeptr n; // ponteiro de arvore aux
	list<treenodeptr> q; // lista aux

	if (arvore != NULL) // se o nó da arvore não estiver vazio
	{
		q.push_back (arvore); // listando a arvore
		while (!q.empty())
		{
			n = *q.begin();
			q.pop_front(); // retira o primeiro nó da lista
			if (n->esq != NULL) // se o nó esquerdo for diferente de NULL
				q.push_back(n->esq); // colocando o nó como ultimo da fila
			if (n->dir != NULL) // se o nó direito for diferente de NULL
				q.push_back(n->dir); // colocando o nó como ultimo da fila
			soma = soma + n->info; // apresentando o percruso em nível
		}
	}
}
void Ordemprim (treenodeptr arvore, int &n) // Função que verificará se há numeros primos na arvore
{
	if (arvore != NULL)
	{
	    // condição para numeros não primos
		if (arvore->info % 2 != 0 && arvore->info % 3 != 0 && arvore->info % 5 != 0 && arvore->info % 7 != 0 ) // condição para numeros não primos
			n++;
        // condição para numeros primos
		else if (arvore->info == 1 || arvore->info == 2 || arvore->info == 3 || arvore->info == 5 || arvore->info == 7) 
			n++; // contando numeros primos
		Ordemprim(arvore->esq, n);
		Ordemprim(arvore->dir, n);
	}
}
int contaPrimos(treenodeptr arvore) // Função que contará quantidade de números primos na arvore
{
	int n = 0; // contador iniciado em zero
	Ordemprim(arvore, n); // chamando função que irá verificar se há numeros primos na arvore

	return n; // retornará a quantidade de numeros primos presentes na arvore
}
int main()
{
    //FAZER UM CODIGO QUE FAÇA PERCURSO EM NIVEL
    // MEDIA DOS ELEMENTOS E VERIFICA A QUANTIDADE DE PRIMOS
	
	treenodeptr arvore = NULL;
	int n;
	int m = 0;
	int soma = 0;
	int primos;
	float media;

	cin >> n;
	
	while(n != -1)
	{
		tInsere(arvore,n);
		m++;
		cin >> n;
	}
	emNivel(arvore,soma);
	
	media = (1.0 * soma) / m;
	
	primos = contaPrimos(arvore);
	
	cout << fixed << setprecision(2);
	cout << "Media: " << media << endl;
	cout << "Quantidade de primos: " << primos << endl;

	tDestruir(arvore);

	return 0;
}
