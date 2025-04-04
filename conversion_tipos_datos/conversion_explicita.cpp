
/* CONVERSION EXPLICITA (CASTING) 
   Es cuando el programador indica explícitamente que se debe realizar una conversión. En C++, hay varias formas de hacer casting:

*/
#include <iostream>
#include <string>
#include <sstream> // biblioteca para convertir entre cadenas(string) entre numeros(int, double, float)

using namespace std; 

int main(){

  // estilo C (casting tradicional )
  double decimal = 3.14;
  int entero = int(decimal); // convierte decimal a entero
  cout << "casting tradicional de decimal a entero: " << entero << endl;


  /* Operadores de casting en c++
     c++ introduce cuatro operadores de casting más seguros y espicificos:
     1. static_cast: Usado para conversión estándar entre tipos relacionados (por ejemplo
     de int a double )*/
  // static_cast
  double numDecimal = 4.25;
  int numEntero = static_cast<int>(numDecimal); // Convierte decimal a entero
  cout << "decimal a entero con static_cast: " << numEntero << endl; // retorna 4 

  

  /*Conversión con std::stringstream:
    Para convertir entre tipos numéricos y cadenas (string), puedes usar la 
    biblioteca <sstream>.*/
  
  // convertir int a string 
  int numeroEntero = 100;
  stringstream ss;
  ss << numeroEntero; // convierte el enterio a string 
  string cadena = ss.str(); // guarda en cadena el entero ya convertido 
  cout << "conversion de entero a string: " << cadena << endl; 



  // convertir string a int
  string cadena2 = "100";
  int numero2;
  ss >> numero2; // convierte string a int
  cout << "conversión de string a entero: " << numero2 << endl;

  




  return 0;
}