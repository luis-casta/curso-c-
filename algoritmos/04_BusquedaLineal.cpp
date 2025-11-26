/*
 * ============================================================================
 * ALGORITMO: BÚSQUEDA LINEAL (LINEAR SEARCH)
 * ============================================================================
 * 
 * DESCRIPCIÓN:
 * La búsqueda lineal es el algoritmo de búsqueda más simple. Recorre
 * secuencialmente cada elemento del arreglo hasta encontrar el elemento
 * buscado o llegar al final del arreglo.
 * 
 * COMPLEJIDAD:
 * - Mejor caso: O(1) cuando el elemento está en la primera posición
 * - Caso promedio: O(n)
 * - Peor caso: O(n) cuando el elemento está al final o no existe
 * 
 * VENTAJAS:
 * - Muy simple de implementar
 * - Funciona en arreglos ordenados y desordenados
 * - No requiere preparación previa de los datos
 * - Útil para arreglos pequeños
 * 
 * DESVENTAJAS:
 * - Ineficiente para arreglos grandes
 * - Siempre revisa elementos uno por uno
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

// Implementación básica de búsqueda lineal
int busquedaLineal(int arreglo[], int tamanio, int elementoBuscado) {
    cout << "\nBuscando el elemento: " << elementoBuscado << endl;
    cout << "Recorriendo el arreglo..." << endl;
    
    // Recorremos cada elemento del arreglo
    for (int i = 0; i < tamanio; i++) {
        cout << "  Posición " << i << ": " << arreglo[i];
        
        // Comparamos el elemento actual con el buscado
        if (arreglo[i] == elementoBuscado) {
            cout << " -> ¡ENCONTRADO!" << endl;
            return i;  // Retornamos el índice donde se encontró
        } else {
            cout << " -> No coincide, continuando..." << endl;
        }
    }
    
    // Si llegamos aquí, el elemento no existe en el arreglo
    cout << "  Elemento no encontrado en el arreglo" << endl;
    return -1;  // Retornamos -1 para indicar que no se encontró
}

// Versión mejorada que cuenta las comparaciones
int busquedaLinealConContador(int arreglo[], int tamanio, int elementoBuscado, int &comparaciones) {
    comparaciones = 0;
    
    for (int i = 0; i < tamanio; i++) {
        comparaciones++;
        if (arreglo[i] == elementoBuscado) {
            return i;
        }
    }
    
    return -1;
}

// Búsqueda de todas las ocurrencias de un elemento
void buscarTodasLasOcurrencias(int arreglo[], int tamanio, int elementoBuscado) {
    cout << "\nBuscando TODAS las ocurrencias de: " << elementoBuscado << endl;
    
    int ocurrenciasEncontradas = 0;
    cout << "Posiciones encontradas: ";
    
    for (int i = 0; i < tamanio; i++) {
        if (arreglo[i] == elementoBuscado) {
            cout << i << " ";
            ocurrenciasEncontradas++;
        }
    }
    
    if (ocurrenciasEncontradas == 0) {
        cout << "Ninguna";
    }
    
    cout << "\nTotal de ocurrencias: " << ocurrenciasEncontradas << endl;
}

int main() {
    cout << "============================================" << endl;
    cout << "    ALGORITMO: BÚSQUEDA LINEAL             " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Búsqueda exitosa
    cout << "\n--- EJEMPLO 1: Búsqueda exitosa ---" << endl;
    int numeros1[] = {10, 23, 45, 70, 11, 15};
    int tamanio1 = sizeof(numeros1) / sizeof(numeros1[0]);
    
    cout << "Arreglo: ";
    imprimirArreglo(numeros1, tamanio1);
    
    int resultado1 = busquedaLineal(numeros1, tamanio1, 70);
    
    if (resultado1 != -1) {
        cout << "\n✓ Elemento encontrado en el índice: " << resultado1 << endl;
    }
    
    // Ejemplo 2: Búsqueda fallida
    cout << "\n\n--- EJEMPLO 2: Búsqueda fallida ---" << endl;
    int numeros2[] = {5, 12, 18, 25, 33};
    int tamanio2 = sizeof(numeros2) / sizeof(numeros2[0]);
    
    cout << "Arreglo: ";
    imprimirArreglo(numeros2, tamanio2);
    
    int resultado2 = busquedaLineal(numeros2, tamanio2, 100);
    
    if (resultado2 == -1) {
        cout << "\n✗ Elemento no encontrado en el arreglo" << endl;
    }
    
    // Ejemplo 3: Comparación de eficiencia
    cout << "\n\n--- EJEMPLO 3: Análisis de eficiencia ---" << endl;
    int numeros3[] = {3, 7, 1, 9, 4, 6, 2, 8, 5};
    int tamanio3 = sizeof(numeros3) / sizeof(numeros3[0]);
    
    cout << "Arreglo: ";
    imprimirArreglo(numeros3, tamanio3);
    
    int comparaciones;
    
    // Mejor caso: elemento al inicio
    busquedaLinealConContador(numeros3, tamanio3, 3, comparaciones);
    cout << "\nBúsqueda de 3 (primer elemento): " << comparaciones << " comparaciones" << endl;
    
    // Caso promedio: elemento en el medio
    busquedaLinealConContador(numeros3, tamanio3, 6, comparaciones);
    cout << "Búsqueda de 6 (elemento medio): " << comparaciones << " comparaciones" << endl;
    
    // Peor caso: elemento al final
    busquedaLinealConContador(numeros3, tamanio3, 5, comparaciones);
    cout << "Búsqueda de 5 (último elemento): " << comparaciones << " comparaciones" << endl;
    
    // Peor caso: elemento no existe
    busquedaLinealConContador(numeros3, tamanio3, 99, comparaciones);
    cout << "Búsqueda de 99 (no existe): " << comparaciones << " comparaciones" << endl;
    
    // Ejemplo 4: Búsqueda de múltiples ocurrencias
    cout << "\n\n--- EJEMPLO 4: Múltiples ocurrencias ---" << endl;
    int numeros4[] = {5, 2, 8, 2, 9, 2, 1, 2};
    int tamanio4 = sizeof(numeros4) / sizeof(numeros4[0]);
    
    cout << "Arreglo: ";
    imprimirArreglo(numeros4, tamanio4);
    
    buscarTodasLasOcurrencias(numeros4, tamanio4, 2);
    
    return 0;
}
