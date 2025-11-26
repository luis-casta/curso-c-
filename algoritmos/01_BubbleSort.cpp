/*
 * ============================================================================
 * ALGORITMO: BUBBLE SORT (ORDENAMIENTO BURBUJA)
 * ============================================================================
 * 
 * DESCRIPCIÓN:
 * El Bubble Sort es uno de los algoritmos de ordenamiento más simples.
 * Funciona comparando repetidamente pares de elementos adyacentes y
 * intercambiándolos si están en el orden incorrecto.
 * 
 * COMPLEJIDAD:
 * - Mejor caso: O(n) cuando el arreglo ya está ordenado
 * - Caso promedio: O(n²)
 * - Peor caso: O(n²)
 * 
 * VENTAJAS:
 * - Simple de entender e implementar
 * - No requiere memoria adicional (ordenamiento in-place)
 * - Estable (mantiene el orden relativo de elementos iguales)
 * 
 * DESVENTAJAS:
 * - Muy ineficiente para arreglos grandes
 * - Realiza muchas comparaciones innecesarias
 * ============================================================================
 */

#include <iostream>
using namespace std;

// Función para imprimir el arreglo
void imprimirArreglo(int arreglo[], int tamanio) {
    cout << "[";
    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i];
        if (i < tamanio - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Implementación del algoritmo Bubble Sort
void bubbleSort(int arreglo[], int tamanio) {
    // Variable para optimizar el algoritmo
    bool huboIntercambio;
    
    // Pasadas externas: necesitamos n-1 pasadas para ordenar n elementos
    for (int i = 0; i < tamanio - 1; i++) {
        huboIntercambio = false;
        
        cout << "\n--- Pasada " << (i + 1) << " ---" << endl;
        
        // Pasadas internas: comparamos elementos adyacentes
        // En cada pasada, el elemento más grande "burbujea" hacia el final
        for (int j = 0; j < tamanio - i - 1; j++) {
            cout << "Comparando " << arreglo[j] << " con " << arreglo[j + 1];
            
            // Si el elemento actual es mayor que el siguiente, los intercambiamos
            if (arreglo[j] > arreglo[j + 1]) {
                // Intercambio usando variable temporal
                int temporal = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temporal;
                
                huboIntercambio = true;
                cout << " -> Intercambio realizado" << endl;
            } else {
                cout << " -> No se intercambia" << endl;
            }
        }
        
        cout << "Estado del arreglo: ";
        imprimirArreglo(arreglo, tamanio);
        
        // Optimización: si no hubo intercambios, el arreglo ya está ordenado
        if (!huboIntercambio) {
            cout << "\n¡El arreglo ya está ordenado! Terminando anticipadamente." << endl;
            break;
        }
    }
}

int main() {
    cout << "============================================" << endl;
    cout << "   ALGORITMO: BUBBLE SORT (BURBUJA)       " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Arreglo desordenado
    cout << "\n--- EJEMPLO 1: Arreglo desordenado ---" << endl;
    int numeros1[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanio1 = sizeof(numeros1) / sizeof(numeros1[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros1, tamanio1);
    
    bubbleSort(numeros1, tamanio1);
    
    cout << "\nArreglo ordenado: ";
    imprimirArreglo(numeros1, tamanio1);
    
    // Ejemplo 2: Arreglo casi ordenado (para ver la optimización)
    cout << "\n\n--- EJEMPLO 2: Arreglo casi ordenado ---" << endl;
    int numeros2[] = {1, 2, 3, 5, 4, 6};
    int tamanio2 = sizeof(numeros2) / sizeof(numeros2[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros2, tamanio2);
    
    bubbleSort(numeros2, tamanio2);
    
    cout << "\nArreglo ordenado: ";
    imprimirArreglo(numeros2, tamanio2);
    
    return 0;
}
