
/*  DESPLAZAMIENTO A LA DERECHA (>>)
El desplazamiento a la derecha (>>) es una operación que mueve los bits de un número hacia la derecha una cantidad n de posiciones.

Cada bit se desplaza n posiciones hacia la derecha.

Los bits que se "salen" por la derecha se pierden.

Los espacios vacíos a la izquierda se rellenan de dos maneras, dependiendo del tipo de desplazamiento:

Desplazamiento lógico (>>) → Se rellenan con ceros (0).

Desplazamiento aritmético (>>) → Se rellenan con el bit más significativo (MSB) para mantener el signo.*/

#include <iostream>
#include <bitset>
using namespace std;

int main()
{
  int a = -76; //   1011 0100  -76 en complemento a dos 

  cout << "a en decimal: " << a << endl;
  cout << "a en binario: " << bitset<8>(a) << endl;

  int resultado = a >> 2; // desplazamiento a la derecha de 2 bits

  cout << "a >> en decimal: " << resultado << endl;
  cout << " >> en binario: " << bitset<8>(resultado) << endl;

  return 0;
}
