
/* Ejercicio 20. Escriba un programa que pida un número N e imprima si es o no un palíndromo
(igual de derecha a izquierda que de izquierda a derecha).
Ej: si se ingresa 121 se debe imprimir:
121 es un numero palindromo.
y si se ingresa 123 se debe imprimir:
123 NO es un numero palindromo.*/

#include <iostream>
using namespace std;

int main()
{
  int numeroUsuario, numeroOriginal, numeroInvertido = 0;

  cout << "Ingrese un número: ";
  cin >> numeroUsuario;

  numeroOriginal = numeroUsuario;

  while (numeroUsuario > 0){

    int digito = numeroUsuario % 10;
    numeroInvertido = numeroInvertido * 10 + digito;
    numeroUsuario = numeroUsuario / 10;
  }

  cout << numeroOriginal << ((numeroOriginal == numeroInvertido) ? " Es un número palíndromo" : 
  " No es un número palídromo") << endl;
  return 0;
}
