#include <iostream>
#include <string>
//Todas las notas son para que no se me olvide lo que es :)
using namespace std;

int opcion;

struct estudiante { //Todo lo que lleva el estudiante
	//Datos del alumno:
	string nombre;
	string apellidos;
	string telefono;
	string email;
	int matricula;
	//calificaciones:
	int cal1;
	int cal2;
	int cal3;
	//dureccion:
	string calle;
	string colonia;
	int nc;//numero de casa


};

estudiante e[10];//Cantidad total del alumnos
//Todas las funciones que se usan en el programa
void ListaAlumnos();
void Alumno();
void Calificacion();
void Manual();
 
int main() {
	system("cls");
	locale::global(locale("spanish"));

	cout << "Este es el Menu Principal" << endl;

	cout << "¿A donde seas ir?" << endl;

	cout << "1. Ver lista de alumnos y sus respectivas calificaciones" << endl;
	cout << "2. Registrar un alumnos." << endl;
	cout << "3. Registrar una calificaciones." << endl;
	cout << "5. Ir al manual del usuario." << endl;
	cout << "6. Salir. " << endl;

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


	}
	}

	void ListaAlumnos(){
	system("cls");

	cout << "Los alumnos que haz registrado son:" << endl;
	        //Aqui van todos los alumnos

	cout << "1. Salir" << endl;

	cin >> opcion;

	if (opcion == 1) {
		main();
	}
}

void Alumno() {
	system("cls");

	cout << "Ingresar un alumno:" << endl;
	cout << "Apelliedo:" << endl;
	//cin >> No se como guardar varias cosas en un alumno, solo puedo poner una:(;
		cout << "Nombre:" << endl;
	//cin >> ;
		cout << "Matricula:" << endl;
		//cin >> ;
		cout << "Telefono:" << endl;
		//cin >> ;
		cout << "Email:" << endl;
		//cin >> ;
		cout << "Direccion:" << endl;
		//cin >> ;

	cout << "1. Salir" << endl;

	cin >> opcion;

	if (opcion == 1) {
		main();
	}
}

void Calificacion() {
	system("cls");

	cout << "Ingresar una calificacion." << endl;

	cout << "1. Salir" << endl;

	cin >> opcion;

	if (opcion == 1) {
		main();
	}
}



void Manual() {
	system("cls");

	cout << "Manual para poder usar este programa:" << endl;
	//Aqui va el Manual
	cout << "1. Salir" << endl;

	cin >> opcion;

	if (opcion == 1) {
		main();
	}
}