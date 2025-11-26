/*
 * EJERCICIO ARREGLOS 3: ELIMINAR DUPLICADOS (NIVEL MEDIO)
 * 
 * Descripción:
 * Este programa elimina los elementos duplicados de un arreglo,
 * dejando solo una copia de cada valor único. Muestra el arreglo
 * original y el arreglo sin duplicados.
 * 
 * Conceptos que aprenderás:
 * - Detección de duplicados
 * - Creación de nuevo arreglo
 * - Comparación de elementos
 * - Conteo de elementos únicos
 * - Algoritmo de filtrado
 */

#include <iostream>
using namespace std;

int main() {
    // Tamaño del arreglo original
    const int TAMANO_ORIGINAL = 15;
    
    // Arreglo original con duplicados
    int arreglo_original[TAMANO_ORIGINAL];
    
    // Arreglo para almacenar elementos únicos
    int arreglo_sin_duplicados[TAMANO_ORIGINAL];
    
    // Contador de elementos únicos
    int cantidad_unicos = 0;
    
    // Solicitar los números al usuario
    cout << "=== ELIMINAR DUPLICADOS ===" << endl;
    cout << "Ingrese " << TAMANO_ORIGINAL << " numeros (pueden repetirse):" << endl;
    
    for(int indice = 0; indice < TAMANO_ORIGINAL; indice++) {
        cout << "Numero " << (indice + 1) << ": ";
        cin >> arreglo_original[indice];
    }
    
    // Mostrar arreglo original
    cout << "\n--- ARREGLO ORIGINAL ---" << endl;
    for(int indice = 0; indice < TAMANO_ORIGINAL; indice++) {
        cout << arreglo_original[indice] << " ";
    }
    cout << endl;
    
    // ALGORITMO PARA ELIMINAR DUPLICADOS
    cout << "\n--- PROCESO DE ELIMINACION ---" << endl;
    
    // Recorrer cada elemento del arreglo original
    for(int indice_actual = 0; indice_actual < TAMANO_ORIGINAL; indice_actual++) {
        int elemento_actual = arreglo_original[indice_actual];
        
        // Verificar si el elemento ya existe en el arreglo de únicos
        bool es_duplicado = false;
        
        for(int indice_unico = 0; indice_unico < cantidad_unicos; indice_unico++) {
            if(arreglo_sin_duplicados[indice_unico] == elemento_actual) {
                es_duplicado = true;
                cout << "Elemento " << elemento_actual << " es duplicado (omitido)" << endl;
                break; // No necesitamos seguir buscando
            }
        }
        
        // Si no es duplicado, agregarlo al arreglo de únicos
        if(!es_duplicado) {
            arreglo_sin_duplicados[cantidad_unicos] = elemento_actual;
            cout << "Elemento " << elemento_actual << " agregado (posicion " 
                 << cantidad_unicos << ")" << endl;
            cantidad_unicos++;
        }
    }
    
    // Mostrar arreglo sin duplicados
    cout << "\n--- ARREGLO SIN DUPLICADOS ---" << endl;
    for(int indice = 0; indice < cantidad_unicos; indice++) {
        cout << arreglo_sin_duplicados[indice] << " ";
    }
    cout << endl;
    
    // Mostrar estadísticas
    cout << "\n--- ESTADISTICAS ---" << endl;
    cout << "Elementos originales: " << TAMANO_ORIGINAL << endl;
    cout << "Elementos unicos: " << cantidad_unicos << endl;
    cout << "Duplicados eliminados: " << (TAMANO_ORIGINAL - cantidad_unicos) << endl;
    
    // Calcular porcentaje de reducción
    double porcentaje_reduccion = ((double)(TAMANO_ORIGINAL - cantidad_unicos) / TAMANO_ORIGINAL) * 100;
    cout << "Porcentaje de reduccion: " << porcentaje_reduccion << "%" << endl;
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === ELIMINAR DUPLICADOS ===
 * Ingrese 15 numeros (pueden repetirse):
 * Numero 1: 5
 * Numero 2: 3
 * Numero 3: 5
 * Numero 4: 7
 * Numero 5: 3
 * Numero 6: 9
 * Numero 7: 5
 * Numero 8: 7
 * Numero 9: 2
 * Numero 10: 3
 * Numero 11: 9
 * Numero 12: 1
 * Numero 13: 5
 * Numero 14: 7
 * Numero 15: 2
 * 
 * --- ARREGLO ORIGINAL ---
 * 5 3 5 7 3 9 5 7 2 3 9 1 5 7 2 
 * 
 * --- PROCESO DE ELIMINACION ---
 * Elemento 5 agregado (posicion 0)
 * Elemento 3 agregado (posicion 1)
 * Elemento 5 es duplicado (omitido)
 * Elemento 7 agregado (posicion 2)
 * Elemento 3 es duplicado (omitido)
 * Elemento 9 agregado (posicion 3)
 * Elemento 5 es duplicado (omitido)
 * Elemento 7 es duplicado (omitido)
 * Elemento 2 agregado (posicion 4)
 * Elemento 3 es duplicado (omitido)
 * Elemento 9 es duplicado (omitido)
 * Elemento 1 agregado (posicion 5)
 * Elemento 5 es duplicado (omitido)
 * Elemento 7 es duplicado (omitido)
 * Elemento 2 es duplicado (omitido)
 * 
 * --- ARREGLO SIN DUPLICADOS ---
 * 5 3 7 9 2 1 
 * 
 * --- ESTADISTICAS ---
 * Elementos originales: 15
 * Elementos unicos: 6
 * Duplicados eliminados: 9
 * Porcentaje de reduccion: 60%
 * 
 * EXPLICACIÓN:
 * - Para cada elemento del arreglo original, verificamos si ya existe en el arreglo de únicos
 * - Si no existe, lo agregamos al arreglo de únicos
 * - Si ya existe, lo omitimos (es un duplicado)
 * - Mantenemos un contador de elementos únicos
 * - Complejidad: O(n²) - para cada elemento verificamos todos los únicos
 */
