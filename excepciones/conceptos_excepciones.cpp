/*
 * CONCEPTOS BÁSICOS DE MANEJO DE EXCEPCIONES
 * 
 * Este archivo demuestra los conceptos fundamentales de excepciones:
 * - Try-catch básico
 * - Throw de excepciones
 * - Tipos de excepciones
 * - Múltiples catch
 */

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// ============================================
// CONCEPTO 1: TRY-CATCH BÁSICO
// ============================================
void concepto_try_catch_basico() {
    cout << "\n=== CONCEPTO 1: TRY-CATCH BASICO ===" << endl;
    
    try {
        cout << "Inicio del bloque try" << endl;
        
        int numero_divisor = 0;
        
        if(numero_divisor == 0) {
            // Lanzar una excepción
            throw "Error: Division por cero";
        }
        
        int resultado = 10 / numero_divisor;
        cout << "Resultado: " << resultado << endl;
        
        cout << "Fin del bloque try" << endl;
        
    } catch(const char* mensaje_error) {
        // Este bloque se ejecuta si hay una excepción
        cout << "Excepcion capturada: " << mensaje_error << endl;
    }
    
    cout << "Programa continua normalmente" << endl;
}

// ============================================
// CONCEPTO 2: EXCEPCIONES ESTÁNDAR
// ============================================
void concepto_excepciones_estandar() {
    cout << "\n=== CONCEPTO 2: EXCEPCIONES ESTANDAR ===" << endl;
    
    try {
        int edad_ingresada;
        cout << "Ingrese edad: ";
        cin >> edad_ingresada;
        
        if(edad_ingresada < 0) {
            // Lanzar excepción estándar
            throw invalid_argument("La edad no puede ser negativa");
        }
        
        if(edad_ingresada > 150) {
            throw out_of_range("Edad fuera de rango razonable");
        }
        
        cout << "Edad valida: " << edad_ingresada << endl;
        
    } catch(invalid_argument& excepcion) {
        cout << "Error de argumento: " << excepcion.what() << endl;
        
    } catch(out_of_range& excepcion) {
        cout << "Error de rango: " << excepcion.what() << endl;
    }
}

// ============================================
// CONCEPTO 3: MÚLTIPLES TIPOS DE EXCEPCIONES
// ============================================
void concepto_multiples_excepciones() {
    cout << "\n=== CONCEPTO 3: MULTIPLES EXCEPCIONES ===" << endl;
    
    int opcion_tipo;
    cout << "Tipo de excepcion a lanzar (1-4): ";
    cin >> opcion_tipo;
    
    try {
        switch(opcion_tipo) {
            case 1:
                throw 42;  // Lanzar int
                break;
            case 2:
                throw 3.14;  // Lanzar double
                break;
            case 3:
                throw "Error de texto";  // Lanzar const char*
                break;
            case 4:
                throw runtime_error("Error en tiempo de ejecucion");
                break;
            default:
                cout << "No se lanza excepcion" << endl;
        }
        
    } catch(int numero_error) {
        cout << "Excepcion de tipo int: " << numero_error << endl;
        
    } catch(double numero_decimal) {
        cout << "Excepcion de tipo double: " << numero_decimal << endl;
        
    } catch(const char* mensaje) {
        cout << "Excepcion de tipo const char*: " << mensaje << endl;
        
    } catch(runtime_error& error) {
        cout << "Excepcion runtime_error: " << error.what() << endl;
        
    } catch(...) {
        // Captura CUALQUIER excepción no capturada antes
        cout << "Excepcion desconocida" << endl;
    }
}

// ============================================
// CONCEPTO 4: EXCEPCIONES EN FUNCIONES
// ============================================
double dividir_numeros(double numerador, double denominador) {
    if(denominador == 0) {
        throw invalid_argument("El denominador no puede ser cero");
    }
    return numerador / denominador;
}

void concepto_excepciones_funciones() {
    cout << "\n=== CONCEPTO 4: EXCEPCIONES EN FUNCIONES ===" << endl;
    
    double num1, num2;
    cout << "Ingrese numerador: ";
    cin >> num1;
    cout << "Ingrese denominador: ";
    cin >> num2;
    
    try {
        double resultado = dividir_numeros(num1, num2);
        cout << "Resultado: " << resultado << endl;
        
    } catch(invalid_argument& error) {
        cout << "Error: " << error.what() << endl;
        cout << "Intente con un denominador diferente" << endl;
    }
}

// ============================================
// CONCEPTO 5: EXCEPCIÓN PERSONALIZADA
// ============================================
class ExcepcionEdadInvalida : public exception {
private:
    string mensaje_error;
    
public:
    ExcepcionEdadInvalida(int edad) {
        mensaje_error = "Edad invalida: " + to_string(edad) + 
                       ". Debe estar entre 0 y 120";
    }
    
    const char* what() const noexcept override {
        return mensaje_error.c_str();
    }
};

void validar_edad(int edad) {
    if(edad < 0 || edad > 120) {
        throw ExcepcionEdadInvalida(edad);
    }
}

void concepto_excepcion_personalizada() {
    cout << "\n=== CONCEPTO 5: EXCEPCION PERSONALIZADA ===" << endl;
    
    int edad;
    cout << "Ingrese edad: ";
    cin >> edad;
    
    try {
        validar_edad(edad);
        cout << "Edad valida: " << edad << " años" << endl;
        
    } catch(ExcepcionEdadInvalida& error) {
        cout << "Error: " << error.what() << endl;
    }
}

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================
int main() {
    int opcion;
    
    do {
        cout << "\n========================================" << endl;
        cout << "   CONCEPTOS DE MANEJO DE EXCEPCIONES" << endl;
        cout << "========================================" << endl;
        cout << "1. Try-catch basico" << endl;
        cout << "2. Excepciones estandar" << endl;
        cout << "3. Multiples tipos de excepciones" << endl;
        cout << "4. Excepciones en funciones" << endl;
        cout << "5. Excepcion personalizada" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                concepto_try_catch_basico();
                break;
            case 2:
                concepto_excepciones_estandar();
                break;
            case 3:
                concepto_multiples_excepciones();
                break;
            case 4:
                concepto_excepciones_funciones();
                break;
            case 5:
                concepto_excepcion_personalizada();
                break;
            case 0:
                cout << "\n¡Adios!" << endl;
                break;
            default:
                cout << "\nOpcion invalida" << endl;
        }
        
    } while(opcion != 0);
    
    return 0;
}

/*
 * NOTAS IMPORTANTES:
 * 
 * 1. SIEMPRE usa try-catch cuando el código puede fallar
 * 2. Captura excepciones por REFERENCIA (&)
 * 3. Ordena los catch de más específico a más general
 * 4. Usa excepciones estándar cuando sea posible
 * 5. Las excepciones permiten separar el manejo de errores
 */
