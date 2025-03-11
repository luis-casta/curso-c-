
// using 
/*
  En C++, using se utiliza para definir alias de tipos, similar a typedef, pero con una sintaxis más moderna y flexible.
*/
#include <iostream>
#include <vector>

using text_t = std::string; // 'test_t' es alias de 'std::string'
using vectorEnteros = std::vector<int>; // 'VectorEnteros' es el alias de std::vector<int>

int main(){
  text_t nombre = "Lyon"; // equivale a 'std::string nombre = "Lyon";
  vectorEnteros numeros = {1,2,3,4,5,6,7}; // equivale a std::vector<int> numeros = {1,2,3,4,5,6,7};

  std::cout << "Nombre: " << nombre << std::endl;

  // for para imprimir vector de números 
  for(int num : numeros){
    std::cout << num << " ";

  }
  std::cout << std::endl; 



  return 0;
}
