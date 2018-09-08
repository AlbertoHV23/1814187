#include <iostream>
using namespace std;

int main() {
	int Altura, Base;

	cout << "Ingre la Altura: " << endl;
	cin >> Altura;

	cout << "Ingresa la Base: " << endl;
	cin >> Base;

	cout << endl;

	cout << "El perimetro de tu rectangulo es:" << endl;
	cout << endl;

	for (int i = 0; i < Altura; i++) {
		for (int j = 0; j < Base; j++) {
			if ((i == 0) || (j == 0) || (i == Altura - 1) || (j == Base - 1)) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}

	system("pause > nul");

	return 0;
}