
/* Ejercicio 30. Escriba un programa que genere un número aleatorio A (entre 0 y 100) y le pida al
usuario que lo adivine, el usuario ingresa un número B y el programa le dirá si B es mayor o menor
que A, esto se repetirá hasta que el usuario adivine el número, en ese momento el programa le dirá
el número de intentos que tardo el usuario en adivinar el número.
Nota: para generar el número aleatorio use la función rand() de la librería <cstdlib>, recuerde
convertirlo al rango (0,100).*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int num_aleatorio = rand() % 99 + 1;

  bool adivinado = false;

  cout << " ****** Bienvenido al juego de adivinza *********" << endl;
  cout << "Adivina el número secreto entre  (0,100)" << endl;

  while (adivinado == false){

    int num_usuario;

    cout << "Ingresea un número: ";
    cin >> num_usuario;

    if (num_aleatorio == num_usuario){

      cout << "Felicidades adivinaste el número secreto :)" << endl;
      adivinado == true; 
      break;
    }
    else if (num_usuario > num_aleatorio ){
      cout << "El número secreto es menor." << endl;

    }
    else if (num_usuario < num_aleatorio){
      cout << "El número secreto es mayor" << endl;

    }
  }


  return 0;
}
