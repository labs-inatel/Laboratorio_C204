#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void media(int x, int y, float &m) // função para calcular a media geometrica de x e y
{
	m = sqrt (x * y); 
}
int main()
{
	int x, y; // numeros a serem inseridos
	float m; // media geometrica

	cin >> x >> y; // fazendo a leitura dos numeros

	if (x >= 0 || y >= 0) // verificando se os numeros sao positivos ou iguais a 1
		media (x, y, m); // chamando a função
	
	cout << fixed << setprecision(2); // apresentando a media geometrica com duas casas deciamais
	cout << "Media: " << m << endl;

	return 0;
}
