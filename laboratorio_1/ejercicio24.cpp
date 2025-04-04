
/* Ejercicio 24. Escriba un programa que pida una número entero e imprima un cuadrado de dicho
tamaño, los bordes del cuadrado deben estar hechos con el carácter `+' y el interior debe estar vacío.
Ej: si se ingresa 4 se debe imprimir:
++++
+  +
+  +
++++
*/

#include <iostream>
using namespace std;              

int main()
{                                     
    int numero;                     
    cout << "Ingrse un número: ";    
    cin >> numero;                                    // 4 

                                
    for (int fila = 0; fila < numero; fila ++){       /* iter 1 f= 0 c= 0   impr? = */

        for (int columna = 0; columna < numero; columna ++){

            if (fila == 0 || fila == numero -1 || columna == 0 || columna == numero -1){

                cout << "+" ;
            }
            else {
                cout << " " ;
            }

        }

        cout << endl; 

    }


    return 0;
}
