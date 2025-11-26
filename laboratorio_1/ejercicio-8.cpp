
// FACTORIAL DE UN NÚMERO N
/* Ejercicio 8. Escriba un programa que pida un número N e imprima en pantalla su factorial.
Ej: si se ingresa 5: 5!=1*2*3*4*5=120, por lo que se debe imprimir:
5!=120
*/



#include <iostream>
using namespace std;

int main(){

  int numero, factorial = 1;

  cout << "Ingrese un número: ";
  cin >> numero;

  for (int i = 1; i <= numero; i++)
  {
    factorial = factorial * i;
  }

  return 0;
}
