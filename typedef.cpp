
// typedef (nombres alternativos), es como un (alias)
/*
  En C++, typedef es una palabra clave que se utiliza para crear alias (nombres alternativos) para tipos de datos existentes. Esto permite definir nombres más cortos, descriptivos o específicos para tipos complejos, lo que mejora la legibilidad y la mantenibilidad del código.
*/
// sintaxis:
// typedef <tipo_existente> <nuevo_nombre>;
#include <iostream>   // Biblioteca para entrada y salida estándar
#include <string>     // Biblioteca para manejar strings
#include <vector>     // Biblioteca para manejar vectores

// Definición de alias con typedef
// por convensión se usa -t al final de cada nombre cuando usamos un alias
typedef int Entero_t;                  // 'Entero' es un alias para 'int'
typedef double Decimal_t;               // 'Decimal' es un alias para 'double'
typedef std::string Palabra_t;          // 'Palabra' es un alias para 'std::string'
typedef std::vector<int> vectorEnteros_t; // 'vectorEnteros' es un alias de 'std::vector<int>'

int main() {
    // Declaración de variables con los alias creados
    Entero_t numero1 = 23;   // Equivalente a 'int numero1 = 23;'
    Decimal_t numero2 = 5.67; // Equivalente a 'double numero2 = 5.67;'
    Palabra_t nombre = "lyon";
    vectorEnteros_t numeros = {1, 2, 3, 4, 5, 6}; // Equivalente a 'std::vector<int> numeros = {...};'

    // Imprimir valores de las variables
    std::cout << "Entero: " << numero1 << " Decimal: " << numero2 << std::endl;
    std::cout << "nombre: " << nombre << std::endl;

    // ERROR: No se puede imprimir directamente un std::vector<int>
    //std::cout << "Vector de números: " << numeros << std::endl; 

    // para imprimir un vector se usa un bucle for 
    std::cout << "Vector de números: ";
    for (Entero_t num : numeros ){ // recorremos el vector, pongo 'Entero_t, porque lo definí como 
      // el alias de 'int'
      std::cout << num << " "; // imprimimos cada número separado por un espacio

    }
    std::cout << std::endl;


    return 0;
}



