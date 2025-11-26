/*
 * EJERCICIO 2: SUMA DE DIAGONAL PRINCIPAL (NIVEL FÁCIL-MEDIO)
 * 
 * Descripción:
 * Este programa calcula la suma de los elementos de la diagonal principal
 * de una matriz cuadrada 3x3. La diagonal principal son los elementos
 * donde el índice de fila es igual al índice de columna.
 * 
 * Conceptos que aprenderás:
 * - Identificar la diagonal principal (i == j)
 * - Acumulación de valores
 * - Matrices cuadradas
 * - Condicionales dentro de bucles anidados
 */

#include <iostream>
using namespace std;

int main() {
    // Tamaño de la matriz cuadrada (mismo número de filas y columnas)
    const int DIMENSION_MATRIZ = 3;
    
    // Declaración e inicialización de una matriz 3x3
    int matriz_cuadrada[DIMENSION_MATRIZ][DIMENSION_MATRIZ] = {
        {1, 2, 3},   // Fila 0: diagonal principal en [0][0] = 1
        {4, 5, 6},   // Fila 1: diagonal principal en [1][1] = 5
        {7, 8, 9}    // Fila 2: diagonal principal en [2][2] = 9
    };
    
    // Variable acumuladora para la suma de la diagonal principal
    // Se inicializa en 0 para ir sumando los elementos
    int suma_diagonal_principal = 0;
    
    // Variable acumuladora para la suma de la diagonal secundaria
    // La diagonal secundaria va de esquina superior derecha a inferior izquierda
    int suma_diagonal_secundaria = 0;
    
    // Mostrar la matriz original
    cout << "Matriz Original:" << endl;
    for(int indice_fila = 0; indice_fila < DIMENSION_MATRIZ; indice_fila++) {
        for(int indice_columna = 0; indice_columna < DIMENSION_MATRIZ; indice_columna++) {
            cout << matriz_cuadrada[indice_fila][indice_columna] << "\t";
        }
        cout << endl;
    }
    
    // Recorrer la matriz para identificar y sumar las diagonales
    cout << "\nElementos de la Diagonal Principal:" << endl;
    for(int indice_fila = 0; indice_fila < DIMENSION_MATRIZ; indice_fila++) {
        for(int indice_columna = 0; indice_columna < DIMENSION_MATRIZ; indice_columna++) {
            // DIAGONAL PRINCIPAL: cuando el índice de fila es igual al de columna
            // Ejemplo: [0][0], [1][1], [2][2]
            if(indice_fila == indice_columna) {
                cout << "Posicion [" << indice_fila << "][" << indice_columna << "] = " 
                     << matriz_cuadrada[indice_fila][indice_columna] << endl;
                
                // Acumular el valor en la suma
                suma_diagonal_principal += matriz_cuadrada[indice_fila][indice_columna];
            }
            
            // DIAGONAL SECUNDARIA: cuando la suma de índices es igual a (dimensión - 1)
            // Para matriz 3x3: i + j = 2
            // Ejemplo: [0][2], [1][1], [2][0]
            if(indice_fila + indice_columna == DIMENSION_MATRIZ - 1) {
                suma_diagonal_secundaria += matriz_cuadrada[indice_fila][indice_columna];
            }
        }
    }
    
    // Mostrar los resultados
    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Suma de la Diagonal Principal: " << suma_diagonal_principal << endl;
    cout << "Suma de la Diagonal Secundaria: " << suma_diagonal_secundaria << endl;
    
    // Calcular y mostrar el promedio de la diagonal principal
    double promedio_diagonal_principal = static_cast<double>(suma_diagonal_principal) / DIMENSION_MATRIZ;
    cout << "Promedio de la Diagonal Principal: " << promedio_diagonal_principal << endl;
    
    return 0;
}

/*
 * SALIDA ESPERADA:
 * 
 * Matriz Original:
 * 1    2    3
 * 4    5    6
 * 7    8    9
 * 
 * Elementos de la Diagonal Principal:
 * Posicion [0][0] = 1
 * Posicion [1][1] = 5
 * Posicion [2][2] = 9
 * 
 * --- RESULTADOS ---
 * Suma de la Diagonal Principal: 15
 * Suma de la Diagonal Secundaria: 15
 * Promedio de la Diagonal Principal: 5
 * 
 * EXPLICACIÓN:
 * Diagonal Principal: 1 + 5 + 9 = 15
 * Diagonal Secundaria: 3 + 5 + 7 = 15
 * 
 * VISUALIZACIÓN:
 * [1]  2  [3]
 *  4  [5]  6
 * [7]  8  [9]
 * 
 * [] = Diagonal Principal
 * [] = Diagonal Secundaria (en este caso [5] pertenece a ambas)
 */
