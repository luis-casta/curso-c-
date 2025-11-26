# Teoría de std::array en C++

## ¿Qué es std::array?

`std::array` es un contenedor de la biblioteca estándar de C++ (introducido en C++11) que encapsula arreglos de tamaño fijo. Es un punto medio entre los arreglos tradicionales de C y `std::vector`.

## Características

✅ **Tamaño fijo**: Definido en tiempo de compilación  
✅ **Sin overhead**: Mismo rendimiento que arreglos C  
✅ **Métodos STL**: Acceso a funciones de la biblioteca estándar  
✅ **Seguridad**: Verificación de límites con `.at()`  
✅ **Copia por valor**: Se puede copiar y asignar fácilmente  

## Incluir la Biblioteca

```cpp
#include <array>
using namespace std;
```

## Declaración e Inicialización

```cpp
// Sintaxis: array<tipo, tamaño> nombre;
array<int, 5> numeros;                    // 5 enteros sin inicializar
array<int, 5> nums = {1, 2, 3, 4, 5};    // Inicialización con lista
array<double, 3> precios = {9.99, 19.99, 29.99};
```

## Operaciones Básicas

```cpp
array<int, 5> arr = {10, 20, 30, 40, 50};

// Acceso
int x = arr[0];           // Primer elemento
int y = arr.at(2);        // Con verificación de límites
int primero = arr.front(); // 10
int ultimo = arr.back();   // 50

// Tamaño
size_t tam = arr.size();   // 5
bool vacio = arr.empty();  // false

// Llenar con un valor
arr.fill(0);              // Todos los elementos = 0
```

## std::array vs Arreglo C vs std::vector

| Característica | array | Arreglo C | vector |
|----------------|-------|-----------|--------|
| Tamaño | Fijo (compilación) | Fijo | Dinámico |
| Rendimiento | Excelente | Excelente | Muy bueno |
| Métodos STL | Sí | No | Sí |
| Seguridad | Alta | Baja | Alta |
| Copia | Fácil | Manual | Fácil |

## Cuándo Usar std::array

✅ Cuando conoces el tamaño en tiempo de compilación  
✅ Cuando necesitas máximo rendimiento  
✅ Cuando quieres usar algoritmos STL  
✅ Cuando necesitas pasar arreglos a funciones fácilmente  

## Ejemplo Completo

```cpp
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    array<int, 5> numeros = {5, 2, 8, 1, 9};
    
    // Ordenar
    sort(numeros.begin(), numeros.end());
    
    // Mostrar
    for(int num : numeros) {
        cout << num << " ";
    }
    
    return 0;
}
```
