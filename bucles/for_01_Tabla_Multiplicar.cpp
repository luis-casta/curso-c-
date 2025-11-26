/*
 * EJERCICIO FOR 1: TABLA DE MULTIPLICAR (NIVEL FÁCIL)
 * 
 * Descripción:
 * Este programa imprime la tabla de multiplicar de un número ingresado
 * por el usuario, del 1 al 10.
 * 
 * Conceptos que aprenderás:
 * - Uso básico del ciclo for
 * - Entrada de datos del usuario
 * - Operaciones aritméticas dentro de un ciclo
 * - Formato de salida
 */

#include <iostream>
using namespace std;

int main() {
    // Variable para almacenar el número del cual queremos la tabla
    int numero_base;
    
    // Solicitar al usuario el número
    cout << "=== TABLA DE MULTIPLICAR ===" << endl;
    cout << "Ingrese un numero: ";
    cin >> numero_base;
    
    // Mostrar encabezado
    cout << "\nTabla del " << numero_base << ":" << endl;
    cout << "------------------------" << endl;
    
    // Ciclo for que va del 1 al 10
    // - Inicialización: multiplicador = 1
    // - Condición: multiplicador <= 10 (mientras sea menor o igual a 10)
    // - Actualización: multiplicador++ (incrementa de 1 en 1)
    for(int multiplicador = 1; multiplicador <= 10; multiplicador++) {
        // Calcular el resultado de la multiplicación
        int resultado = numero_base * multiplicador;
        
        // Mostrar la operación y el resultado
        cout << numero_base << " x " << multiplicador << " = " << resultado << endl;
    }
    
    cout << "------------------------" << endl;
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === TABLA DE MULTIPLICAR ===
 * Ingrese un numero: 7
 * 
 * Tabla del 7:
 * ------------------------
 * 7 x 1 = 7
 * 7 x 2 = 14
 * 7 x 3 = 21
 * 7 x 4 = 28
 * 7 x 5 = 35
 * 7 x 6 = 42
 * 7 x 7 = 49
 * 7 x 8 = 56
 * 7 x 9 = 63
 * 7 x 10 = 70
 * ------------------------
 * 
 * EXPLICACIÓN:
 * El ciclo for se ejecuta 10 veces, desde multiplicador=1 hasta multiplicador=10.
 * En cada iteración, multiplica el número base por el multiplicador actual.
 */
