/*
 * ============================================================================
 * ALGORITMO: QUICK SORT (ORDENAMIENTO RÁPIDO)
 * ============================================================================
 * 
 * DESCRIPCIÓN:
 * Quick Sort es un algoritmo de ordenamiento muy eficiente basado en
 * "divide y vencerás". Selecciona un elemento como "pivote" y particiona
 * el arreglo de modo que los elementos menores queden a la izquierda
 * y los mayores a la derecha. Luego ordena recursivamente cada partición.
 * 
 * COMPLEJIDAD:
 * - Mejor caso: O(n log n) cuando las particiones son balanceadas
 * - Caso promedio: O(n log n)
 * - Peor caso: O(n²) cuando el pivote es siempre el menor o mayor elemento
 * 
 * VENTAJAS:
 * - Uno de los algoritmos más rápidos en la práctica
 * - Ordenamiento in-place (usa poca memoria adicional)
 * - Muy eficiente para arreglos grandes
 * - Buen rendimiento en caché
 * 
 * DESVENTAJAS:
 * - No es estable (puede cambiar el orden de elementos iguales)
 * - Peor caso O(n²) si no se elige bien el pivote
 * - Implementación recursiva puede causar stack overflow en casos extremos
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
    cout << "]";
}

// Función para imprimir con indentación
void imprimirIndentado(string mensaje, int nivel) {
    for (int i = 0; i < nivel; i++) {
        cout << "  ";
    }
    cout << mensaje;
}

// Función para intercambiar dos elementos
void intercambiar(int& a, int& b) {
    int temporal = a;
    a = b;
    b = temporal;
}

// Función de partición (Lomuto partition scheme)
int particionar(int arreglo[], int inicio, int fin, int nivel) {
    // Elegimos el último elemento como pivote
    int pivote = arreglo[fin];
    
    imprimirIndentado("", nivel);
    cout << "Pivote seleccionado: " << pivote << endl;
    
    imprimirIndentado("", nivel);
    cout << "Particionando: ";
    for (int k = inicio; k <= fin; k++) {
        cout << arreglo[k];
        if (k < fin) cout << ", ";
    }
    cout << endl;
    
    // Índice del elemento más pequeño
    int i = inicio - 1;
    
    // Recorremos el arreglo y movemos elementos menores al pivote a la izquierda
    for (int j = inicio; j < fin; j++) {
        imprimirIndentado("  ", nivel);
        cout << "Comparando " << arreglo[j] << " con pivote " << pivote;
        
        if (arreglo[j] <= pivote) {
            i++;
            if (i != j) {
                cout << " -> Intercambiando " << arreglo[i] << " ↔ " << arreglo[j];
                intercambiar(arreglo[i], arreglo[j]);
            } else {
                cout << " -> Ya está en posición correcta";
            }
        } else {
            cout << " -> No se mueve";
        }
        cout << endl;
    }
    
    // Colocamos el pivote en su posición final
    intercambiar(arreglo[i + 1], arreglo[fin]);
    
    imprimirIndentado("", nivel);
    cout << "Pivote " << pivote << " colocado en posición " << (i + 1) << endl;
    
    imprimirIndentado("", nivel);
    cout << "Resultado: ";
    for (int k = inicio; k <= fin; k++) {
        if (k == i + 1) {
            cout << "[" << arreglo[k] << "]";  // Pivote en su posición final
        } else {
            cout << arreglo[k];
        }
        if (k < fin) cout << ", ";
    }
    cout << endl;
    
    return i + 1;  // Retornamos la posición del pivote
}

// Función recursiva de Quick Sort
void quickSort(int arreglo[], int inicio, int fin, int nivel = 0) {
    // Caso base: si hay 1 o menos elementos, ya está ordenado
    if (inicio >= fin) {
        return;
    }
    
    imprimirIndentado("", nivel);
    cout << "┌─ Ordenando subarreglo: ";
    for (int i = inicio; i <= fin; i++) {
        cout << arreglo[i];
        if (i < fin) cout << ", ";
    }
    cout << endl;
    
    // Particionamos el arreglo y obtenemos la posición del pivote
    int indicePivote = particionar(arreglo, inicio, fin, nivel);
    
    // Ordenamos recursivamente la partición izquierda (menores que el pivote)
    if (indicePivote - 1 > inicio) {
        imprimirIndentado("", nivel);
        cout << "├─ Subárbol izquierdo (menores que " << arreglo[indicePivote] << ")" << endl;
        quickSort(arreglo, inicio, indicePivote - 1, nivel + 1);
    }
    
    // Ordenamos recursivamente la partición derecha (mayores que el pivote)
    if (indicePivote + 1 < fin) {
        imprimirIndentado("", nivel);
        cout << "└─ Subárbol derecho (mayores que " << arreglo[indicePivote] << ")" << endl;
        quickSort(arreglo, indicePivote + 1, fin, nivel + 1);
    }
}

int main() {
    cout << "============================================" << endl;
    cout << "   ALGORITMO: QUICK SORT (RÁPIDO)         " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Arreglo pequeño para visualizar el proceso
    cout << "\n--- EJEMPLO 1: Visualización del proceso ---" << endl;
    int numeros1[] = {10, 7, 8, 9, 1, 5};
    int tamanio1 = sizeof(numeros1) / sizeof(numeros1[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros1, tamanio1);
    cout << endl << endl;
    
    cout << "Proceso de ordenamiento:" << endl;
    cout << "========================" << endl;
    quickSort(numeros1, 0, tamanio1 - 1);
    
    cout << "\n✓ Arreglo ordenado: ";
    imprimirArreglo(numeros1, tamanio1);
    cout << endl;
    
    // Ejemplo 2: Arreglo más grande
    cout << "\n\n--- EJEMPLO 2: Arreglo más complejo ---" << endl;
    int numeros2[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanio2 = sizeof(numeros2) / sizeof(numeros2[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros2, tamanio2);
    cout << endl << endl;
    
    quickSort(numeros2, 0, tamanio2 - 1);
    
    cout << "\n✓ Arreglo ordenado: ";
    imprimirArreglo(numeros2, tamanio2);
    cout << endl;
    
    // Ejemplo 3: Con números negativos
    cout << "\n\n--- EJEMPLO 3: Con números negativos ---" << endl;
    int numeros3[] = {-5, 20, -10, 3, 0, -1};
    int tamanio3 = sizeof(numeros3) / sizeof(numeros3[0]);
    
    cout << "Arreglo original: ";
    imprimirArreglo(numeros3, tamanio3);
    cout << endl << endl;
    
    quickSort(numeros3, 0, tamanio3 - 1);
    
    cout << "\n✓ Arreglo ordenado: ";
    imprimirArreglo(numeros3, tamanio3);
    cout << endl;
    
    // Análisis de complejidad
    cout << "\n\n--- ANÁLISIS DE COMPLEJIDAD ---" << endl;
    cout << "\nQuick Sort utiliza 'Divide y Vencerás' con particionamiento:" << endl;
    cout << "1. PIVOTE: Selecciona un elemento como pivote" << endl;
    cout << "2. PARTICIONA: Reorganiza para que menores estén a la izquierda" << endl;
    cout << "3. RECURSIÓN: Ordena recursivamente cada partición" << endl;
    
    cout << "\nCaso promedio: O(n log n)" << endl;
    cout << "  • Particiones balanceadas" << endl;
    cout << "  • Muy eficiente en la práctica" << endl;
    
    cout << "\nPeor caso: O(n²)" << endl;
    cout << "  • Ocurre cuando el arreglo ya está ordenado" << endl;
    cout << "  • Pivote siempre es el menor o mayor elemento" << endl;
    cout << "  • Se puede evitar con selección aleatoria del pivote" << endl;
    
    cout << "\n¡Quick Sort es generalmente el más rápido en la práctica!" << endl;
    
    return 0;
}
