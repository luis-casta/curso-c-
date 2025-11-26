/*
 * EJERCICIO ARREGLOS 5: ROTACIÓN DE ARREGLO (NIVEL DIFÍCIL)
 * 
 * Descripción:
 * Este programa rota los elementos de un arreglo hacia la izquierda o derecha
 * un número específico de posiciones. Implementa múltiples métodos de rotación
 * y muestra el proceso paso a paso.
 * 
 * Conceptos que aprenderás:
 * - Rotación de arreglos
 * - Algoritmo de inversión para rotación
 * - Rotación cíclica
 * - Manejo de índices modulares
 * - Optimización de rotaciones
 */

#include <iostream>
using namespace std;

// Función para invertir una porción del arreglo
void invertir_seccion(int arreglo[], int inicio, int fin) {
    while(inicio < fin) {
        int temporal = arreglo[inicio];
        arreglo[inicio] = arreglo[fin];
        arreglo[fin] = temporal;
        inicio++;
        fin--;
    }
}

// Función para mostrar el arreglo
void mostrar_arreglo(int arreglo[], int tamano) {
    for(int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int main() {
    // Tamaño del arreglo
    const int TAMANO_ARREGLO = 10;
    
    // Arreglos para diferentes métodos
    int arreglo_original[TAMANO_ARREGLO];
    int arreglo_rotado[TAMANO_ARREGLO];
    
    // Solicitar los números al usuario
    cout << "=== ROTACION DE ARREGLO ===" << endl;
    cout << "Ingrese " << TAMANO_ARREGLO << " numeros:" << endl;
    
    for(int indice = 0; indice < TAMANO_ARREGLO; indice++) {
        cout << "Numero " << (indice + 1) << ": ";
        cin >> arreglo_original[indice];
    }
    
    // Solicitar número de posiciones a rotar
    int posiciones_rotar;
    char direccion;
    
    cout << "\nIngrese el numero de posiciones a rotar: ";
    cin >> posiciones_rotar;
    
    cout << "Direccion (I=Izquierda, D=Derecha): ";
    cin >> direccion;
    
    // Optimización: reducir rotaciones innecesarias
    // Rotar n veces es lo mismo que rotar n % tamano veces
    posiciones_rotar = posiciones_rotar % TAMANO_ARREGLO;
    
    // Mostrar arreglo original
    cout << "\n--- ARREGLO ORIGINAL ---" << endl;
    mostrar_arreglo(arreglo_original, TAMANO_ARREGLO);
    
    // Copiar arreglo original para diferentes métodos
    for(int i = 0; i < TAMANO_ARREGLO; i++) {
        arreglo_rotado[i] = arreglo_original[i];
    }
    
    if(direccion == 'I' || direccion == 'i') {
        // ROTACIÓN A LA IZQUIERDA usando algoritmo de inversión
        cout << "\n--- ROTACION A LA IZQUIERDA (" << posiciones_rotar << " posiciones) ---" << endl;
        cout << "\nMETODO 1: Algoritmo de Inversion" << endl;
        cout << "Paso 1: Invertir primeros " << posiciones_rotar << " elementos" << endl;
        
        invertir_seccion(arreglo_rotado, 0, posiciones_rotar - 1);
        cout << "Estado: ";
        mostrar_arreglo(arreglo_rotado, TAMANO_ARREGLO);
        
        cout << "Paso 2: Invertir elementos restantes" << endl;
        invertir_seccion(arreglo_rotado, posiciones_rotar, TAMANO_ARREGLO - 1);
        cout << "Estado: ";
        mostrar_arreglo(arreglo_rotado, TAMANO_ARREGLO);
        
        cout << "Paso 3: Invertir todo el arreglo" << endl;
        invertir_seccion(arreglo_rotado, 0, TAMANO_ARREGLO - 1);
        cout << "Estado: ";
        mostrar_arreglo(arreglo_rotado, TAMANO_ARREGLO);
        
    } else if(direccion == 'D' || direccion == 'd') {
        // ROTACIÓN A LA DERECHA usando algoritmo de inversión
        cout << "\n--- ROTACION A LA DERECHA (" << posiciones_rotar << " posiciones) ---" << endl;
        cout << "\nMETODO 1: Algoritmo de Inversion" << endl;
        
        // Para rotar a la derecha k posiciones, es equivalente a
        // rotar a la izquierda (n - k) posiciones
        int rotacion_equivalente = TAMANO_ARREGLO - posiciones_rotar;
        
        cout << "Paso 1: Invertir primeros " << rotacion_equivalente << " elementos" << endl;
        invertir_seccion(arreglo_rotado, 0, rotacion_equivalente - 1);
        cout << "Estado: ";
        mostrar_arreglo(arreglo_rotado, TAMANO_ARREGLO);
        
        cout << "Paso 2: Invertir elementos restantes" << endl;
        invertir_seccion(arreglo_rotado, rotacion_equivalente, TAMANO_ARREGLO - 1);
        cout << "Estado: ";
        mostrar_arreglo(arreglo_rotado, TAMANO_ARREGLO);
        
        cout << "Paso 3: Invertir todo el arreglo" << endl;
        invertir_seccion(arreglo_rotado, 0, TAMANO_ARREGLO - 1);
        cout << "Estado: ";
        mostrar_arreglo(arreglo_rotado, TAMANO_ARREGLO);
    }
    
    // Mostrar resultado final
    cout << "\n--- RESULTADO FINAL ---" << endl;
    cout << "Arreglo original:  ";
    mostrar_arreglo(arreglo_original, TAMANO_ARREGLO);
    cout << "Arreglo rotado:    ";
    mostrar_arreglo(arreglo_rotado, TAMANO_ARREGLO);
    
    // MÉTODO 2: Rotación usando arreglo auxiliar
    cout << "\n--- METODO 2: Usando Arreglo Auxiliar ---" << endl;
    int arreglo_auxiliar[TAMANO_ARREGLO];
    
    if(direccion == 'I' || direccion == 'i') {
        // Rotación a la izquierda
        for(int i = 0; i < TAMANO_ARREGLO; i++) {
            int nueva_posicion = (i - posiciones_rotar + TAMANO_ARREGLO) % TAMANO_ARREGLO;
            arreglo_auxiliar[nueva_posicion] = arreglo_original[i];
        }
    } else {
        // Rotación a la derecha
        for(int i = 0; i < TAMANO_ARREGLO; i++) {
            int nueva_posicion = (i + posiciones_rotar) % TAMANO_ARREGLO;
            arreglo_auxiliar[nueva_posicion] = arreglo_original[i];
        }
    }
    
    cout << "Resultado con arreglo auxiliar: ";
    mostrar_arreglo(arreglo_auxiliar, TAMANO_ARREGLO);
    
    // Verificar que ambos métodos dan el mismo resultado
    bool metodos_coinciden = true;
    for(int i = 0; i < TAMANO_ARREGLO; i++) {
        if(arreglo_rotado[i] != arreglo_auxiliar[i]) {
            metodos_coinciden = false;
            break;
        }
    }
    
    cout << "\n--- VERIFICACION ---" << endl;
    if(metodos_coinciden) {
        cout << "¡Ambos metodos producen el mismo resultado! ✓" << endl;
    } else {
        cout << "Los metodos producen resultados diferentes (error)" << endl;
    }
    
    // Análisis de complejidad
    cout << "\n--- ANALISIS DE COMPLEJIDAD ---" << endl;
    cout << "Metodo 1 (Inversion):" << endl;
    cout << "  - Tiempo: O(n)" << endl;
    cout << "  - Espacio: O(1) - in-place" << endl;
    cout << "\nMetodo 2 (Arreglo auxiliar):" << endl;
    cout << "  - Tiempo: O(n)" << endl;
    cout << "  - Espacio: O(n) - requiere arreglo adicional" << endl;
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === ROTACION DE ARREGLO ===
 * Ingrese 10 numeros:
 * Numero 1: 1
 * Numero 2: 2
 * Numero 3: 3
 * Numero 4: 4
 * Numero 5: 5
 * Numero 6: 6
 * Numero 7: 7
 * Numero 8: 8
 * Numero 9: 9
 * Numero 10: 10
 * 
 * Ingrese el numero de posiciones a rotar: 3
 * Direccion (I=Izquierda, D=Derecha): I
 * 
 * --- ARREGLO ORIGINAL ---
 * 1 2 3 4 5 6 7 8 9 10 
 * 
 * --- ROTACION A LA IZQUIERDA (3 posiciones) ---
 * 
 * METODO 1: Algoritmo de Inversion
 * Paso 1: Invertir primeros 3 elementos
 * Estado: 3 2 1 4 5 6 7 8 9 10 
 * Paso 2: Invertir elementos restantes
 * Estado: 3 2 1 10 9 8 7 6 5 4 
 * Paso 3: Invertir todo el arreglo
 * Estado: 4 5 6 7 8 9 10 1 2 3 
 * 
 * --- RESULTADO FINAL ---
 * Arreglo original:  1 2 3 4 5 6 7 8 9 10 
 * Arreglo rotado:    4 5 6 7 8 9 10 1 2 3 
 * 
 * --- METODO 2: Usando Arreglo Auxiliar ---
 * Resultado con arreglo auxiliar: 4 5 6 7 8 9 10 1 2 3 
 * 
 * --- VERIFICACION ---
 * ¡Ambos metodos producen el mismo resultado! ✓
 * 
 * --- ANALISIS DE COMPLEJIDAD ---
 * Metodo 1 (Inversion):
 *   - Tiempo: O(n)
 *   - Espacio: O(1) - in-place
 * 
 * Metodo 2 (Arreglo auxiliar):
 *   - Tiempo: O(n)
 *   - Espacio: O(n) - requiere arreglo adicional
 * 
 * EXPLICACIÓN:
 * 
 * ROTACIÓN A LA IZQUIERDA (3 posiciones):
 * Original: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 * Rotado:   [4, 5, 6, 7, 8, 9, 10, 1, 2, 3]
 * Los primeros 3 elementos van al final
 * 
 * ALGORITMO DE INVERSIÓN:
 * 1. Invertir los primeros k elementos
 * 2. Invertir los elementos restantes
 * 3. Invertir todo el arreglo
 * 
 * Este algoritmo es óptimo: O(n) tiempo, O(1) espacio
 */
