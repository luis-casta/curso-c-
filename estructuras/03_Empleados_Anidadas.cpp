/*
 * EJERCICIO ESTRUCTURAS 3: ESTRUCTURAS ANIDADAS - EMPLEADOS (NIVEL MEDIO)
 * 
 * Descripción:
 * Sistema de gestión de empleados usando estructuras anidadas.
 * Demuestra cómo una estructura puede contener otras estructuras.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Estructura para representar una fecha
struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Estructura para representar una dirección
struct Direccion {
    string calle_nombre;
    int numero_exterior;
    string colonia;
    string ciudad;
    string codigo_postal;
};

// Estructura principal que contiene otras estructuras
struct Empleado {
    string nombre_completo;
    int numero_empleado;
    double salario_mensual;
    Fecha fecha_contratacion;    // Estructura anidada
    Direccion direccion_casa;    // Estructura anidada
    string departamento;
};

// Función para mostrar una fecha
void mostrar_fecha(const Fecha& fecha) {
    cout << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
}

// Función para mostrar información del empleado
void mostrar_empleado(const Empleado& emp) {
    cout << "\n--- INFORMACION DEL EMPLEADO ---" << endl;
    cout << "Nombre: " << emp.nombre_completo << endl;
    cout << "Numero de empleado: " << emp.numero_empleado << endl;
    cout << "Salario mensual: $" << fixed << setprecision(2) << emp.salario_mensual << endl;
    cout << "Departamento: " << emp.departamento << endl;
    
    cout << "Fecha de contratacion: ";
    mostrar_fecha(emp.fecha_contratacion);
    cout << endl;
    
    cout << "Direccion: " << emp.direccion_casa.calle_nombre 
         << " #" << emp.direccion_casa.numero_exterior << endl;
    cout << "  Colonia: " << emp.direccion_casa.colonia << endl;
    cout << "  Ciudad: " << emp.direccion_casa.ciudad << endl;
    cout << "  CP: " << emp.direccion_casa.codigo_postal << endl;
}

int main() {
    const int CANTIDAD_EMPLEADOS = 3;
    Empleado lista_empleados[CANTIDAD_EMPLEADOS];
    
    cout << "=== SISTEMA DE GESTION DE EMPLEADOS ===" << endl;
    
    // Registrar empleados
    for(int indice = 0; indice < CANTIDAD_EMPLEADOS; indice++) {
        cout << "\n=== EMPLEADO " << (indice + 1) << " ===" << endl;
        
        cin.ignore();
        cout << "Nombre completo: ";
        getline(cin, lista_empleados[indice].nombre_completo);
        
        cout << "Numero de empleado: ";
        cin >> lista_empleados[indice].numero_empleado;
        
        cout << "Salario mensual: $";
        cin >> lista_empleados[indice].salario_mensual;
        
        cin.ignore();
        cout << "Departamento: ";
        getline(cin, lista_empleados[indice].departamento);
        
        // Ingresar fecha de contratación (estructura anidada)
        cout << "\nFecha de contratacion:" << endl;
        cout << "  Dia: ";
        cin >> lista_empleados[indice].fecha_contratacion.dia;
        cout << "  Mes: ";
        cin >> lista_empleados[indice].fecha_contratacion.mes;
        cout << "  Año: ";
        cin >> lista_empleados[indice].fecha_contratacion.anio;
        
        // Ingresar dirección (estructura anidada)
        cin.ignore();
        cout << "\nDireccion:" << endl;
        cout << "  Calle: ";
        getline(cin, lista_empleados[indice].direccion_casa.calle_nombre);
        cout << "  Numero: ";
        cin >> lista_empleados[indice].direccion_casa.numero_exterior;
        cin.ignore();
        cout << "  Colonia: ";
        getline(cin, lista_empleados[indice].direccion_casa.colonia);
        cout << "  Ciudad: ";
        getline(cin, lista_empleados[indice].direccion_casa.ciudad);
        cout << "  Codigo postal: ";
        getline(cin, lista_empleados[indice].direccion_casa.codigo_postal);
    }
    
    // Mostrar todos los empleados
    cout << "\n\n=== LISTA DE EMPLEADOS ===" << endl;
    for(int indice = 0; indice < CANTIDAD_EMPLEADOS; indice++) {
        mostrar_empleado(lista_empleados[indice]);
    }
    
    // Calcular estadísticas
    double salario_total = 0;
    double salario_maximo = lista_empleados[0].salario_mensual;
    double salario_minimo = lista_empleados[0].salario_mensual;
    
    for(int indice = 0; indice < CANTIDAD_EMPLEADOS; indice++) {
        salario_total += lista_empleados[indice].salario_mensual;
        
        if(lista_empleados[indice].salario_mensual > salario_maximo) {
            salario_maximo = lista_empleados[indice].salario_mensual;
        }
        
        if(lista_empleados[indice].salario_mensual < salario_minimo) {
            salario_minimo = lista_empleados[indice].salario_mensual;
        }
    }
    
    double salario_promedio = salario_total / CANTIDAD_EMPLEADOS;
    
    cout << "\n=== ESTADISTICAS SALARIALES ===" << endl;
    cout << fixed << setprecision(2);
    cout << "Nomina total mensual: $" << salario_total << endl;
    cout << "Salario promedio: $" << salario_promedio << endl;
    cout << "Salario maximo: $" << salario_maximo << endl;
    cout << "Salario minimo: $" << salario_minimo << endl;
    
    return 0;
}

/*
 * EXPLICACIÓN:
 * - Definimos 3 estructuras: Fecha, Direccion y Empleado
 * - Empleado contiene dos estructuras anidadas
 * - Accedemos a miembros anidados con doble punto: emp.fecha.dia
 * - Las funciones reciben estructuras por referencia constante
 * - Esto evita copias innecesarias y mejora el rendimiento
 */
