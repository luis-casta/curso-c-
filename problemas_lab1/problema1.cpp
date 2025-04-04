
/* Problema1: Escriba un programa que identique si un carácter ingresado es una vocal, una con-
sonante o ninguna de las 2 e imprima un mensaje según el caso.

Nota: el formato de salida debe ser:
no es una letra.
a es una vocal.
*/

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
  char letra;

  cout << "Ingrese un carácter: ";
  cin >> letra;

  char caracter = tolower(letra);

  if (isalpha(caracter)){

    if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == '0' || caracter == 'u'){

      cout << caracter << " es una vocal" << endl;

    }
    else {
      cout << caracter << " es una consonante" << endl;
    }
  }
  else {
    cout << " El caracter no es una letra" << endl;
  }



  return 0;
}
