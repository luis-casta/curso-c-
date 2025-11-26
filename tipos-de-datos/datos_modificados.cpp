
// datos modificados 

/*
  Estos tipos de datos modifican el tamaño o el comportamiento de los tipos primitivos:
  signed: Indica que el tipo puede ser positivo o negativo (por defecto, los tipos int, char, short y long son signed).
*/

#include <iostream>
using namespace std;

int main() {
    signed int a = -10;
    unsigned int positivo = 20; // almacena solo numeros positivos
    long long numeroGrande = 84786584584574; // entero largo con mas capacidad que long
    
    cout << "Ejemplos de datos modificados:" << endl;
    cout << "signed int: " << a << endl;
    cout << "unsigned int: " << positivo << endl;
    cout << "long long: " << numeroGrande << endl;
    
    return 0;
}
