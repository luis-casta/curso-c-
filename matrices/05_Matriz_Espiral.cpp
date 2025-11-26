/*
 * EJERCICIO 5: RECORRIDO EN ESPIRAL DE UNA MATRIZ (NIVEL DIFÍCIL)
 * 
 * Descripción:
 * Este programa recorre una matriz en forma de espiral (en sentido horario)
 * comenzando desde la esquina superior izquierda. El recorrido va hacia la
 * derecha, luego abajo, luego izquierda, luego arriba, y así sucesivamente
 * formando una espiral hasta llegar al centro.
 * 
 * Ejemplo para matriz 4x4:
 *  1  →  2  →  3  →  4
 *                    ↓
 *  12 → 13 → 14    5
 *  ↑              ↓
 *  11   16   15    6
 *  ↑              ↓
 *  10 ←  9  ←  8  ← 7
 * 
 * Orden de recorrido: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
 * 
 * Conceptos que aprenderás:
 * - Algoritmos de recorrido complejo
 * - Manejo de límites dinámicos
 * - Cambio de dirección en recorridos
 * - Lógica de control avanzada
 * - Resolución de problemas algorítmicos
 */

#include <iostream>
using namespace std;

int main() {
    // Dimensiones de la matriz
    const int NUMERO_FILAS = 4;
    const int NUMERO_COLUMNAS = 4;
    
    // Matriz de ejemplo 4x4
    int matriz[NUMERO_FILAS][NUMERO_COLUMNAS] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    // Variables para controlar los límites del recorrido
    // Estos límites se van ajustando a medida que completamos cada "capa" de la espiral
    int limite_fila_superior = 0;           // Límite superior (primera fila a recorrer)
    int limite_fila_inferior = NUMERO_FILAS - 1;  // Límite inferior (última fila a recorrer)
    int limite_columna_izquierda = 0;       // Límite izquierdo (primera columna a recorrer)
    int limite_columna_derecha = NUMERO_COLUMNAS - 1;  // Límite derecho (última columna a recorrer)
    
    // Mostrar la matriz original
    cout << "=== MATRIZ ORIGINAL ===" << endl;
    for(int fila = 0; fila < NUMERO_FILAS; fila++) {
        for(int columna = 0; columna < NUMERO_COLUMNAS; columna++) {
            cout << matriz[fila][columna] << "\t";
        }
        cout << endl;
    }
    
    cout << "\n=== RECORRIDO EN ESPIRAL ===" << endl;
    cout << "Elementos en orden de recorrido: ";
    
    // El recorrido continúa mientras los límites no se crucen
    while(limite_fila_superior <= limite_fila_inferior && 
          limite_columna_izquierda <= limite_columna_derecha) {
        
        // PASO 1: Recorrer de IZQUIERDA a DERECHA en la fila superior
        // Vamos desde la columna izquierda hasta la columna derecha
        // en la fila superior actual
        for(int columna = limite_columna_izquierda; columna <= limite_columna_derecha; columna++) {
            cout << matriz[limite_fila_superior][columna] << " ";
        }
        // Ya recorrimos la fila superior, la movemos hacia abajo
        limite_fila_superior++;
        
        // PASO 2: Recorrer de ARRIBA a ABAJO en la columna derecha
        // Vamos desde la fila superior (ya actualizada) hasta la fila inferior
        // en la columna derecha actual
        for(int fila = limite_fila_superior; fila <= limite_fila_inferior; fila++) {
            cout << matriz[fila][limite_columna_derecha] << " ";
        }
        // Ya recorrimos la columna derecha, la movemos hacia la izquierda
        limite_columna_derecha--;
        
        // PASO 3: Recorrer de DERECHA a IZQUIERDA en la fila inferior
        // Solo si aún quedan filas por recorrer
        if(limite_fila_superior <= limite_fila_inferior) {
            // Vamos desde la columna derecha (ya actualizada) hasta la columna izquierda
            // en la fila inferior actual
            for(int columna = limite_columna_derecha; columna >= limite_columna_izquierda; columna--) {
                cout << matriz[limite_fila_inferior][columna] << " ";
            }
            // Ya recorrimos la fila inferior, la movemos hacia arriba
            limite_fila_inferior--;
        }
        
        // PASO 4: Recorrer de ABAJO a ARRIBA en la columna izquierda
        // Solo si aún quedan columnas por recorrer
        if(limite_columna_izquierda <= limite_columna_derecha) {
            // Vamos desde la fila inferior (ya actualizada) hasta la fila superior
            // en la columna izquierda actual
            for(int fila = limite_fila_inferior; fila >= limite_fila_superior; fila--) {
                cout << matriz[fila][limite_columna_izquierda] << " ";
            }
            // Ya recorrimos la columna izquierda, la movemos hacia la derecha
            limite_columna_izquierda++;
        }
    }
    
    cout << endl;
    
    // Explicación visual del proceso
    cout << "\n=== EXPLICACION DEL RECORRIDO ===" << endl;
    cout << "1. Primera capa (exterior):" << endl;
    cout << "   - Derecha: 1 → 2 → 3 → 4" << endl;
    cout << "   - Abajo: 8 → 12 → 16" << endl;
    cout << "   - Izquierda: 15 ← 14 ← 13" << endl;
    cout << "   - Arriba: 9 ← 5" << endl;
    cout << "\n2. Segunda capa (interior):" << endl;
    cout << "   - Derecha: 6 → 7" << endl;
    cout << "   - Abajo: 11" << endl;
    cout << "   - Izquierda: 10" << endl;
    
    // Estadísticas del recorrido
    int total_elementos = NUMERO_FILAS * NUMERO_COLUMNAS;
    cout << "\n=== ESTADISTICAS ===" << endl;
    cout << "Total de elementos recorridos: " << total_elementos << endl;
    cout << "Dimensiones de la matriz: " << NUMERO_FILAS << "x" << NUMERO_COLUMNAS << endl;
    
    // Calcular número de capas en la espiral
    int numero_capas = (min(NUMERO_FILAS, NUMERO_COLUMNAS) + 1) / 2;
    cout << "Numero de capas en la espiral: " << numero_capas << endl;
    
    return 0;
}

/*
 * SALIDA ESPERADA:
 * 
 * === MATRIZ ORIGINAL ===
 * 1    2    3    4
 * 5    6    7    8
 * 9    10   11   12
 * 13   14   15   16
 * 
 * === RECORRIDO EN ESPIRAL ===
 * Elementos en orden de recorrido: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
 * 
 * === EXPLICACION DEL RECORRIDO ===
 * 1. Primera capa (exterior):
 *    - Derecha: 1 → 2 → 3 → 4
 *    - Abajo: 8 → 12 → 16
 *    - Izquierda: 15 ← 14 ← 13
 *    - Arriba: 9 ← 5
 * 
 * 2. Segunda capa (interior):
 *    - Derecha: 6 → 7
 *    - Abajo: 11
 *    - Izquierda: 10
 * 
 * === ESTADISTICAS ===
 * Total de elementos recorridos: 16
 * Dimensiones de la matriz: 4x4
 * Numero de capas en la espiral: 2
 * 
 * VISUALIZACIÓN DEL RECORRIDO:
 * 
 *  1  →  2  →  3  →  4
 *                    ↓
 *  ↑              ↓  8
 *  5    6  →  7      ↓
 *  ↑         ↓      12
 *  9   10 ← 11       ↓
 *  ↑                16
 * 13 ← 14 ← 15  ←  ←
 * 
 * COMPLEJIDAD:
 * - Tiempo: O(n×m) donde n=filas y m=columnas
 * - Espacio: O(1) (no usamos espacio adicional proporcional al tamaño)
 * 
 * APLICACIONES PRÁCTICAS:
 * - Procesamiento de imágenes
 * - Algoritmos de compresión
 * - Juegos (movimiento de personajes en laberintos)
 * - Impresión de matrices en formatos especiales
 */
