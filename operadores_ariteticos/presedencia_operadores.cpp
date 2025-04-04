
/*precedencia de operadores aritmeticos: 
  En C++, los operadores aritméticos tienen una precedencia específica que determina el orden en que se evalúan en una expresión. Aquí te explico la precedencia de los operadores aritméticos, de mayor a menor prioridad:*/

  /*Precedencia de operadores aritméticos:

Operadores: ++, --

Descripción: Incremento o decremento del valor antes de usarlo.

Asociatividad: Derecha a izquierda.

Operadores de multiplicación, división y módulo:

Operadores: *, /, %

Descripción: Multiplicación, división y módulo (resto de la división).

Asociatividad: Izquierda a derecha.

Operadores de suma y resta:

Operadores: +, -

Descripción: Suma y resta.

Asociatividad: Izquierda a derecha.

*/
#include <iostream>

using namespace std;

int main(){

  // multiplicación antes que suma o resta
  double multiplicacion = 12 + 3 - 2 * 4; 
  cout << "Resultado: " << multiplicacion << endl;

  // division antes que resta:
  double division = 9 - 4 / 2; // primero se realiza 4/2 y el resultado se le resta al 9
  cout << "Divison: " << division << endl;

  // modulo antes que suma 
  double resto = 7 % 3 + 2; // primereo se hace el modulo que es 1 y se le suma 2 
  cout << "Resto: " << resto << endl;




  return 0;
}

