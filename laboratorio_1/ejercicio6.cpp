
/* Ejercicio 6. Escriba un programa que pida dos números A y B e imprima en pantalla la potencia
AB, sin hacer uso de librerías matemáticas.
Ej: si se ingresan 5 y 3 se debe imprimir:
5∧3=125 */

#include <iostream>

using namespace std;

int main()
{
  int base, exponente , potencia = 1;

  cout << "Ingrese la base: ";
  cin >> base;

  cout << "Ingrese el exponenete: ";
  cin >> exponente;

  for (int i = 1; i <= exponente; i++){

    potencia = potencia * base;

  }
  cout << base << "^" << exponente << " = " << potencia << endl;

  return 0;
}
