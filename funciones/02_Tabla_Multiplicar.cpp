#include <iostream>
using namespace std;

// Ejercicio 2: Tabla de Multiplicar (Nivel: Fácil)
// Objetivo: Crear una función 'void' que imprima la tabla de multiplicar de un número.

// Declaración de la función
void imprimirTabla(int numero);

int main() {
    int num;

    cout << "=== Ejercicio 2: Tabla de Multiplicar ===" << endl;
    cout << "Introduce un número para ver su tabla: ";
    cin >> num;

    // Llamada a la función void (no retorna valor, solo ejecuta una acción)
    imprimirTabla(num);

    return 0;
}

// Definición de la función
void imprimirTabla(int numero) {
    // Explicación: Al ser 'void', esta función no tiene 'return' con valor.
    // Su propósito es mostrar información en pantalla.
    cout << "Tabla del " << numero << ":" << endl;
    for (int i = 1; i <= 10; ++i) {
        cout << numero << " x " << i << " = " << (numero * i) << endl;
    }
}
