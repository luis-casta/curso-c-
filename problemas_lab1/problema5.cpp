
/*Problema 5. Escriba un programa que muestre el siguiente patrón en la pantalla:

     *
    ***
   *****
  *******
   *****
    ***
     *

*/

#include <iostream>

using namespace std;

int main()
{
  int filas = 7;

  for (int i = 1; i <= filas; i++){

    int espacios = abs(4 - i);
    int asteriscos = 7 - (2 * espacios);

    for (int j = 0; j < espacios; j++){

      cout << " ";
    }
    
    for (int k = 0; k < asteriscos; k++){

      cout << "*";

    }
  }

  cout << endl;


  return 0;
}

