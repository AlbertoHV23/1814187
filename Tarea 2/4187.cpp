#include<iostream>

using namespace std;

int main()
{
	char apellido{ 20 };
	char nombre{ 20 };
	int edad;
	char telefono{ 20 };

	cout << "Apellido: "; cin>>apellido;
	cout << "Nombre: "; cin>>nombre;
	cout << "Edad: "; cin>>edad;
	cout << "Telefono: ";cin>>telefono;

	cout << "\nNombre: " << apellido;
	cout << "Nombre: " << nombre << endl;
	cout << "\nEdad: " << edad << endl;
	cout << "Telefono:" << telefono << endl;


	return 0;
}