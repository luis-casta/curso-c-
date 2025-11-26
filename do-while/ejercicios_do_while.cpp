// EJERCICIOS DO-WHILE: Colección completa de 5 ejercicios progresivos

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ============================================
// EJERCICIO 1: VALIDACIÓN DE NÚMERO (FÁCIL)
// ============================================
void ejercicio1_validacion_numero() {
    int numero_ingresado;
    
    cout << "\n=== EJERCICIO 1: VALIDACION DE NUMERO ===" << endl;
    
    do {
        cout << "Ingrese un numero entre 1 y 100: ";
        cin >> numero_ingresado;
        
        if(numero_ingresado < 1 || numero_ingresado > 100) {
            cout << "Error: Numero fuera de rango. Intente nuevamente." << endl;
        }
    } while(numero_ingresado < 1 || numero_ingresado > 100);
    
    cout << "¡Numero valido! Ingresaste: " << numero_ingresado << endl;
}

// ============================================
// EJERCICIO 2: MENÚ SIMPLE (FÁCIL-MEDIO)
// ============================================
void ejercicio2_menu_simple() {
    int opcion_menu;
    
    cout << "\n=== EJERCICIO 2: MENU SIMPLE ===" << endl;
    
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Saludar" << endl;
        cout << "2. Despedirse" << endl;
        cout << "3. Mostrar hora actual" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion_menu;
        
        switch(opcion_menu) {
            case 1:
                cout << "¡Hola! Bienvenido" << endl;
                break;
            case 2:
                cout << "¡Hasta luego!" << endl;
                break;
            case 3:
                cout << "Mostrando hora..." << endl;
                break;
            case 0:
                cout << "Saliendo del menu..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
        
    } while(opcion_menu != 0);
}

// ============================================
// EJERCICIO 3: JUEGO ADIVINANZA (MEDIO)
// ============================================
void ejercicio3_juego_adivinanza() {
    srand(time(0));
    int numero_secreto = rand() % 100 + 1;
    int intento_usuario;
    int cantidad_intentos = 0;
    
    cout << "\n=== EJERCICIO 3: JUEGO DE ADIVINANZA ===" << endl;
    cout << "Adivina el numero entre 1 y 100" << endl;
    
    do {
        cantidad_intentos++;
        cout << "\nIntento #" << cantidad_intentos << ": ";
        cin >> intento_usuario;
        
        if(intento_usuario < numero_secreto) {
            cout << "Muy bajo! Intenta con un numero mayor" << endl;
        } else if(intento_usuario > numero_secreto) {
            cout << "Muy alto! Intenta con un numero menor" << endl;
        } else {
            cout << "\n¡FELICIDADES! Adivinaste el numero!" << endl;
            cout << "Numero de intentos: " << cantidad_intentos << endl;
        }
        
    } while(intento_usuario != numero_secreto);
}

// ============================================
// EJERCICIO 4: CALCULADORA REPETITIVA (MEDIO-DIFÍCIL)
// ============================================
void ejercicio4_calculadora_repetitiva() {
    char continuar_calculando;
    
    cout << "\n=== EJERCICIO 4: CALCULADORA REPETITIVA ===" << endl;
    
    do {
        double numero_uno, numero_dos;
        char operador;
        
        cout << "\nIngrese primer numero: ";
        cin >> numero_uno;
        cout << "Ingrese operador (+, -, *, /): ";
        cin >> operador;
        cout << "Ingrese segundo numero: ";
        cin >> numero_dos;
        
        switch(operador) {
            case '+':
                cout << "Resultado: " << (numero_uno + numero_dos) << endl;
                break;
            case '-':
                cout << "Resultado: " << (numero_uno - numero_dos) << endl;
                break;
            case '*':
                cout << "Resultado: " << (numero_uno * numero_dos) << endl;
                break;
            case '/':
                if(numero_dos != 0) {
                    cout << "Resultado: " << (numero_uno / numero_dos) << endl;
                } else {
                    cout << "Error: Division por cero" << endl;
                }
                break;
            default:
                cout << "Operador invalido" << endl;
        }
        
        cout << "\n¿Realizar otra operacion? (s/n): ";
        cin >> continuar_calculando;
        
    } while(continuar_calculando == 's' || continuar_calculando == 'S');
    
    cout << "¡Gracias por usar la calculadora!" << endl;
}

// ============================================
// EJERCICIO 5: SISTEMA DE LOGIN (DIFÍCIL)
// ============================================
void ejercicio5_sistema_login() {
    const string usuario_correcto = "admin";
    const string contrasena_correcta = "1234";
    string usuario_ingresado, contrasena_ingresada;
    int intentos_restantes = 3;
    bool acceso_concedido = false;
    
    cout << "\n=== EJERCICIO 5: SISTEMA DE LOGIN ===" << endl;
    
    do {
        cout << "\n--- INICIO DE SESION ---" << endl;
        cout << "Intentos restantes: " << intentos_restantes << endl;
        
        cout << "Usuario: ";
        cin >> usuario_ingresado;
        cout << "Contraseña: ";
        cin >> contrasena_ingresada;
        
        if(usuario_ingresado == usuario_correcto && 
           contrasena_ingresada == contrasena_correcta) {
            acceso_concedido = true;
            cout << "\n¡Acceso concedido! Bienvenido " << usuario_ingresado << endl;
            
            // Menú del sistema
            int opcion_sistema;
            do {
                cout << "\n--- MENU DEL SISTEMA ---" << endl;
                cout << "1. Ver perfil" << endl;
                cout << "2. Configuracion" << endl;
                cout << "3. Ayuda" << endl;
                cout << "0. Cerrar sesion" << endl;
                cout << "Opcion: ";
                cin >> opcion_sistema;
                
                switch(opcion_sistema) {
                    case 1:
                        cout << "Mostrando perfil..." << endl;
                        break;
                    case 2:
                        cout << "Abriendo configuracion..." << endl;
                        break;
                    case 3:
                        cout << "Mostrando ayuda..." << endl;
                        break;
                    case 0:
                        cout << "Cerrando sesion..." << endl;
                        break;
                    default:
                        cout << "Opcion invalida" << endl;
                }
            } while(opcion_sistema != 0);
            
        } else {
            intentos_restantes--;
            if(intentos_restantes > 0) {
                cout << "Usuario o contraseña incorrectos" << endl;
            } else {
                cout << "\n¡CUENTA BLOQUEADA!" << endl;
                cout << "Ha excedido el numero maximo de intentos" << endl;
            }
        }
        
    } while(!acceso_concedido && intentos_restantes > 0);
}

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================
int main() {
    int ejercicio_seleccionado;
    
    do {
        cout << "\n========================================" << endl;
        cout << "      EJERCICIOS DE DO-WHILE" << endl;
        cout << "========================================" << endl;
        cout << "1. Validacion de numero" << endl;
        cout << "2. Menu simple" << endl;
        cout << "3. Juego de adivinanza" << endl;
        cout << "4. Calculadora repetitiva" << endl;
        cout << "5. Sistema de login" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione ejercicio: ";
        cin >> ejercicio_seleccionado;
        
        switch(ejercicio_seleccionado) {
            case 1:
                ejercicio1_validacion_numero();
                break;
            case 2:
                ejercicio2_menu_simple();
                break;
            case 3:
                ejercicio3_juego_adivinanza();
                break;
            case 4:
                ejercicio4_calculadora_repetitiva();
                break;
            case 5:
                ejercicio5_sistema_login();
                break;
            case 0:
                cout << "\n¡Adios!" << endl;
                break;
            default:
                cout << "\nEjercicio invalido" << endl;
        }
        
    } while(ejercicio_seleccionado != 0);
    
    return 0;
}
