#include <iostream>
#include <string>

//Todas las notas son para que no se me olvide lo que es :)
using namespace std;

int opcion;
int c;
bool encontrado = false;

struct estudiante { //Todo lo que lleva el estudiante
					//Datos del alumno:
	int id;
	string nombre;
	string apellidos;
	string telefono;
	string email;
	int matricula;
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
void IngresarAlumno();
void IngresarCalificacion();
void Manual();
void menu();
void BuscarMat();
void Buscar();
void BuscarNom();
void modificar();

int main() {
	system("color F0");
	cout << " �A donde deseas ir?" << endl;
	cout << "   1. Menu Principal" << endl;
	cout << "   2. Manual de usuario" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1:
		menu();
		break;
	case 2:
		Manual();
		break;
	}
}


void menu() {
	e[c].id = c;
	system("cls");
	locale::global(locale("spanish"));
	cout << "Bienvenido al menu Principal";
	cout << endl;
	cout << " �A donde desar seas ir?" << endl;

	cout << "   1. Ver lista de alumnos y sus respectivas calificaciones" << endl;
	cout << "   2. Registrar un alumnos." << endl;
	cout << "   3. Registrar una calificaciones." << endl;
	cout << "   4. Buscar." << endl;
	cout << "   5. Ir al manual del usuario." << endl;
	cout << "   6. Salir. " << endl;

	cin >> opcion;

	switch (opcion) {

	case 1:
		ListaAlumnos();
		break;

	case 2:
		IngresarAlumno();
		break;

	case 3:
		IngresarCalificacion();
		break;

	case 4:
		Buscar();
		break;
	
	case 5:
		Manual();
		break;

	default:
		break;
	}
	
}


void IngresarAlumno() {
	system("cls");
	int c = 0;
	cout << "Ingresar un alumno:" << endl;
	cout << endl;

	cin.ignore();
	cout << "Apellidos: ";
	getline(cin, e[c].apellidos);
	cout << "Nombre: ";
	getline(cin, e[c].nombre);
	cout << "Matricula: ";
	cin >> e[c].matricula;
	cin.ignore();
	cout << "Telefono: ";
	getline(cin, e[c].telefono);
	cout << "Email: ";
	getline(cin, e[c].email);
	cout << "Direccion: " << endl;
	cout << "Calle: ";
	getline(cin, e[c].calle);
	cout << "colonia: ";
	getline(cin, e[c].colonia);
	c++;

	cout << endl;
	cout << endl;
	cout << "1. Menu" << endl;
	cin >> opcion;

	if (opcion == 1) {
		menu();
	}
	system("pause > nul");
}


void ListaAlumnos() {
	system("cls");

	cout << "Los alumnos que haz registrado son:" << endl;
	for (int i = 0;i < c;i++) {
		cout << "Datos del alumno:" << endl;
		cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << endl;
		cout << "Matricula: " << e[i].matricula << endl;
		cout << "Correo: " << e[i].email << endl;
		cout << "Telefono: " << e[i].telefono << endl;
		cout << "Direccion: " << e[i].calle << " " << e[i].colonia << endl;
		cout << "Calificaciones:" << endl;
		cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
		cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;



	}
	cout << endl;
	cout << endl;
	cout << "1. Menu" << endl;

	cin >> opcion;

	if (opcion == 1) {
		menu();
	}
	system("pause>nul");
}

void IngresarCalificacion() {
	system("cls");
	cout << "�Que calificacion desea agregar?." << endl;
	cout << endl;
	cout << "  1. Calificaci�n 1" << endl;
	cout << "  2. Calificaci�n 2" << endl;
	cout << "  3. Calificaci�n 3" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		cout << "Ingrese la Calificaci�n 1: ";
		cin >> e[c].cal1;
		break;
	case 2:
		cout << "Ingrese la Calificaci�n 2: ";
		cin >> e[c].cal2;
		break;
	case 3:
		cout << "Ingrese la Calificaci�n 3: ";
		cin >> e[c].cal3;
		break;
	default:
		break;
	}

	//El promedio no estoy seguro de estar bien, asi que lo dejare en forma de comentario
	//float promedio = (((e[c].cal1*.30) + (e[c].cal2*.25) + (e[c].cal3*.40)) / 3);
	cout << "| Calificacion 1: " << e[c].cal1 << "  |" << "| Calificacion 2: " << e[c].cal2 << " |" << "| Calificacion 3:  " << e[c].cal3 << " |";
	cout << endl;
	//cout << "Promedio: " << promedio << endl;
	cout << endl;
	cout << "�Desea agregar otra calificacion?" << endl;
		cout << "  1. Si" << endl;
		cout << "  2. Ir al Menu Principal" << endl;
	cin >> opcion;

	if (opcion == 1) {
		IngresarCalificacion();
	}
	else {
		menu();
	}
	system("pause > nul");
}
 
void Buscar() {
	system("cls");
	 cout << "�Como desea hacer su busqueda?" << endl;
	 cout << "  1. Busqueda por nombre." << endl;
	 cout << "  2. Busqueda por Matricula." << endl;
	 cin >> opcion;

	 switch (opcion) {
	 case 1:
		 BuscarNom();
		 break;
	 case 2:
		 BuscarMat();
		 break;
	 }
 }

void BuscarNom() {
	cin.ignore();
	system("cls");
	cout << "�Qu� nombre buscas? " << endl;
	string n;
	getline(cin, n);
	
	int i = 0;
	while (i < c) {	

		if (strcmp(n.c_str(), e[i].nombre.c_str()) == 0) {
			cout << "Datos del alumno:" << endl;
			cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << " " << e[i].colonia << endl;
			cout << "Calificaciones:" << endl;
			cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;


			encontrado = true;
			break; 
		}
		i++;
	}
	if (!encontrado) {
		cout << "No hab�a registros con ese nombre" << endl;
	}

	system("pause > nul");
	cout << endl;
	cout << "1. Menu" << endl;
	cin >> opcion;
	if (opcion == 1) {

		menu();
	}

}

void BuscarMat() {
	cin.ignore();
	system("cls");
	cout << "�Qu� Matricula buscas? " << endl;
	cin >> opcion;
	bool encontrado = 0;
	int i = 0;
	while (i < c) {

		if (e[i].matricula == opcion) {
			cout << "Datos del alumno:" << endl;
			cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << " " << e[i].colonia << endl;
			cout << "Calificaciones:" << endl;
			cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;

			encontrado = true;
			break;

			cout << "�Desea modificar algo de este alumno?" << endl;
			cout << " 1. Si" << endl;
			cout << " 2. Ir al Menu Principal" << endl;
			cin >> opcion;

			if (opcion == 1) {
				modificar();

			}
			else {
				menu();
			}
		}
		i++;
	}
	if (!encontrado) {
		cout << "No hab�a registros con esa matricula" << endl;
	}

	system("pause > nul");
	cout << endl;
	cout << "1. Menu" << endl;
	cin >> opcion;
	if (opcion == 1) {

		menu();
	}
}

void modificar() {
	cout << "�Que desea Modificar?" << endl;
	cout << " 1. Nombre: " << endl;
	cout << " 2. Apellidos: " << endl;
	cout << " 3. Matricula: " << endl;
	cout << " 4. Telefono: " << endl;
	cout << " 5. Correo: " << endl;
	cout << " 6. Calle: " << endl;
	cout << " 7. Colonia: " << endl;
	cin >> opcion;
	
	switch (opcion)
	{
	case 1:
		cout << "Ingrese un nuevo Nombre: ";
		getline(cin, e[c].nombre);
		break;

	case 1:
		cout << "Ingrese un nuevo Nombre: ";
		getline(cin, e[c].nombre);
		break;
	}


}

void Manual() {
	system("cls");

	cout << "Manual para poder usar :" << endl;
	cout << "Lo primero que hay que hacer es ingresar al menu." << endl;



	cout << endl;
	cout << "1. Menu" << endl;
	cin >> opcion;
	if (opcion == 1) {
		menu();
	}

	system("pause > nul");
}
