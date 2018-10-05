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
void eliminar();

int main() {
	locale::global(locale("spanish"));
	c = 0;
	system("color F0");
	cout << " ¿A donde deseas ir?" << endl;
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
	cout << " ¿A donde desar seas ir?" << endl;

	cout << "   1. Ver lista de alumnos y sus respectivas calificaciones." << endl;
	cout << "   2. Registrar un alumnos." << endl;
	cout << "   3. Registrar una calificaciones." << endl;
	cout << "   4. Buscar." << endl;
	cout << "   5. Eliminar un alumno." << endl;
	cout << "   6. Modificar un alumno." << endl;
	cout << "   7. Ir al manual del usuario." << endl;
	cout << "   8. Salir. " << endl;

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
		eliminar();
		break;

	case 6:
		modificar();
		break;

	case 7:
		Manual();
		break;

	default:
		break;
	}

}


void IngresarAlumno() {
	system("cls");

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
	cout << "Numero de casa: ";
	cin >> e[c].nc;
	cin.ignore();
	cout << "colonia: ";
	getline(cin, e[c].colonia);
	

	c++;

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
	int j = 0;
	
	if(j<c){
		cout << "Los alumnos que haz registrado son:" << endl;
		for (int i = 0;i < c;i++) {

			cout << endl;
			cout << "Datos del alumno:" << endl;
			cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << "        Matricula: " << e[i].matricula << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << " Nª " << e[i].nc << ", " << e[i].colonia << endl;
			cout << "Calificaciones:" << endl;
			cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
			//tocout << "Promedio: " << promedio << endl;
			cout << endl;
		}

	}
	else {
		cout << "Por el momento no haz registrado a nadie.";
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
	cout << "Ingresar una calificacion." << endl;
	cout << endl;

	cout << "Ingrese la calificacion 1:" << endl;
	cin >> e[c].cal1;
	cout << "Ingrese la calificacion 2:" << endl;
	cin >> e[c].cal2;
	cout << "Ingrese la calificacion 3:" << endl;
	cin >> e[c].cal3;
	

		float promedio = ((e[c].cal1*.30) + (e[c].cal2*.25) + (e[c].cal3*.45)) ;
		cout << "| Calificacion 1: " << e[c].cal1 << "  |" << "| Calificacion 2: " << e[c].cal2 << " |" << "| Calificacion 3:  " << e[c].cal3 << " |";
		cout << endl;
	
	cout << "Promedio: " << promedio << endl;
	cout << endl;
	
	cout << "  1. Ir al Menu Principal" << endl;
	cin >> opcion;

	if (opcion == 1) {
		menu();
	}
	
	system("pause > nul");
}

void Buscar() {
	system("cls");
	cout << "¿Como desea hacer su busqueda?" << endl;
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
	cout << "¿Que nombre buscas? " << endl;
	string n;
	getline(cin, n);

	int i = 0;
	while (i < c) {

		if (strcmp(n.c_str(), e[i].nombre.c_str()) == 0) {
			cout << "Datos del alumno:" << endl;
			cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << "        Matricula: " << e[i].matricula << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << "Nª " << e[i].nc << ", " << e[i].colonia << endl;
			cout << "Calificaciones:" << endl;
			cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
			cout << endl;



			encontrado = true;
			break;
		}
		i++;
	}
	if (!encontrado) {
		cout << "No se encontraron registros con ese nombre" << endl;
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
	cout << "¿Que Matricula buscas? " << endl;
	cin >> opcion;
	cout << endl;
	bool encontrado = 0;

	int i = 0;
	while (i < c) {

		if (e[i].matricula == opcion) {
			cout << "Datos del alumno:" << endl;
			cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << "        Matricula: " << e[i].matricula << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << "Nª " << e[i].nc << ", " << e[i].colonia << endl;
			cout << "Calificaciones:" << endl;
			cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
			cout << endl;


			encontrado = true;
			break;



			cout << "¿Que desea hacer con este alumno?" << endl;
			cout << " 1. Modifcar." << endl;
			cout << " 2. Eliminar." << endl;
			cout << " 1. Regresar al Menu Principal." << endl;
			cin >> opcion;

			switch (opcion)
			{
			case 1:
				modificar();
				break;
			case 2:
				eliminar();
				break;

			default:
				menu();
				break;
			}
			/*if (opcion == 1) {
				modificar();

			}
			else {
				menu();
			}*/
		}
		i++;
	}
	if (!encontrado) {
		cout << "No habia registros con esa matricula" << endl;
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
	system("cls");
	cout << "¿Que Matricula buscas? " << endl;
	cin >> opcion;

	int i = 0;
	while (i < c) {

		if (e[i].matricula == opcion) {
			cout << "¿Que desea Modificar?" << endl;
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
				cout << "Nombre: ";
				getline(cin, e[c].nombre);
				break;

			case 2:
				cout << "Apellido: ";
				getline(cin, e[c].apellidos);
				break;

			case 3:
				cin.ignore();
				cout << "Matricula: ";
				cin >> e[c].matricula;

				break;

			case 4:
				cout << "Telefono: ";
				getline(cin, e[c].telefono);
				break;

			case 5:
				cout << "Correo: ";
				getline(cin, e[c].email);
				break;

			case 6:
				cout << "Calle: ";
				getline(cin, e[c].calle);
				break;

			case 7:
				cout << "Colonia: ";
				getline(cin, e[c].colonia);
				break;

			}
			
			if (opcion != 0) {
				cout << "Datos del alumno:" << endl;
				cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << "        Matricula: " << e[i].matricula << endl;
				cout << "Matricula: " << e[i].matricula << endl;
				cout << "Correo: " << e[i].email << endl;
				cout << "Telefono: " << e[i].telefono << endl;
				cout << "Direccion: " << e[i].calle << "Nª " << e[i].nc << ", " << e[i].colonia << endl;
				cout << "Calificaciones:" << endl;
				cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
				cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
				cout << endl;
			}


		}
		i++;
	}
}

void eliminar() {
	cin.ignore();
	system("cls");
	cout << "¿Que Matricula buscas? " << endl;
	cin >> opcion;

	int i = 0;
	while (i < c) {

		if (e[i].matricula == opcion) {
			cout << "Datos del alumno:" << endl;
			cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << "        Matricula: " << e[i].matricula << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << "Nª " << e[i].nc << ", " << e[i].colonia << endl;
			cout << "Calificaciones:" << endl;
			cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
			cout << endl;


			cout << "¿Eliminar a " << e[i].id << "?" << endl;
			cout << "1. Sí \n2. No" << endl;
			cin >> opcion;

			if (opcion == 1 && c != 0) {
				for (int j = i; j < c; j++)
				{
					e[j] = e[j + 1];
				}
				c--;
			}
			break;
		}
		if (i == c) {
			cout << "No encontré nada" << endl;
		}
		i++;
	}

	system("pause > nul");
	menu();
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
