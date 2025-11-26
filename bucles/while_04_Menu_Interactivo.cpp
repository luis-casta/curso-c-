/*
 * EJERCICIO WHILE 4: MENÚ INTERACTIVO (NIVEL MEDIO-DIFÍCIL)
 * 
 * Descripción:
 * Este programa implementa un menú interactivo con múltiples opciones
 * para realizar operaciones matemáticas. El menú se repite hasta que
 * el usuario elija salir.
 * 
 * Conceptos que aprenderás:
 * - Ciclo while para menús
 * - Switch-case dentro de while
 * - Validación de opciones
 * - Funciones matemáticas
 * - Organización de código
 */

#include <iostream>
#include <cmath>   // Para pow(), sqrt()
#include <iomanip> // Para setprecision
using namespace std;

int main() {
    // Variable para almacenar la opción del usuario
    int opcion_menu = -1;
    
    // Variables para operaciones
    double numero_uno, numero_dos, resultado;
    int numero_entero, numero_tabla, multiplicador;
    long long factorial;
    int contador;
    
    // Mostrar bienvenida
    cout << "========================================" << endl;
    cout << "   CALCULADORA CIENTIFICA INTERACTIVA   " << endl;
    cout << "========================================" << endl;
    
    // Ciclo principal del menú
    // Continúa mientras la opción NO sea 0 (salir)
    while(opcion_menu != 0) {
        // Mostrar el menú
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. Potencia (a^b)" << endl;
        cout << "6. Raiz cuadrada" << endl;
        cout << "7. Factorial" << endl;
        cout << "8. Tabla de multiplicar" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_menu;
        
        // Procesar la opción seleccionada
        switch(opcion_menu) {
            case 1: // Suma
                cout << "\n=== SUMA ===" << endl;
                cout << "Ingrese el primer numero: ";
                cin >> numero_uno;
                cout << "Ingrese el segundo numero: ";
                cin >> numero_dos;
                resultado = numero_uno + numero_dos;
                cout << "Resultado: " << numero_uno << " + " << numero_dos 
                     << " = " << resultado << endl;
                break;
                
            case 2: // Resta
                cout << "\n=== RESTA ===" << endl;
                cout << "Ingrese el primer numero: ";
                cin >> numero_uno;
                cout << "Ingrese el segundo numero: ";
                cin >> numero_dos;
                resultado = numero_uno - numero_dos;
                cout << "Resultado: " << numero_uno << " - " << numero_dos 
                     << " = " << resultado << endl;
                break;
                
            case 3: // Multiplicación
                cout << "\n=== MULTIPLICACION ===" << endl;
                cout << "Ingrese el primer numero: ";
                cin >> numero_uno;
                cout << "Ingrese el segundo numero: ";
                cin >> numero_dos;
                resultado = numero_uno * numero_dos;
                cout << "Resultado: " << numero_uno << " × " << numero_dos 
                     << " = " << resultado << endl;
                break;
                
            case 4: // División
                cout << "\n=== DIVISION ===" << endl;
                cout << "Ingrese el dividendo: ";
                cin >> numero_uno;
                cout << "Ingrese el divisor: ";
                cin >> numero_dos;
                
                // Validar que el divisor no sea cero
                if(numero_dos == 0) {
                    cout << "Error: No se puede dividir entre cero." << endl;
                } else {
                    resultado = numero_uno / numero_dos;
                    cout << fixed << setprecision(4);
                    cout << "Resultado: " << numero_uno << " ÷ " << numero_dos 
                         << " = " << resultado << endl;
                }
                break;
                
            case 5: // Potencia
                cout << "\n=== POTENCIA ===" << endl;
                cout << "Ingrese la base: ";
                cin >> numero_uno;
                cout << "Ingrese el exponente: ";
                cin >> numero_dos;
                resultado = pow(numero_uno, numero_dos);
                cout << "Resultado: " << numero_uno << "^" << numero_dos 
                     << " = " << resultado << endl;
                break;
                
            case 6: // Raíz cuadrada
                cout << "\n=== RAIZ CUADRADA ===" << endl;
                cout << "Ingrese el numero: ";
                cin >> numero_uno;
                
                // Validar que el número sea no negativo
                if(numero_uno < 0) {
                    cout << "Error: No se puede calcular la raiz de un numero negativo." << endl;
                } else {
                    resultado = sqrt(numero_uno);
                    cout << fixed << setprecision(4);
                    cout << "Resultado: √" << numero_uno << " = " << resultado << endl;
                }
                break;
                
            case 7: // Factorial
                cout << "\n=== FACTORIAL ===" << endl;
                cout << "Ingrese un numero entero positivo: ";
                cin >> numero_entero;
                
                // Validar que sea positivo
                if(numero_entero < 0) {
                    cout << "Error: El factorial solo existe para numeros no negativos." << endl;
                } else if(numero_entero > 20) {
                    cout << "Advertencia: El factorial de numeros grandes puede causar overflow." << endl;
                    cout << "Calculando factorial de " << numero_entero << "..." << endl;
                }
                
                // Calcular factorial
                if(numero_entero >= 0) {
                    factorial = 1;
                    contador = 1;
                    
                    // Usar while para calcular el factorial
                    while(contador <= numero_entero) {
                        factorial *= contador;
                        contador++;
                    }
                    
                    cout << "Resultado: " << numero_entero << "! = " << factorial << endl;
                }
                break;
                
            case 8: // Tabla de multiplicar
                cout << "\n=== TABLA DE MULTIPLICAR ===" << endl;
                cout << "Ingrese el numero: ";
                cin >> numero_tabla;
                
                cout << "\nTabla del " << numero_tabla << ":" << endl;
                cout << "-------------------" << endl;
                
                multiplicador = 1;
                while(multiplicador <= 10) {
                    cout << numero_tabla << " × " << multiplicador << " = " 
                         << (numero_tabla * multiplicador) << endl;
                    multiplicador++;
                }
                break;
                
            case 0: // Salir
                cout << "\n¡Gracias por usar la calculadora!" << endl;
                cout << "Programa terminado." << endl;
                break;
                
            default: // Opción inválida
                cout << "\nError: Opcion invalida." << endl;
                cout << "Por favor, seleccione una opcion del menu." << endl;
                break;
        }
        
        // Pausa antes de mostrar el menú nuevamente
        if(opcion_menu != 0) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }
    
    cout << "\n========================================" << endl;
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * ========================================
 *    CALCULADORA CIENTIFICA INTERACTIVA   
 * ========================================
 * 
 * --- MENU PRINCIPAL ---
 * 1. Suma
 * 2. Resta
 * 3. Multiplicacion
 * 4. Division
 * 5. Potencia (a^b)
 * 6. Raiz cuadrada
 * 7. Factorial
 * 8. Tabla de multiplicar
 * 0. Salir
 * ----------------------
 * Seleccione una opcion: 5
 * 
 * === POTENCIA ===
 * Ingrese la base: 2
 * Ingrese el exponente: 10
 * Resultado: 2^10 = 1024
 * 
 * Presione Enter para continuar...
 * 
 * --- MENU PRINCIPAL ---
 * 1. Suma
 * 2. Resta
 * 3. Multiplicacion
 * 4. Division
 * 5. Potencia (a^b)
 * 6. Raiz cuadrada
 * 7. Factorial
 * 8. Tabla de multiplicar
 * 0. Salir
 * ----------------------
 * Seleccione una opcion: 7
 * 
 * === FACTORIAL ===
 * Ingrese un numero entero positivo: 5
 * Resultado: 5! = 120
 * 
 * Presione Enter para continuar...
 * 
 * --- MENU PRINCIPAL ---
 * [...]
 * Seleccione una opcion: 0
 * 
 * ¡Gracias por usar la calculadora!
 * Programa terminado.
 * 
 * ========================================
 * 
 * EXPLICACIÓN:
 * - El ciclo while continúa mientras opcion_menu != 0
 * - En cada iteración:
 *   1. Se muestra el menú
 *   2. Se lee la opción del usuario
 *   3. Se ejecuta la operación correspondiente con switch-case
 *   4. Se espera que el usuario presione Enter
 * - El ciclo termina cuando el usuario selecciona 0 (Salir)
 * 
 * PATRÓN DE MENÚ:
 * - Muy común en aplicaciones de consola
 * - Permite al usuario realizar múltiples operaciones
 * - El menú se repite hasta que el usuario decida salir
 * 
 * VALIDACIONES:
 * - División por cero
 * - Raíz cuadrada de números negativos
 * - Factorial de números negativos
 * - Opciones inválidas del menú
 */
