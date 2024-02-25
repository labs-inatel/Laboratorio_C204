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
treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento nao encontrado
		return NULL; // retorna vazio
	else	if (x == p->info) // elemento encontrado na raiz
		return p; // retorna a raiz
	else if (x < p->info) // procura na sub arvore esquerda
		return tPesq(p->esq, x); // retorna sub arvore esq
	else             // procura na sub arvore direita
		return tPesq(p->dir, x); // retorna sub arvore dir
}
void contfolha (treenodeptr arvore, int &folha, int &aux, int &p) // Função para realizar contagem das folhas da arvore
{
	if (arvore != NULL)
	{
		aux = 0;
		contfolha(arvore->esq, folha, aux, p);
		contfolha(arvore->dir, folha, aux, p);
		
		if(aux == 2 && arvore->info == p) // se aux for igual a 2, ou seja, quando o elemento não tiver filhos (2 NULL)
		{
			folha++; // conta quantidade de folhas
			aux = 0;
		}
	}
	else
		aux++; // contando a quantidade de vazios (NULL) na arvore
}
treenodeptr tMenor(treenodeptr &arvore) // Função para encontrar o menor nó da arvore
{
	treenodeptr t;
	t = arvore;
	if (t->esq == NULL) // encontrou o menor valor
	{
		arvore = arvore->dir;
		return t; // retorna o menor nó da arvore
	}
	else // continua a busca na sub arvore esquerda
		return tMenor(arvore->esq);
}
int tRemove(treenodeptr &arvore, int procurado)
{
	treenodeptr p;
	if (arvore == NULL) // arvore vazia
		return 1;
	if (procurado == arvore->info) // verificando se o nó da arvoré é o mesmo valor que o nó procurado
	{
		p = arvore;
		if (arvore->esq == NULL)  // a arvore nao tem filho esquerdo
			arvore = arvore->dir;

		else if (arvore->dir == NULL) // a arvore nao tem filho direito
			arvore = arvore->esq;

		else // a arvore tem ambos os filhos
		{
			p = tMenor(arvore->dir); // chamando a função tMenor para verificar qual é o menor nó da arvore
			arvore->info = p->info; // inserindo o nó menor no lugar do nó removido da arvore (nó procurado)
		}

		delete p; // deletando o nó procurado
		return 0; // retornando 0 caso tenha encontrado e removido o nó procurado
	}
	else if (procurado < arvore->info)
		return tRemove(arvore->esq, procurado);
	else
		return tRemove(arvore->dir, procurado);
}
void emOrdem (treenodeptr arvore, int &maior, int &menor, int &aux2)
{
	if(arvore != NULL)
	{
		emOrdem(arvore->esq, maior, menor, aux2);
		cout << arvore->info << " ";

		if (aux2 == 0) // DEIXA PASSAR O PRIMEIRO ELEMENTO Q CONSEQUENTEMENTE É O MENOR DA ARVORE
		{
			menor = arvore->info;
			aux2++;
		}
		if(arvore->info > maior) // BUSCA O MAIOR VALOR
			maior = arvore->info;

		emOrdem(arvore->dir, maior, menor, aux2);
	}
}
int main()
{
	//FAZER UM CODIGO QUE PESQUISE UM VALOR E MOSTRE SE ELE ESTÁ OU NÃO NA ARVORE
	//TAMBEM VERIFICA SE O VALOR PROCURADO É UMA FOLHA E RETIRA ELA DA ARVORE
	//APRESENTA A ARVORE SEM O VALOR PROCURADO E APRESENTA O MAIOR E O MENOR VALOR DA ARVORE
	//SE O VALOR NÃO FOR ENCONTRADO, ELE TAMBÉM APRESENTARÁ O MAIOR E MENOR DA ARVORE 

	treenodeptr arvore = NULL;
	treenodeptr retorno = NULL; // PARA AMARZENAR O RETORNO DA FUNÇÃO tPesq
	int n;
	int p; // VALOR PROCURADO
	int folha = 0; // PARA VARIFICAÇÃO SE É UMA FOLHA
	int aux; // PARA AJUDAR NA VERIFICAÇÃO DA FOLHA
	int aux2 = 0; // PARA AJUDAR NA VERIFICAÇÃO DO MENOR VALOR 
	int removeu = 0; // RETORNO PARA VERIFICAÇÃO SE REMOVEU OU NÃO REMOVEU
	int maior = -1; 
	int menor = 1000;

	cin >> n;

	while (n != -1) // INSERINDO VALORES NA ARVORE
	{
		tInsere(arvore, n);
		cin >> n;
	}
	cin >> p; // LENDO VALOR PROCURADO

	retorno = tPesq(arvore, p); // PESQUISANDO O VALOR NA ARVORE

	if(retorno == NULL) // SE O VALOR FOR NULL, NAO TA NA ARVORE
		cout << "Elemento nao encontrado na arvore" << endl;
	
	else // SE O VALOR DIFERENTE DE NULL, TA NA ARVORE
	{
		cout << "Elemento encontrado na arvore" << endl;
		
		contfolha (arvore, folha, aux, p); // VERIFICANDO SE É UMA FOLHA

		if(folha != 0) // SE FOLHA FOR DIFERENTE DE ZERO, É UMA FOLHA
		{
			cout << "O elemento " << p << " e uma folha" << endl;
			
			while(removeu == 0) // RETIRANDO O ELEMENTO DA ARVORE
				removeu = tRemove(arvore, p);
		}
		else // SE FOLHA FOR IGUAL A ZERO, NÃO É UMA FOLHA
			cout << "O elemento " << p << " não e uma folha" << endl;
	}

	emOrdem(arvore, maior, menor, aux2); // ORDENANDO A ARVORE E BUSCANDO MAIOR E MENOR VALOR
	
	cout << endl;
	cout << "O menor elemento da arvore e: " << menor << endl;
	cout << "O maior elemento da arvore e: " << maior << endl;

	tDestruir (arvore); 

	return 0;
}
