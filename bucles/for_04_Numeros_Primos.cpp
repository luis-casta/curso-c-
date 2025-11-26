/*
 * EJERCICIO FOR 4: NÚMEROS PRIMOS (NIVEL MEDIO-DIFÍCIL)
 * 
 * Descripción:
 * Este programa encuentra y muestra todos los números primos en un rango
 * especificado por el usuario. Un número primo es aquel que solo es
 * divisible por 1 y por sí mismo.
 * 
 * Conceptos que aprenderás:
 * - Ciclos for anidados
 * - Algoritmo de verificación de primalidad
 * - Uso de banderas (flags)
 * - Optimización de algoritmos
 * - Operador módulo para verificar divisibilidad
 */

#include <iostream>
#include <cmath> // Para usar sqrt()
using namespace std;

int main() {
    // Variables para el rango de búsqueda
    int limite_inferior, limite_superior;
    
    // Contador de números primos encontrados
    int cantidad_primos = 0;
    
    // Solicitar el rango al usuario
    cout << "=== BUSQUEDA DE NUMEROS PRIMOS ===" << endl;
    cout << "Ingrese el limite inferior: ";
    cin >> limite_inferior;
    cout << "Ingrese el limite superior: ";
    cin >> limite_superior;
    
    // Validar entrada
    if(limite_inferior < 2) {
        limite_inferior = 2; // El primer número primo es 2
        cout << "Nota: El limite inferior se ajusto a 2 (primer primo)" << endl;
    }
    
    if(limite_superior < limite_inferior) {
        cout << "Error: El limite superior debe ser mayor al inferior" << endl;
        return 1;
    }
    
    cout << "\nNumeros primos entre " << limite_inferior << " y " << limite_superior << ":" << endl;
    cout << "----------------------------------------" << endl;
    
    // Ciclo principal: recorre todos los números en el rango
    for(int numero_actual = limite_inferior; numero_actual <= limite_superior; numero_actual++) {
        // Bandera para indicar si el número es primo
        bool es_primo = true;
        
        // Casos especiales
        if(numero_actual < 2) {
            es_primo = false; // 0 y 1 no son primos
        }
        else if(numero_actual == 2) {
            es_primo = true; // 2 es el único número primo par
        }
        else if(numero_actual % 2 == 0) {
            es_primo = false; // Los números pares mayores a 2 no son primos
        }
        else {
            // Verificar divisibilidad desde 3 hasta la raíz cuadrada del número
            // OPTIMIZACIÓN: Solo necesitamos verificar hasta sqrt(numero_actual)
            // porque si n = a * b y a > sqrt(n), entonces b < sqrt(n)
            int limite_verificacion = static_cast<int>(sqrt(numero_actual));
            
            // Verificar divisibilidad con números impares
            // Comenzamos en 3 e incrementamos de 2 en 2 (solo impares)
            for(int divisor = 3; divisor <= limite_verificacion; divisor += 2) {
                // Si el número es divisible por el divisor, no es primo
                if(numero_actual % divisor == 0) {
                    es_primo = false;
                    break; // No necesitamos seguir verificando
                }
            }
        }
        
        // Si el número es primo, mostrarlo
        if(es_primo) {
            cout << numero_actual << " ";
            cantidad_primos++;
            
            // Salto de línea cada 10 números para mejor visualización
            if(cantidad_primos % 10 == 0) {
                cout << endl;
            }
        }
    }
    
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Total de numeros primos encontrados: " << cantidad_primos << endl;
    
    // Calcular densidad de primos en el rango
    int total_numeros = limite_superior - limite_inferior + 1;
    double porcentaje_primos = (static_cast<double>(cantidad_primos) / total_numeros) * 100;
    cout << "Porcentaje de primos en el rango: " << porcentaje_primos << "%" << endl;
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === BUSQUEDA DE NUMEROS PRIMOS ===
 * Ingrese el limite inferior: 1
 * Ingrese el limite superior: 50
 * Nota: El limite inferior se ajusto a 2 (primer primo)
 * 
 * Numeros primos entre 2 y 50:
 * ----------------------------------------
 * 2 3 5 7 11 13 17 19 23 29 
 * 31 37 41 43 47 
 * ----------------------------------------
 * Total de numeros primos encontrados: 15
 * Porcentaje de primos en el rango: 30%
 * 
 * EXPLICACIÓN DEL ALGORITMO:
 * 
 * Para verificar si un número N es primo:
 * 1. Si N < 2: NO es primo
 * 2. Si N = 2: SÍ es primo (único primo par)
 * 3. Si N es par: NO es primo
 * 4. Si N es impar: verificar divisibilidad desde 3 hasta √N
 *    - Solo verificamos números impares (3, 5, 7, 9, ...)
 *    - Si encontramos un divisor: NO es primo
 *    - Si no encontramos divisores: SÍ es primo
 * 
 * OPTIMIZACIÓN:
 * - Solo verificamos hasta √N porque cualquier divisor mayor a √N
 *   tendría un par divisor menor a √N
 * - Solo verificamos números impares (incremento de 2 en 2)
 * - Usamos break para salir del ciclo cuando encontramos un divisor
 * 
 * COMPLEJIDAD:
 * - Para cada número N, verificamos hasta √N divisores
 * - Complejidad aproximada: O(n * √n) donde n es el tamaño del rango
 */
