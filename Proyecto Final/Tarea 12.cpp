#include <iostream>
#include <string>
//Todas las notas son para que no se me olvide lo que es :)
using namespace std;

int opcion;
int c;

struct estudiante { //Todo lo que lleva el estudiante
					//Datos del alumno:
	string nombre;
	string apellidos;
	string telefono;
	string email;
	string matricula;
	//calificaciones:
	float cal1;
	float cal2;
	float cal3;
	//dureccion:
	string calle;
	string colonia;
	int nc;//numero de casa


};

estudiante e[100];//Cantidad total del alumnos
				 //Todas las funciones que se usan en el programa
void ListaAlumnos();
void Alumno();
void Calificacion();
void Manual();

int main() {
	c = 0;
	system("cls");
	locale::global(locale("spanish"));

	cout << "Este es el Menu Principal" << endl;

	cout << "¿A donde seas ir?" << endl;

	cout << "1. Ver lista de alumnos y sus respectivas calificaciones" << endl;
	cout << "2. Registrar un alumnos." << endl;
	cout << "3. Registrar una calificaciones." << endl;
	cout << "5. Ir al manual del usuario." << endl;
	cout << "6. Menu. " << endl;

	cin >> opcion;

	switch (opcion) {

	case 1:
		ListaAlumnos();
		break;

	case 2:
		Alumno();
		break;

	case 3:
		Calificacion();
		break;

	case 4:
		Manual();
		break;

	default:
		break;
	}
	int c = 0;
}

void Alumno() {
	system("cls");

	cout << "Ingresar un alumno:" << endl;
	cout << endl;
	cout << "Apellidos:";
	getline(cin, e[c].apellidos);
	cout << "Nombre:";
	getline(cin, e[c].nombre);
	cout << "Matricula:";
	getline(cin, e[c].matricula);
	cout << "Telefono:";
	getline(cin, e[c].telefono);
	cout << "Email:";
	getline(cin, e[c].email);
	cout << "Direccion:" << endl;
	cout << "Calle:";
	getline(cin, e[c].calle);
	cout << "colonia:";
	getline(cin, e[c].colonia);
	c++;
	cout << "1. Menu" << endl;

	cin >> opcion;

	if (opcion == 1) {
		main();
	}
	system("pause > nul");
}


void ListaAlumnos() {
	system("cls");
	
	cout << "Los alumnos que haz registrado son:" << endl;
	system("pause");
	
		//Tarea 12
		for (int i = 0;i < 100;i++){
			if (i == c) {
				break;
			}

		cout << "Datos del alumno:" << endl;
		cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << endl;
		cout << "Matricula: " << e[i].matricula << endl;
		cout << "Corrreo: " << e[i].email << endl;
		cout << "Telefono: "<< e[i].telefono << endl;
		cout << "Calificaciones;" << endl;
		cout << "Calificacion 1:" << " " << e[i].cal1 << endl;
		cout << "Calificacion 2:" << " " << e[i].cal1 << endl;
		cout << "Calificacion 3:" << " " << e[i].cal3 << endl;
		cout << "1. Menu" << endl;
	
		cin >> opcion;
		system("pause");
			}


	if (opcion == 1) {
		main();
	
	}
	
}



void Calificacion() {
	system("cls");
	cout << "Ingresar una calificacion." << endl;
	cout << endl;

	cout << "Ingrese la calificacion 1:" << endl;
	cin >> e[c].cal1;
	cout << "Ingrese la calificacion 2:" << endl;
	cin >> e[c].cal2;
	cout << "Ingrese la calificacion 3:" << endl;
	cin >> e[c].cal3;
	
	cout << "1. Menu" << endl;

	cin >> opcion;

	if (opcion == 1) {
		main();
	}
	system("pause > nul");
}



void Manual() {
	system("cls");

	cout << "Manual para poder usar este programa:" << endl;
	//Aqui va el Manual
	cout << "1. Menu" << endl;

	cin >> opcion;

	if (opcion == 1) {
		main();
	}
	system("pause > nul");
}