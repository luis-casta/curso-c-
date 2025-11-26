// EJERCICIO ARRAYS 1-5: Colección de ejercicios con std::array

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

// EJERCICIO 1: Operaciones básicas
void ejercicio1() {
    cout << "=== EJERCICIO 1: OPERACIONES BASICAS ===" << endl;
    array<int, 5> nums = {10, 20, 30, 40, 50};
    
    cout << "Primer elemento: " << nums.front() << endl;
    cout << "Ultimo elemento: " << nums.back() << endl;
    cout << "Tamaño: " << nums.size() << endl;
    
    nums.fill(0);
    cout << "Despues de fill(0): ";
    for(int n : nums) cout << n << " ";
    cout << endl;
}

// EJERCICIO 2: Ordenamiento
void ejercicio2() {
    cout << "\n=== EJERCICIO 2: ORDENAMIENTO ===" << endl;
    array<int, 8> nums = {64, 34, 25, 12, 22, 11, 90, 88};
    
    cout << "Original: ";
    for(int n : nums) cout << n << " ";
    cout << endl;
    
    sort(nums.begin(), nums.end());
    cout << "Ordenado: ";
    for(int n : nums) cout << n << " ";
    cout << endl;
}

// EJERCICIO 3: Búsqueda
void ejercicio3() {
    cout << "\n=== EJERCICIO 3: BUSQUEDA ===" << endl;
    array<int, 6> nums = {10, 20, 30, 40, 50, 60};
    int buscar = 30;
    
    auto it = find(nums.begin(), nums.end(), buscar);
    if(it != nums.end()) {
        cout << "Encontrado " << buscar << " en posicion " 
             << distance(nums.begin(), it) << endl;
    }
}

// EJERCICIO 4: Estadísticas
void ejercicio4() {
    cout << "\n=== EJERCICIO 4: ESTADISTICAS ===" << endl;
    array<double, 5> calificaciones = {85.5, 92.0, 78.5, 95.0, 88.5};
    
    double suma = 0;
    for(double cal : calificaciones) suma += cal;
    double promedio = suma / calificaciones.size();
    
    auto max_it = max_element(calificaciones.begin(), calificaciones.end());
    auto min_it = min_element(calificaciones.begin(), calificaciones.end());
    
    cout << "Promedio: " << promedio << endl;
    cout << "Maxima: " << *max_it << endl;
    cout << "Minima: " << *min_it << endl;
}

// EJERCICIO 5: Matriz con array
void ejercicio5() {
    cout << "\n=== EJERCICIO 5: MATRIZ 3x3 ===" << endl;
    array<array<int, 3>, 3> matriz = {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }};
    
    cout << "Matriz:" << endl;
    for(const auto& fila : matriz) {
        for(int val : fila) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    // Suma diagonal
    int suma_diagonal = 0;
    for(size_t i = 0; i < 3; i++) {
        suma_diagonal += matriz[i][i];
    }
    cout << "Suma diagonal principal: " << suma_diagonal << endl;
}

int main() {
    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio4();
    ejercicio5();
    return 0;
}
