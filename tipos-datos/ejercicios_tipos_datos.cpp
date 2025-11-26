// EJERCICIO TIPOS DE DATOS 1-5: Colección de ejercicios

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// EJERCICIO 1: Tipos enteros
void ejercicio1() {
    cout << "=== EJERCICIO 1: TIPOS ENTEROS ===" << endl;
    
    short edad_corta = 25;
    int edad = 30;
    long poblacion = 7800000000;
    long long distancia = 9223372036854775807;
    
    cout << "short: " << edad_corta << " (tamaño: " << sizeof(short) << " bytes)" << endl;
    cout << "int: " << edad << " (tamaño: " << sizeof(int) << " bytes)" << endl;
    cout << "long: " << poblacion << " (tamaño: " << sizeof(long) << " bytes)" << endl;
    cout << "long long: " << distancia << " (tamaño: " << sizeof(long long) << " bytes)" << endl;
}

// EJERCICIO 2: Tipos flotantes
void ejercicio2() {
    cout << "\n=== EJERCICIO 2: TIPOS FLOTANTES ===" << endl;
    
    float pi_float = 3.14159f;
    double pi_double = 3.14159265358979;
    long double pi_long = 3.141592653589793238L;
    
    cout << fixed << setprecision(15);
    cout << "float: " << pi_float << " (tamaño: " << sizeof(float) << " bytes)" << endl;
    cout << "double: " << pi_double << " (tamaño: " << sizeof(double) << " bytes)" << endl;
    cout << "long double: " << pi_long << " (tamaño: " << sizeof(long double) << " bytes)" << endl;
}

// EJERCICIO 3: Caracteres y booleanos
void ejercicio3() {
    cout << "\n=== EJERCICIO 3: CHAR Y BOOL ===" << endl;
    
    char letra = 'A';
    char numero_char = '5';
    bool es_verdadero = true;
    bool es_falso = false;
    
    cout << "char letra: " << letra << " (codigo ASCII: " << (int)letra << ")" << endl;
    cout << "char numero: " << numero_char << " (codigo ASCII: " << (int)numero_char << ")" << endl;
    cout << "bool true: " << es_verdadero << endl;
    cout << "bool false: " << es_falso << endl;
}

// EJERCICIO 4: Strings y conversiones
void ejercicio4() {
    cout << "\n=== EJERCICIO 4: STRINGS Y CONVERSIONES ===" << endl;
    
    string nombre = "Juan";
    string apellido = "Perez";
    string nombre_completo = nombre + " " + apellido;
    
    cout << "Nombre completo: " << nombre_completo << endl;
    cout << "Longitud: " << nombre_completo.length() << endl;
    
    // Conversiones
    string numero_str = "12345";
    int numero_int = stoi(numero_str);
    cout << "String a int: " << numero_str << " -> " << numero_int << endl;
    
    double decimal = 3.14159;
    string decimal_str = to_string(decimal);
    cout << "Double a string: " << decimal << " -> " << decimal_str << endl;
}

// EJERCICIO 5: Límites y unsigned
void ejercicio5() {
    cout << "\n=== EJERCICIO 5: LIMITES Y UNSIGNED ===" << endl;
    
    cout << "Limites de int:" << endl;
    cout << "  Minimo: " << numeric_limits<int>::min() << endl;
    cout << "  Maximo: " << numeric_limits<int>::max() << endl;
    
    cout << "\nLimites de unsigned int:" << endl;
    cout << "  Minimo: " << numeric_limits<unsigned int>::min() << endl;
    cout << "  Maximo: " << numeric_limits<unsigned int>::max() << endl;
    
    cout << "\nLimites de double:" << endl;
    cout << "  Minimo: " << numeric_limits<double>::min() << endl;
    cout << "  Maximo: " << numeric_limits<double>::max() << endl;
    
    // Unsigned vs signed
    int negativo = -10;
    unsigned int positivo = 4000000000;
    
    cout << "\nSigned int: " << negativo << endl;
    cout << "Unsigned int: " << positivo << endl;
}

int main() {
    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio4();
    ejercicio5();
    return 0;
}
