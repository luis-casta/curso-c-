/*Realize un programa que lea de la entrada estandar los suguientes datos de una persona
edad, sexo y altura.
Tras leer los datos el programa debe mostrarlos en la salida estandar*/
#include <iostream>
#include <string>
#include <iomanip> // necesario para fixed y setprecision
using namespace std;

int main()
{
  int edad;
  string sexo;
  double estatura;

  cout << "Edad: ";
  cin >> edad;

  cin.ignore(); // limpiar el buffer de entrada para evitar problemas con getline()

  cout << "sexo: ";
  getline(cin, sexo); // getline se usa para leer una linea entera
  cout << "Atura (en centimetros): ";
  cin >> estatura;

  cout << "\nDatos Ingresados: \n ";
  cout << "Edad: " << edad << endl;
  cout << "Sexo: " << sexo << endl;
  cout << "Estatura: " << fixed << setprecision(2) << estatura << endl; // necesitamos usar fixed
  // y setpreccision(2) porque si ponemos estatura que termine en cero(0) sin setprecision c++ lo borra

  return 0;
}

/*NOTA:
  Qué es el buffer:
  El buffer de entrada es un área de memoria donde se almacenan temporalmente los datos ingresados por el usuario antes de que el programa los procese. Cuando utilizamos cin, los datos ingresados se quedan en este buffer hasta que el programa los lee completamente.

  Cuando usas cin para leer un número:
int edad;
cin >> edad;
el usuario ingresa un valor y presiona Enter (\n). El número se guarda en edad, pero el Enter (\n) se queda en el buffer.

Si después usamos getline(cin, sexo);:

string sexo;
getline(cin, sexo);
el getline detecta el Enter en el buffer y lo toma como la entrada, haciendo que sexo quede vacío.

*/
