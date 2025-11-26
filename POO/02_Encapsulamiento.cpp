#include <iostream>
#include <string>

using namespace std;

// ==========================================
// DEFINICIÓN: ENCAPSULAMIENTO
// ==========================================
/*
 * ENCAPSULAMIENTO:
 * Es el principio que consiste en ocultar los detalles internos de una clase
 * y exponer solo lo necesario a través de una interfaz pública.
 * 
 * MODIFICADORES DE ACCESO:
 * - public: Accesible desde cualquier parte del programa.
 * - private: Accesible solo desde dentro de la misma clase.
 * - protected: Accesible desde la misma clase y sus clases derivadas (herencia).
 * 
 * GETTERS Y SETTERS:
 * Métodos públicos para acceder (get) y modificar (set) atributos privados
 * de forma controlada.
 */

class CuentaBancaria {
private:
    // Atributos privados: No se pueden acceder directamente desde fuera
    string titular;
    double saldo;
    string numeroCuenta;

public:
    // Constructor
    CuentaBancaria(string _titular, string _numeroCuenta, double _saldoInicial) {
        titular = _titular;
        numeroCuenta = _numeroCuenta;
        if (_saldoInicial >= 0) {
            saldo = _saldoInicial;
        } else {
            saldo = 0;
            cout << "Error: El saldo inicial no puede ser negativo. Se ha establecido en 0." << endl;
        }
    }

    // --- Getters (Obtener valores) ---
    string getTitular() {
        return titular;
    }

    double getSaldo() {
        return saldo;
    }

    // --- Setters (Modificar valores con validación) ---
    void setTitular(string _nuevoTitular) {
        if (!_nuevoTitular.empty()) {
            titular = _nuevoTitular;
        } else {
            cout << "Error: El nombre del titular no puede estar vacío." << endl;
        }
    }

    // Método para depositar dinero
    void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
            cout << "Depósito exitoso. Nuevo saldo: " << saldo << endl;
        } else {
            cout << "Error: La cantidad a depositar debe ser positiva." << endl;
        }
    }

    // Método para retirar dinero
    void retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            cout << "Retiro exitoso. Nuevo saldo: " << saldo << endl;
        } else {
            cout << "Error: Fondos insuficientes o cantidad inválida." << endl;
        }
    }
};

int main() {
    // Crear una cuenta
    CuentaBancaria miCuenta("Carlos Perez", "123456789", 1000.0);

    // Intentar acceder a atributos privados (Esto daría error de compilación)
    // miCuenta.saldo = 5000; // ERROR: 'saldo' es privado

    // Acceder a través de métodos públicos
    cout << "Titular: " << miCuenta.getTitular() << endl;
    cout << "Saldo actual: " << miCuenta.getSaldo() << endl;

    // Operaciones
    miCuenta.depositar(500);
    miCuenta.retirar(200);
    miCuenta.retirar(2000); // Intento de retiro inválido

    // Modificar titular usando Setter
    miCuenta.setTitular("Carlos Gomez");
    cout << "Nuevo titular: " << miCuenta.getTitular() << endl;

    return 0;
}
