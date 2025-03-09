
// nameespaces (espacios de mombre)
/*
   Un namespace es una región del código que agrupa identificadores (nombres de variables, funciones, clases, etc.) bajo un nombre único.

Los namespaces evitan que dos o más identificadores con el mismo nombre entren en conflicto.

Se accede a los elementos dentro de un namespace usando el operador de resolución de ámbito (::).
*/
#include <iostream>

// definir un namespace
namespace miNamespace {
   int numero = 29; // variable dentro del namespace
   void saludar(){  // función dentro del namespace
      std::cout << "Hola desde mi namespace" << std::endl;

   }

}

int main(){
   // accedemos a los elementos del namespace desde el main
   std::cout << "Número: " << miNamespace::numero << std::endl;
   miNamespace::saludar();


   return 0;
}
