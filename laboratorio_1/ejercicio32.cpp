/* Ejercicio 32. Escriba un programa que pida al usuario ingresar una serie de
números enteros positivos (el usuario ingresará -1 para terminar la entrada).
El programa debe calcular y mostrar:
1. La cantidad total de números ingresados
2. La suma de todos los números
3. El promedio de los números
4. El número mayor ingresado
5. El número menor ingresado
6. Cuántos números pares e impares se ingresaron

Nota: No contar el -1 en las estadísticas. */

#include <iostream>
#include <limits>
using namespace std;

int main(){
    int numero;
    int cantidad = 0;
    int suma = 0;
    int mayor = numeric_limits<int>::min();
    int menor = numeric_limits<int>::max();
    int pares = 0;
    int impares = 0;

    cout << "========================================" << endl;
    cout << "  CALCULADORA DE ESTADÍSTICAS" << endl;
    cout << "========================================" << endl;
    cout << "Ingrese números enteros positivo: " << endl;
    cout << "para términar ingrese -1 " << endl;
    cout << "========================================" << endl;

    while (true){
        cout << "\nIngrese un número: ";
        cin >> numero;

        if(numero == -1){
            break;
        }

        if(numero < 0){
            cout << "Ingrese solo números positivos";
            continue;
        }
        cantidad++;

        suma += numero;

        if(numero > mayor){
            mayor = numero;
        }
        if(numero < menor){
            menor = numero;
        }

        if (numero % 2 == 0){
            pares++;
        }else{
            impares++;
        }
    }

     cout << "\n========================================" << endl;
    cout << "          RESULTADOS" << endl;
    cout << "========================================" << endl;

    if(cantidad == 0){
        cout << "No se ingresarón números válidos";
    }else {
        cout << "1. Cantidad de números ingresados: " << cantidad << endl;
        cout << "2. Suma total: " << suma << endl;
        cout << "3. Promedio: " << static_cast<double>(suma) / cantidad << endl;
        cout << "4. Número mayor: " << mayor << endl;
        cout << "5. Número menor: " << menor << endl;
        cout << "6. Números pares: " << pares << endl;
        cout << "   Números impares: " << impares << endl;
    }
     cout << "========================================" << endl;
     cout << "Gracias por usar el programa!" << endl;

    return 0;
} 