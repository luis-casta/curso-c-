
// std
/*/
  En C++, std es un espacio de nombres (namespace) que contiene todas las funciones, objetos y clases de la biblioteca estándar de C++, como entradas/salidas, contenedores, algoritmos, entre otros. Al usar std, se hace referencia a elementos de la biblioteca estándar.
*/

/*
  std::cout: Se usa para imprimir en la consola.
std::cin: Se utiliza para leer entradas del usuario (en este caso, la edad).
std::vector: Es un contenedor dinámico que se utiliza para almacenar una colección de enteros.
std::string: Se usa para manejar cadenas de texto.
std::endl: Inserta un salto de línea y asegura que el flujo de salida se vacíe.
*/

#include <iostream>
#include <vector>
#include <string>
// using namespace std; se puede poner aca y no escribir std donde correspone,
//pero hay que uasarlo con cuidado 

int main(){
 // std::cout imprime mensaje en pantalla
 std::cout << "Hola mundo" << std::endl; // std::endl salto de linea

 //std::string variable de tipo string 
 std::string nombre;

 std::cout << "Ingrese su nombre";

 // lee la entrada del usuario (algo parecido al input de python)
 std::cin >> nombre; 

 // std::vector crea un vector de enteros
 std::vector<int> numeros = {2,3,4,56,};

 return 0;
}

// NoTA: podemos poner antes del main using namespace std; y no nos tocaria 
//escribir std, sino solo la funcion que sigue despues  de este, pero no es 
//muy recomendable para codigos extensos 
