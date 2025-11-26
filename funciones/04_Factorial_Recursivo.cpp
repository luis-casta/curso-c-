#include <iostream>
using namespace std;

// Ejercicio 4: Factorial Recursivo (Nivel: Difícil)
// Objetivo: Implementar una función recursiva (que se llama a sí misma).

// Declaración de la función
unsigned long long factorial(int n);

int main() {
    int numero;

    cout << "=== Ejercicio 4: Factorial Recursivo ===" << endl;
    cout << "Introduce un número entero positivo: ";
    cin >> numero;

    if (numero < 0) {
        cout << "El factorial no está definido para números negativos." << endl;
    } else {
        unsigned long long resultado = factorial(numero);
        cout << "El factorial de " << numero << " es: " << resultado << endl;
    }

    return 0;
}

// Definición de la función recursiva
unsigned long long factorial(int n) {
    // Caso base: El factorial de 0 o 1 es 1.
    // Es CRUCIAL tener un caso base para evitar un bucle infinito.
    if (n <= 1) {
        return 1;
    }
    
    // Paso recursivo: n! = n * (n-1)!
    // La función se llama a sí misma con un valor menor.
    return n * factorial(n - 1);
}
