#include<iostream>
#include<iomanip>
using namespace std;

void converte(float F, float &C, float &K) // Função para converter Fahrenheit em Celsius e Kelvin
{
	C =(F-32)* 5/9; // convertendo Fahrenheit em Celsius 
	K = C + 273; //convertendo Fahrenheit em Kelvin
}
int main()
{
	float F; // temperatura em Fahrenheit
	float C; // temperatura em Celsius
	float K; // temperatura em Kelvin

	cin >> F; // fazendo a leitura da temperatura em Fahrenheit

	converte (F,C,K); // chamando a função

	cout << fixed << setprecision(2); // apresentando a media geometrica com duas casas deciamais
	cout << "Celsius: " << C << endl;
	cout << "Kelvin: " << K << endl;

	return 0;
}
