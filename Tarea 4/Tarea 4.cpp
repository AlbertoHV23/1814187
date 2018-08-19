#include<iostream>
#include<math.h>

using namespace std;

int main(){
locale::global(locale("spanish"));

float radio;
cout << "Escribe tu radio: ";
cin >> radio;

float angulo;
cout << "Escribe tu angulo: ";
cin >> angulo;

float coseno;
float X;
X = radio * cos(angulo);
cout << "\nTu coordenada en el eje x es: " << X << endl;

float seno;
float Y;
Y = radio * sin(angulo);
cout << "Tu coordenada en el eje Y es: " << Y << endl;


system("pause");
}
