/*
 * Ejercicio 3: Matriz Transpuesta Dinámica (Nivel: Difícil)
 * 
 * Objetivo: Dominar el uso de punteros a punteros (doble puntero) para
 * crear matrices dinámicas y manipular estructuras de datos complejas.
 * 
 * Tarea:
 * 1. Pide al usuario el número de filas y columnas.
 * 2. Crea una matriz dinámica usando punteros a punteros (int**).
 * 3. Llena la matriz con valores ingresados por el usuario.
 * 4. Muestra la matriz original.
 * 5. Calcula y muestra la matriz transpuesta (filas se convierten en columnas).
 *    Nota: Puedes imprimirla directamente o crear una nueva matriz dinámica para la transpuesta.
 * 6. Libera toda la memoria reservada (cuidado con el orden de liberación).
 */

#include <iostream>

int main() {
    int filas, cols;
    std::cout << "Ingrese numero de filas: ";
    std::cin >> filas;
    std::cout << "Ingrese numero de columnas: ";
    std::cin >> cols;

    // 1. Reservar memoria para las filas (array de punteros)
    int** matriz = new int*[filas];

    // 2. Reservar memoria para las columnas de cada fila
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[cols];
    }

    // 3. Llenar la matriz
    std::cout << "\nIngrese los valores de la matriz:" << std::endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Matriz[" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }

    // 4. Mostrar matriz original
    std::cout << "\n--- Matriz Original ---" << std::endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // 5. Mostrar matriz transpuesta
    // La transpuesta tiene 'cols' filas y 'filas' columnas
    std::cout << "\n--- Matriz Transpuesta ---" << std::endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < filas; j++) {
            // Imprimimos matriz[j][i] en lugar de matriz[i][j]
            std::cout << matriz[j][i] << "\t";
        }
        std::cout << std::endl;
    }

    // 6. Liberar memoria
    // Primero liberamos cada fila
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    // Luego liberamos el array de punteros
    delete[] matriz;

    std::cout << "\nMemoria liberada correctamente." << std::endl;

    return 0;
}
