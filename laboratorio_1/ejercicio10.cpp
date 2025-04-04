
/*Ejercicio 10. Escriba un programa que pida un número N e imprima en pantalla todos los múlti-
plos de dicho número entre 1 y 100.
Ej: si se ingresa 33 se debe imprimir:
Multiplos de 33  menores que 100:
33
66
99*/

#include <iostream>

using namespace std;

int main()
{
  int numero;

  cout << "Ingrese un número: ";  
  cin >> numero;

  cout << "Multiplos de " << numero << " menores que 100: " << endl;

  for (int i = numero; i <= 100; i = i + numero)
  {
    cout << i << endl;
  }
  
  return 0;
}
