/*
 * EJERCICIO WHILE 1: VALIDACIÓN DE ENTRADA (NIVEL FÁCIL)
 * 
 * Descripción:
 * Este programa solicita al usuario que ingrese un número dentro de un
 * rango específico (1-10). Si el número está fuera del rango, el programa
 * sigue pidiendo la entrada hasta que sea válida.
 * 
 * Conceptos que aprenderás:
 * - Uso básico del ciclo while
 * - Validación de entrada del usuario
 * - Condiciones lógicas compuestas (AND, OR)
 * - Bucle de validación
 */

#include <iostream>
using namespace std;

int main() {
    // Constantes para definir el rango válido
    const int VALOR_MINIMO = 1;
    const int VALOR_MAXIMO = 10;
    
    // Variable para almacenar el número ingresado
    int numero_ingresado;
    
    // Bandera para controlar si la entrada es válida
    bool entrada_valida = false;
    
    cout << "=== VALIDACION DE ENTRADA ===" << endl;
    cout << "Debe ingresar un numero entre " << VALOR_MINIMO 
         << " y " << VALOR_MAXIMO << endl << endl;
    
    // Ciclo while que continúa mientras la entrada NO sea válida
    // El ciclo se repite hasta que entrada_valida sea true
    while(!entrada_valida) {
        cout << "Ingrese un numero: ";
        cin >> numero_ingresado;
        
        // Verificar si el número está dentro del rango válido
        if(numero_ingresado >= VALOR_MINIMO && numero_ingresado <= VALOR_MAXIMO) {
            // El número es válido
            entrada_valida = true;
            cout << "\n¡Excelente! El numero " << numero_ingresado 
                 << " es valido." << endl;
        }
        else {
            // El número NO es válido, mostrar mensaje de error
            cout << "Error: El numero debe estar entre " << VALOR_MINIMO 
                 << " y " << VALOR_MAXIMO << endl;
            cout << "Intente nuevamente." << endl << endl;
        }
    }
    
    // Una vez que salimos del ciclo, tenemos un número válido
    cout << "\n--- RESULTADO ---" << endl;
    cout << "Numero validado: " << numero_ingresado << endl;
    
    // Mostrar información adicional sobre el número
    if(numero_ingresado % 2 == 0) {
        cout << "El numero es PAR" << endl;
    } else {
        cout << "El numero es IMPAR" << endl;
    }
    
    // Calcular el cuadrado del número
    int cuadrado = numero_ingresado * numero_ingresado;
    cout << "El cuadrado de " << numero_ingresado << " es: " << cuadrado << endl;
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA (con entradas incorrectas):
 * 
 * === VALIDACION DE ENTRADA ===
 * Debe ingresar un numero entre 1 y 10
 * 
 * Ingrese un numero: 15
 * Error: El numero debe estar entre 1 y 10
 * Intente nuevamente.
 * 
 * Ingrese un numero: -3
 * Error: El numero debe estar entre 1 y 10
 * Intente nuevamente.
 * 
 * Ingrese un numero: 0
 * Error: El numero debe estar entre 1 y 10
 * Intente nuevamente.
 * 
 * Ingrese un numero: 7
 * 
 * ¡Excelente! El numero 7 es valido.
 * 
 * --- RESULTADO ---
 * Numero validado: 7
 * El numero es IMPAR
 * El cuadrado de 7 es: 49
 * 
 * EXPLICACIÓN:
 * - El ciclo while continúa mientras entrada_valida sea false
 * - En cada iteración, se solicita un número al usuario
 * - Si el número está en el rango [1, 10], entrada_valida se vuelve true
 * - Si no está en el rango, se muestra un error y el ciclo continúa
 * - El ciclo termina cuando entrada_valida es true
 * 
 * VENTAJA DEL WHILE:
 * No sabemos cuántas veces el usuario ingresará un número incorrecto,
 * por eso while es más apropiado que for en este caso.
 */
