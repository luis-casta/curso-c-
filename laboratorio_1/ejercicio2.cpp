
/* Ejercicio 2. Escriba un programa que pida un número N e imprima en pantalla si es par o impar.
Ej: si se ingresa 5 se debe imprimir:
5 es impar
*/

#include <iostream>

using namespace std;

int main()
{
  int numero;
  cout << "Ingrsee un número: ";
  cin >> numero;

  cout << numero << ((numero % 2 == 0) ? " Es par" : " Es impar") << endl;


  return 0;
}
