
/* Problema 11. Escriba un programa que reciba un número y calcule el mínimo común múltiplo de
todos los números enteros entre 1 y el número ingresado.
Ej: Si se recibe 4 el programa debe imprimir 12.
Nota: la salida del programa debe ser: El minimo comun multiplo es: 12.*/

#include <iostream>

using namespace std;

int main()
{
  int numero, mcm = 1;   

  cout << "Ingrtese un número: ";
  cin >> numero;

  for (int i = 1; i <= numero; i++){

    int multiplo = mcm;

    while (true){

      if (multiplo % i == 0){

        mcm = multiplo;
        break;

      }
      else{
        multiplo += mcm;
      }

    }

  }
  cout << "El minimo común multiplo de 1 hasta " << numero << " es:  " << mcm << endl;

  return 0;
}
