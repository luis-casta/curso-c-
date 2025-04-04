
/* Ejercicio 12. Escriba un programa que pida un número N e imprima todas las potencias desde N¹ hata N⁵
Ej: si se ingresa 3 se debe imprimir:
3∧1=3
3∧2=9
3∧3=27
3∧4=81
3∧5=243
*/

#include <iostream>
using namespace std;

int main()
{
  int base, potencia = 1;
  cout << "Ingrese la base: ";
  cin >> base;

  for (int exponente = 1; exponente <= 5; exponente++){

    potencia = potencia * base;

    cout << base << "^" << exponente << " = " << potencia << endl;
}

  return 0;
}
