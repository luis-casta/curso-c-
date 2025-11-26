/*
 * ============================================================================
 * ALGORITMO: BÚSQUEDA BINARIA (BINARY SEARCH)
 * ============================================================================
 * 
 * DESCRIPCIÓN:
 * La búsqueda binaria es un algoritmo eficiente que funciona dividiendo
 * repetidamente el espacio de búsqueda a la mitad. Compara el elemento
 * buscado con el elemento del medio y descarta la mitad donde no puede estar.
 * 
 * REQUISITO IMPORTANTE: El arreglo DEBE estar ordenado.
 * 
 * COMPLEJIDAD:
 * - Mejor caso: O(1) cuando el elemento está en el medio
 * - Caso promedio: O(log n)
 * - Peor caso: O(log n)
 * 
 * VENTAJAS:
 * - Muy eficiente para arreglos grandes ordenados
 * - Reduce drásticamente el número de comparaciones
 * - Mucho más rápido que la búsqueda lineal
 * 
 * DESVENTAJAS:
 * - Requiere que el arreglo esté ordenado
 * - Más complejo de implementar que la búsqueda lineal
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

// Función para imprimir el rango de búsqueda actual
void imprimirRango(int arreglo[], int inicio, int fin, int medio) {
    cout << "  Rango actual: [";
    for (int i = inicio; i <= fin; i++) {
        if (i == medio) {
            cout << "(" << arreglo[i] << ")";  // Elemento del medio destacado
        } else {
            cout << arreglo[i];
        }
        if (i < fin) cout << ", ";
    }
    cout << "]" << endl;
}

// Implementación iterativa de búsqueda binaria
int busquedaBinariaIterativa(int arreglo[], int tamanio, int elementoBuscado) {
    int inicio = 0;
    int fin = tamanio - 1;
    int iteracion = 1;
    
    cout << "\nBuscando el elemento: " << elementoBuscado << endl;
    cout << "Método: Iterativo" << endl;
    
    while (inicio <= fin) {
        cout << "\n--- Iteración " << iteracion << " ---" << endl;
        
        // Calculamos el índice del medio
        int medio = inicio + (fin - inicio) / 2;
        
        cout << "  Inicio: " << inicio << ", Fin: " << fin << ", Medio: " << medio << endl;
        imprimirRango(arreglo, inicio, fin, medio);
        cout << "  Elemento del medio: " << arreglo[medio] << endl;
        
        // Verificamos si encontramos el elemento
        if (arreglo[medio] == elementoBuscado) {
            cout << "  ¡ENCONTRADO en la posición " << medio << "!" << endl;
            return medio;
        }
        
        // Si el elemento buscado es menor, descartamos la mitad derecha
        if (arreglo[medio] > elementoBuscado) {
            cout << "  " << elementoBuscado << " < " << arreglo[medio] 
                 << " -> Descartando mitad derecha" << endl;
            fin = medio - 1;
        }
        // Si el elemento buscado es mayor, descartamos la mitad izquierda
        else {
            cout << "  " << elementoBuscado << " > " << arreglo[medio] 
                 << " -> Descartando mitad izquierda" << endl;
            inicio = medio + 1;
        }
        
        iteracion++;
    }
    
    cout << "\n  Elemento no encontrado en el arreglo" << endl;
    return -1;
}

// Implementación recursiva de búsqueda binaria
int busquedaBinariaRecursiva(int arreglo[], int inicio, int fin, int elementoBuscado, int nivel = 1) {
    // Caso base: si inicio > fin, el elemento no existe
    if (inicio > fin) {
        return -1;
    }
    
    // Calculamos el índice del medio
    int medio = inicio + (fin - inicio) / 2;
    
    cout << "\n  Nivel de recursión " << nivel << ":" << endl;
    cout << "    Inicio: " << inicio << ", Fin: " << fin << ", Medio: " << medio << endl;
    cout << "    Elemento del medio: " << arreglo[medio] << endl;
    
    // Caso base: encontramos el elemento
    if (arreglo[medio] == elementoBuscado) {
        cout << "    ¡ENCONTRADO!" << endl;
        return medio;
    }
    
    // Llamada recursiva en la mitad izquierda
    if (arreglo[medio] > elementoBuscado) {
        cout << "    Buscando en mitad izquierda..." << endl;
        return busquedaBinariaRecursiva(arreglo, inicio, medio - 1, elementoBuscado, nivel + 1);
    }
    
    // Llamada recursiva en la mitad derecha
    cout << "    Buscando en mitad derecha..." << endl;
    return busquedaBinariaRecursiva(arreglo, medio + 1, fin, elementoBuscado, nivel + 1);
}

int main() {
    cout << "============================================" << endl;
    cout << "    ALGORITMO: BÚSQUEDA BINARIA            " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Búsqueda iterativa exitosa
    cout << "\n--- EJEMPLO 1: Búsqueda iterativa ---" << endl;
    int numeros1[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int tamanio1 = sizeof(numeros1) / sizeof(numeros1[0]);
    
    cout << "Arreglo ordenado: ";
    imprimirArreglo(numeros1, tamanio1);
    
    int resultado1 = busquedaBinariaIterativa(numeros1, tamanio1, 23);
    
    if (resultado1 != -1) {
        cout << "\n✓ Elemento encontrado en el índice: " << resultado1 << endl;
    }
    
    // Ejemplo 2: Búsqueda recursiva
    cout << "\n\n--- EJEMPLO 2: Búsqueda recursiva ---" << endl;
    int numeros2[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int tamanio2 = sizeof(numeros2) / sizeof(numeros2[0]);
    
    cout << "Arreglo ordenado: ";
    imprimirArreglo(numeros2, tamanio2);
    
    cout << "\nBuscando el elemento: 13" << endl;
    cout << "Método: Recursivo" << endl;
    
    int resultado2 = busquedaBinariaRecursiva(numeros2, 0, tamanio2 - 1, 13);
    
    if (resultado2 != -1) {
        cout << "\n✓ Elemento encontrado en el índice: " << resultado2 << endl;
    }
    
    // Ejemplo 3: Elemento no encontrado
    cout << "\n\n--- EJEMPLO 3: Elemento no encontrado ---" << endl;
    int numeros3[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int tamanio3 = sizeof(numeros3) / sizeof(numeros3[0]);
    
    cout << "Arreglo ordenado: ";
    imprimirArreglo(numeros3, tamanio3);
    
    int resultado3 = busquedaBinariaIterativa(numeros3, tamanio3, 25);
    
    if (resultado3 == -1) {
        cout << "\n✗ Elemento no encontrado" << endl;
    }
    
    // Ejemplo 4: Comparación de eficiencia
    cout << "\n\n--- EJEMPLO 4: Eficiencia vs Búsqueda Lineal ---" << endl;
    cout << "\nPara un arreglo de 1,000,000 elementos:" << endl;
    cout << "  • Búsqueda Lineal: hasta 1,000,000 comparaciones" << endl;
    cout << "  • Búsqueda Binaria: máximo 20 comparaciones (log₂ 1,000,000)" << endl;
    cout << "\nPara un arreglo de 1,000,000,000 elementos:" << endl;
    cout << "  • Búsqueda Lineal: hasta 1,000,000,000 comparaciones" << endl;
    cout << "  • Búsqueda Binaria: máximo 30 comparaciones (log₂ 1,000,000,000)" << endl;
    
    cout << "\n¡La búsqueda binaria es exponencialmente más rápida!" << endl;
    
    return 0;
}
