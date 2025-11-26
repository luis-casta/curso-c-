
/* Ejercicio 28. Escriba un programa que encuentre el valor aproximado de pi en base a la siguiente
suma infinita:
π = 4( 1 - 1/3 + 1/5 - 1/7 + 1/9 ...
El usuario debe ingresar el número de elementos usados en la aproximación.Ej: si se ingresa 3 π = 4(1- 1/3 + 1/5) = 3,46667, por lo que se debe imprimir:
pi es aproximadamente: 3.46667*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num_elementos;
    double pi_aproximado = 0.0;
    
    cout << "Ingrese el número de elementos para aproximar pi: ";
    cin >> num_elementos;
    
    // Calcular la aproximación de pi usando la serie infinita
    for(int i = 0; i < num_elementos; i++) {
        double termino = 1.0 / (2 * i + 1);
        if(i % 2 == 0) {
            pi_aproximado += termino;
        } else {
            pi_aproximado -= termino;
        }
    }
    
    pi_aproximado *= 4;
    
    cout << fixed << setprecision(5);
    cout << "pi es aproximadamente: " << pi_aproximado << endl;
    
    return 0;
}