/*
 * ============================================================================
 * EJERCICIO 4: MANIPULACIÓN DE BITS - SET, CLEAR, TOGGLE, CHECK (MEDIO-DIFÍCIL)
 * ============================================================================
 * 
 * OBJETIVO:
 * Implementar operaciones fundamentales de manipulación de bits individuales:
 * - SET: Activar un bit específico (ponerlo en 1)
 * - CLEAR: Desactivar un bit específico (ponerlo en 0)
 * - TOGGLE: Invertir un bit específico (0→1 o 1→0)
 * - CHECK: Verificar el estado de un bit específico
 * 
 * OPERACIONES:
 * - SET bit n:    numero |= (1 << n)
 * - CLEAR bit n:  numero &= ~(1 << n)
 * - TOGGLE bit n: numero ^= (1 << n)
 * - CHECK bit n:  (numero >> n) & 1
 * 
 * APLICACIONES:
 * - Manejo de flags y permisos
 * - Configuración de registros de hardware
 * - Optimización de memoria
 * - Sistemas embebidos
 * ============================================================================
 */

#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

// Clase para manipular bits de manera visual y educativa
class ManipuladorBits {
private:
    unsigned int numero;
    
    void mostrarEstado(string operacion = "") {
        if (operacion != "") {
            cout << "\n" << operacion << endl;
        }
        cout << "Valor decimal: " << numero << endl;
        cout << "Valor binario: ";
        bitset<16> bits(numero);
        cout << bits << endl;
        cout << "Posiciones:    ";
        for (int i = 15; i >= 0; i--) {
            cout << (i % 10);
        }
        cout << endl;
    }
    
public:
    ManipuladorBits(unsigned int valor = 0) : numero(valor) {}
    
    // Activar (SET) un bit específico
    void activarBit(int posicion) {
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║  OPERACIÓN: ACTIVAR BIT " << posicion << "         ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        mostrarEstado("Estado ANTES:");
        
        cout << "\nOperación: numero |= (1 << " << posicion << ")" << endl;
        cout << "Máscara: ";
        bitset<16> mascara(1 << posicion);
        cout << mascara << " (decimal: " << (1 << posicion) << ")" << endl;
        
        numero |= (1 << posicion);
        
        mostrarEstado("\nEstado DESPUÉS:");
        cout << "✓ Bit " << posicion << " activado" << endl;
    }
    
    // Desactivar (CLEAR) un bit específico
    void desactivarBit(int posicion) {
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║  OPERACIÓN: DESACTIVAR BIT " << posicion << "      ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        mostrarEstado("Estado ANTES:");
        
        cout << "\nOperación: numero &= ~(1 << " << posicion << ")" << endl;
        cout << "Máscara: ";
        bitset<16> mascara(~(1 << posicion));
        cout << mascara << endl;
        
        numero &= ~(1 << posicion);
        
        mostrarEstado("\nEstado DESPUÉS:");
        cout << "✓ Bit " << posicion << " desactivado" << endl;
    }
    
    // Invertir (TOGGLE) un bit específico
    void invertirBit(int posicion) {
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║  OPERACIÓN: INVERTIR BIT " << posicion << "        ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        mostrarEstado("Estado ANTES:");
        
        bool estadoAnterior = (numero >> posicion) & 1;
        
        cout << "\nOperación: numero ^= (1 << " << posicion << ")" << endl;
        cout << "Máscara: ";
        bitset<16> mascara(1 << posicion);
        cout << mascara << " (decimal: " << (1 << posicion) << ")" << endl;
        cout << "Bit actual: " << estadoAnterior << " → ";
        
        numero ^= (1 << posicion);
        
        bool estadoNuevo = (numero >> posicion) & 1;
        cout << estadoNuevo << endl;
        
        mostrarEstado("\nEstado DESPUÉS:");
        cout << "✓ Bit " << posicion << " invertido" << endl;
    }
    
    // Verificar (CHECK) el estado de un bit
    bool verificarBit(int posicion) {
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║  OPERACIÓN: VERIFICAR BIT " << posicion << "       ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        mostrarEstado("Estado actual:");
        
        bool estado = (numero >> posicion) & 1;
        
        cout << "\nOperación: (numero >> " << posicion << ") & 1" << endl;
        cout << "Resultado: " << estado << " (" << (estado ? "ACTIVADO" : "DESACTIVADO") << ")" << endl;
        
        return estado;
    }
    
    // Obtener el valor actual
    unsigned int obtenerValor() {
        return numero;
    }
    
    // Establecer un nuevo valor
    void establecerValor(unsigned int valor) {
        numero = valor;
    }
    
    // Mostrar todos los bits
    void mostrarTodos() {
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║  ESTADO DE TODOS LOS BITS          ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        mostrarEstado();
        
        cout << "\nEstado individual de cada bit:" << endl;
        for (int i = 15; i >= 0; i--) {
            bool estado = (numero >> i) & 1;
            cout << "Bit " << setw(2) << i << ": " << estado 
                 << " " << (estado ? "■" : "□") << endl;
        }
    }
};

// Ejemplo práctico: Sistema de permisos
class SistemaPermisos {
private:
    unsigned int permisos;
    
    // Definición de permisos (usando posiciones de bits)
    enum Permiso {
        LEER = 0,
        ESCRIBIR = 1,
        EJECUTAR = 2,
        ELIMINAR = 3,
        CREAR = 4,
        MODIFICAR = 5,
        COMPARTIR = 6,
        ADMIN = 7
    };
    
    string nombrePermiso(int pos) {
        switch(pos) {
            case LEER: return "LEER";
            case ESCRIBIR: return "ESCRIBIR";
            case EJECUTAR: return "EJECUTAR";
            case ELIMINAR: return "ELIMINAR";
            case CREAR: return "CREAR";
            case MODIFICAR: return "MODIFICAR";
            case COMPARTIR: return "COMPARTIR";
            case ADMIN: return "ADMIN";
            default: return "DESCONOCIDO";
        }
    }
    
public:
    SistemaPermisos() : permisos(0) {}
    
    void otorgarPermiso(int permiso) {
        permisos |= (1 << permiso);
        cout << "✓ Permiso " << nombrePermiso(permiso) << " otorgado" << endl;
    }
    
    void revocarPermiso(int permiso) {
        permisos &= ~(1 << permiso);
        cout << "✗ Permiso " << nombrePermiso(permiso) << " revocado" << endl;
    }
    
    bool tienePermiso(int permiso) {
        return (permisos >> permiso) & 1;
    }
    
    void mostrarPermisos() {
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║  PERMISOS DEL USUARIO              ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        bitset<8> bits(permisos);
        cout << "Estado binario: " << bits << endl;
        cout << "\nPermisos activos:" << endl;
        
        for (int i = 0; i < 8; i++) {
            bool tiene = tienePermiso(i);
            cout << "[" << (tiene ? "✓" : " ") << "] " 
                 << nombrePermiso(i) << endl;
        }
    }
};

int main() {
    cout << "============================================" << endl;
    cout << "  EJERCICIO 4: MANIPULACIÓN DE BITS       " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Operaciones básicas
    cout << "\n=== EJEMPLO 1: Operaciones básicas ===" << endl;
    ManipuladorBits manipulador(0);
    
    manipulador.activarBit(3);
    manipulador.activarBit(5);
    manipulador.activarBit(7);
    
    manipulador.verificarBit(5);
    manipulador.verificarBit(4);
    
    manipulador.invertirBit(5);
    manipulador.invertirBit(4);
    
    manipulador.desactivarBit(7);
    
    manipulador.mostrarTodos();
    
    // Ejemplo 2: Sistema de permisos
    cout << "\n\n=== EJEMPLO 2: Sistema de permisos ===" << endl;
    SistemaPermisos usuario;
    
    cout << "\nOtorgando permisos básicos..." << endl;
    usuario.otorgarPermiso(0);  // LEER
    usuario.otorgarPermiso(1);  // ESCRIBIR
    usuario.otorgarPermiso(2);  // EJECUTAR
    
    usuario.mostrarPermisos();
    
    cout << "\nOtorgando permisos adicionales..." << endl;
    usuario.otorgarPermiso(4);  // CREAR
    usuario.otorgarPermiso(5);  // MODIFICAR
    
    usuario.mostrarPermisos();
    
    cout << "\nRevocando permiso de escritura..." << endl;
    usuario.revocarPermiso(1);  // ESCRIBIR
    
    usuario.mostrarPermisos();
    
    // Ejemplo 3: Verificación de permisos
    cout << "\n\n=== EJEMPLO 3: Verificación de permisos ===" << endl;
    cout << "¿Puede LEER? " << (usuario.tienePermiso(0) ? "SÍ ✓" : "NO ✗") << endl;
    cout << "¿Puede ESCRIBIR? " << (usuario.tienePermiso(1) ? "SÍ ✓" : "NO ✗") << endl;
    cout << "¿Puede ELIMINAR? " << (usuario.tienePermiso(3) ? "SÍ ✓" : "NO ✗") << endl;
    cout << "¿Es ADMIN? " << (usuario.tienePermiso(7) ? "SÍ ✓" : "NO ✗") << endl;
    
    // Ejemplo 4: Manipulación interactiva
    cout << "\n\n=== EJEMPLO 4: Manipulación interactiva ===" << endl;
    ManipuladorBits interactivo(0);
    
    int opcion;
    do {
        cout << "\n--- MENÚ DE OPERACIONES ---" << endl;
        cout << "1. Activar un bit" << endl;
        cout << "2. Desactivar un bit" << endl;
        cout << "3. Invertir un bit" << endl;
        cout << "4. Verificar un bit" << endl;
        cout << "5. Mostrar todos los bits" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        
        if (opcion >= 1 && opcion <= 4) {
            int posicion;
            cout << "Ingresa la posición del bit (0-15): ";
            cin >> posicion;
            
            if (posicion >= 0 && posicion <= 15) {
                switch(opcion) {
                    case 1: interactivo.activarBit(posicion); break;
                    case 2: interactivo.desactivarBit(posicion); break;
                    case 3: interactivo.invertirBit(posicion); break;
                    case 4: interactivo.verificarBit(posicion); break;
                }
            } else {
                cout << "Posición inválida. Debe estar entre 0 y 15." << endl;
            }
        } else if (opcion == 5) {
            interactivo.mostrarTodos();
        }
        
    } while (opcion != 0);
    
    cout << "\n¡Gracias por usar el manipulador de bits!" << endl;
    
    return 0;
}
