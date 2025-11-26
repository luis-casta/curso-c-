/*
 * ============================================================================
 * ALGORITMO: MERGE SORT (ORDENAMIENTO POR MEZCLA)
 * ============================================================================
 * 
 * DESCRIPCIÓN:
 * Merge Sort es un algoritmo de ordenamiento basado en la técnica de
 * "divide y vencerás". Divide el arreglo en mitades, ordena cada mitad
 * recursivamente y luego las combina (merge) en orden.
 * 
 * COMPLEJIDAD:
 * - Mejor caso: O(n log n)
 * - Caso promedio: O(n log n)
 * - Peor caso: O(n log n)
 * 
 * VENTAJAS:
 * - Complejidad garantizada O(n log n) en todos los casos
 * - Estable (mantiene el orden de elementos iguales)
 * - Predecible y eficiente para arreglos grandes
 * - Excelente para ordenar listas enlazadas
 * 
 * DESVENTAJAS:
 * - Requiere memoria adicional O(n) para el arreglo temporal
 * - Más lento que Quick Sort en la práctica para arreglos pequeños
 * - No es ordenamiento in-place
 * ============================================================================
 */

#include <iostream>
using namespace std;

// Contador global para visualizar el proceso
int nivelRecursion = 0;

// Función para imprimir el arreglo
void imprimirArreglo(int arreglo[], int tamanio) {
    cout << "[";
    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i];
        if (i < tamanio - 1) cout << ", ";
    }
    cout << "]";
}

// Función para imprimir con indentación según el nivel de recursión
void imprimirIndentado(string mensaje, int nivel) {
    for (int i = 0; i < nivel; i++) {
        cout << "  ";
    }
    cout << mensaje;
}

// Función para combinar (merge) dos subarreglos ordenados
void merge(int arreglo[], int inicio, int medio, int fin, int nivel) {
    // Calculamos los tamaños de los dos subarreglos
    int tamanioIzquierdo = medio - inicio + 1;
    int tamanioDerecho = fin - medio;
    
    // Creamos arreglos temporales
    int* izquierdo = new int[tamanioIzquierdo];
    int* derecho = new int[tamanioDerecho];
    
    // Copiamos los datos a los arreglos temporales
    for (int i = 0; i < tamanioIzquierdo; i++) {
        izquierdo[i] = arreglo[inicio + i];
    }
    for (int j = 0; j < tamanioDerecho; j++) {
        derecho[j] = arreglo[medio + 1 + j];
    }
    
    imprimirIndentado("", nivel);
    cout << "Mezclando: ";
    imprimirArreglo(izquierdo, tamanioIzquierdo);
    cout << " + ";
    imprimirArreglo(derecho, tamanioDerecho);
    cout << endl;
    
    // Índices para recorrer los arreglos
    int i = 0;      // Índice del subarreglo izquierdo
    int j = 0;      // Índice del subarreglo derecho
    int k = inicio; // Índice del arreglo principal
    
    // Mezclamos los elementos en orden
    while (i < tamanioIzquierdo && j < tamanioDerecho) {
        if (izquierdo[i] <= derecho[j]) {
            arreglo[k] = izquierdo[i];
            i++;
        } else {
            arreglo[k] = derecho[j];
            j++;
        }
        k++;
    }
    
    // Copiamos los elementos restantes del subarreglo izquierdo (si hay)
    while (i < tamanioIzquierdo) {
        arreglo[k] = izquierdo[i];
        i++;
        k++;
    }
    
    // Copiamos los elementos restantes del subarreglo derecho (si hay)
    while (j < tamanioDerecho) {
        arreglo[k] = derecho[j];
        j++;
        k++;
    }
    
    imprimirIndentado("", nivel);
    cout << "Resultado: ";
    for (int idx = inicio; idx <= fin; idx++) {
        cout << arreglo[idx];
        if (idx < fin) cout << ", ";
    }
    cout << endl;
    
    // Liberamos la memoria de los arreglos temporales
    delete[] izquierdo;
    delete[] derecho;
}

// Función recursiva de Merge Sort
void mergeSort(int arreglo[], int inicio, int fin, int nivel = 0) {
    // Caso base: si hay 1 o menos elementos, ya está ordenado
    if (inicio >= fin) {
        return;
    }
    
    imprimirIndentado("", nivel);
    cout << "Dividiendo: ";
    for (int i = inicio; i <= fin; i++) {
        cout << arreglo[i];
        if (i < fin) cout << ", ";
    }
    cout << endl;
    
    // Encontramos el punto medio
    int medio = inicio + (fin - inicio) / 2;
    
    // Ordenamos recursivamente la primera mitad
    imprimirIndentado("", nivel);
    cout << "↓ Mitad izquierda" << endl;
    mergeSort(arreglo, inicio, medio, nivel + 1);
    
    // Ordenamos recursivamente la segunda mitad
    imprimirIndentado("", nivel);
    cout << "↓ Mitad derecha" << endl;
    mergeSort(arreglo, medio + 1, fin, nivel + 1);
    
    // Combinamos las dos mitades ordenadas
    imprimirIndentado("", nivel);
    cout << "↑ Combinando mitades" << endl;
    merge(arreglo, inicio, medio, fin, nivel);
}

int main() {
    cout << "============================================" << endl;
    cout << "   ALGORITMO: MERGE SORT (MEZCLA)         " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Arreglo pequeño para visualizar el proceso
    cout << "\n--- EJEMPLO 1: Visualización del proceso ---" << endl;
    int numeros1[] = {38, 27, 43, 3, 9, 82, 10};
    int tamanio1 = sizeof(numeros1) / sizeof(numeros1[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros1, tamanio1);
    cout << endl << endl;
    
    cout << "Proceso de ordenamiento:" << endl;
    cout << "========================" << endl;
    mergeSort(numeros1, 0, tamanio1 - 1);
    
    cout << "\n✓ Arreglo ordenado: ";
    imprimirArreglo(numeros1, tamanio1);
    cout << endl;
    
    // Ejemplo 2: Arreglo con números negativos
    cout << "\n\n--- EJEMPLO 2: Con números negativos ---" << endl;
    int numeros2[] = {-5, 20, -10, 3, 0, -1, 15};
    int tamanio2 = sizeof(numeros2) / sizeof(numeros2[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros2, tamanio2);
    cout << endl << endl;
    
    mergeSort(numeros2, 0, tamanio2 - 1);
    
    cout << "\n✓ Arreglo ordenado: ";
    imprimirArreglo(numeros2, tamanio2);
    cout << endl;
    
    // Ejemplo 3: Análisis de complejidad
    cout << "\n\n--- ANÁLISIS DE COMPLEJIDAD ---" << endl;
    cout << "\nMerge Sort utiliza la estrategia 'Divide y Vencerás':" << endl;
    cout << "1. DIVIDE: Divide el arreglo en dos mitades" << endl;
    cout << "2. VENCERÁS: Ordena recursivamente cada mitad" << endl;
    cout << "3. COMBINA: Mezcla las dos mitades ordenadas" << endl;
    
    cout << "\nNúmero de divisiones: log₂(n)" << endl;
    cout << "Trabajo en cada nivel: n comparaciones" << endl;
    cout << "Complejidad total: O(n log n)" << endl;
    
    cout << "\nEjemplo con n = 8 elementos:" << endl;
    cout << "  • Niveles de recursión: log₂(8) = 3" << endl;
    cout << "  • Comparaciones por nivel: ~8" << endl;
    cout << "  • Total aproximado: 8 × 3 = 24 operaciones" << endl;
    
    return 0;
}
