/*
 * EJERCICIO VECTORES 4: MATRIZ DINÁMICA (NIVEL MEDIO-DIFÍCIL)
 * 
 * Descripción:
 * Programa que crea y manipula una matriz usando vector de vectores.
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int filas, columnas;
    
    cout << "=== MATRIZ DINAMICA CON VECTORES ===" << endl;
    cout << "Ingrese numero de filas: ";
    cin >> filas;
    cout << "Ingrese numero de columnas: ";
    cin >> columnas;
    
    // Crear matriz dinámica
    vector<vector<int>> matriz(filas, vector<int>(columnas));
    
    // Llenar matriz
    cout << "\nIngrese los elementos de la matriz:" << endl;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
    
    // Mostrar matriz
    cout << "\n--- MATRIZ INGRESADA ---" << endl;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            cout << setw(5) << matriz[i][j];
        }
        cout << endl;
    }
    
    // Calcular suma de cada fila
    cout << "\n--- SUMA POR FILA ---" << endl;
    for(int i = 0; i < filas; i++) {
        int suma_fila = 0;
        for(int j = 0; j < columnas; j++) {
            suma_fila += matriz[i][j];
        }
        cout << "Fila " << i << ": " << suma_fila << endl;
    }
    
    // Calcular suma de cada columna
    cout << "\n--- SUMA POR COLUMNA ---" << endl;
    for(int j = 0; j < columnas; j++) {
        int suma_columna = 0;
        for(int i = 0; i < filas; i++) {
            suma_columna += matriz[i][j];
        }
        cout << "Columna " << j << ": " << suma_columna << endl;
    }
    
    return 0;
}
