
/*CONVERSION IMPLICITA (AUTOMATICA):alignas
 Ocurre automáticamente cuando el compilador convierte un tipo de dato en otro sin necesidad de una instrucción explícita. Esto sucede en operaciones donde los tipos de datos no coinciden.
 */
#include <iostream>

int main(){
  int entero = 5;
  double decimal = entero; // conversión implicita de int a double

  std::cout << "Salida: " << decimal << std::endl; // salida 5.0




  return 0;

}