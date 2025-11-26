#include <iostream>
#include <string>

using namespace std;

// ==========================================
// DEFINICIÓN: CLASE Y OBJETO
// ==========================================
/*
 * CLASE:
 * Es una plantilla o molde que define las propiedades (atributos) y 
 * comportamientos (métodos) comunes a un conjunto de objetos.
 * 
 * OBJETO:
 * Es una instancia concreta de una clase. Tiene un estado (valores de sus atributos)
 * y un comportamiento (definido por sus métodos).
 */

// Definición de la clase 'Persona'
class Persona {
public: // Modificador de acceso (lo veremos en detalle en Encapsulamiento)
    
    // Atributos (Propiedades)
    string nombre;
    int edad;
    string ocupacion;

    // Constructor: Método especial que se llama al crear un objeto (se llama automaticamente)
    Persona(string _nombre, int _edad, string _ocupacion) {
        nombre = _nombre;
        edad = _edad;
        ocupacion = _ocupacion;
    }

    // Métodos (Comportamientos)
    void saludar() {
        cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " años." << endl;
    }

    void trabajar() {
        cout << nombre << " está trabajando como " << ocupacion << "." << endl;
    }
};

int main() {
    // Creación de Objetos (Instanciación)
    
    // Objeto 1
    Persona persona1("Juan", 30, "Ingeniero");
    
    // Objeto 2
    Persona persona2("Maria", 25, "Doctora");

    // Uso de los objetos
    cout << "--- Objeto 1 ---" << endl;
    persona1.saludar();
    persona1.trabajar();

    cout << "\n--- Objeto 2 ---" << endl;
    persona2.saludar();
    persona2.trabajar();

    // Modificando atributos directamente (posible porque son public)
    persona1.edad = 31;
    cout << "\nJuan ha cumplido años. Ahora tiene: " << persona1.edad << endl;

    return 0;
}
