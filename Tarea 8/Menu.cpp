#include<iostream>
using namespace std;

void main(){
	int mat;
	char nombre[20];
	cout << "Ingresa tu nombre: " << endl;
	cin >> nombre;
	cout<<"Ingresa tu matricula:" << endl;
	cin >> mat;

	cout << nombre << " Estas en el menu principal. " <<endl<<  "¿A donde quieres ir? " << endl;
		int opcion;
		cout << "1.Calificaciones: " << endl;
		cout << "2.Informacion del alumno: " << endl;
		cout << "3.Soporte Tecnico" << endl;
		cout << "4.Salir" << endl;
		cin >> opcion;
		
		if (opcion == 1) {
			cout << nombre << " Tus calificaciones son:" << endl;
			cout << "...No tines calificaciones por el momento." << endl;
			cout << endl;
			cout << "¿Quieres regresar al menu principal? " << endl;
			int opcion2;
			cout << "1.-Si" << endl << "2.NO" << endl;
			cin >> opcion2;
			if (opcion2 == 1) {
				cout << nombre << " Estas en el menu principal. " << endl << "¿A donde quieres ir? " << endl;
				int opcion;
				cout << "1.Calificaciones: " << endl;
				cout << "2.Informacion del alumno: " << endl;
				cout << "3.Soporte Tecnico" << endl;
				cout << "4.Salir" << endl;
				cin >> opcion;

			}
			else {
				cout << "¿Deseas salir?" << endl;
				cout << "1.-Si" << endl << "2.NO" << endl;
				cin >> opcion2;
				if (opcion2 == 1) {
					cout << " ";
					}
				else{
					cout << nombre << " Tus calificaciones son:" << endl;
					cout << "...No tines calificaciones por el momento." << endl;
				}
			}
}
		else if(opcion == 2) {
			cout << "Tu imformación es: " << endl;
			cout << nombre << " " << mat << endl;
			cout << endl;
			cout << "¿Quieres regresar al menu principal? " << endl;
			int opcion2;
			cout << "1.-Si" << endl << "2.NO" << endl;
			cin >> opcion2;
			if (opcion2 == 1) {
				cout << nombre << " Estas en el menu principal. " << endl << "¿A donde quieres ir? " << endl;
				int opcion;
				cout << "1.Calificaciones: " << endl;
				cout << "2.Informacion del alumno: " << endl;
				cout << "3.Soporte Tecnico" << endl;
				cout << "4.Salir" << endl;
				cin >> opcion;

			}
			else {
				cout << "¿Deseas salir?" << endl;
				cout << "1.-Si" << endl << "2.NO" << endl;
				cin >> opcion2;
				if (opcion2 == 1) {
					cout << " ";
				}
				else {
					cout << "Tu imformación es: " << endl;
					cout << nombre << " " << mat << endl;
					cout << endl;
				}
			}
		}
		else if (opcion == 3) {
			cout << "Espere, en un momento le comunicamos a un tecnico" << endl;
			cout << "¿Quieres regresar al menu principal? " << endl;
			int opcion2;
			cout << "1.-Si" << endl << "2.NO" << endl;
			cin >> opcion2;
			if (opcion2 == 1) {
				cout << nombre << " Estas en el menu principal. " << endl << "¿A donde quieres ir? " << endl;
				int opcion;
				cout << "1.Calificaciones: " << endl;
				cout << "2.Informacion del alumno: " << endl;
				cout << "3.Soporte Tecnico" << endl;
				cout << "4.Salir" << endl;
				cin >> opcion;

			}
			else {
				cout << "¿Deseas salir?" << endl;
				cout << "1.-Si" << endl << "2.NO" << endl;
				cin >> opcion2;
				if (opcion2 == 1) {
					cout << " ";
				}
				else {
					cout << "Espere, en un momento le comunicamos a un tecnico" << endl;
				}



			}
		}
		else{


			
		}
		
		system("pause > nul");




}