
/* OPERADOR XOR (^)

  devuelve 1 si los bits son diferentes, 0 si son iguales 
  
Bit A         Bit B           A&B
0              0         =     0
0              1         =     1
1              0         =     1
1              1         =     0
*/

#include <iostream>
using namespace std;

int main()
{
  int a = 5; // 0101 en binario 
  int b = 3; // 0011 en binario 

  int resultado = a & b;  //     0     1     0      1
                          //     0     0     1      1
                      //       = 0   = 1   = 1     =0  = 0110 en binario = 1 en decimal 
  cout << "Resultado = " << resultado << endl;

  return 0;
}

