#include <iostream>
#include <string>

using namespace std;

// ==========================================
// DEFINICIÓN: ABSTRACCIÓN
// ==========================================
/*
 * ABSTRACCIÓN:
 * Es el proceso de ocultar los detalles de implementación complejos y mostrar
 * solo la funcionalidad esencial del objeto.
 * 
 * CLASES ABSTRACTAS:
 * Son clases que no se pueden instanciar directamente. Sirven como modelos
 * o interfaces para otras clases.
 * 
 * FUNCIONES VIRTUALES PURAS:
 * Son funciones que no tienen implementación en la clase base y DEBEN ser
 * implementadas por las clases derivadas.
 * Sintaxis: virtual void funcion() = 0;
 */

// Clase Abstracta 'Forma'
class Forma {
public:
    // Función virtual pura
    // Esto convierte a 'Forma' en una clase abstracta
    virtual double calcularArea() = 0;
    
    virtual void mostrarTipo() = 0;

    // Las clases abstractas pueden tener métodos normales también
    void descripcion() {
        cout << "Soy una forma geométrica." << endl;
    }

    // Destructor virtual
    virtual ~Forma() {}
};

class Circulo : public Forma {
private:
    double radio;

public:
    Circulo(double _radio) : radio(_radio) {}

    // Implementación obligatoria del método virtual puro
    double calcularArea() override {
        return 3.14159 * radio * radio;
    }

    void mostrarTipo() override {
        cout << "Círculo" << endl;
    }
};

class Rectangulo : public Forma {
private:
    double base, altura;

public:
    Rectangulo(double _base, double _altura) : base(_base), altura(_altura) {}

    double calcularArea() override {
        return base * altura;
    }

    void mostrarTipo() override {
        cout << "Rectángulo" << endl;
    }
};

int main() {
    // Forma miForma; // ERROR: No se puede instanciar una clase abstracta

    // Sí se pueden usar punteros a la clase abstracta
    Forma* forma1 = new Circulo(5.0);
    Forma* forma2 = new Rectangulo(4.0, 6.0);

    cout << "--- Forma 1 ---" << endl;
    forma1->mostrarTipo();
    cout << "Área: " << forma1->calcularArea() << endl;
    forma1->descripcion();

    cout << "\n--- Forma 2 ---" << endl;
    forma2->mostrarTipo();
    cout << "Área: " << forma2->calcularArea() << endl;
    forma2->descripcion();

    delete forma1;
    delete forma2;

    return 0;
}
