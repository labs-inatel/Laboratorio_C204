#include<iostream>
#include<cmath>
using namespace std;

float calc_delta(float a, float b, float c) // função para calcular delta
{
	float res;

	res = (pow(b, 2) - (4 * a * c)); // calculando delta

	return res; // retornando o valor de delta
}
int main()
{
	float x, y, z;
	float delta;

	cin >> x >> y >> z; // fazendo a leitura dos dados

	if (x != 0) // garantindo que a não seja zero
		delta = calc_delta(x, y, z); // chamando a função

	cout << "delta = " << delta << endl; // apresentando o resultado

	return 0;
}
