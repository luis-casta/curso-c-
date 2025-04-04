
/* OPERADOR NOT (~)
invierte los bits, cambia 0 por 1 y 1 por 0
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 5; // 0101 en binario
    int b = 3; // 0011 en binario

    int resultado_not_a = ~a;  // NOT bit a bit de 'a'  1010
    int resultado_not_b = ~b;  // NOT bit a bit de 'b'  1100

    cout << "NOT de a (~a) = " << resultado_not_a << endl;
    cout << "NOT de b (~b) = " << resultado_not_b << endl;

    return 0;
}

