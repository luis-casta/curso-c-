/*
 * EJERCICIO FOR 2: SUMA DE NÚMEROS PARES (NIVEL FÁCIL-MEDIO)
 * 
 * Descripción:
 * Este programa calcula la suma de todos los números pares desde 1
 * hasta un límite ingresado por el usuario.
 * 
 * Conceptos que aprenderás:
 * - Ciclo for con incremento de 2 en 2
 * - Acumulación de valores
 * - Identificación de números pares
 * - Contador de elementos
 */

#include <iostream>
using namespace std;

int main() {
    // Variable para el límite superior
    int limite_superior;
    
    // Variable acumuladora para la suma
    int suma_pares = 0;
    
    // Contador de cuántos números pares se sumaron
    int cantidad_pares = 0;
    
    // Solicitar el límite al usuario
    cout << "=== SUMA DE NUMEROS PARES ===" << endl;
    cout << "Ingrese el limite superior: ";
    cin >> limite_superior;
    
    // Validar que el límite sea positivo
    if(limite_superior < 1) {
        cout << "Error: El limite debe ser mayor a 0" << endl;
        return 1;
    }
    
    cout << "\nNumeros pares encontrados: ";
    
    // Ciclo for que recorre los números pares
    // Comenzamos en 2 (primer número par) e incrementamos de 2 en 2
    for(int numero_actual = 2; numero_actual <= limite_superior; numero_actual += 2) {
        // Mostrar el número par actual
        cout << numero_actual << " ";
        
        // Acumular el número en la suma
        suma_pares += numero_actual;
        
        // Incrementar el contador de números pares
        cantidad_pares++;
    }
    
    cout << endl;
    
    // Mostrar resultados
    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Cantidad de numeros pares: " << cantidad_pares << endl;
    cout << "Suma total: " << suma_pares << endl;
    
    // Calcular y mostrar el promedio
    if(cantidad_pares > 0) {
        double promedio = static_cast<double>(suma_pares) / cantidad_pares;
        cout << "Promedio: " << promedio << endl;
    }
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === SUMA DE NUMEROS PARES ===
 * Ingrese el limite superior: 20
 * 
 * Numeros pares encontrados: 2 4 6 8 10 12 14 16 18 20 
 * 
 * --- RESULTADOS ---
 * Cantidad de numeros pares: 10
 * Suma total: 110
 * Promedio: 11
 * 
 * EXPLICACIÓN:
 * - El ciclo comienza en 2 (primer número par)
 * - Se incrementa de 2 en 2 (numero_actual += 2)
 * - Esto garantiza que solo recorremos números pares
 * - Suma: 2+4+6+8+10+12+14+16+18+20 = 110
 * - Promedio: 110 / 10 = 11
 * 
 * ALTERNATIVA:
 * También podríamos usar: for(int i = 1; i <= limite; i++)
 * y dentro verificar: if(i % 2 == 0) { suma += i; }
 * Pero incrementar de 2 en 2 es más eficiente.
 */
