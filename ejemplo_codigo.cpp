#include <iostream> // Biblioteca para entrada/salida estándar
#include <string>   // Biblioteca para us
// Función para saludar al usuario
void saludar(const std::string &nombre) {
  std::cout << "¡Hola, " << nombre << "!" << std::endl;
}

// Función principal
int main() {
  // Declaración de variables
  std::string nombre;
  int edad;

  // Solicitar datos al usuario
  std::cout << "Ingresa tu nombre: ";
  std::getline(std::cin, nombre); // Leer una línea de texto

  std::cout << "Ingresa tu edad: ";
  std::cin >> edad; // Leer un número entero

  // Llamar a la función saludar
  saludar(nombre);

  // Condicional para verificar la edad
  if (edad >= 18) {
    std::cout << "Eres mayor de edad." << std::endl;
  } else {
    std::cout << "Eres menor de edad." << std::endl;
  }

  // Bucle para contar hasta 5
  std::cout << "Contando hasta 5:" << std::endl;
  for (int i = 1; i <= 5; ++i) {
    {
    }
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // Indicar que el programa terminó correctamente
}
