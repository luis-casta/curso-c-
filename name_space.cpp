
// nameespaces (espacios de mombre)
/*
   Un namespace es una región del código que agrupa identificadores (nombres de variables, funciones, clases, etc.) bajo un nombre único.

Los namespaces evitan que dos o más identificadores con el mismo nombre entren en conflicto.

Se accede a los elementos dentro de un namespace usando el operador de resolución de ámbito (::).
*/

// dentro de los namespaces tambien podemos crear funciones


#include <iostream>

using namespace std;

// crtear espacio de nombre 
namespace primero {
   int x = 1;
}

// otro namespace 
namespace segundo {
   int x = 2;
}

int main()
{
   int x = 0;
   //int x = 2; en c++ si a una variable le asigno un valor, no puedo reasignarle un nuevo valor 
   // porque me daria un error de redeclaración, para corregirlo eso tengo que crear un namespace 

    // valor de x desde el main
    cout << "Valor de x desde  el main: " << x << endl;

   // valor de x desde el namespace primerop
   cout << "valor de x desde el namespace primero: " << primero::x << endl; 

   // valor de x desde el namespace segundo
   cout << "valor de x desde el namespace segundo: " << segundo::x << endl; 
   

}

/* NOTA: 
   si tengo varias varieables con el mismo nombre y no especifico el nombre de espacio que q
   quiero que se use, toma el valor de la variable que está dentro del main, si quiero 
   cambiar esto, debo especificar el nombre del namespace seguido de :: y nombre
   de la variable.  */