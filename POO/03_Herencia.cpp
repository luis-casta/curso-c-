#include <iostream>
#include <string>

using namespace std;

// ==========================================
// DEFINICIÓN: HERENCIA
// ==========================================
/*
 * HERENCIA:
 * Es un mecanismo que permite crear nuevas clases basadas en clases existentes.
 * La nueva clase (derivada o hija) hereda los atributos y métodos de la clase
 * existente (base o padre).
 * 
 * VENTAJAS:
 * - Reutilización de código.
 * - Jerarquía lógica.
 * - Facilita el mantenimiento.
 */

// Clase Base (Padre)
class Animal {
protected: // Accesible por las clases derivadas
    string nombre;
    int edad;

public:
    Animal(string _nombre, int _edad) {
        nombre = _nombre;
        edad = _edad;
    }

    void comer() {
        cout << nombre << " está comiendo." << endl;
    }

    void dormir() {
        cout << nombre << " está durmiendo." << endl;
    }
};

// Clase Derivada (Hija) - Perro hereda de Animal
class Perro : public Animal {
private:
    string raza;

public:
    // Constructor de la clase derivada
    // Debe llamar al constructor de la clase base
    Perro(string _nombre, int _edad, string _raza) : Animal(_nombre, _edad) {
        raza = _raza;
    }

    // Método propio de la clase Perro
    void ladrar() {
        cout << nombre << " dice: ¡Guau! ¡Guau!" << endl;
    }

    void mostrarInfo() {
        cout << "Perro: " << nombre << ", Edad: " << edad << ", Raza: " << raza << endl;
    }
};

// Otra Clase Derivada - Gato hereda de Animal
class Gato : public Animal {
public:
    Gato(string _nombre, int _edad) : Animal(_nombre, _edad) {}

    void maullar() {
        cout << nombre << " dice: ¡Miau!" << endl;
    }
};

int main() {
    // Crear un objeto de la clase derivada Perro
    Perro miPerro("Max", 3, "Labrador");

    // Usar métodos heredados de Animal
    miPerro.comer();
    miPerro.dormir();

    // Usar métodos propios de Perro
    miPerro.ladrar();
    miPerro.mostrarInfo();

    cout << "----------------" << endl;

    // Crear un objeto de la clase derivada Gato
    Gato miGato("Luna", 2);
    miGato.comer();
    miGato.maullar();

    return 0;
}
