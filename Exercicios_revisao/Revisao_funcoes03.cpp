#include<iostream>
#include<iomanip>
using namespace std;

float ideal(float h, char sexo) //Função para calcular o peso ideal
{
	float peso; // variavel para armazenar o valor do peso ideal
	
	//Calcular o peso ideal de acordo com o respectivo sexo:
	if (sexo == 'M')
		peso = (72.7 * h) - 58;
	else if (sexo == 'F')
		peso = (62.1 * h) - 44.7;
		
	return peso; // retorna o valor do peso ideal
}
int main()
{
	float altura; // variavel para fazer leitura da altura do individuo
	char sexo; // variavel para fazer leitura do sexo do individuo
	float peso; // variavel para armazenar o retorno da função "ideal"

	//Fazer leitura da altura e sexo:
	cin >> altura >> sexo;

	peso = ideal(altura, sexo); // Chamar a função "ideal"
	
	//Apresentar o resultado:
	cout << fixed << setprecision(2);
	cout << "Peso ideal = " << peso << " kg" << endl;

	return 0;
}
