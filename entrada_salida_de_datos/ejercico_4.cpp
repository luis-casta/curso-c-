
/*Ejercicio: Registro de datos personales

Escribe un programa en C++ que solicite al usuario los siguientes datos:

Nombre completo
Edad (en años)
Peso (en kilogramos con decimales)
El programa debe leer estos datos desde la entrada estándar y luego mostrarlos en la salida estándar con un formato adecuado.*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  string nombre;
  int edad;
  double peso;

  cout << "Nombre completo: ";
  getline(cin, nombre); // getline para poder leer varias palabras en la misma linea

  cout << "Edad: ";
  cin >> edad;

  cout << "Peso: ";
  cin >> peso;

  cout << "\nDatos personales: \n";
  cout << "Nombre Completo: " << nombre << endl;
  cout << "Edad: " << edad << endl;
  cout << "Peso: " << fixed << setprecision(2) << peso << endl;

  return 0;
}