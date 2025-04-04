
/* CICLO FOR :
El ciclo for en C++ se usa cuando sabemos cuántas veces queremos repetir una acción. Se escribe así:

for (inicialización; condición; actualización) {
    // Código a ejecutar en cada iteración
}

Cómo funciona?
1. Inicialización → Se ejecuta una sola vez al inicio (por ejemplo, int i = 0).
2. Condición → Mientras sea verdadera, el bucle se repite.
3. Actualización → Se ejecuta después de cada iteración (por ejemplo, i++ para aumentar el contador).
*/

#include <iostream>
using namespace std;

void bucleCreciente(){

// imprimir los números del 1 al 1o
  for (int i = 1; i <= 10; i++){

    cout << i << endl;

  }
}

void sumaIterativa(){

  // sumar los primeros 10 numeros
  int suma = 0; 
  for (int numero = 1; numero <= 10; numero++){
    suma += numero;

  }
  cout << "La suma de los primeros 1o números es: " << suma << endl;
}

void pares(){
  
  // imprimir los números pares del 2 al 20
  for (int i = 2; i <= 20; i+=2){

    cout << i << " " << endl;
  }
  
}

int main(){

  int opcion;

  do {
    cout << "\nEjemplos de bucle for\n";
    cout << "1. Bucle crecieente (nnúmeros del 1 al 10)\n";
    cout << "2. Suma iterativa (suma de los primeros 10 números)\n";
    cout << "3. Números pares del 2 al 20\n";
    cout << "4. Salir\n";

    cout << "Elija una opción: ";

    cin >> opcion; 

    

    switch (opcion){
      case 1: 
        bucleCreciente();
        break;
      case 2:
        sumaIterativa();
        break;
      case 3:
        pares();
        break;
      case 4:
        cout << "Saliendo del programa ... " << endl;
        break;
      default:
        cout << "Opción no valida intentalo de nuevo." << endl;

    }

  } while (opcion != 4);


  return 0;
}