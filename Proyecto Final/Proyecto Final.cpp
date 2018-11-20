#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <time.h>
using namespace std;

int opcion;
int c;
bool encontrado = false;
int longitud;
bool arroba = false, com = false, repetir = false;



struct estudiante { 
	int id;
	string nombre;
	string apellidos;
	int matricula;
	string email;
	string telefono;
	string calle;
	string colonia;
	int nc;
	float cal1;
	float cal2;
	float cal3;
	float promedio;
	
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
	
	ifstream leer("ListasFCFM.txt", ios::binary);

	if (leer.is_open()) {

		while (!leer.eof()) {
			leer.read((char*)&e, sizeof(e));
		}
	}
	else {
		cout << "Archivo inexistente o problemas para abrirlo." << endl;
		system("pause>nul");
	}


	
	leer.close();
	for (int i = 0; i < 100; i++)
	{
		if (e[i].nc != 0) {
			c++;
		}
	}
	

	menu();
	return 0;
}


void menu() {

	
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
		excel();
		Guardar();
		menu();
		break;

	case 8:
		excel();
		Guardar();	
		break;

	default:
		cout << "Ingrese una opcion correcta" << endl;
		system("pause");
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
	system("cls");
	
	
	cout << "Nombre: ";
	getline(cin, e[c].nombre);
	system("cls");
	
	cout << "Matricula: " << endl;
	cout << "¿Quieres generar una matricula aleatoria?" << endl;
	cout << "  1. Si." << endl;
	cout << "  2. No." << endl;
	
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		srand(time(NULL));
		e[c].matricula = 1800000 + rand() % (2000000 - 1800000);
		
		cout << "Tu matricula generada es " << e[c].matricula << endl;
		system("pause>nul");
		cin.ignore();
		system("cls");

		break;
	
	case 2:
		cout << "Ingresa una matricula:" << endl;
		cin >> e[c].matricula;
		
			for (int i = 0;i < c; i++) {
			if (e[c].matricula != e[i].matricula ) {
			}
				else {
				cout << " Intentelo de nuevo con otra matricula DIFERENTE..." << endl;
				system("pause");
				cout << "Matricula: ";
				cin >> e[c].matricula;
				
				system("cls");
				}
			}
			cin.ignore();
			system("cls");			
		break;

	
	default:
		cout << "Verifique que sea una opcion correcta..." << endl;
		cout << "Matricula: ";
		cin >> e[c].matricula;
		cin.ignore();
		break;
	}
	
	
	
	cout << "Telefono: ";
	getline(cin, e[c].telefono);

	 longitud = e[c].telefono.size();
		if (longitud < 13 && longitud>7) {	
			repetir = true;
			system("cls");
		}
		else
		{
		cout << "Ingrese un numero valido..." << endl;
			system("pause>nul");
			system("cls");
		}
		while (repetir== false)
		{
			cout << "Telefono: ";
			getline(cin, e[c].telefono);

			longitud = e[c].telefono.size();
			if (longitud < 13 && longitud>7) {
				repetir = true;
				system("cls");
			}
			else
			{
				cout << "Ingrese un numero valido..." << endl;
				system("pause>nul");
				system("cls");
			}
		}
			

	cout << "Email: ";
	getline(cin, e[c].email);
	longitud = e[c].email.size();
	repetir = false;
	
			
	for (int i = 1;i<=longitud;i++) {   
		if (e[c].email[i] == 64) {					
			arroba = true;
		}
		if (e[c].email[longitud - 4] == 46 && e[c].email[longitud - 3] == 99 && e[c].email[longitud - 2] == 111 && e[c].email[longitud-1] ==109) {
			com = true;
		}		
		if (arroba == true && com == true) {
			repetir = true;
			system("cls");
		}

	}

	if (arroba == false && com == true) {
		cout << "Tu correo no tiene un @" << endl;
		cout << "Intentelo de nuevo..." << endl;
	}
	if (arroba == true && com == false) {
		cout << "Tu correo no termina en .com" << endl;
		cout << "Intentelo de nuevo..." << endl;	
	}
	
	if (arroba == false && com == false) {
		cout << "Tu correo no tiene un @ y tambien le falta terminar en .com" << endl;
		cout << "Intentelo de nuevo..." << endl;
	}

	while (repetir == false)
	{
		arroba = false;
		com = false;
		getline(cin, e[c].email);
		longitud = e[c].email.size();
				

		for (int i = 1;i <= longitud;i++) {
			if (e[c].email[i] == 64) {
				arroba = true;
			}
			if (e[c].email[longitud - 4] == 46 && e[c].email[longitud - 3] == 99 && e[c].email[longitud - 2] == 111 && e[c].email[longitud-1] ==	109)
			{
				com = true;
			}
			if (arroba == true && com == true) {
				repetir = true;
				system("cls");
			}
		
		}
		if (arroba == false && com == true) {
			cout << "Tu correo no tiene un @" << endl;
			cout << "Intentelo de nuevo..." << endl;
		}
		if (arroba == true && com == false) {
			cout << "Tu correo no termina en .com" << endl;
			cout << "Intentelo de nuevo..." << endl;
		}
		if (arroba == false && com == false) {
			cout << "Tu correo no tiene un @ y tambien le falta terminar en .com" << endl;
			cout << "Intentelo de nuevo..." << endl;
			
		}

	}

	while (longitud < 5) {
		cout << "Ingrese un correo valido" << endl;
		getline(cin, e[c].email);
		int longitud = e[c].email.size();
		system("cls");
	}

	
	
	
	cout << "Calle: ";
	getline(cin, e[c].calle);
	system("cls");
	
	
	cout << "Numero de casa: ";
	cin >> e[c].nc;
	cin.ignore();
	system("cls");
	
	
	cout << "colonia: ";
	getline(cin, e[c].colonia);
	system("cls");
	
	cout << "Calificacion 1:" ;
	cin >> e[c].cal1;
	cin.ignore();
	
	
	
	cout << "Calificacion 2:" ;
	cin >> e[c].cal2;
	
	
	cout << "Calificacion 3:" ;
	cin >> e[c].cal3;
	
	
	if (e[c].cal1 == 0 || e[c].cal2 == 0 || e[c].cal3 == 0) {
		e[c].promedio = 0;
	}
	else {
	
		e[c].promedio = round(((e[c].cal1*.30) + (e[c].cal2*.25) + (e[c].cal3*.45)));
	}
	
	c++;

	cout << endl;
	cout << "1.Ir al Menu Princioal." << endl;
	cin >> opcion;

	if (opcion == 1) {
		menu();
	} 
	else {
		cout << "Ingresa una opcion valida" << endl;
		IngresarAlumno();
	}
	system("pause > nul");
}


void ListaAlumnos() {
	system("cls");
		
		cout << "Los alumnos que haz registrado son:" << endl;
		for (int i = 0; i < c; i++) {
			
			cout << "Datos del alumno:" << endl;
			cout << endl;
			cout << "Nombre: " << e[i].nombre <<" "<< e[i].apellidos << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			//cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << " Nª " << e[i].nc << ". " <</* e[i].colonia <<*/ endl;
			cout << "Calificaciones:" << endl;
			cout << "|  Cal 1:  |" << "|  Cal 2:  |" << "|  Cal 3:  |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
			cout << "Promedio: " << e[i].promedio << endl;
			cout << "________________________________________________________________________________" << endl;
		}
		
	

	cout << endl;
	cout << "1. Menu" << endl;
	cin >> opcion;

	if (opcion == 1) {
		menu();
	}
	else {
		cout << "Ingresa una opcion valida" << endl;
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

		string nombreTemp = e[i].nombre;

		int longitud = nombreTemp.size();
		for (int j = 0; j < longitud; j++) {
			if (j == longitud - 1) {
				nombreTemp[j] = toupper(nombreTemp[j]);
			}
			else {
				nombreTemp[j] = tolower(nombreTemp[j]);
			}
		}
		string nTemp = n; 

		int l = nTemp.size();
		for (int j = 0; j < l; j++) {
			if (j == l - 1) {
				nTemp[j] = toupper(nTemp[j]);
			}
			else {
				nTemp[j] = tolower(nTemp[j]);
			}
		}

		if (strcmp(nTemp.c_str(), nombreTemp.c_str()) == 0) {
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
	else {
		cout << "Ingresa una opcion valida" << endl;
		
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
	else {
		cout << "Ingresa una opcion valida" << endl;
		
	}
}

void modificar() {
	system("cls");
	cout << "¿Que Matricula buscas? " << endl;
	cin >> opcion;

	for (int i = 0;i < c;i++) {

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
				cin.ignore();
				cout << "Nombre: ";
				getline(cin, e[i].nombre);
				
				break;

			case 1:
				cin.ignore();
				cout << "Apellido: ";
				getline(cin, e[i].apellidos);
				
				break;

			case 2:
				cout << "Matricula: ";
				cin >> e[i].matricula;

				break;

			case 3:
				cin.ignore();
				cout << "Telefono: ";
				getline(cin, e[i].telefono);
			
				break;

			case 4:
				cin.ignore();
				cout << "Correo: ";
				getline(cin, e[i].email);
				
				break;

			case 5:
				cin.ignore();
				cout << "Calle: ";
				getline(cin, e[i].calle);
				
				break;

			case 6:
				cin.ignore();
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
				cout << "Ingrese una opcion correcta" << endl;
				system("pause");
				modificar();
				break;
			}

			if (opcion != -1) {
				cout << "Datos del alumno:" << endl;
				cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos  << endl;
				cout << "Matricula: " << e[i].matricula << endl;
				//cout << "Correo: " << e[i].email << endl;
				cout << "Telefono: " << e[i].telefono << endl;
				cout << "Direccion: " << e[i].calle << "Nª " << e[i].nc << ", " /*<< e[i].colonia*/ << endl;
				cout << "Calificaciones:" << endl;
				cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
				cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
				if (e[i].cal1 == 0 || e[i].cal2 == 0 || e[i].cal3 == 0) {
					e[i].promedio = 0;
					cout << "Promedio: " << e[i].promedio;
				}
				else {
					e[i].promedio = round(((e[i].cal1*.30) + (e[i].cal2*.25) + (e[i].cal3*.45)));
					cout << "Promedio: " << e[i].promedio;
				}
				
				cout << endl;
			}
		}
		else {
			cout << "No se encontro a nadie con esta matricula" << endl;
			system("pause > nul");
			modificar();
		}
	
		i++;
		
	}

	Guardar();
	system("pause");
	excel();
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
			cout << "Nombre: " << e[i].nombre << " " << e[i].apellidos << endl;
			cout << "Matricula: " << e[i].matricula << endl;
			cout << "Correo: " << e[i].email << endl;
			cout << "Telefono: " << e[i].telefono << endl;
			cout << "Direccion: " << e[i].calle << "Nª " << e[i].nc << ", " << e[i].colonia << endl;
			cout << "Calificaciones:" << endl;
			cout << "| Cal 1: |" << "| Cal 2: |" << "| Cal 3: |" << endl;
			cout << "|    " << e[i].cal1 << "   |" << "|    " << e[i].cal2 << "   |" << "|    " << e[i].cal3 << "   |" << endl;
			cout << endl;


			cout << "¿Eliminar a " << e[i].matricula << "?" << endl;
			cout << " 1. Sí \n 2. No" << endl;
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
	cout << endl;
	cout << "1. Ir al Menu Principal" << endl;
	cin >> opcion;
	if (opcion == 1) {
		menu();
	}
	else {
		cout << "Ingresa una opcion valida" << endl;
	
	}
}

void Manual() {
	system("cls");

	ifstream read;
	string line;

	read.open("Manual.md");
	if (read.is_open()) {

		while (!read.eof()) {

			getline(read, line);
			cout << line << endl;
		}
	}
	else {
		cout << "Archivo inexistente o problemas para abrirlo." << endl;

	}
	cout << "1. Menu" << endl;
	cin >> opcion;
	if (opcion == 1) {
		menu();
	}

	system("pause > nul");
}
void Guardar() {
	cout << "¿Deseas guardar?" << endl;
	cout << " 1. Sí \n 2. No." << endl;

	cin >> opcion;
	if (opcion == 1) {
		
		ofstream archivo;


		archivo.open("ListasFCFM.txt", ios::binary);

		
		archivo.write((char*)&e, sizeof(e));

		
		archivo.close();
	}
	
}
void excel() {
	ofstream archivo;

	archivo.open("ListasFCFM.csv");
	archivo << "Nombre: "<< ",";
	archivo << "Apellido: " << ",";
	archivo << "Matricula: " << ",";
	archivo << "Correo: " << ",";
	archivo << "Telefono: " << ",";
	archivo << "Parcial 1: " << ",";
	archivo << "Parcial 2: " << ",";
	archivo << "Parcial 3: " << ",";
	archivo << "Promedio: " << endl;
	for (int i = 0;i < c;i++) {
		
		archivo << e[i].nombre << ",";
		archivo << e[i].apellidos << ",";
		archivo << to_string(e[i].matricula) << ",";
		archivo << e[i].email << ",";
		archivo << e[i].telefono << ",";
		archivo << (e[i].cal1) << ",";
		archivo << to_string(e[i].cal2) << ",";
		archivo << to_string(e[i].cal3) << ",";
		archivo << to_string(e[i].promedio) << endl;

	}
	archivo.close();

}



