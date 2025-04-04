
/* Ejercicio 14. Escriba un programa que imprima dos columnas paralelas, una con los números del
1 al 50 y otra con los números del 50 al 1.
Ej: las primeras lineas a imprimir serían:
1   50 
2   49
3   48
*/

#include <iostream>
using namespace std;

int main()
{
  for (int incremento = 1, decremento = 50; incremento <= 50; incremento ++, decremento -- ){

    cout << incremento << "         " << decremento << endl;

  }
  return 0;
}
