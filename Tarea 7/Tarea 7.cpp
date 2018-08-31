#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

//Juego de piedra, papel o tijeras
void main(){
	system("color 3f");
	int g=0,p=0,e=0;  //g=GANADAS, p=PERDIDAS,e=EMPATADAS
	bool decision = true;

	while (decision = true) {
		cout << "Elige una opcion;" << endl;
		cout << "1.-Piedra" << endl;
		cout << "2.-Papel" << endl;
		cout << "3.-Tijera" << endl;

		srand(time(NULL));

		int PC;
		PC = rand () % 4;

		int pipati;//pipati = Piedra papel o tijera...
		cin >> pipati;

		if (pipati == 1) {
			if (PC == 1) {
				cout << "La computadora jugo Piedra: " << "Empate" << endl;
				e = e + 1;
			}
			else if (PC == 2) {
				cout << "La computadora jugo Papel: " << "Perdiste" << endl;
				p = p + 1;
			}
			else {
				cout << "La computadora jugo Tijera: "<< "Ganaste " << endl;
				g = g + 1;
			}

		}

		else if (pipati == 2) {

			if (PC == 1) {
				cout << "La computadora jugo piedra: " << "Ganaste" << endl;
				g = g + 1;
			}
			else if (PC == 2) {
				cout << "La computadora jugo papel: " << "Empate" << endl;
				e = e + 1;
			}
			else {
				cout << "La computadora jugo tijeras: "  << "Perdiste" << endl;
				p = p + 1;
			}

		}
		else if (pipati == 3) {

			if (PC == 1) {
				cout << "La computadora jugo piedra: " << "Perdiste" << endl;
				p = p + 1;
			}
			else if (PC == 2) {
				cout << "la computadora jugo papel: " << "Ganaste" << endl;
				g = g + 1;
			}
			else {
				cout << "La computadora jugo tijeras: " << "Empate" << endl;
				e = e + 1;
			}

		}

		else {
			decision = false;
		}
		cout << "/n";
		cout << "Partidas Ganadas: " << g << endl;
		cout << "Partidas Perdidas: " << p << endl;
		cout << "Partidas Empatadas: " << g << endl;

	}
		
	system("pause");

}