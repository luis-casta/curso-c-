#include <iostream>
using namespace std;

// Ejercicio 3: Intercambio de Variables (Nivel: Medio)
// Objetivo: Entender el paso por referencia (&) para modificar variables originales.

// Declaración de la función
// Nota el uso de '&' antes del nombre de la variable. Esto indica referencia.
void intercambiar(int &a, int &b);

int main() {
    int x, y;

    cout << "=== Ejercicio 3: Intercambio por Referencia ===" << endl;
    cout << "Introduce el valor de X: ";
    cin >> x;
    cout << "Introduce el valor de Y: ";
    cin >> y;

    cout << "\nAntes del intercambio: X = " << x << ", Y = " << y << endl;

    // Llamamos a la función. Los cambios dentro de ella afectarán a x e y.
    intercambiar(x, y);

    cout << "Después del intercambio: X = " << x << ", Y = " << y << endl;

    return 0;
}

// Definición de la función
void intercambiar(int &a, int &b) {
    // Usamos una variable temporal para guardar el valor de 'a'
    // antes de sobrescribirlo con 'b'.
    int temp = a;
    a = b;
    b = temp;
    
    cout << "[Dentro de la función] Valores intercambiados." << endl;
}
