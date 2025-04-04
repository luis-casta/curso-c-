
/* OPERADOR OR (|)

devuelve 1 si al menos uno de los bits es 1 

bit A   bit bB   A | B
0        0      =  0
0        1      =  1
1        0      =  1
1        1      =  1
*/

#include <iostream>
using namespace std;

int main()
{
  int a = 5; // 0101 en binario 
  int b = 3; // 0011 en binario 

  int resultado = a ^ b;  //     0     1     0      1
                          //     0     0     1      1
                      //       = 0   = 1   = 1    = 1  = 0111 en binario = 6 en decimal 
  cout << "Resultado = " << resultado << endl;

  return 0;
}
