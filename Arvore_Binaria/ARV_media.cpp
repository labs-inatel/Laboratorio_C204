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
void soma_elementos (treenodeptr arvore, float &soma) // função para calcular soma dos elementos
{
	
	if (arvore != NULL)
	{
		soma += arvore->info; // somando elementos da arvore, soma será passada para função main por parâmetro de referência
		soma_elementos(arvore->esq, soma);
		soma_elementos(arvore->dir, soma);
	}
}
int main()
{
	treenodeptr arvore = NULL; // ponteiro para a raíz da arvore
	int n; // numeros de elementos inseridos na arvore
	int i = 0; // contador
	float soma; // var para armazenar a soma dos elementos
	float media; // var para armazenar a media dos elementos

    // Realizando a leitura dos elementos a serem inseridos na arvore
	cin >> n;

	while(n != -1) // serão só inseridos elementos diferentes de -1 na arvore
	{
		tInsere(arvore, n); // inserindo elementos na arvore
		i++; // contando os elementos inseridos
		cin >> n; // realizando a leitura dos elementos novamente
		
	}
    soma_elementos(arvore, soma); // chamando a função que irá realizar a soma dos elementos
	media = soma/i; // realizando a media dos elementos
	
	// Apresentando o resultado com duas casas decimais
	cout << fixed << setprecision(2);
	cout << "Media: " << media << endl;

	return 0;
}