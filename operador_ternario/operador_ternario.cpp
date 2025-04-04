
/* OPERADOR TERNARIO:
   El operador ternario en C++ es una forma abreviada de escribir 
   una condición if-else. Su sintaxis es:
   (condición) ? expresión_si_verdadero : expresión_si_falso;
*/
// EJEMPLO: comprobar si un número es para usando el operador ternario

#include <iostream>
using namespace std;

int main()
{
  int num;
  cout << "Ingrse un número: ";
  cin >> num;

  cout << num << ((num % 2 == 0) ? " es par " : " es impar") << endl;  // en este caso pongo la expresion entre parentesis porque el operador << (desplazamientoizquierda) tiene mayor precedencia que el operador ? (ternario)

  return 0;
}
