
/* Problema 9. Escriba un programa que pida un número entero N e imprima el resultado de la suma
de todos sus dígitos elevados a sí mismos.
Ej: si se ingresa 1223 el resultado sería 1¹ + 2² + 2² + 3³ = 36

Nota: la salida del programa debe ser: El resultado de la suma es: 36.*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, suma_total = 0;

    cout << "Ingrese un número entero: ";
    cin >> N;

    int numero = N; // Copia para trabajar

    while (numero > 0) {
        int digito = numero % 10;
        suma_total += pow(digito, digito);
        numero = numero / 10;
    }

    cout << "El resultado de la suma es: " << suma_total << "." << endl;

    return 0;
}