/*
 * ============================================================================
 * ALGORITMO: SELECTION SORT (ORDENAMIENTO POR SELECCIÓN)
 * ============================================================================
 * 
 * DESCRIPCIÓN:
 * El Selection Sort divide el arreglo en dos partes: ordenada y desordenada.
 * En cada iteración, busca el elemento mínimo de la parte desordenada y
 * lo coloca al final de la parte ordenada.
 * 
 * COMPLEJIDAD:
 * - Mejor caso: O(n²)
 * - Caso promedio: O(n²)
 * - Peor caso: O(n²)
 * 
 * VENTAJAS:
 * - Simple de implementar
 * - Realiza el mínimo número de intercambios (máximo n-1)
 * - No requiere memoria adicional
 * 
 * DESVENTAJAS:
 * - Ineficiente para arreglos grandes
 * - No es estable (puede cambiar el orden de elementos iguales)
 * - Siempre realiza O(n²) comparaciones, incluso si está ordenado
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

// Función para imprimir el arreglo mostrando la parte ordenada
void imprimirArregloConDivision(int arreglo[], int tamanio, int posicionOrdenada) {
    cout << "[";
    for (int i = 0; i < tamanio; i++) {
        if (i == posicionOrdenada && i > 0) {
            cout << " | ";  // Separador entre parte ordenada y desordenada
        }
        cout << arreglo[i];
        if (i < tamanio - 1 && i + 1 != posicionOrdenada) cout << ", ";
    }
    cout << "]" << endl;
}

// Implementación del algoritmo Selection Sort
void selectionSort(int arreglo[], int tamanio) {
    // Recorremos todo el arreglo excepto el último elemento
    for (int i = 0; i < tamanio - 1; i++) {
        cout << "\n--- Pasada " << (i + 1) << " ---" << endl;
        
        // Asumimos que el primer elemento de la parte desordenada es el mínimo
        int indiceMinimo = i;
        
        cout << "Buscando el mínimo desde la posición " << i << "..." << endl;
        
        // Buscamos el elemento mínimo en la parte desordenada
        for (int j = i + 1; j < tamanio; j++) {
            cout << "  Comparando arreglo[" << indiceMinimo << "]=" << arreglo[indiceMinimo]
                 << " con arreglo[" << j << "]=" << arreglo[j];
            
            if (arreglo[j] < arreglo[indiceMinimo]) {
                indiceMinimo = j;
                cout << " -> Nuevo mínimo encontrado: " << arreglo[indiceMinimo] << endl;
            } else {
                cout << " -> Se mantiene el mínimo actual" << endl;
            }
        }
        
        // Si encontramos un mínimo diferente, lo intercambiamos
        if (indiceMinimo != i) {
            cout << "\nIntercambiando arreglo[" << i << "]=" << arreglo[i]
                 << " con arreglo[" << indiceMinimo << "]=" << arreglo[indiceMinimo] << endl;
            
            int temporal = arreglo[i];
            arreglo[i] = arreglo[indiceMinimo];
            arreglo[indiceMinimo] = temporal;
        } else {
            cout << "\nEl elemento ya está en su posición correcta" << endl;
        }
        
        cout << "Estado: ";
        imprimirArregloConDivision(arreglo, tamanio, i + 1);
        cout << "        (ordenado | desordenado)" << endl;
    }
}

int main() {
    cout << "============================================" << endl;
    cout << "  ALGORITMO: SELECTION SORT (SELECCIÓN)   " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Arreglo desordenado
    cout << "\n--- EJEMPLO 1: Arreglo desordenado ---" << endl;
    int numeros1[] = {64, 25, 12, 22, 11};
    int tamanio1 = sizeof(numeros1) / sizeof(numeros1[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros1, tamanio1);
    
    selectionSort(numeros1, tamanio1);
    
    cout << "\n✓ Arreglo completamente ordenado: ";
    imprimirArreglo(numeros1, tamanio1);
    
    // Ejemplo 2: Arreglo con números negativos
    cout << "\n\n--- EJEMPLO 2: Arreglo con negativos ---" << endl;
    int numeros2[] = {-5, 20, -10, 3, 0, -1};
    int tamanio2 = sizeof(numeros2) / sizeof(numeros2[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros2, tamanio2);
    
    selectionSort(numeros2, tamanio2);
    
    cout << "\n✓ Arreglo completamente ordenado: ";
    imprimirArreglo(numeros2, tamanio2);
    
    return 0;
}
