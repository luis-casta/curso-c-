/*
 * EJERCICIO VECTORES 1: OPERACIONES BÁSICAS (NIVEL FÁCIL)
 * 
 * Descripción:
 * Este programa demuestra las operaciones básicas con vectores:
 * agregar, eliminar, acceder y modificar elementos.
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Crear un vector vacío
    vector<int> numeros;
    
    cout << "=== OPERACIONES BASICAS CON VECTORES ===" << endl;
    
    // Agregar elementos
    cout << "\n1. Agregando elementos con push_back():" << endl;
    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);
    numeros.push_back(40);
    numeros.push_back(50);
    
    cout << "Vector: ";
    for(int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Tamaño: " << numeros.size() << endl;
    
    // Acceder a elementos
    cout << "\n2. Accediendo a elementos:" << endl;
    cout << "Primer elemento (front): " << numeros.front() << endl;
    cout << "Ultimo elemento (back): " << numeros.back() << endl;
    cout << "Elemento en posicion 2: " << numeros[2] << endl;
    cout << "Elemento en posicion 3 (con at): " << numeros.at(3) << endl;
    
    // Modificar elementos
    cout << "\n3. Modificando elementos:" << endl;
    numeros[0] = 100;
    numeros.at(2) = 300;
    cout << "Despues de modificar posiciones 0 y 2:" << endl;
    cout << "Vector: ";
    for(int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    
    // Eliminar último elemento
    cout << "\n4. Eliminando el ultimo elemento con pop_back():" << endl;
    numeros.pop_back();
    cout << "Vector: ";
    for(int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Nuevo tamaño: " << numeros.size() << endl;
    
    // Verificar si está vacío
    cout << "\n5. Verificando si esta vacio:" << endl;
    cout << "¿Esta vacio? " << (numeros.empty() ? "Si" : "No") << endl;
    
    // Limpiar el vector
    cout << "\n6. Limpiando el vector con clear():" << endl;
    numeros.clear();
    cout << "Tamaño despues de clear(): " << numeros.size() << endl;
    cout << "¿Esta vacio? " << (numeros.empty() ? "Si" : "No") << endl;
    
    return 0;
}
