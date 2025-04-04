
/* Problema 7. En la serie de Fibonacci, cada número es la suma de los 2 anteriores e inicia con 1 y
1. Ej: 1, 1, 2, 3, 5, 8, ....
Escriba un programa que reciba un número n y halle la suma de todos los números pares en la serie
de Fibonacci menores a n.
Ej: si se ingresa 10, sería la suma de 2+8 =10
Nota: el formato de salida debe ser: El resultado de la suma es: 10*/

#include <iostream>

using namespace std;

int main()
{
  int numLimite;

  cout << "Ingrese un número: ";
  cin >> numLimite;

  int numAnterior = 1;
  int numActual = 1;
  int numSiguiente;
  int sumPares = 0;

  while (numActual < numLimite)
  {
    cout << numActual << endl;
    
    if (numActual % 2 == 0){

      sumPares += numActual;
    }

    numSiguiente = numAnterior + numActual;

    numAnterior = numActual;
    numActual = numSiguiente;
  }

  cout << "\nEl resultado de la suma es: " << sumPares << endl;
  



  return 0;
}
