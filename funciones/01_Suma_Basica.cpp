#include <iostream>
using namespace std;

// Ejercicio 1: Función Básica de Suma (Nivel: Fácil)
// Objetivo: Crear una función que reciba dos enteros y retorne su suma.

// Declaración de la función
int sumar(int a, int b);

int main() {
    int num1, num2;

    cout << "=== Ejercicio 1: Suma de dos números ===" << endl;
    cout << "Introduce el primer número: ";
    cin >> num1;
    cout << "Introduce el segundo número: ";
    cin >> num2;

    // Llamada a la función
    int resultado = sumar(num1, num2);

    cout << "La suma de " << num1 << " + " << num2 << " es: " << resultado << endl;

    return 0;
}

// Definición de la función
int sumar(int a, int b) {
    // Explicación: Esta función toma dos parámetros 'a' y 'b',
    // los suma y devuelve el resultado usando 'return'.
    return a + b;
}
