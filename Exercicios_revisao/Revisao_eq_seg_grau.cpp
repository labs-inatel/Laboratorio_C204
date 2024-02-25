#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

float calc_raizes(float a, float b, float c, float &x1, float &x2) // função para calcular raizes
{
	float delta;

	delta = (pow(b, 2) - (4 * a * c)); // calculando delta

	if(delta >= 0) // se delta for positivo ou igual a zero, existe raizes reais
	{
		x1 = ((- b - sqrt(delta)) / (2 * a));
		x2 = ((- b + sqrt(delta)) / (2 * a));

		return 0; // retorna zero se houver raizes reais
	}
	else
		return 1; // retorna um se não houver raizes reais
}
int main()
{
	float a, b, c;
	float x1, x2;
	float total;

	cin >> a >> b >> c; // fazendo a leitura dos dados

	if (a != 0)  // garantindo que a não seja zero
	{
		total = calc_raizes(a, b, c, x1, x2); // chamando a função

		if (total == 0) // verificando se existe raizes reais
		{
			if (x1 == x2) // se delta for zero, as raizes x1 e x2 terão o valor de zero tambem
				cout << "x = " << x2 << endl;

			else if (x1 > x2 || x1 < x2) // se delta for maior que zero, as raizes reais terão valores distintos
			{
				cout << fixed << setprecision (2); // apresentando o resusltado com duas casas decimais
				cout << "x1 = " << x1 << endl;
				cout << "x2 = " << x2 << endl;
			}
		}
		else // se delta for negativo, logo não haverá raizes reais
			cout << "Nao ha raizes reais" << endl;

		return 0;
	}
}
