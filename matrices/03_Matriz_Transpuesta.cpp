/*
 * EJERCICIO 3: MATRIZ TRANSPUESTA (NIVEL MEDIO)
 * 
 * Descripción:
 * Este programa calcula la transpuesta de una matriz. La transpuesta
 * de una matriz se obtiene intercambiando filas por columnas.
 * Si A es una matriz m×n, entonces A^T es una matriz n×m donde
 * A^T[i][j] = A[j][i]
 * 
 * Conceptos que aprenderás:
 * - Transposición de matrices
 * - Matrices de diferentes dimensiones
 * - Intercambio de índices
 * - Creación de nuevas matrices a partir de operaciones
 */

#include <iostream>
using namespace std;

int main() {
    // Dimensiones de la matriz original
    const int NUMERO_FILAS_ORIGINAL = 3;
    const int NUMERO_COLUMNAS_ORIGINAL = 4;
    
    // Dimensiones de la matriz transpuesta (se invierten)
    const int NUMERO_FILAS_TRANSPUESTA = NUMERO_COLUMNAS_ORIGINAL;
    const int NUMERO_COLUMNAS_TRANSPUESTA = NUMERO_FILAS_ORIGINAL;
    
    // Matriz original de 3x4
    int matriz_original[NUMERO_FILAS_ORIGINAL][NUMERO_COLUMNAS_ORIGINAL] = {
        {1,  2,  3,  4},   // Fila 0
        {5,  6,  7,  8},   // Fila 1
        {9, 10, 11, 12}    // Fila 2
    };
    
    // Matriz transpuesta de 4x3 (las dimensiones se invierten)
    // Esta matriz almacenará el resultado de la transposición
    int matriz_transpuesta[NUMERO_FILAS_TRANSPUESTA][NUMERO_COLUMNAS_TRANSPUESTA];
    
    // Mostrar la matriz original
    cout << "=== MATRIZ ORIGINAL ===" << endl;
    cout << "Dimensiones: " << NUMERO_FILAS_ORIGINAL << " filas x " 
         << NUMERO_COLUMNAS_ORIGINAL << " columnas" << endl << endl;
    
    for(int indice_fila = 0; indice_fila < NUMERO_FILAS_ORIGINAL; indice_fila++) {
        for(int indice_columna = 0; indice_columna < NUMERO_COLUMNAS_ORIGINAL; indice_columna++) {
            cout << matriz_original[indice_fila][indice_columna] << "\t";
        }
        cout << endl;
    }
    
    // OPERACIÓN DE TRANSPOSICIÓN
    // Recorremos la matriz original y copiamos cada elemento
    // intercambiando los índices de fila y columna
    cout << "\n--- Proceso de Transposicion ---" << endl;
    
    for(int indice_fila = 0; indice_fila < NUMERO_FILAS_ORIGINAL; indice_fila++) {
        for(int indice_columna = 0; indice_columna < NUMERO_COLUMNAS_ORIGINAL; indice_columna++) {
            // La clave de la transposición: intercambiar índices
            // El elemento en posición [i][j] de la original
            // va a la posición [j][i] de la transpuesta
            matriz_transpuesta[indice_columna][indice_fila] = 
                matriz_original[indice_fila][indice_columna];
            
            // Mostrar el proceso (opcional, para entender mejor)
            if(indice_fila == 0 && indice_columna < 2) {
                cout << "Original[" << indice_fila << "][" << indice_columna << "] = " 
                     << matriz_original[indice_fila][indice_columna]
                     << " -> Transpuesta[" << indice_columna << "][" << indice_fila << "] = "
                     << matriz_transpuesta[indice_columna][indice_fila] << endl;
            }
        }
    }
    
    // Mostrar la matriz transpuesta
    cout << "\n=== MATRIZ TRANSPUESTA ===" << endl;
    cout << "Dimensiones: " << NUMERO_FILAS_TRANSPUESTA << " filas x " 
         << NUMERO_COLUMNAS_TRANSPUESTA << " columnas" << endl << endl;
    
    for(int indice_fila = 0; indice_fila < NUMERO_FILAS_TRANSPUESTA; indice_fila++) {
        for(int indice_columna = 0; indice_columna < NUMERO_COLUMNAS_TRANSPUESTA; indice_columna++) {
            cout << matriz_transpuesta[indice_fila][indice_columna] << "\t";
        }
        cout << endl;
    }
    
    // Verificación: mostrar cómo las filas se convirtieron en columnas
    cout << "\n--- VERIFICACION ---" << endl;
    cout << "Primera fila de la original: 1, 2, 3, 4" << endl;
    cout << "Primera columna de la transpuesta: ";
    for(int indice_fila = 0; indice_fila < NUMERO_FILAS_TRANSPUESTA; indice_fila++) {
        cout << matriz_transpuesta[indice_fila][0];
        if(indice_fila < NUMERO_FILAS_TRANSPUESTA - 1) cout << ", ";
    }
    cout << endl;
    
    return 0;
}

/*
 * SALIDA ESPERADA:
 * 
 * === MATRIZ ORIGINAL ===
 * Dimensiones: 3 filas x 4 columnas
 * 
 * 1    2    3    4
 * 5    6    7    8
 * 9    10   11   12
 * 
 * --- Proceso de Transposicion ---
 * Original[0][0] = 1 -> Transpuesta[0][0] = 1
 * Original[0][1] = 2 -> Transpuesta[1][0] = 2
 * 
 * === MATRIZ TRANSPUESTA ===
 * Dimensiones: 4 filas x 3 columnas
 * 
 * 1    5    9
 * 2    6    10
 * 3    7    11
 * 4    8    12
 * 
 * --- VERIFICACION ---
 * Primera fila de la original: 1, 2, 3, 4
 * Primera columna de la transpuesta: 1, 2, 3, 4
 * 
 * EXPLICACIÓN VISUAL:
 * 
 * Original (3×4):          Transpuesta (4×3):
 * [1   2   3   4]          [1   5   9]
 * [5   6   7   8]    ->    [2   6  10]
 * [9  10  11  12]          [3   7  11]
 *                          [4   8  12]
 * 
 * Las filas se convierten en columnas y viceversa
 */
