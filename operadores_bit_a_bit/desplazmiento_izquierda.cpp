
/*  Operador << (Desplazamiento a la izquierda) en C++
El operador << (shift left o desplazamiento a la izquierda) mueve los bits de un número hacia la izquierda n posiciones, rellenando con ceros a la derecha.

Regla General:
x << n  =  x * (2^n) 4 << 3 = 4 * (2³)

*/

#include <iostream>
using namespace std;

int main()
{
  int a = 3; // 0011 en binario 
  int resultado = a << 2; // desplazar 2 bit a la izquierda

  cout << "Número original: " << a << endl;
  cout << "Número con desplazamiento a la izquierda (2 bits): " << resultado << endl;




  return 0;
}
