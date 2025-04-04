
/* Ejercicio 18. Escriba un programa que pida un número N e imprima si es o no un cuadrado per-
fecto.
Ej: si se ingresa 9 se debe imprimir:
9 es un cuadrado perfecto.
y si se ingresa 8 se debe imprimir:
8 NO es un cuadrado perfecto.*/

#include <iostream>
using namespace std;

int main()
{
  int numero;
  cout << "Ingresa un número: ";
  cin >> numero;

  bool esPerfecto = false;

  for (int i = 0; i * i <= numero; i++){

    if (i * i == numero){
      esPerfecto = true;
      break;
    }

  }
  
  cout << numero << ((esPerfecto == true) ? " Es cuadrado perfecto" : " No es cuadrado perfecto" ) << endl;


  return 0;
}
