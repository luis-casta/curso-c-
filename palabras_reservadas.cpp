#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>

// Palabras clave relacionadas con clases y herencia
class Base {
public:
    virtual void foo() = 0; // Palabra clave 'virtual' y '= 0' para función pura
};

class Derived : public Base { // Palabra clave 'class' y 'public'
public:
    void foo() override { // Palabra clave 'override'
        std::cout << "Derived::foo()" << std::endl;
    }
};

// Palabras clave relacionadas con control de flujo
void controlFlowExample() {
    int x = 10;
    if (x > 5) { // Palabra clave 'if'
        std::cout << "x es mayor que 5" << std::endl;
    } else { // Palabra clave 'else'
        std::cout << "x es menor o igual a 5" << std::endl;
    }

    for (int i = 0; i < 5; ++i) { // Palabra clave 'for'
        std::cout << "Iteración: " << i << std::endl;
    }

    while (x > 0) { // Palabra clave 'while'
        std::cout << "x: " << x << std::endl;
        x--;
    }

    do { // Palabra clave 'do'
        std::cout << "x en do-while: " << x << std::endl;
        x++;
    } while (x < 5); // Palabra clave 'while'

    switch (x) { // Palabra clave 'switch'
        case 5: // Palabra clave 'case'
            std::cout << "x es 5" << std::endl;
            break; // Palabra clave 'break'
        default: // Palabra clave 'default'
            std::cout << "x no es 5" << std::endl;
    }
}

// Palabras clave relacionadas con manejo de excepciones
void exceptionExample() {
    try { // Palabra clave 'try'
        throw std::runtime_error("Error de ejemplo"); // Palabra clave 'throw'
    } catch (const std::exception& e) { // Palabra clave 'catch'
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }
}

// Palabras clave relacionadas con tipos y modificadores
void typeModifiersExample() {
    const int y = 42; // Palabra clave 'const'
    volatile int z = 10; // Palabra clave 'volatile'
    static int counter = 0; // Palabra clave 'static'
    counter++;
    std::cout << "Contador estático: " << counter << std::endl;

    auto lambda = []() { // Palabra clave 'auto' y '[]' para lambda
        std::cout << "Lambda ejecutada" << std::endl;
    };
    lambda();
}

// Palabras clave relacionadas con memoria y punteros
void memoryManagementExample() {
    int* ptr = new int(10); // Palabra clave 'new'
    std::cout << "Valor asignado dinámicamente: " << *ptr << std::endl;
    delete ptr; // Palabra clave 'delete'

    std::unique_ptr<int> smartPtr = std::make_unique<int>(20); // Uso de punteros inteligentes
    std::cout << "Valor en puntero inteligente: " << *smartPtr << std::endl;
}

// Palabras clave relacionadas con plantillas
template <typename T> // Palabra clave 'template' y 'typename'
void templateExample(T value) {
    std::cout << "Valor de la plantilla: " << value << std::endl;
}

// Palabras clave relacionadas con espacios de nombres
namespace MyNamespace { // Palabra clave 'namespace'
    void namespaceFunction() {
        std::cout << "Función en MyNamespace" << std::endl;
    }
}

// Palabras clave relacionadas con control de acceso
class AccessControlExample {
private: // Palabra clave 'private'
    int privateVar = 1;

protected: // Palabra clave 'protected'
    int protectedVar = 2;

public: // Palabra clave 'public'
    int publicVar = 3;
};

// Palabras clave relacionadas con hilos (C++11 en adelante)
#include <thread>
void threadExample() {
    std::thread t([]() { // Palabra clave 'thread'
        std::cout << "Hilo en ejecución" << std::endl;
    });
    t.join(); // Palabra clave 'join'
}

// Palabras clave relacionadas con atributos (C++11 en adelante)
[[nodiscard]] int mustUseReturnValue() { // Atributo '[[nodiscard]]'
    return 42;
}

int main() {
    // Uso de palabras clave en main
    Derived d;
    d.foo();

    controlFlowExample();
    exceptionExample();
    typeModifiersExample();
    memoryManagementExample();
    templateExample(3.14); // Uso de plantilla con double
    MyNamespace::namespaceFunction();

    AccessControlExample ace;
    std::cout << "Variable pública: " << ace.publicVar << std::endl;

    threadExample();
    mustUseReturnValue(); // Advertencia si no se usa el valor de retorno

    return 0; // Palabra clave 'return'
}