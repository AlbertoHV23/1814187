#include <iostream>
using namespace std;

void main() {
	locale::global(locale("spanish"));
	int n;
	cout << "Escribe el n�mero de lados de tu pol�gono regular: ";
	cin >> n;

	int medidaAngulo;

	medidaAngulo = (180 * (n - 2))/n;

	cout << "El angulo de tu poligono es: " << medidaAngulo << "�." << endl;

	system("pause");
}