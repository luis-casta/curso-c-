
/* Ejercicio 16. Escriba un programa que pida constantemente números hasta que se ingrese el nú-
mero cero e imprima en pantalla el promedio de los números ingresados (excluyendo el cero).
Ej: si se ingresan 1, 2, 3, 0 se debe imprimir:
El promedio es: 2 */

#include <iostream>
using namespace std;

int main()
{
  int numero, contador = 0 , suma = 0;
  

  cout << "Ingrese números (ingrese 0 para salir.)" << endl;
  
  while (true){

    cout << "Ingrese un número: ";
    cin >> numero;

    if (numero == 0){

      break;
    }
    //suma = suma + numero;
    suma += numero;
    contador ++;
  }
  float promedio = static_cast<float>(suma) / contador;

  cout << "El promedio es: " << promedio << endl;

  
return 0;
}


