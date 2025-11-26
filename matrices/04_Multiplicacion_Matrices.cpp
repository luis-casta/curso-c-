/*
 * EJERCICIO 4: MULTIPLICACIÓN DE MATRICES (NIVEL MEDIO-DIFÍCIL)
 * 
 * Descripción:
 * Este programa multiplica dos matrices siguiendo las reglas del álgebra lineal.
 * Para multiplicar una matriz A (m×n) por una matriz B (n×p), el número de
 * columnas de A debe ser igual al número de filas de B. El resultado es una
 * matriz C (m×p) donde cada elemento C[i][j] es el producto punto de la
 * fila i de A con la columna j de B.
 * 
 * Fórmula: C[i][j] = Σ(A[i][k] * B[k][j]) para k = 0 hasta n-1
 * 
 * Conceptos que aprenderás:
 * - Multiplicación de matrices
 * - Producto punto de vectores
 * - Bucles triples anidados
 * - Validación de dimensiones compatibles
 * - Acumulación en operaciones complejas
 */

#include <iostream>
using namespace std;

int main() {
    // Dimensiones de la primera matriz A (2×3)
    const int FILAS_MATRIZ_A = 2;
    const int COLUMNAS_MATRIZ_A = 3;
    
    // Dimensiones de la segunda matriz B (3×2)
    const int FILAS_MATRIZ_B = 3;
    const int COLUMNAS_MATRIZ_B = 2;
    
    // Dimensiones de la matriz resultado C (2×2)
    // Filas de A × Columnas de B
    const int FILAS_MATRIZ_RESULTADO = FILAS_MATRIZ_A;
    const int COLUMNAS_MATRIZ_RESULTADO = COLUMNAS_MATRIZ_B;
    
    // Verificación: las matrices son compatibles para multiplicación
    // El número de columnas de A debe ser igual al número de filas de B
    if(COLUMNAS_MATRIZ_A != FILAS_MATRIZ_B) {
        cout << "ERROR: Las matrices no son compatibles para multiplicacion" << endl;
        cout << "Columnas de A (" << COLUMNAS_MATRIZ_A << ") debe ser igual a Filas de B (" 
             << FILAS_MATRIZ_B << ")" << endl;
        return 1;
    }
    
    // Primera matriz A (2×3)
    int matriz_a[FILAS_MATRIZ_A][COLUMNAS_MATRIZ_A] = {
        {1, 2, 3},   // Fila 0 de A
        {4, 5, 6}    // Fila 1 de A
    };
    
    // Segunda matriz B (3×2)
    int matriz_b[FILAS_MATRIZ_B][COLUMNAS_MATRIZ_B] = {
        {7,  8},     // Fila 0 de B
        {9, 10},     // Fila 1 de B
        {11, 12}     // Fila 2 de B
    };
    
    // Matriz resultado C (2×2)
    // Se inicializa con ceros porque iremos acumulando valores
    int matriz_resultado[FILAS_MATRIZ_RESULTADO][COLUMNAS_MATRIZ_RESULTADO] = {0};
    
    // Mostrar la matriz A
    cout << "=== MATRIZ A ===" << endl;
    cout << "Dimensiones: " << FILAS_MATRIZ_A << "x" << COLUMNAS_MATRIZ_A << endl;
    for(int fila = 0; fila < FILAS_MATRIZ_A; fila++) {
        for(int columna = 0; columna < COLUMNAS_MATRIZ_A; columna++) {
            cout << matriz_a[fila][columna] << "\t";
        }
        cout << endl;
    }
    
    // Mostrar la matriz B
    cout << "\n=== MATRIZ B ===" << endl;
    cout << "Dimensiones: " << FILAS_MATRIZ_B << "x" << COLUMNAS_MATRIZ_B << endl;
    for(int fila = 0; fila < FILAS_MATRIZ_B; fila++) {
        for(int columna = 0; columna < COLUMNAS_MATRIZ_B; columna++) {
            cout << matriz_b[fila][columna] << "\t";
        }
        cout << endl;
    }
    
    // OPERACIÓN DE MULTIPLICACIÓN
    cout << "\n--- Proceso de Multiplicacion ---" << endl;
    
    // Bucle triple anidado para la multiplicación
    // Primer bucle: recorre las filas de A
    for(int indice_fila_a = 0; indice_fila_a < FILAS_MATRIZ_A; indice_fila_a++) {
        
        // Segundo bucle: recorre las columnas de B
        for(int indice_columna_b = 0; indice_columna_b < COLUMNAS_MATRIZ_B; indice_columna_b++) {
            
            // Variable para acumular el producto punto
            int suma_productos = 0;
            
            // Tercer bucle: calcula el producto punto
            // Recorre las columnas de A (que es igual a las filas de B)
            for(int indice_k = 0; indice_k < COLUMNAS_MATRIZ_A; indice_k++) {
                // Multiplicar elemento de fila de A con elemento de columna de B
                int producto_parcial = matriz_a[indice_fila_a][indice_k] * 
                                      matriz_b[indice_k][indice_columna_b];
                
                suma_productos += producto_parcial;
                
                // Mostrar el cálculo detallado para el primer elemento
                if(indice_fila_a == 0 && indice_columna_b == 0) {
                    cout << "C[0][0] += A[0][" << indice_k << "] * B[" << indice_k << "][0] = "
                         << matriz_a[indice_fila_a][indice_k] << " * " 
                         << matriz_b[indice_k][indice_columna_b] << " = " 
                         << producto_parcial << endl;
                }
            }
            
            // Asignar el resultado a la matriz C
            matriz_resultado[indice_fila_a][indice_columna_b] = suma_productos;
            
            if(indice_fila_a == 0 && indice_columna_b == 0) {
                cout << "C[0][0] = " << suma_productos << endl << endl;
            }
        }
    }
    
    // Mostrar la matriz resultado
    cout << "=== MATRIZ RESULTADO (A × B) ===" << endl;
    cout << "Dimensiones: " << FILAS_MATRIZ_RESULTADO << "x" << COLUMNAS_MATRIZ_RESULTADO << endl;
    for(int fila = 0; fila < FILAS_MATRIZ_RESULTADO; fila++) {
        for(int columna = 0; columna < COLUMNAS_MATRIZ_RESULTADO; columna++) {
            cout << matriz_resultado[fila][columna] << "\t";
        }
        cout << endl;
    }
    
    // Verificación manual del primer elemento
    cout << "\n--- VERIFICACION MANUAL ---" << endl;
    cout << "C[0][0] = (1×7) + (2×9) + (3×11) = 7 + 18 + 33 = 58" << endl;
    cout << "Valor calculado: " << matriz_resultado[0][0] << endl;
    
    return 0;
}

/*
 * SALIDA ESPERADA:
 * 
 * === MATRIZ A ===
 * Dimensiones: 2x3
 * 1    2    3
 * 4    5    6
 * 
 * === MATRIZ B ===
 * Dimensiones: 3x2
 * 7    8
 * 9    10
 * 11   12
 * 
 * --- Proceso de Multiplicacion ---
 * C[0][0] += A[0][0] * B[0][0] = 1 * 7 = 7
 * C[0][0] += A[0][1] * B[1][0] = 2 * 9 = 18
 * C[0][0] += A[0][2] * B[2][0] = 3 * 11 = 33
 * C[0][0] = 58
 * 
 * === MATRIZ RESULTADO (A × B) ===
 * Dimensiones: 2x2
 * 58   64
 * 139  154
 * 
 * --- VERIFICACION MANUAL ---
 * C[0][0] = (1×7) + (2×9) + (3×11) = 7 + 18 + 33 = 58
 * Valor calculado: 58
 * 
 * EXPLICACIÓN DETALLADA:
 * 
 * Para calcular C[0][0]:
 * - Tomar fila 0 de A: [1, 2, 3]
 * - Tomar columna 0 de B: [7, 9, 11]
 * - Multiplicar elemento por elemento y sumar: (1×7) + (2×9) + (3×11) = 58
 * 
 * Para calcular C[0][1]:
 * - Tomar fila 0 de A: [1, 2, 3]
 * - Tomar columna 1 de B: [8, 10, 12]
 * - Multiplicar elemento por elemento y sumar: (1×8) + (2×10) + (3×12) = 64
 * 
 * Y así sucesivamente para todos los elementos...
 */
