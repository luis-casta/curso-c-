// EJERCICIOS SWITCH-CASE: Colección completa de 5 ejercicios progresivos

#include <iostream>
#include <string>
using namespace std;

// ============================================
// EJERCICIO 1: DÍAS DE LA SEMANA (FÁCIL)
// ============================================
void ejercicio1_dias_semana() {
    int numero_dia;
    
    cout << "\n=== EJERCICIO 1: DIAS DE LA SEMANA ===" << endl;
    cout << "Ingrese un numero (1-7): ";
    cin >> numero_dia;
    
    cout << "Dia seleccionado: ";
    switch(numero_dia) {
        case 1:
            cout << "Lunes" << endl;
            break;
        case 2:
            cout << "Martes" << endl;
            break;
        case 3:
            cout << "Miercoles" << endl;
            break;
        case 4:
            cout << "Jueves" << endl;
            break;
        case 5:
            cout << "Viernes" << endl;
            break;
        case 6:
            cout << "Sabado" << endl;
            break;
        case 7:
            cout << "Domingo" << endl;
            break;
        default:
            cout << "Numero invalido (debe ser 1-7)" << endl;
            break;
    }
}

// ============================================
// EJERCICIO 2: CALCULADORA BÁSICA (FÁCIL-MEDIO)
// ============================================
void ejercicio2_calculadora() {
    double numero_primero, numero_segundo, resultado;
    char operador_matematico;
    
    cout << "\n=== EJERCICIO 2: CALCULADORA ===" << endl;
    cout << "Ingrese primer numero: ";
    cin >> numero_primero;
    cout << "Ingrese operador (+, -, *, /): ";
    cin >> operador_matematico;
    cout << "Ingrese segundo numero: ";
    cin >> numero_segundo;
    
    switch(operador_matematico) {
        case '+':
            resultado = numero_primero + numero_segundo;
            cout << "Resultado: " << numero_primero << " + " << numero_segundo 
                 << " = " << resultado << endl;
            break;
            
        case '-':
            resultado = numero_primero - numero_segundo;
            cout << "Resultado: " << numero_primero << " - " << numero_segundo 
                 << " = " << resultado << endl;
            break;
            
        case '*':
            resultado = numero_primero * numero_segundo;
            cout << "Resultado: " << numero_primero << " * " << numero_segundo 
                 << " = " << resultado << endl;
            break;
            
        case '/':
            if(numero_segundo != 0) {
                resultado = numero_primero / numero_segundo;
                cout << "Resultado: " << numero_primero << " / " << numero_segundo 
                     << " = " << resultado << endl;
            } else {
                cout << "Error: Division por cero no permitida" << endl;
            }
            break;
            
        default:
            cout << "Operador invalido" << endl;
            break;
    }
}

// ============================================
// EJERCICIO 3: MENÚ DE RESTAURANTE (MEDIO)
// ============================================
void ejercicio3_menu_restaurante() {
    int opcion_menu;
    double precio_total = 0;
    char continuar;
    
    cout << "\n=== EJERCICIO 3: MENU DE RESTAURANTE ===" << endl;
    
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Hamburguesa ($50)" << endl;
        cout << "2. Pizza ($80)" << endl;
        cout << "3. Ensalada ($35)" << endl;
        cout << "4. Refresco ($15)" << endl;
        cout << "5. Postre ($25)" << endl;
        cout << "Seleccione: ";
        cin >> opcion_menu;
        
        switch(opcion_menu) {
            case 1:
                cout << "Agregado: Hamburguesa" << endl;
                precio_total += 50;
                break;
            case 2:
                cout << "Agregado: Pizza" << endl;
                precio_total += 80;
                break;
            case 3:
                cout << "Agregado: Ensalada" << endl;
                precio_total += 35;
                break;
            case 4:
                cout << "Agregado: Refresco" << endl;
                precio_total += 15;
                break;
            case 5:
                cout << "Agregado: Postre" << endl;
                precio_total += 25;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        
        cout << "¿Agregar mas items? (s/n): ";
        cin >> continuar;
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "\nTotal a pagar: $" << precio_total << endl;
}

// ============================================
// EJERCICIO 4: CALIFICACIONES (MEDIO-DIFÍCIL)
// ============================================
void ejercicio4_calificaciones() {
    double calificacion_numerica;
    char calificacion_letra;
    
    cout << "\n=== EJERCICIO 4: SISTEMA DE CALIFICACIONES ===" << endl;
    cout << "Ingrese calificacion numerica (0-100): ";
    cin >> calificacion_numerica;
    
    // Convertir a letra
    if(calificacion_numerica >= 90) {
        calificacion_letra = 'A';
    } else if(calificacion_numerica >= 80) {
        calificacion_letra = 'B';
    } else if(calificacion_numerica >= 70) {
        calificacion_letra = 'C';
    } else if(calificacion_numerica >= 60) {
        calificacion_letra = 'D';
    } else {
        calificacion_letra = 'F';
    }
    
    cout << "Calificacion: " << calificacion_letra << endl;
    
    // Descripción según la letra
    switch(calificacion_letra) {
        case 'A':
            cout << "Excelente trabajo!" << endl;
            cout << "Rango: 90-100" << endl;
            cout << "Estado: APROBADO con honores" << endl;
            break;
            
        case 'B':
            cout << "Muy buen trabajo!" << endl;
            cout << "Rango: 80-89" << endl;
            cout << "Estado: APROBADO" << endl;
            break;
            
        case 'C':
            cout << "Buen trabajo" << endl;
            cout << "Rango: 70-79" << endl;
            cout << "Estado: APROBADO" << endl;
            break;
            
        case 'D':
            cout << "Trabajo aceptable" << endl;
            cout << "Rango: 60-69" << endl;
            cout << "Estado: APROBADO (minimo)" << endl;
            break;
            
        case 'F':
            cout << "Necesitas mejorar" << endl;
            cout << "Rango: 0-59" << endl;
            cout << "Estado: REPROBADO" << endl;
            break;
            
        default:
            cout << "Calificacion no reconocida" << endl;
            break;
    }
}

// ============================================
// EJERCICIO 5: SISTEMA COMPLETO (DIFÍCIL)
// ============================================
void ejercicio5_sistema_completo() {
    int opcion_principal;
    
    cout << "\n=== EJERCICIO 5: SISTEMA DE GESTION ===" << endl;
    
    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Gestion de Estudiantes" << endl;
        cout << "2. Gestion de Profesores" << endl;
        cout << "3. Gestion de Cursos" << endl;
        cout << "4. Reportes" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion_principal;
        
        switch(opcion_principal) {
            case 1: {
                int sub_opcion;
                cout << "\n--- ESTUDIANTES ---" << endl;
                cout << "1. Registrar" << endl;
                cout << "2. Consultar" << endl;
                cout << "3. Modificar" << endl;
                cout << "Opcion: ";
                cin >> sub_opcion;
                
                switch(sub_opcion) {
                    case 1:
                        cout << "Registrando estudiante..." << endl;
                        break;
                    case 2:
                        cout << "Consultando estudiante..." << endl;
                        break;
                    case 3:
                        cout << "Modificando estudiante..." << endl;
                        break;
                    default:
                        cout << "Opcion invalida" << endl;
                }
                break;
            }
            
            case 2:
                cout << "\nGestion de Profesores (en desarrollo)" << endl;
                break;
                
            case 3:
                cout << "\nGestion de Cursos (en desarrollo)" << endl;
                break;
                
            case 4:
                cout << "\nGenerando reportes..." << endl;
                break;
                
            case 0:
                cout << "\n¡Hasta luego!" << endl;
                break;
                
            default:
                cout << "\nOpcion invalida" << endl;
                break;
        }
        
    } while(opcion_principal != 0);
}

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================
int main() {
    int ejercicio_seleccionado;
    
    do {
        cout << "\n========================================" << endl;
        cout << "    EJERCICIOS DE SWITCH-CASE" << endl;
        cout << "========================================" << endl;
        cout << "1. Dias de la semana" << endl;
        cout << "2. Calculadora basica" << endl;
        cout << "3. Menu de restaurante" << endl;
        cout << "4. Sistema de calificaciones" << endl;
        cout << "5. Sistema completo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione ejercicio: ";
        cin >> ejercicio_seleccionado;
        
        switch(ejercicio_seleccionado) {
            case 1:
                ejercicio1_dias_semana();
                break;
            case 2:
                ejercicio2_calculadora();
                break;
            case 3:
                ejercicio3_menu_restaurante();
                break;
            case 4:
                ejercicio4_calificaciones();
                break;
            case 5:
                ejercicio5_sistema_completo();
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
