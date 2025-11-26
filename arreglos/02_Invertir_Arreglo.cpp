/*
 * EJERCICIO ARREGLOS 2: INVERTIR UN ARREGLO (NIVEL FÁCIL-MEDIO)
 * 
 * Descripción:
 * Este programa invierte el orden de los elementos de un arreglo.
 * El primer elemento se convierte en el último, el segundo en el
 * penúltimo, y así sucesivamente.
 * 
 * Conceptos que aprenderás:
 * - Manipulación de arreglos
 * - Intercambio de elementos
 * - Índices simétricos
 * - Algoritmo de inversión in-place
 */

#include <iostream>
using namespace std;

int main() {
    // Tamaño del arreglo
    const int TAMANO_ARREGLO = 8;
    
    // Declaración e inicialización del arreglo
    int numeros[TAMANO_ARREGLO];
    
    // Solicitar los números al usuario
    cout << "=== INVERTIR ARREGLO ===" << endl;
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
    
    // ALGORITMO DE INVERSIÓN
    // Intercambiamos elementos desde los extremos hacia el centro
    // Solo necesitamos recorrer hasta la mitad del arreglo
    cout << "\n--- PROCESO DE INVERSION ---" << endl;
    
    for(int indice_izquierdo = 0; indice_izquierdo < TAMANO_ARREGLO / 2; indice_izquierdo++) {
        // Calcular el índice simétrico desde la derecha
        int indice_derecho = TAMANO_ARREGLO - 1 - indice_izquierdo;
        
        // Mostrar el intercambio que se va a realizar
        cout << "Intercambiar posicion " << indice_izquierdo << " (" << numeros[indice_izquierdo] 
             << ") con posicion " << indice_derecho << " (" << numeros[indice_derecho] << ")" << endl;
        
        // Intercambiar los elementos usando una variable temporal
        int temporal = numeros[indice_izquierdo];
        numeros[indice_izquierdo] = numeros[indice_derecho];
        numeros[indice_derecho] = temporal;
    }
    
    // Mostrar arreglo invertido
    cout << "\n--- ARREGLO INVERTIDO ---" << endl;
    for(int indice = 0; indice < TAMANO_ARREGLO; indice++) {
        cout << numeros[indice] << " ";
    }
    cout << endl;
    
    // Verificación visual
    cout << "\n--- VERIFICACION ---" << endl;
    cout << "El primer elemento ahora es el ultimo" << endl;
    cout << "El ultimo elemento ahora es el primero" << endl;
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === INVERTIR ARREGLO ===
 * Ingrese 8 numeros:
 * Numero 1: 10
 * Numero 2: 20
 * Numero 3: 30
 * Numero 4: 40
 * Numero 5: 50
 * Numero 6: 60
 * Numero 7: 70
 * Numero 8: 80
 * 
 * --- ARREGLO ORIGINAL ---
 * 10 20 30 40 50 60 70 80 
 * 
 * --- PROCESO DE INVERSION ---
 * Intercambiar posicion 0 (10) con posicion 7 (80)
 * Intercambiar posicion 1 (20) con posicion 6 (70)
 * Intercambiar posicion 2 (30) con posicion 5 (60)
 * Intercambiar posicion 3 (40) con posicion 4 (50)
 * 
 * --- ARREGLO INVERTIDO ---
 * 80 70 60 50 40 30 20 10 
 * 
 * --- VERIFICACION ---
 * El primer elemento ahora es el ultimo
 * El ultimo elemento ahora es el primero
 * 
 * EXPLICACIÓN:
 * - Recorremos solo hasta la mitad del arreglo (TAMANO/2)
 * - Para cada posición i desde la izquierda, calculamos su simétrico: (TAMANO-1-i)
 * - Intercambiamos los elementos en esas posiciones
 * - Usamos una variable temporal para no perder datos durante el intercambio
 */
