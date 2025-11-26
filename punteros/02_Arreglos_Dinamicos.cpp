/*
 * Ejercicio 2: Arreglos Dinámicos (Nivel: Medio)
 * 
 * Objetivo: Aprender a gestionar memoria dinámica con 'new' y 'delete',
 * y a recorrer arreglos usando aritmética de punteros.
 * 
 * Tarea:
 * 1. Pide al usuario el tamaño del arreglo.
 * 2. Reserva memoria dinámica para un arreglo de enteros de ese tamaño.
 * 3. Pide al usuario que ingrese los valores del arreglo.
 * 4. Imprime los valores usando un puntero auxiliar para recorrer el arreglo
 *    (sin usar índices como arr[i], sino *(ptr + i) o ptr++).
 * 5. Libera la memoria reservada.
 */

#include <iostream>

int main() {
    int n;
    std::cout << "Ingrese el tamano del arreglo: ";
    std::cin >> n;

    // Reserva de memoria dinámica
    int* arreglo = new int[n];

    // Llenado del arreglo
    std::cout << "Ingrese " << n << " numeros:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Numero " << i + 1 << ": ";
        std::cin >> arreglo[i]; // Aquí podemos usar sintaxis de corchetes para facilitar la lectura
    }

    // Impresión usando aritmética de punteros
    std::cout << "\n--- Valores del arreglo (usando punteros) ---" << std::endl;
    int* ptr = arreglo; // Puntero auxiliar al inicio del arreglo
    for (int i = 0; i < n; i++) {
        // Accedemos al valor apuntado por (ptr + i)
        std::cout << "Posicion " << i << ": " << *(ptr + i) << std::endl;
    }

    // Liberación de memoria
    delete[] arreglo;
    std::cout << "\nMemoria liberada correctamente." << std::endl;

    return 0;
}
