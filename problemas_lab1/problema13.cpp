
/* Problema 13. Escriba un programa que reciba un número y calcule la suma de todos los primos
menores que el número ingresado.
Ej: Si se recibe 10 el programa debe imprimir 17.
Nota: la salida del programa debe ser: El resultado de la suma es: 17.*/

#include <iostream>

using namespace std;

int main()
{
  int numero, suma = 0;

  cout << "Ingresa un número: ";
  cin >> numero;

  for (int i = 2; i < numero; i++){

    bool esPrimo = true;

    for (int j = 2; j < i; j++){

      if (i % j == 0){ 

        esPrimo = false;
      }
    }

    if (esPrimo == true){

      suma += i;

  }
  
}
  cout << "La suma es: " << suma << endl;
  return 0;
}

