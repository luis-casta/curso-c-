// EJERCICIOS DE MANEJO DE EXCEPCIONES: Colección completa de 5 ejercicios progresivos

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// ============================================
// EJERCICIO 1: CALCULADORA SEGURA (FÁCIL)
// ============================================
void ejercicio1_calculadora_segura() {
    cout << "\n=== EJERCICIO 1: CALCULADORA SEGURA ===" << endl;
    
    double numero_uno, numero_dos;
    char operador;
    
    cout << "Ingrese primer numero: ";
    cin >> numero_uno;
    cout << "Ingrese operador (+, -, *, /): ";
    cin >> operador;
    cout << "Ingrese segundo numero: ";
    cin >> numero_dos;
    
    try {
        double resultado;
        
        switch(operador) {
            case '+':
                resultado = numero_uno + numero_dos;
                break;
            case '-':
                resultado = numero_uno - numero_dos;
                break;
            case '*':
                resultado = numero_uno * numero_dos;
                break;
            case '/':
                if(numero_dos == 0) {
                    throw invalid_argument("Division por cero no permitida");
                }
                resultado = numero_uno / numero_dos;
                break;
            default:
                throw invalid_argument("Operador invalido");
        }
        
        cout << "Resultado: " << resultado << endl;
        
    } catch(invalid_argument& error) {
        cout << "Error: " << error.what() << endl;
    }
}

// ============================================
// EJERCICIO 2: VALIDADOR DE ENTRADA (FÁCIL-MEDIO)
// ============================================
class ExcepcionEntradaInvalida : public exception {
private:
    string mensaje;
    
public:
    ExcepcionEntradaInvalida(string msg) : mensaje(msg) {}
    
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

int leer_numero_rango(int minimo, int maximo) {
    int numero;
    cout << "Ingrese numero entre " << minimo << " y " << maximo << ": ";
    cin >> numero;
    
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw ExcepcionEntradaInvalida("Entrada no es un numero valido");
    }
    
    if(numero < minimo || numero > maximo) {
        throw out_of_range("Numero fuera del rango permitido");
    }
    
    return numero;
}

void ejercicio2_validador_entrada() {
    cout << "\n=== EJERCICIO 2: VALIDADOR DE ENTRADA ===" << endl;
    
    try {
        int edad = leer_numero_rango(0, 120);
        cout << "Edad valida: " << edad << " años" << endl;
        
        int calificacion = leer_numero_rango(0, 100);
        cout << "Calificacion valida: " << calificacion << endl;
        
    } catch(ExcepcionEntradaInvalida& error) {
        cout << "Error de entrada: " << error.what() << endl;
        
    } catch(out_of_range& error) {
        cout << "Error de rango: " << error.what() << endl;
    }
}

// ============================================
// EJERCICIO 3: GESTIÓN DE ARREGLOS (MEDIO)
// ============================================
class ExcepcionIndiceInvalido : public exception {
private:
    string mensaje;
    
public:
    ExcepcionIndiceInvalido(int indice, int tamano) {
        mensaje = "Indice " + to_string(indice) + 
                 " fuera de rango (0-" + to_string(tamano-1) + ")";
    }
    
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

class ArregloSeguro {
private:
    vector<int> datos;
    
public:
    ArregloSeguro(int tamano) : datos(tamano, 0) {}
    
    void establecer(int indice, int valor) {
        if(indice < 0 || indice >= datos.size()) {
            throw ExcepcionIndiceInvalido(indice, datos.size());
        }
        datos[indice] = valor;
    }
    
    int obtener(int indice) {
        if(indice < 0 || indice >= datos.size()) {
            throw ExcepcionIndiceInvalido(indice, datos.size());
        }
        return datos[indice];
    }
    
    int tamano() const {
        return datos.size();
    }
    
    void mostrar() {
        cout << "Arreglo: ";
        for(int valor : datos) {
            cout << valor << " ";
        }
        cout << endl;
    }
};

void ejercicio3_gestion_arreglos() {
    cout << "\n=== EJERCICIO 3: GESTION DE ARREGLOS ===" << endl;
    
    try {
        ArregloSeguro arreglo(5);
        
        // Establecer valores
        arreglo.establecer(0, 10);
        arreglo.establecer(1, 20);
        arreglo.establecer(2, 30);
        
        arreglo.mostrar();
        
        // Intentar acceder a índice inválido
        cout << "\nIntentando acceder a indice 10..." << endl;
        arreglo.establecer(10, 100);  // Esto lanzará excepción
        
    } catch(ExcepcionIndiceInvalido& error) {
        cout << "Error: " << error.what() << endl;
    }
}

// ============================================
// EJERCICIO 4: SISTEMA BANCARIO (MEDIO-DIFÍCIL)
// ============================================
class ExcepcionSaldoInsuficiente : public exception {
private:
    string mensaje;
    
public:
    ExcepcionSaldoInsuficiente(double saldo, double monto) {
        mensaje = "Saldo insuficiente. Saldo: $" + to_string(saldo) +
                 ", Monto solicitado: $" + to_string(monto);
    }
    
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

class ExcepcionMontoInvalido : public exception {
public:
    const char* what() const noexcept override {
        return "El monto debe ser mayor a cero";
    }
};

class CuentaBancaria {
private:
    string titular;
    double saldo;
    
public:
    CuentaBancaria(string nombre, double saldo_inicial) 
        : titular(nombre), saldo(saldo_inicial) {
        if(saldo_inicial < 0) {
            throw invalid_argument("El saldo inicial no puede ser negativo");
        }
    }
    
    void depositar(double monto) {
        if(monto <= 0) {
            throw ExcepcionMontoInvalido();
        }
        saldo += monto;
        cout << "Deposito exitoso. Nuevo saldo: $" << saldo << endl;
    }
    
    void retirar(double monto) {
        if(monto <= 0) {
            throw ExcepcionMontoInvalido();
        }
        if(monto > saldo) {
            throw ExcepcionSaldoInsuficiente(saldo, monto);
        }
        saldo -= monto;
        cout << "Retiro exitoso. Nuevo saldo: $" << saldo << endl;
    }
    
    double obtener_saldo() const {
        return saldo;
    }
    
    void mostrar_info() {
        cout << "Titular: " << titular << endl;
        cout << "Saldo: $" << saldo << endl;
    }
};

void ejercicio4_sistema_bancario() {
    cout << "\n=== EJERCICIO 4: SISTEMA BANCARIO ===" << endl;
    
    try {
        CuentaBancaria cuenta("Juan Perez", 1000.0);
        cuenta.mostrar_info();
        
        int opcion;
        do {
            cout << "\n1. Depositar" << endl;
            cout << "2. Retirar" << endl;
            cout << "3. Ver saldo" << endl;
            cout << "0. Volver" << endl;
            cout << "Opcion: ";
            cin >> opcion;
            
            try {
                switch(opcion) {
                    case 1: {
                        double monto;
                        cout << "Monto a depositar: $";
                        cin >> monto;
                        cuenta.depositar(monto);
                        break;
                    }
                    case 2: {
                        double monto;
                        cout << "Monto a retirar: $";
                        cin >> monto;
                        cuenta.retirar(monto);
                        break;
                    }
                    case 3:
                        cout << "Saldo actual: $" << cuenta.obtener_saldo() << endl;
                        break;
                }
                
            } catch(ExcepcionSaldoInsuficiente& error) {
                cout << "Error: " << error.what() << endl;
                
            } catch(ExcepcionMontoInvalido& error) {
                cout << "Error: " << error.what() << endl;
            }
            
        } while(opcion != 0);
        
    } catch(invalid_argument& error) {
        cout << "Error al crear cuenta: " << error.what() << endl;
    }
}

// ============================================
// EJERCICIO 5: SISTEMA COMPLETO CON MÚLTIPLES EXCEPCIONES (DIFÍCIL)
// ============================================
class ExcepcionUsuarioNoEncontrado : public exception {
public:
    const char* what() const noexcept override {
        return "Usuario no encontrado";
    }
};

class ExcepcionCredencialesInvalidas : public exception {
public:
    const char* what() const noexcept override {
        return "Usuario o contraseña incorrectos";
    }
};

class ExcepcionPermisosDenegados : public exception {
public:
    const char* what() const noexcept override {
        return "No tiene permisos para realizar esta accion";
    }
};

class SistemaUsuarios {
private:
    struct Usuario {
        string nombre;
        string contrasena;
        bool es_admin;
    };
    
    vector<Usuario> usuarios;
    Usuario* usuario_actual = nullptr;
    
public:
    SistemaUsuarios() {
        // Usuarios predefinidos
        usuarios.push_back({"admin", "admin123", true});
        usuarios.push_back({"usuario", "user123", false});
    }
    
    void iniciar_sesion(string nombre, string contrasena) {
        for(auto& usuario : usuarios) {
            if(usuario.nombre == nombre) {
                if(usuario.contrasena == contrasena) {
                    usuario_actual = &usuario;
                    cout << "Sesion iniciada como: " << nombre << endl;
                    return;
                }
                throw ExcepcionCredencialesInvalidas();
            }
        }
        throw ExcepcionUsuarioNoEncontrado();
    }
    
    void realizar_accion_admin() {
        if(!usuario_actual) {
            throw runtime_error("Debe iniciar sesion primero");
        }
        if(!usuario_actual->es_admin) {
            throw ExcepcionPermisosDenegados();
        }
        cout << "Accion de administrador ejecutada exitosamente" << endl;
    }
    
    bool hay_sesion() const {
        return usuario_actual != nullptr;
    }
    
    void cerrar_sesion() {
        if(!usuario_actual) {
            throw runtime_error("No hay sesion activa");
        }
        cout << "Sesion cerrada" << endl;
        usuario_actual = nullptr;
    }
};

void ejercicio5_sistema_completo() {
    cout << "\n=== EJERCICIO 5: SISTEMA COMPLETO ===" << endl;
    
    SistemaUsuarios sistema;
    int opcion;
    
    do {
        cout << "\n1. Iniciar sesion" << endl;
        cout << "2. Accion de administrador" << endl;
        cout << "3. Cerrar sesion" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        try {
            switch(opcion) {
                case 1: {
                    string usuario, contrasena;
                    cout << "Usuario: ";
                    cin >> usuario;
                    cout << "Contraseña: ";
                    cin >> contrasena;
                    sistema.iniciar_sesion(usuario, contrasena);
                    break;
                }
                case 2:
                    sistema.realizar_accion_admin();
                    break;
                case 3:
                    sistema.cerrar_sesion();
                    break;
            }
            
        } catch(ExcepcionUsuarioNoEncontrado& error) {
            cout << "Error: " << error.what() << endl;
            
        } catch(ExcepcionCredencialesInvalidas& error) {
            cout << "Error: " << error.what() << endl;
            
        } catch(ExcepcionPermisosDenegados& error) {
            cout << "Error: " << error.what() << endl;
            
        } catch(runtime_error& error) {
            cout << "Error: " << error.what() << endl;
            
        } catch(...) {
            cout << "Error desconocido" << endl;
        }
        
    } while(opcion != 0);
}

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================
int main() {
    int ejercicio;
    
    do {
        cout << "\n========================================" << endl;
        cout << "  EJERCICIOS DE MANEJO DE EXCEPCIONES" << endl;
        cout << "========================================" << endl;
        cout << "1. Calculadora segura" << endl;
        cout << "2. Validador de entrada" << endl;
        cout << "3. Gestion de arreglos" << endl;
        cout << "4. Sistema bancario" << endl;
        cout << "5. Sistema completo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione ejercicio: ";
        cin >> ejercicio;
        
        switch(ejercicio) {
            case 1:
                ejercicio1_calculadora_segura();
                break;
            case 2:
                ejercicio2_validador_entrada();
                break;
            case 3:
                ejercicio3_gestion_arreglos();
                break;
            case 4:
                ejercicio4_sistema_bancario();
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
    } while(ejercicio != 0);
    
    return 0;
}
