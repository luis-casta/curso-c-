/* Problema 17. La secuencia de números triangulares se forma al sumar su
posición en el arreglo con el valor del número anterior: 1, 1+2=3, 3+3=6,
6+4=10, 10+5=15, 15+6=21, 21+7=28... Si listamos los números triangulares y sus
divisores tenemos: 1: 1 3: 1,3 6: 1,2,3,6 10: 1,2,5,10 15: 1,3,5,15 21: 1,3,7,21
28: 1,2,4,7,14,28
Se observa que 28 es el primer número triangular que tiene más de 5 divisores.
Escriba un programa que reciba un número k y calcule cual es el primer número
triangular que tiene más de k divisores. Tip: el enésimo número triangular se
puede representar como n*(n+1)/2. Nota: la salida del programa debe ser: El
numero es: 28 que tiene 6 divisores.*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k;

    cout << "Ingrese un número: ";
    cin >> k;

    int posicion = 1;

    while (true) {
        int n_esimo = (posicion * (posicion + 1)) / 2;
        int divisores = 0;

        // Optimización: solo iterar hasta la raíz cuadrada
        for (int i = 1; i <= sqrt(n_esimo); i++) {
            if (n_esimo % i == 0) {
                // Si i es divisor, también lo es n_esimo/i
                divisores += (i * i == n_esimo) ? 1 : 2;
            }
        }

        if (divisores > k) {
            cout << "El número es: " << n_esimo 
                 << " que tiene " << divisores << " divisores" << endl;
            break;
        }

        posicion++;
    }

    return 0;
}