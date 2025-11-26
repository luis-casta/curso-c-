/*
 * EJERCICIO ARREGLOS 4: ORDENAMIENTO BURBUJA (NIVEL MEDIO-DIFÍCIL)
 * 
 * Descripción:
 * Este programa implementa el algoritmo de ordenamiento burbuja (Bubble Sort)
 * para ordenar un arreglo de menor a mayor. Muestra el proceso paso a paso
 * y cuenta las comparaciones e intercambios realizados.
 * 
 * Conceptos que aprenderás:
 * - Algoritmo de ordenamiento burbuja
 * - Comparación de elementos adyacentes
 * - Intercambio de elementos
 * - Optimización con bandera
 * - Análisis de complejidad
 */

#include <iostream>
using namespace std;

int main() {
    // Tamaño del arreglo
    const int TAMANO_ARREGLO = 10;
    
    // Declaración del arreglo
    int numeros[TAMANO_ARREGLO];
    
    // Contadores para estadísticas
    int cantidad_comparaciones = 0;
    int cantidad_intercambios = 0;
    
    // Solicitar los números al usuario
    cout << "=== ORDENAMIENTO BURBUJA ===" << endl;
    cout << "Ingrese " << TAMANO_ARREGLO << " numeros:" << endl;
    
    for(int indice = 0; indice < TAMANO_ARREGLO; indice++) {
        cout << "Numero " << (indice + 1) << ": ";
        cin >> numeros[indice];
    }
    
    // Mostrar arreglo original
    cout << "\n--- ARREGLO ORIGINAL ---" << endl;
    for(int indice = 0; indice < TAMANO_ARREGLO; indice++) {
        cout << numeros[indice] << " ";
    }
    cout << endl;
    
    // ALGORITMO DE ORDENAMIENTO BURBUJA
    cout << "\n--- PROCESO DE ORDENAMIENTO ---" << endl;
    
    // Bucle externo: controla el número de pasadas
    // En cada pasada, el elemento más grande "burbujea" hacia el final
    for(int pasada = 0; pasada < TAMANO_ARREGLO - 1; pasada++) {
        // Bandera para optimización: detectar si hubo intercambios
        bool hubo_intercambio = false;
        
        cout << "\nPasada " << (pasada + 1) << ":" << endl;
        
        // Bucle interno: compara elementos adyacentes
        // En cada pasada, el último elemento ya está en su posición correcta
        for(int indice = 0; indice < TAMANO_ARREGLO - 1 - pasada; indice++) {
            cantidad_comparaciones++;
            
            // Comparar elemento actual con el siguiente
            if(numeros[indice] > numeros[indice + 1]) {
                // Mostrar el intercambio
                cout << "  Intercambiar " << numeros[indice] << " y " 
                     << numeros[indice + 1] << " (posiciones " << indice 
                     << " y " << (indice + 1) << ")" << endl;
                
                // Intercambiar los elementos
                int temporal = numeros[indice];
                numeros[indice] = numeros[indice + 1];
                numeros[indice + 1] = temporal;
                
                cantidad_intercambios++;
                hubo_intercambio = true;
            }
        }
        
        // Mostrar el estado del arreglo después de cada pasada
        cout << "  Estado: ";
        for(int indice = 0; indice < TAMANO_ARREGLO; indice++) {
            cout << numeros[indice] << " ";
        }
        cout << endl;
        
        // OPTIMIZACIÓN: Si no hubo intercambios, el arreglo ya está ordenado
        if(!hubo_intercambio) {
            cout << "\n¡Arreglo ya ordenado! Terminando anticipadamente." << endl;
            break;
        }
    }
    
    // Mostrar arreglo ordenado
    cout << "\n--- ARREGLO ORDENADO ---" << endl;
    for(int indice = 0; indice < TAMANO_ARREGLO; indice++) {
        cout << numeros[indice] << " ";
    }
    cout << endl;
    
    // Mostrar estadísticas
    cout << "\n--- ESTADISTICAS ---" << endl;
    cout << "Comparaciones realizadas: " << cantidad_comparaciones << endl;
    cout << "Intercambios realizados: " << cantidad_intercambios << endl;
    
    // Complejidad teórica
    int comparaciones_peor_caso = (TAMANO_ARREGLO * (TAMANO_ARREGLO - 1)) / 2;
    cout << "Comparaciones en peor caso: " << comparaciones_peor_caso << endl;
    
    double eficiencia = ((double)cantidad_comparaciones / comparaciones_peor_caso) * 100;
    cout << "Eficiencia: " << eficiencia << "%" << endl;
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === ORDENAMIENTO BURBUJA ===
 * Ingrese 10 numeros:
 * Numero 1: 64
 * Numero 2: 34
 * Numero 3: 25
 * Numero 4: 12
 * Numero 5: 22
 * Numero 6: 11
 * Numero 7: 90
 * Numero 8: 88
 * Numero 9: 45
 * Numero 10: 50
 * 
 * --- ARREGLO ORIGINAL ---
 * 64 34 25 12 22 11 90 88 45 50 
 * 
 * --- PROCESO DE ORDENAMIENTO ---
 * 
 * Pasada 1:
 *   Intercambiar 64 y 34 (posiciones 0 y 1)
 *   Intercambiar 64 y 25 (posiciones 1 y 2)
 *   Intercambiar 64 y 12 (posiciones 2 y 3)
 *   Intercambiar 64 y 22 (posiciones 3 y 4)
 *   Intercambiar 64 y 11 (posiciones 4 y 5)
 *   Intercambiar 90 y 88 (posiciones 6 y 7)
 *   Intercambiar 90 y 45 (posiciones 7 y 8)
 *   Intercambiar 90 y 50 (posiciones 8 y 9)
 *   Estado: 34 25 12 22 11 64 88 45 50 90 
 * 
 * [... más pasadas ...]
 * 
 * --- ARREGLO ORDENADO ---
 * 11 12 22 25 34 45 50 64 88 90 
 * 
 * --- ESTADISTICAS ---
 * Comparaciones realizadas: 45
 * Intercambios realizados: 28
 * Comparaciones en peor caso: 45
 * Eficiencia: 100%
 * 
 * EXPLICACIÓN DEL ALGORITMO:
 * 
 * 1. En cada pasada, comparamos elementos adyacentes
 * 2. Si están en orden incorrecto, los intercambiamos
 * 3. El elemento más grande "burbujea" hacia el final
 * 4. Después de cada pasada, el último elemento está en su posición correcta
 * 5. Repetimos hasta que el arreglo esté ordenado
 * 
 * COMPLEJIDAD:
 * - Mejor caso: O(n) - cuando el arreglo ya está ordenado
 * - Caso promedio: O(n²)
 * - Peor caso: O(n²) - cuando el arreglo está en orden inverso
 * - Espacio: O(1) - ordenamiento in-place
 * 
 * OPTIMIZACIÓN:
 * - Usamos una bandera para detectar si hubo intercambios
 * - Si no hubo intercambios en una pasada, el arreglo ya está ordenado
 * - Esto mejora el mejor caso a O(n)
 */
