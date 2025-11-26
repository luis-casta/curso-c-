/*
 * EJERCICIO WHILE 5: SIMULADOR DE CAJERO AUTOMÁTICO (NIVEL DIFÍCIL)
 * 
 * Descripción:
 * Este programa simula un cajero automático completo con autenticación,
 * múltiples operaciones bancarias, historial de transacciones y límites
 * de seguridad. Demuestra el uso avanzado de ciclos while anidados.
 * 
 * Conceptos que aprenderás:
 * - Ciclos while anidados
 * - Sistema de autenticación
 * - Gestión de estado (saldo, intentos)
 * - Validaciones complejas
 * - Simulación de sistema real
 * - Límites de seguridad
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Configuración de la cuenta (en un sistema real, esto vendría de una base de datos)
    const string PIN_CORRECTO = "1234";
    const int MAX_INTENTOS_PIN = 3;
    const double SALDO_INICIAL = 1000.00;
    const double LIMITE_RETIRO_DIARIO = 500.00;
    const double MONTO_MINIMO_DEPOSITO = 10.00;
    
    // Variables del sistema
    double saldo_actual = SALDO_INICIAL;
    double total_retirado_hoy = 0.0;
    int cantidad_transacciones = 0;
    bool sesion_activa = false;
    
    // Mostrar pantalla de bienvenida
    cout << "========================================" << endl;
    cout << "      CAJERO AUTOMATICO BANCARIO       " << endl;
    cout << "========================================" << endl;
    
    // FASE 1: AUTENTICACIÓN
    string pin_ingresado;
    int intentos_realizados = 0;
    bool autenticacion_exitosa = false;
    
    cout << "\n--- AUTENTICACION ---" << endl;
    
    // Ciclo de autenticación (máximo 3 intentos)
    while(intentos_realizados < MAX_INTENTOS_PIN && !autenticacion_exitosa) {
        intentos_realizados++;
        
        cout << "\nIntento " << intentos_realizados << " de " << MAX_INTENTOS_PIN << endl;
        cout << "Ingrese su PIN: ";
        cin >> pin_ingresado;
        
        if(pin_ingresado == PIN_CORRECTO) {
            autenticacion_exitosa = true;
            sesion_activa = true;
            cout << "\n¡Autenticacion exitosa!" << endl;
            cout << "Bienvenido a su cuenta." << endl;
        } else {
            int intentos_restantes = MAX_INTENTOS_PIN - intentos_realizados;
            if(intentos_restantes > 0) {
                cout << "PIN incorrecto." << endl;
                cout << "Intentos restantes: " << intentos_restantes << endl;
            }
        }
    }
    
    // Verificar si se bloqueó la cuenta
    if(!autenticacion_exitosa) {
        cout << "\n¡CUENTA BLOQUEADA!" << endl;
        cout << "Ha excedido el numero maximo de intentos." << endl;
        cout << "Por favor, contacte a su banco." << endl;
        return 1;
    }
    
    // FASE 2: MENÚ DE OPERACIONES
    int opcion_seleccionada = -1;
    
    // Ciclo principal del cajero
    while(sesion_activa) {
        // Mostrar menú principal
        cout << "\n========================================" << endl;
        cout << "           MENU PRINCIPAL               " << endl;
        cout << "========================================" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Depositar dinero" << endl;
        cout << "4. Ver historial de transacciones" << endl;
        cout << "5. Cambiar PIN" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_seleccionada;
        
        switch(opcion_seleccionada) {
            case 1: { // Consultar saldo
                cout << "\n--- CONSULTA DE SALDO ---" << endl;
                cout << fixed << setprecision(2);
                cout << "Saldo actual: $" << saldo_actual << endl;
                cout << "Limite de retiro disponible hoy: $" 
                     << (LIMITE_RETIRO_DIARIO - total_retirado_hoy) << endl;
                cantidad_transacciones++;
                break;
            }
            
            case 2: { // Retirar dinero
                cout << "\n--- RETIRO DE DINERO ---" << endl;
                cout << "Saldo disponible: $" << saldo_actual << endl;
                cout << "Limite de retiro disponible hoy: $" 
                     << (LIMITE_RETIRO_DIARIO - total_retirado_hoy) << endl;
                
                double monto_retiro;
                cout << "\nIngrese el monto a retirar: $";
                cin >> monto_retiro;
                
                // Validaciones
                bool retiro_valido = true;
                
                if(monto_retiro <= 0) {
                    cout << "Error: El monto debe ser mayor a cero." << endl;
                    retiro_valido = false;
                }
                else if(monto_retiro > saldo_actual) {
                    cout << "Error: Saldo insuficiente." << endl;
                    retiro_valido = false;
                }
                else if(total_retirado_hoy + monto_retiro > LIMITE_RETIRO_DIARIO) {
                    cout << "Error: Excede el limite de retiro diario." << endl;
                    cout << "Puede retirar maximo: $" 
                         << (LIMITE_RETIRO_DIARIO - total_retirado_hoy) << endl;
                    retiro_valido = false;
                }
                
                // Realizar retiro si es válido
                if(retiro_valido) {
                    saldo_actual -= monto_retiro;
                    total_retirado_hoy += monto_retiro;
                    cantidad_transacciones++;
                    
                    cout << "\n¡Retiro exitoso!" << endl;
                    cout << "Monto retirado: $" << monto_retiro << endl;
                    cout << "Nuevo saldo: $" << saldo_actual << endl;
                    cout << "\nPor favor, retire su dinero." << endl;
                }
                break;
            }
            
            case 3: { // Depositar dinero
                cout << "\n--- DEPOSITO DE DINERO ---" << endl;
                cout << "Saldo actual: $" << saldo_actual << endl;
                
                double monto_deposito;
                cout << "\nIngrese el monto a depositar: $";
                cin >> monto_deposito;
                
                // Validaciones
                if(monto_deposito < MONTO_MINIMO_DEPOSITO) {
                    cout << "Error: El deposito minimo es $" << MONTO_MINIMO_DEPOSITO << endl;
                }
                else if(monto_deposito <= 0) {
                    cout << "Error: El monto debe ser mayor a cero." << endl;
                }
                else {
                    saldo_actual += monto_deposito;
                    cantidad_transacciones++;
                    
                    cout << "\n¡Deposito exitoso!" << endl;
                    cout << "Monto depositado: $" << monto_deposito << endl;
                    cout << "Nuevo saldo: $" << saldo_actual << endl;
                }
                break;
            }
            
            case 4: { // Ver historial
                cout << "\n--- HISTORIAL DE TRANSACCIONES ---" << endl;
                cout << "Total de transacciones realizadas: " << cantidad_transacciones << endl;
                cout << "Saldo inicial: $" << SALDO_INICIAL << endl;
                cout << "Saldo actual: $" << saldo_actual << endl;
                
                double cambio_saldo = saldo_actual - SALDO_INICIAL;
                if(cambio_saldo > 0) {
                    cout << "Incremento neto: +$" << cambio_saldo << endl;
                } else if(cambio_saldo < 0) {
                    cout << "Decremento neto: -$" << (-cambio_saldo) << endl;
                } else {
                    cout << "Sin cambios en el saldo" << endl;
                }
                
                cout << "Total retirado hoy: $" << total_retirado_hoy << endl;
                break;
            }
            
            case 5: { // Cambiar PIN
                cout << "\n--- CAMBIO DE PIN ---" << endl;
                cout << "Nota: En un sistema real, esto actualizaria la base de datos." << endl;
                cout << "Por seguridad, esta funcion esta deshabilitada en esta simulacion." << endl;
                break;
            }
            
            case 0: { // Salir
                cout << "\n--- CERRANDO SESION ---" << endl;
                cout << "Resumen de la sesion:" << endl;
                cout << "- Transacciones realizadas: " << cantidad_transacciones << endl;
                cout << "- Saldo final: $" << saldo_actual << endl;
                cout << "\n¡Gracias por usar nuestro cajero!" << endl;
                cout << "No olvide retirar su tarjeta." << endl;
                sesion_activa = false;
                break;
            }
            
            default: {
                cout << "\nError: Opcion invalida." << endl;
                cout << "Por favor, seleccione una opcion del menu." << endl;
                break;
            }
        }
        
        // Pausa antes de mostrar el menú nuevamente
        if(sesion_activa && opcion_seleccionada != 0) {
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
 *       CAJERO AUTOMATICO BANCARIO       
 * ========================================
 * 
 * --- AUTENTICACION ---
 * 
 * Intento 1 de 3
 * Ingrese su PIN: 9999
 * PIN incorrecto.
 * Intentos restantes: 2
 * 
 * Intento 2 de 3
 * Ingrese su PIN: 1234
 * 
 * ¡Autenticacion exitosa!
 * Bienvenido a su cuenta.
 * 
 * ========================================
 *            MENU PRINCIPAL               
 * ========================================
 * 1. Consultar saldo
 * 2. Retirar dinero
 * 3. Depositar dinero
 * 4. Ver historial de transacciones
 * 5. Cambiar PIN
 * 0. Salir
 * ----------------------------------------
 * Seleccione una opcion: 1
 * 
 * --- CONSULTA DE SALDO ---
 * Saldo actual: $1000.00
 * Limite de retiro disponible hoy: $500.00
 * 
 * [... más operaciones ...]
 * 
 * Seleccione una opcion: 0
 * 
 * --- CERRANDO SESION ---
 * Resumen de la sesion:
 * - Transacciones realizadas: 3
 * - Saldo final: $950.00
 * 
 * ¡Gracias por usar nuestro cajero!
 * No olvide retirar su tarjeta.
 * 
 * ========================================
 * 
 * EXPLICACIÓN:
 * Este programa usa TRES ciclos while:
 * 
 * 1. Ciclo de autenticación:
 *    - Permite máximo 3 intentos de PIN
 *    - Bloquea la cuenta si se exceden los intentos
 * 
 * 2. Ciclo principal del menú:
 *    - Continúa mientras sesion_activa sea true
 *    - Procesa las operaciones del usuario
 * 
 * 3. Ciclos internos (implícitos en validaciones):
 *    - Verifican condiciones antes de ejecutar operaciones
 * 
 * CARACTERÍSTICAS DE SEGURIDAD:
 * - Autenticación con PIN
 * - Límite de intentos de autenticación
 * - Límite de retiro diario
 * - Validación de montos
 * - Verificación de saldo suficiente
 * 
 * APLICACIÓN REAL:
 * Este código simula un cajero automático real con:
 * - Sistema de autenticación
 * - Múltiples operaciones bancarias
 * - Validaciones de seguridad
 * - Historial de transacciones
 * - Límites de operación
 */
