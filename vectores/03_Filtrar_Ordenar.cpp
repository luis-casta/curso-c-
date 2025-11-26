/*
 * EJERCICIO VECTORES 3: FILTRAR Y ORDENAR (NIVEL MEDIO)
 * 
 * Descripción:
 * Programa que filtra números pares e impares y los ordena.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numeros;
    vector<int> pares;
    vector<int> impares;
    
    cout << "=== FILTRAR Y ORDENAR NUMEROS ===" << endl;
    
    // Ingresar números
    int cantidad;
    cout << "¿Cuantos numeros desea ingresar? ";
    cin >> cantidad;
    
    for(int i = 0; i < cantidad; i++) {
        int num;
        cout << "Numero " << (i + 1) << ": ";
        cin >> num;
        numeros.push_back(num);
    }
    
    // Filtrar pares e impares
    for(int num : numeros) {
        if(num % 2 == 0) {
            pares.push_back(num);
        } else {
            impares.push_back(num);
        }
    }
    
    // Ordenar
    sort(pares.begin(), pares.end());
    sort(impares.begin(), impares.end(), greater<int>()); // Descendente
    
    // Mostrar resultados
    cout << "\n--- NUMEROS PARES (ordenados ascendente) ---" << endl;
    for(int num : pares) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "\n--- NUMEROS IMPARES (ordenados descendente) ---" << endl;
    for(int num : impares) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "\nCantidad de pares: " << pares.size() << endl;
    cout << "Cantidad de impares: " << impares.size() << endl;
    
    return 0;
}
