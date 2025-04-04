
/* OPERADOR AND (&):
Operador "AND" bit a bit (Bitwise AND)
Se usa para realizar una operación AND bit a bit entre dos números enteros. Compara cada bit de los operandos y devuelve 1 solo si ambos bits son 1, de lo contrario devuelve 0. 

AND (&) devulve 1 si ambos bits son 1, de lo contrario devulve 0

Bit A         Bit B           A&B
0              0         =     0
0              1         =     0
1              0         =     0
1              1         =     1
*/

#include <iostream>
using namespace std;

int main()
{
  int a = 5; // 0101 en binario 
  int b = 3; // 0011 en binario 

  int resultado = a & b;  //     0     1     0      1
                          //     0     0     1      1
                      //       = 0   = 0    =0     =1  = 0001 en binario = 1 en decimal 
  int resultadoIzquierda = resultado << 2 ;
  int resultadoDerecha = resultado>> 2;

  cout << "Resultado AND (A&B)= " << resultado << endl;
  cout << "Resultado deplazado izquierda (AND << ) " << resultadoIzquierda << endl;
  cout << "Resultado desplazado derecha (AND >> ) " << resultadoDerecha << endl;

  return 0;
}
