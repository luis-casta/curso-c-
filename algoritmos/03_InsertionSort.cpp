/*
 * ============================================================================
 * ALGORITMO: INSERTION SORT (ORDENAMIENTO POR INSERCIÓN)
 * ============================================================================
 * 
 * DESCRIPCIÓN:
 * El Insertion Sort construye el arreglo ordenado de uno en uno, tomando
 * elementos de la parte desordenada e insertándolos en la posición correcta
 * de la parte ordenada. Similar a ordenar cartas en la mano.
 * 
 * COMPLEJIDAD:
 * - Mejor caso: O(n) cuando el arreglo ya está ordenado
 * - Caso promedio: O(n²)
 * - Peor caso: O(n²) cuando el arreglo está ordenado inversamente
 * 
 * VENTAJAS:
 * - Eficiente para arreglos pequeños o casi ordenados
 * - Estable (mantiene el orden de elementos iguales)
 * - Ordenamiento in-place (no requiere memoria adicional)
 * - Adaptativo (aprovecha el orden existente)
 * 
 * DESVENTAJAS:
 * - Ineficiente para arreglos grandes
 * - Requiere muchos desplazamientos en el peor caso
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

// Función para imprimir el arreglo destacando el elemento a insertar
void imprimirConDestaque(int arreglo[], int tamanio, int posicionDestacada) {
    cout << "[";
    for (int i = 0; i < tamanio; i++) {
        if (i == posicionDestacada) {
            cout << "(" << arreglo[i] << ")";  // Elemento destacado entre paréntesis
        } else {
            cout << arreglo[i];
        }
        if (i < tamanio - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Implementación del algoritmo Insertion Sort
void insertionSort(int arreglo[], int tamanio) {
    // Comenzamos desde el segundo elemento (índice 1)
    // El primer elemento se considera ya ordenado
    for (int i = 1; i < tamanio; i++) {
        cout << "\n--- Iteración " << i << " ---" << endl;
        
        // Guardamos el elemento actual que vamos a insertar
        int elementoActual = arreglo[i];
        cout << "Elemento a insertar: " << elementoActual << endl;
        
        cout << "Estado antes de insertar: ";
        imprimirConDestaque(arreglo, tamanio, i);
        
        // Encontramos la posición correcta para insertar el elemento
        int j = i - 1;
        
        cout << "Buscando posición correcta..." << endl;
        
        // Desplazamos los elementos mayores hacia la derecha
        while (j >= 0 && arreglo[j] > elementoActual) {
            cout << "  Desplazando " << arreglo[j] << " hacia la derecha" << endl;
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        
        // Insertamos el elemento en su posición correcta
        arreglo[j + 1] = elementoActual;
        
        if (j + 1 == i) {
            cout << "El elemento ya estaba en su posición correcta" << endl;
        } else {
            cout << "Insertando " << elementoActual << " en la posición " << (j + 1) << endl;
        }
        
        cout << "Estado después de insertar: ";
        imprimirArreglo(arreglo, tamanio);
    }
}

int main() {
    cout << "============================================" << endl;
    cout << " ALGORITMO: INSERTION SORT (INSERCIÓN)    " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Arreglo desordenado
    cout << "\n--- EJEMPLO 1: Arreglo desordenado ---" << endl;
    int numeros1[] = {12, 11, 13, 5, 6};
    int tamanio1 = sizeof(numeros1) / sizeof(numeros1[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros1, tamanio1);
    cout << "(El primer elemento [12] se considera ordenado)" << endl;
    
    insertionSort(numeros1, tamanio1);
    
    cout << "\n✓ Arreglo completamente ordenado: ";
    imprimirArreglo(numeros1, tamanio1);
    
    // Ejemplo 2: Arreglo casi ordenado (mejor caso)
    cout << "\n\n--- EJEMPLO 2: Arreglo casi ordenado ---" << endl;
    int numeros2[] = {2, 3, 4, 1, 5, 6};
    int tamanio2 = sizeof(numeros2) / sizeof(numeros2[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros2, tamanio2);
    cout << "(Nota: Solo el 1 está fuera de lugar)" << endl;
    
    insertionSort(numeros2, tamanio2);
    
    cout << "\n✓ Arreglo completamente ordenado: ";
    imprimirArreglo(numeros2, tamanio2);
    
    // Ejemplo 3: Arreglo ordenado inversamente (peor caso)
    cout << "\n\n--- EJEMPLO 3: Arreglo invertido (peor caso) ---" << endl;
    int numeros3[] = {5, 4, 3, 2, 1};
    int tamanio3 = sizeof(numeros3) / sizeof(numeros3[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros3, tamanio3);
    
    insertionSort(numeros3, tamanio3);
    
    cout << "\n✓ Arreglo completamente ordenado: ";
    imprimirArreglo(numeros3, tamanio3);
    
    return 0;
}
