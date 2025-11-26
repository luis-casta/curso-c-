/*
 * EJERCICIO ARREGLOS 1: BUSCAR MÁXIMO Y MÍNIMO (NIVEL FÁCIL)
 * 
 * Descripción:
 * Este programa encuentra el valor máximo y mínimo en un arreglo de números
 * ingresados por el usuario, junto con sus posiciones.
 * 
 * Conceptos que aprenderás:
 * - Declaración de arreglos
 * - Entrada de datos en arreglos
 * - Recorrido de arreglos
 * - Búsqueda de máximo y mínimo
 * - Almacenamiento de posiciones
 */

#include <iostream>
using namespace std;

int main() {
    // Tamaño del arreglo
    const int TAMANO_ARREGLO = 10;
    
    // Declaración del arreglo
    int numeros[TAMANO_ARREGLO];
    
    // Variables para almacenar máximo, mínimo y sus posiciones
    int valor_maximo;
    int valor_minimo;
    int posicion_maximo = 0;
    int posicion_minimo = 0;
    
    // Solicitar los números al usuario
    cout << "=== BUSCAR MAXIMO Y MINIMO ===" << endl;
    cout << "Ingrese " << TAMANO_ARREGLO << " numeros:" << endl;
    
    for(int indice = 0; indice < TAMANO_ARREGLO; indice++) {
        cout << "Numero " << (indice + 1) << ": ";
        cin >> numeros[indice];
    }
    
    // Inicializar máximo y mínimo con el primer elemento
    valor_maximo = numeros[0];
    valor_minimo = numeros[0];
    
    // Recorrer el arreglo para encontrar máximo y mínimo
    for(int indice = 1; indice < TAMANO_ARREGLO; indice++) {
        // Verificar si es el nuevo máximo
        if(numeros[indice] > valor_maximo) {
            valor_maximo = numeros[indice];
            posicion_maximo = indice;
        }
        
        // Verificar si es el nuevo mínimo
        if(numeros[indice] < valor_minimo) {
            valor_minimo = numeros[indice];
            posicion_minimo = indice;
        }
    }
    
    // Mostrar el arreglo completo
    cout << "\n--- ARREGLO INGRESADO ---" << endl;
    cout << "Posicion: ";
    for(int indice = 0; indice < TAMANO_ARREGLO; indice++) {
        cout << indice << "\t";
    }
    cout << endl;
    
    cout << "Valor:    ";
    for(int indice = 0; indice < TAMANO_ARREGLO; indice++) {
        cout << numeros[indice] << "\t";
    }
    cout << endl;
    
    // Mostrar resultados
    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Valor MAXIMO: " << valor_maximo << endl;
    cout << "Posicion: " << posicion_maximo << endl;
    
    cout << "\nValor MINIMO: " << valor_minimo << endl;
    cout << "Posicion: " << posicion_minimo << endl;
    
    // Calcular el rango
    int rango = valor_maximo - valor_minimo;
    cout << "\nRango (max - min): " << rango << endl;
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === BUSCAR MAXIMO Y MINIMO ===
 * Ingrese 10 numeros:
 * Numero 1: 45
 * Numero 2: 12
 * Numero 3: 89
 * Numero 4: 23
 * Numero 5: 67
 * Numero 6: 34
 * Numero 7: 91
 * Numero 8: 56
 * Numero 9: 78
 * Numero 10: 29
 * 
 * --- ARREGLO INGRESADO ---
 * Posicion: 0    1    2    3    4    5    6    7    8    9
 * Valor:    45   12   89   23   67   34   91   56   78   29
 * 
 * --- RESULTADOS ---
 * Valor MAXIMO: 91
 * Posicion: 6
 * 
 * Valor MINIMO: 12
 * Posicion: 1
 * 
 * Rango (max - min): 79
 */
