#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// DEFINICIÓN: POLIMORFISMO
// ==========================================
/*
 * POLIMORFISMO:
 * Capacidad de que objetos de diferentes clases respondan al mismo mensaje (método)
 * de formas diferentes.
 * 
 * REQUISITOS EN C++:
 * 1. Herencia.
 * 2. Funciones Virtuales (virtual) en la clase base.
 * 3. Uso de punteros o referencias a la clase base.
 * 
 * PALABRA CLAVE 'virtual':
 * Indica que el método puede ser sobrescrito (overridden) en clases derivadas
 * y que se debe usar "enlace dinámico" (decidir qué método llamar en tiempo de ejecución).
 * 
 * PALABRA CLAVE 'override':
 * (C++11 en adelante) Asegura que estamos sobrescribiendo un método virtual.
 */

class Figura {
public:
    // Método virtual: permite ser sobrescrito
    virtual void dibujar() {
        cout << "Dibujando una figura genérica." << endl;
    }

    // Destructor virtual: Importante para limpiar memoria correctamente en polimorfismo
    virtual ~Figura() {}
};

class Circulo : public Figura {
public:
    // Sobrescritura del método dibujar
    void dibujar() override {
        cout << "Dibujando un Círculo O" << endl;
    }
};

class Rectangulo : public Figura {
public:
    void dibujar() override {
        cout << "Dibujando un Rectángulo []" << endl;
    }
};

class Triangulo : public Figura {
public:
    void dibujar() override {
        cout << "Dibujando un Triángulo /\\" << endl;
    }
};

int main() {
    // Polimorfismo usando punteros
    
    Figura* figura1 = new Circulo();
    Figura* figura2 = new Rectangulo();
    Figura* figura3 = new Triangulo();

    cout << "--- Polimorfismo con punteros individuales ---" << endl;
    // Aunque el tipo del puntero es Figura*, se llama al método de la clase derivada
    figura1->dibujar(); // Llama a Circulo::dibujar()
    figura2->dibujar(); // Llama a Rectangulo::dibujar()
    figura3->dibujar(); // Llama a Triangulo::dibujar()

    cout << "\n--- Polimorfismo con arreglo de punteros ---" << endl;
    // Podemos tener una colección de diferentes figuras tratadas uniformemente
    vector<Figura*> figuras;
    figuras.push_back(figura1);
    figuras.push_back(figura2);
    figuras.push_back(figura3);
    figuras.push_back(new Circulo());

    for (Figura* f : figuras) {
        f->dibujar();
    }

    // Limpieza de memoria
    for (Figura* f : figuras) {
        delete f; // Llama al destructor virtual
    }
    // Nota: figura1, figura2, figura3 ya fueron borrados en el bucle porque estaban en el vector

    return 0;
}
