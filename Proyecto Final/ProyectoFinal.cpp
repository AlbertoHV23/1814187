#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int opcion;
int c;
bool encontrado = false;

struct estudiante { 
	int id;
	string nombre;
	string apellidos;
	string telefono;
	string email;
	int matricula;
	float cal1, cal2, cal3;
	float promedio;

	string calle;
	string colonia;
	int nc;
};

estudiante e[100];

void ListaAlumnos();
void IngresarAlumno();
void Manual();
void menu();
void BuscarMat();
void Buscar();
void BuscarNom();
void modificar();
void eliminar();
void Guardar();
void excel();

int main() {
	locale::global(locale("spanish"));
	c = 0;
	system("color F0");
	
	ifstream leer("ListasFCFM.data", ios::binary);

	// Leer el archivo
	leer.read((char*)&e, sizeof(e));

	// Cerrar el archivo
	leer.close();
	for (int i = 0; i < 100; i++)
	{
		if (e[i].id != 0) {
			c++;
		}
	}

	menu();
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
	cout << "   3. Buscar." << endl;
	cout << "   4. Eliminar un alumno." << endl;
	cout << "   5. Modificar un alumno." << endl;
	cout << "   6. Ir al manual del usuario." << endl;
	cout << "   7. Guardar. " << endl;
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
		Buscar();
		break;

	case 4:
		eliminar();
		break;

	case 5:
		modificar();
		break;

	case 6:
		Manual();
		break;

	case 7:
		Guardar();
		excel();
		menu();
		break;

	case 8:
		Guardar();
		excel();
		
		break;

	default:
		cout << "Ingrese una opcion correcta";
		menu();
		break;
	}

}


void IngresarAlumno() {
	system("cls");

	cout << "Ingrese un alumno:" << endl;
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
	cout << "Calificacion 1:" << endl;
	cin >> e[c].cal1;
	cin.ignore();
	cout << "Calificacion 2:" << endl;
	cin >> e[c].cal2;
	cout << "Calificacion 3:" << endl;
	cin >> e[c].cal3;
	if (e[c].cal1 == 0 || e[c].cal2 == 0 || e[c].cal3 == 0) {
		e[c].promedio = 0;
	}
	else {
	
		e[c].promedio = ((e[c].cal1*.30) + (e[c].cal2*.25) + (e[c].cal3*.45));
	}
	
	c++;

	cout << endl;
	cout << "1.Ir al Menu Princioal." << endl;
	cin >> opcion;

	if (opcion == 1) {
		menu();
	} 
	else {
		cout << "Ingresa una opcion valida";
		IngresarAlumno();
	}
	system("pause > nul");
}


void ListaAlumnos() {
	system("cls");
	int j = 0;

	if (j<c) {
		cout << "Los alumnos que haz registrado son:" << endl;
		for (int i = 0;i < c;i++) {

			cout << endl;
			cout << "Datos del alumno:" << endl;
			cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << " Nª " << e[i].nc << ", " << e[i].colonia << endl;
			cout << "Calificaciones:" << endl;
			cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
			cout << "Promedio: " << e[i].promedio << endl;
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
	else {
		cout << "Ingresa una opcion valida";
		ListaAlumnos();
	}
	system("pause>nul");
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
			cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << "Nª " << e[i].nc << ", " << e[i].colonia << endl;
			cout << "Calificaciones:" << endl;
			cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
			cout << "Promedio: " << e[i].promedio << endl;
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
	cout << "1. Ir al Menu Principal." << endl;
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
			cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << "Nª " << e[i].nc << ", " << e[i].colonia << endl;
			cout << "Calificaciones:" << endl;
			cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
			cout << "Promedio: " << e[i].promedio << endl;
			cout << endl;


			encontrado = true;
			break;



			cout << "¿Que desea hacer con este alumno?" << endl;
			cout << " 1. Modifcar." << endl;
			cout << " 2. Eliminar." << endl;
			cout << " 3. Regresar al Menu Principal." << endl;
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
			
		}
		i++;
	}
	if (!encontrado) {
		cout << "No habia registros con esa matricula" << endl;
	}

	system("pause > nul");
	cout << endl;
	cout << "1. Ir al Menu Principal" << endl;
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
			cout << " 0. Nombre: " << endl;
			cout << " 1. Apellidos: " << endl;
			cout << " 2. Matricula: " << endl;
			cout << " 3. Telefono: " << endl;
			cout << " 4. Correo: " << endl;
			cout << " 5. Calle: " << endl;
			cout << " 6. Colonia: " << endl;
			cout << " 7. Calificacion 1: " << endl;
			cout << " 8. Calificacion 2: " << endl;
			cout << " 9. Calificacion 3: " << endl;
			cin >> opcion;

			switch (opcion)
			{
			case 0:
				cout << "Nombre: ";
				getline(cin, e[i].nombre);
				break;

			case 1:
				cout << "Apellido: ";
				getline(cin, e[i].apellidos);
				break;

			case 2:
				cin.ignore();
				cout << "Matricula: ";
				cin >> e[i].matricula;

				break;

			case 3:
				cout << "Telefono: ";
				getline(cin, e[i].telefono);
				break;

			case 4:
				cout << "Correo: ";
				getline(cin, e[i].email);
				break;

			case 5:
				cout << "Calle: ";
				getline(cin, e[i].calle);
				break;

			case 6:
				cout << "Colonia: ";
				getline(cin, e[i].colonia);
				break;

			case 7:
				cout << "Ingrese una nueva Calificacion: ";
				cin >> e[i].cal1;
				break;

			case 8:
				cout << "Ingrese una nueva Calificacion: ";
				cin >> e[i].cal2;
				break;

			case 9:
				cout << "Ingrese una nueva Calificacion: ";
				cin >> e[i].cal3;
				break;
		
			default:
				cout << "Ingrese una opcion correcta";
				modificar();
				break;
			}

			if (opcion != -1) {
				cout << "Datos del alumno:" << endl;
				cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << "        Matricula: " << e[i].matricula << endl;
				cout << "Matricula: " << e[i].matricula << endl;
				cout << "Correo: " << e[i].email << endl;
				cout << "Telefono: " << e[i].telefono << endl;
				cout << "Direccion: " << e[i].calle << "Nª " << e[i].nc << ", " << e[i].colonia << endl;
				cout << "Calificaciones:" << endl;
				cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
				cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
				if (e[i].cal1 == 0 || e[i].cal2 == 0 || e[i].cal3 == 0) {
					e[i].promedio = 0;
					cout << "Promedio: " << e[i].promedio;
				}
				else {
					e[i].promedio = ((e[i].cal1*.30) + (e[i].cal2*.25) + (e[i].cal3*.45));
					cout << "Promedio: " << e[i].promedio;
				}
				
				cout << endl;
			}
		}
		
		Guardar();
		excel();

		i++;
	}

	system("pause > nul");
	menu();
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
void Guardar() {
	cout << "¿Deseas guardar?" << endl;
	cout << "1.- Sí \n2. No." << endl;

	cin >> opcion;
	if (opcion == 1) {
		
		ofstream archivo;

		// Se guarda como binario
		archivo.open("ListasFCFM.txt", ios::binary);

		// Se escribe el arreglo entero en el archivo
		archivo.write((char*)&e, sizeof(e));

		// Al terminar se cierra el archivo
		archivo.close();
	}


	
}
void excel() {
	ofstream archivo;

	archivo.open("ListasFCFM.csv");
	for (int i = 0;i < c;i++) {
		
		archivo << e[i].nombre << ",";
		archivo << e[i].apellidos << ",";
		archivo << to_string(e[i].matricula) << ",";
		archivo << e[i].email << ",";
		archivo << e[i].telefono << ",";
		archivo << to_string(e[i].cal1) << ",";
		archivo << to_string(e[i].cal2) << ",";
		archivo << to_string(e[i].cal3) << ",";
		archivo << to_string(e[i].promedio) << endl;

	}
	archivo.close();

}