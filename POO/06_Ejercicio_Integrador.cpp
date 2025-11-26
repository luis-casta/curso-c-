#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// EJERCICIO INTEGRADOR: SISTEMA DE EMPLEADOS
// ==========================================
/*
 * OBJETIVO:
 * Crear un sistema que gestione diferentes tipos de empleados usando
 * todos los conceptos de POO aprendidos.
 * 
 * REQUERIMIENTOS:
 * 1. Clase base abstracta 'Empleado'.
 * 2. Clases derivadas 'EmpleadoAsalariado' y 'EmpleadoPorHoras'.
 * 3. Polimorfismo para calcular el salario.
 * 4. Encapsulamiento para proteger los datos.
 */

// Clase Abstracta
class Empleado {
protected:
    string nombre;
    int id;

public:
    Empleado(string _nombre, int _id) : nombre(_nombre), id(_id) {}

    virtual ~Empleado() {}

    // Método virtual puro
    virtual double calcularSalario() = 0;

    virtual void mostrarDetalles() {
        cout << "ID: " << id << " | Nombre: " << nombre;
    }
};

// Empleado con salario fijo mensual
class EmpleadoAsalariado : public Empleado {
private:
    double salarioMensual;

public:
    EmpleadoAsalariado(string _nombre, int _id, double _salarioMensual) 
        : Empleado(_nombre, _id), salarioMensual(_salarioMensual) {}

    double calcularSalario() override {
        return salarioMensual;
    }

    void mostrarDetalles() override {
        Empleado::mostrarDetalles();
        cout << " | Tipo: Asalariado | Salario Mensual: $" << salarioMensual << endl;
    }
};

// Empleado que cobra por horas trabajadas
class EmpleadoPorHoras : public Empleado {
private:
    double tarifaPorHora;
    int horasTrabajadas;

public:
    EmpleadoPorHoras(string _nombre, int _id, double _tarifaPorHora) 
        : Empleado(_nombre, _id), tarifaPorHora(_tarifaPorHora), horasTrabajadas(0) {}

    void registrarHoras(int horas) {
        if (horas > 0) {
            horasTrabajadas += horas;
        }
    }

    double calcularSalario() override {
        return tarifaPorHora * horasTrabajadas;
    }

    void mostrarDetalles() override {
        Empleado::mostrarDetalles();
        cout << " | Tipo: Por Horas | Tarifa: $" << tarifaPorHora 
             << " | Horas: " << horasTrabajadas << endl;
    }
};

int main() {
    // Crear lista de empleados
    vector<Empleado*> nomina;

    // Crear empleados
    EmpleadoAsalariado* emp1 = new EmpleadoAsalariado("Ana Lopez", 101, 3000.0);
    EmpleadoPorHoras* emp2 = new EmpleadoPorHoras("Pedro Ruiz", 102, 15.0);

    // Registrar horas para el empleado por horas
    emp2->registrarHoras(40);
    emp2->registrarHoras(10); // 50 horas en total

    // Agregar a la nómina
    nomina.push_back(emp1);
    nomina.push_back(emp2);

    cout << "=== REPORTE DE NÓMINA ===" << endl;
    double totalNomina = 0;

    for (Empleado* e : nomina) {
        e->mostrarDetalles();
        double salario = e->calcularSalario();
        cout << " -> Salario a pagar: $" << salario << endl;
        totalNomina += salario;
        cout << "-------------------------" << endl;
    }

    cout << "Total a pagar en nómina: $" << totalNomina << endl;

    // Limpieza
    for (Empleado* e : nomina) {
        delete e;
    }

    return 0;
}
