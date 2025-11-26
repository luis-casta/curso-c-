/*
 * EJERCICIO 1: SUMA DE MATRICES (NIVEL FÁCIL)
 * 
 * Descripción:
 * Este programa suma dos matrices de 2x2 elemento por elemento.
 * Es el ejercicio más básico para entender cómo trabajar con matrices.
 * 
 * Conceptos que aprenderás:
 * - Declaración e inicialización de matrices
 * - Acceso a elementos de una matriz
 * - Recorrido de matrices con bucles anidados
 * - Operaciones aritméticas con elementos de matrices
 */

#include <iostream>
using namespace std;

int main() {
    // Definimos el tamaño de las matrices como constantes
    // Esto facilita modificar el tamaño si es necesario
    const int NUMERO_FILAS = 2;
    const int NUMERO_COLUMNAS = 2;
    
    // Declaración e inicialización de la primera matriz
    // Cada fila se inicializa entre llaves {}
    int matriz_primera[NUMERO_FILAS][NUMERO_COLUMNAS] = {
        {1, 2},  // Primera fila: elementos en posiciones [0][0] y [0][1]
        {3, 4}   // Segunda fila: elementos en posiciones [1][0] y [1][1]
    };
    
    // Declaración e inicialización de la segunda matriz
    int matriz_segunda[NUMERO_FILAS][NUMERO_COLUMNAS] = {
        {5, 6},  // Primera fila
        {7, 8}   // Segunda fila
    };
    
    // Declaración de la matriz resultado (inicialmente vacía)
    // Esta matriz almacenará la suma de las dos matrices anteriores
    int matriz_resultado[NUMERO_FILAS][NUMERO_COLUMNAS];
    
    // Mostrar la primera matriz
    cout << "Primera Matriz:" << endl;
    for(int indice_fila = 0; indice_fila < NUMERO_FILAS; indice_fila++) {
        for(int indice_columna = 0; indice_columna < NUMERO_COLUMNAS; indice_columna++) {
            // Mostramos cada elemento con tabulación para mejor formato
            cout << matriz_primera[indice_fila][indice_columna] << "\t";
        }
        cout << endl; // Nueva línea después de cada fila
    }
    
    // Mostrar la segunda matriz
    cout << "\nSegunda Matriz:" << endl;
    for(int indice_fila = 0; indice_fila < NUMERO_FILAS; indice_fila++) {
        for(int indice_columna = 0; indice_columna < NUMERO_COLUMNAS; indice_columna++) {
            cout << matriz_segunda[indice_fila][indice_columna] << "\t";
        }
        cout << endl;
    }
    
    // OPERACIÓN PRINCIPAL: Sumar las dos matrices
    // Recorremos cada posición de las matrices
    for(int indice_fila = 0; indice_fila < NUMERO_FILAS; indice_fila++) {
        for(int indice_columna = 0; indice_columna < NUMERO_COLUMNAS; indice_columna++) {
            // La suma se realiza elemento por elemento
            // matriz_resultado[i][j] = matriz_primera[i][j] + matriz_segunda[i][j]
            matriz_resultado[indice_fila][indice_columna] = 
                matriz_primera[indice_fila][indice_columna] + 
                matriz_segunda[indice_fila][indice_columna];
        }
    }
    
    // Mostrar la matriz resultado
    cout << "\nMatriz Resultado (Suma):" << endl;
    for(int indice_fila = 0; indice_fila < NUMERO_FILAS; indice_fila++) {
        for(int indice_columna = 0; indice_columna < NUMERO_COLUMNAS; indice_columna++) {
            cout << matriz_resultado[indice_fila][indice_columna] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}

/*
 * SALIDA ESPERADA:
 * 
 * Primera Matriz:
 * 1    2
 * 3    4
 * 
 * Segunda Matriz:
 * 5    6
 * 7    8
 * 
 * Matriz Resultado (Suma):
 * 6    8
 * 10   12
 * 
 * EXPLICACIÓN:
 * [1+5=6]   [2+6=8]
 * [3+7=10]  [4+8=12]
 */
