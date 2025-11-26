
/* AÑO BISIESTO CON OPERADOR TERNARIO:
  haga un programa que pida un año y verifique si es bisiesto utlizando el operador ternario:
  un número es bisiesto si cumple al menos una de las siguientes condiciones:
  1. si es divisible por 400
  2. si es divisible por 4, pero No por 100
  */

#include <iostream>
using namespace std;

int main()
{
  int año;
  cout << "ingrese un año: ";
  cin >> año;

  cout << año << ((año % 400 == 0 && año % 100 != 0) || (año % 4 == 0) ? " ES bisiesto" : " No es bisiesto") << endl;

  return 0;
}
