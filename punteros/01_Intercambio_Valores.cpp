/*
 * Ejercicio 1: Intercambio de Valores (Nivel: Fácil)
 * 
 * Objetivo: Comprender cómo los punteros pueden modificar los valores
 * de las variables originales pasadas a una función.
 * 
 * Tarea:
 * 1. Crea una función llamada 'intercambiar' que reciba dos punteros a enteros.
 * 2. La función debe intercambiar los valores de las variables a las que apuntan.
 * 3. En el main, declara dos variables, imprime sus valores, llama a la función
 *    y vuelve a imprimir para verificar el cambio.
 */

#include <iostream>

// Función para intercambiar valores usando punteros
void intercambiar(int* a, int* b) {
    int temporal = *a; // Guardamos el valor al que apunta 'a'
    *a = *b;           // Asignamos el valor de 'b' a la dirección de 'a'
    *b = temporal;     // Asignamos el valor temporal a la dirección de 'b'
}

int main() {
    int x = 10;
    int y = 20;

    std::cout << "--- Antes del intercambio ---" << std::endl;
    std::cout << "x: " << x << ", y: " << y << std::endl;

    // Llamamos a la función pasando las direcciones de memoria (&)
    intercambiar(&x, &y);

    std::cout << "\n--- Despues del intercambio ---" << std::endl;
    std::cout << "x: " << x << ", y: " << y << std::endl;

    return 0;
}
