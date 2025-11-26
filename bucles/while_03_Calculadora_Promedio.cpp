/*
 * EJERCICIO WHILE 3: CALCULADORA DE PROMEDIO (NIVEL MEDIO)
 * 
 * Descripción:
 * Este programa calcula el promedio de una serie de números ingresados
 * por el usuario. El usuario puede ingresar tantos números como desee
 * y terminar ingresando 0. El programa calcula estadísticas completas.
 * 
 * Conceptos que aprenderás:
 * - Ciclo while con centinela (valor de parada)
 * - Acumulación de valores
 * - Contadores
 * - Cálculo de máximo y mínimo
 * - Promedio y estadísticas
 */

#include <iostream>
#include <iomanip> // Para setprecision
#include <limits>  // Para numeric_limits
using namespace std;

int main() {
    // Variables para acumulación y conteo
    double suma_total = 0.0;        // Suma de todos los números
    int cantidad_numeros = 0;       // Cantidad de números ingresados
    
    // Variables para estadísticas
    double numero_maximo = numeric_limits<double>::lowest();  // Inicializar con el menor valor posible
    double numero_minimo = numeric_limits<double>::max();     // Inicializar con el mayor valor posible
    
    // Variable para almacenar cada número ingresado
    double numero_actual;
    
    // Mostrar instrucciones
    cout << "=== CALCULADORA DE PROMEDIO ===" << endl;
    cout << "Ingrese numeros para calcular el promedio." << endl;
    cout << "Ingrese 0 para terminar y ver los resultados." << endl;
    cout << "----------------------------------------" << endl;
    
    // Solicitar el primer número
    cout << "\nIngrese un numero: ";
    cin >> numero_actual;
    
    // Ciclo while que continúa mientras el número NO sea 0
    // El valor 0 actúa como "centinela" o señal de parada
    while(numero_actual != 0) {
        // Incrementar el contador
        cantidad_numeros++;
        
        // Acumular el número en la suma total
        suma_total += numero_actual;
        
        // Actualizar el máximo si es necesario
        if(numero_actual > numero_maximo) {
            numero_maximo = numero_actual;
        }
        
        // Actualizar el mínimo si es necesario
        if(numero_actual < numero_minimo) {
            numero_minimo = numero_actual;
        }
        
        // Mostrar información parcial
        cout << "Numeros ingresados hasta ahora: " << cantidad_numeros << endl;
        cout << "Suma parcial: " << suma_total << endl;
        
        // Solicitar el siguiente número
        cout << "\nIngrese un numero (0 para terminar): ";
        cin >> numero_actual;
    }
    
    // Verificar si se ingresó al menos un número
    if(cantidad_numeros == 0) {
        cout << "\nNo se ingresaron numeros. Programa terminado." << endl;
        return 0;
    }
    
    // Calcular el promedio
    double promedio = suma_total / cantidad_numeros;
    
    // Calcular el rango (diferencia entre máximo y mínimo)
    double rango = numero_maximo - numero_minimo;
    
    // Mostrar resultados
    cout << "\n========================================" << endl;
    cout << "           RESULTADOS FINALES           " << endl;
    cout << "========================================" << endl;
    
    cout << fixed << setprecision(2); // Formato con 2 decimales
    
    cout << "\nCantidad de numeros: " << cantidad_numeros << endl;
    cout << "Suma total: " << suma_total << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Numero maximo: " << numero_maximo << endl;
    cout << "Numero minimo: " << numero_minimo << endl;
    cout << "Rango (max - min): " << rango << endl;
    
    // Análisis adicional
    cout << "\n--- ANALISIS ADICIONAL ---" << endl;
    
    // Contar cuántos números están por encima y por debajo del promedio
    cout << "\nPara ver cuantos numeros estan por encima/debajo del promedio," << endl;
    cout << "necesitarias almacenar todos los numeros (usando arreglos)." << endl;
    cout << "Promedio calculado: " << promedio << endl;
    
    // Clasificar el promedio
    if(promedio > 0) {
        cout << "El promedio es POSITIVO" << endl;
    } else if(promedio < 0) {
        cout << "El promedio es NEGATIVO" << endl;
    } else {
        cout << "El promedio es CERO" << endl;
    }
    
    // Mostrar si hay mucha variación en los datos
    if(rango > promedio * 2) {
        cout << "Los datos tienen ALTA variacion (rango grande)" << endl;
    } else if(rango > promedio) {
        cout << "Los datos tienen MODERADA variacion" << endl;
    } else {
        cout << "Los datos tienen BAJA variacion (valores similares)" << endl;
    }
    
    cout << "\n========================================" << endl;
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === CALCULADORA DE PROMEDIO ===
 * Ingrese numeros para calcular el promedio.
 * Ingrese 0 para terminar y ver los resultados.
 * ----------------------------------------
 * 
 * Ingrese un numero: 10
 * Numeros ingresados hasta ahora: 1
 * Suma parcial: 10
 * 
 * Ingrese un numero (0 para terminar): 20
 * Numeros ingresados hasta ahora: 2
 * Suma parcial: 30
 * 
 * Ingrese un numero (0 para terminar): 15
 * Numeros ingresados hasta ahora: 3
 * Suma parcial: 45
 * 
 * Ingrese un numero (0 para terminar): 25
 * Numeros ingresados hasta ahora: 4
 * Suma parcial: 70
 * 
 * Ingrese un numero (0 para terminar): 30
 * Numeros ingresados hasta ahora: 5
 * Suma parcial: 100
 * 
 * Ingrese un numero (0 para terminar): 0
 * 
 * ========================================
 *            RESULTADOS FINALES           
 * ========================================
 * 
 * Cantidad de numeros: 5
 * Suma total: 100.00
 * Promedio: 20.00
 * Numero maximo: 30.00
 * Numero minimo: 10.00
 * Rango (max - min): 20.00
 * 
 * --- ANALISIS ADICIONAL ---
 * 
 * Para ver cuantos numeros estan por encima/debajo del promedio,
 * necesitarias almacenar todos los numeros (usando arreglos).
 * Promedio calculado: 20.00
 * El promedio es POSITIVO
 * Los datos tienen MODERADA variacion
 * 
 * ========================================
 * 
 * EXPLICACIÓN:
 * - El ciclo while continúa mientras numero_actual != 0
 * - El valor 0 es el "centinela" que indica el fin de la entrada
 * - En cada iteración:
 *   1. Se incrementa el contador
 *   2. Se acumula el número en la suma
 *   3. Se actualizan máximo y mínimo
 *   4. Se solicita el siguiente número
 * - Al salir del ciclo, se calculan y muestran las estadísticas
 * 
 * PATRÓN CENTINELA:
 * - Un valor especial (0 en este caso) indica el fin de la entrada
 * - Útil cuando no sabemos cuántos valores ingresará el usuario
 * - El centinela NO se incluye en los cálculos
 * 
 * LIMITACIÓN:
 * - No podemos calcular desviación estándar sin almacenar todos los valores
 * - Para eso necesitaríamos usar arreglos o vectores
 */
