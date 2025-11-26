/*Operadores Aritmeticos:
Permiten realizar operaciones matemáticas básicas.

Operador	              Descripción	           Ejemplo
+	                        Suma	                 a + b
-	                        Resta	                 a - b
*	                        Multiplicación	       a * b
/	                        División	             a / b
%	                        Módulo            (resto de la división)	     a % b
🔹 Nota: En la división entre enteros, el resultado es entero (5 / 2 da 2).
*/

#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;
    
    cout << "Ejemplos de operadores aritméticos:" << endl;
    cout << "a = " << a << ", b = " << b << endl << endl;
    
    cout << "Suma: " << a << " + " << b << " = " << (a + b) << endl;
    cout << "Resta: " << a << " - " << b << " = " << (a - b) << endl;
    cout << "Multiplicación: " << a << " * " << b << " = " << (a * b) << endl;
    cout << "División: " << a << " / " << b << " = " << (a / b) << endl;
    cout << "Módulo: " << a << " % " << b << " = " << (a % b) << endl;
    
    return 0;
}
