# Teoría de Vectores (std::vector) en C++

## ¿Qué es un Vector?

Un **vector** (`std::vector`) es un contenedor de la biblioteca estándar de C++ (STL) que implementa un **arreglo dinámico**. A diferencia de los arreglos tradicionales, los vectores pueden cambiar su tamaño automáticamente durante la ejecución del programa.

## Características Principales

✅ **Tamaño dinámico**: Crece y se reduce automáticamente  
✅ **Acceso aleatorio**: Acceso O(1) a cualquier elemento  
✅ **Gestión automática de memoria**: No necesitas usar `new` o `delete`  
✅ **Seguridad**: Incluye verificación de límites con `.at()`  
✅ **Funciones útiles**: Muchos métodos incorporados  

## Incluir la Biblioteca

```cpp
#include <vector>
using namespace std;
```

## Declaración e Inicialización

### Declaración Básica

```cpp
vector<int> numeros;              // Vector vacío de enteros
vector<double> precios;           // Vector vacío de doubles
vector<string> nombres;           // Vector vacío de strings
```

### Inicialización con Tamaño

```cpp
vector<int> numeros(10);          // Vector de 10 enteros (inicializados en 0)
vector<double> precios(5, 9.99);  // Vector de 5 doubles, todos con valor 9.99
```

### Inicialización con Lista

```cpp
vector<int> numeros = {1, 2, 3, 4, 5};
vector<string> dias = {"Lunes", "Martes", "Miercoles"};
```

### Copiar un Vector

```cpp
vector<int> original = {1, 2, 3};
vector<int> copia = original;     // Copia todos los elementos
```

## Operaciones Básicas

### Agregar Elementos

```cpp
vector<int> numeros;

numeros.push_back(10);    // Agrega 10 al final
numeros.push_back(20);    // Agrega 20 al final
numeros.push_back(30);    // Agrega 30 al final
// Vector: [10, 20, 30]
```

### Acceder a Elementos

```cpp
vector<int> numeros = {10, 20, 30, 40, 50};

// Método 1: Operador []
int x = numeros[0];       // Primer elemento: 10
int y = numeros[2];       // Tercer elemento: 30

// Método 2: Método .at() (con verificación de límites)
int z = numeros.at(1);    // Segundo elemento: 20

// Método 3: Primer y último elemento
int primero = numeros.front();  // 10
int ultimo = numeros.back();    // 50
```

### Modificar Elementos

```cpp
numeros[0] = 100;         // Cambia el primer elemento
numeros.at(2) = 300;      // Cambia el tercer elemento
```

### Eliminar Elementos

```cpp
numeros.pop_back();       // Elimina el último elemento
numeros.clear();          // Elimina todos los elementos
```

### Tamaño del Vector

```cpp
int tamano = numeros.size();        // Número de elementos
bool vacio = numeros.empty();       // true si está vacío
int capacidad = numeros.capacity(); // Capacidad reservada
```

## Recorrer un Vector

### Con Índice (for tradicional)

```cpp
for(int i = 0; i < numeros.size(); i++) {
    cout << numeros[i] << " ";
}
```

### Con Rango (for-each, C++11)

```cpp
for(int numero : numeros) {
    cout << numero << " ";
}
```

### Con Iteradores

```cpp
for(auto it = numeros.begin(); it != numeros.end(); it++) {
    cout << *it << " ";
}
```

## Métodos Importantes

| Método | Descripción | Complejidad |
|--------|-------------|-------------|
| `push_back(x)` | Agrega x al final | O(1) amortizado |
| `pop_back()` | Elimina el último elemento | O(1) |
| `size()` | Retorna el número de elementos | O(1) |
| `empty()` | Verifica si está vacío | O(1) |
| `clear()` | Elimina todos los elementos | O(n) |
| `front()` | Retorna el primer elemento | O(1) |
| `back()` | Retorna el último elemento | O(1) |
| `at(i)` | Accede al elemento en posición i | O(1) |
| `insert(pos, x)` | Inserta x en posición pos | O(n) |
| `erase(pos)` | Elimina elemento en posición pos | O(n) |
| `resize(n)` | Cambia el tamaño a n | O(n) |
| `reserve(n)` | Reserva capacidad para n elementos | O(n) |

## Insertar y Eliminar en Posiciones Específicas

### Insertar

```cpp
vector<int> numeros = {1, 2, 4, 5};

// Insertar 3 en la posición 2
numeros.insert(numeros.begin() + 2, 3);
// Resultado: [1, 2, 3, 4, 5]
```

### Eliminar

```cpp
vector<int> numeros = {1, 2, 3, 4, 5};

// Eliminar el elemento en posición 2
numeros.erase(numeros.begin() + 2);
// Resultado: [1, 2, 4, 5]
```

## Vectores Multidimensionales

### Vector de Vectores (Matriz)

```cpp
// Matriz de 3x4
vector<vector<int>> matriz(3, vector<int>(4, 0));

// Acceso
matriz[0][0] = 1;
matriz[1][2] = 5;

// Recorrido
for(int i = 0; i < matriz.size(); i++) {
    for(int j = 0; j < matriz[i].size(); j++) {
        cout << matriz[i][j] << " ";
    }
    cout << endl;
}
```

## Ordenamiento y Búsqueda

### Ordenar un Vector

```cpp
#include <algorithm>

vector<int> numeros = {5, 2, 8, 1, 9};

// Ordenar de menor a mayor
sort(numeros.begin(), numeros.end());
// Resultado: [1, 2, 5, 8, 9]

// Ordenar de mayor a menor
sort(numeros.begin(), numeros.end(), greater<int>());
// Resultado: [9, 8, 5, 2, 1]
```

### Buscar un Elemento

```cpp
#include <algorithm>

vector<int> numeros = {1, 2, 5, 8, 9};

// Buscar el valor 5
auto it = find(numeros.begin(), numeros.end(), 5);

if(it != numeros.end()) {
    cout << "Encontrado en posición: " << (it - numeros.begin()) << endl;
} else {
    cout << "No encontrado" << endl;
}
```

## Ventajas de los Vectores

✅ **Tamaño dinámico**: No necesitas saber el tamaño de antemano  
✅ **Fácil de usar**: Muchas funciones incorporadas  
✅ **Seguro**: Gestión automática de memoria  
✅ **Eficiente**: Buen rendimiento para la mayoría de operaciones  
✅ **Compatible con STL**: Funciona con algoritmos estándar  

## Desventajas de los Vectores

❌ **Inserción/eliminación en medio**: O(n) - lento para listas grandes  
❌ **Realocación**: Puede ser costoso cuando crece  
❌ **Overhead de memoria**: Puede reservar más espacio del necesario  

## Vector vs Arreglo Tradicional

| Característica | Vector | Arreglo |
|----------------|--------|---------|
| Tamaño | Dinámico | Fijo |
| Gestión de memoria | Automática | Manual |
| Funciones | Muchas | Pocas |
| Rendimiento | Ligeramente menor | Ligeramente mayor |
| Seguridad | Mayor | Menor |
| Uso recomendado | Casi siempre | Casos específicos |

## Buenas Prácticas

1. **Usa `.at()` para depuración** (lanza excepción si índice inválido)
   ```cpp
   int x = numeros.at(i);  // Seguro
   ```

2. **Reserva capacidad si conoces el tamaño aproximado**
   ```cpp
   vector<int> numeros;
   numeros.reserve(1000);  // Evita realocaciones
   ```

3. **Usa referencias en bucles for-each para evitar copias**
   ```cpp
   for(const auto& elemento : numeros) {
       // No copia el elemento
   }
   ```

4. **Verifica si está vacío antes de acceder**
   ```cpp
   if(!numeros.empty()) {
       int x = numeros.front();
   }
   ```

## Ejemplo Completo

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Crear vector
    vector<int> numeros;
    
    // Agregar elementos
    numeros.push_back(5);
    numeros.push_back(2);
    numeros.push_back(8);
    numeros.push_back(1);
    
    // Mostrar tamaño
    cout << "Tamaño: " << numeros.size() << endl;
    
    // Recorrer
    for(int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    
    // Ordenar
    sort(numeros.begin(), numeros.end());
    
    // Mostrar ordenado
    for(int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
```

## Cuándo Usar Vectores

✅ Cuando no conoces el tamaño de antemano  
✅ Cuando necesitas agregar/eliminar elementos frecuentemente al final  
✅ Cuando quieres código más limpio y seguro  
✅ Cuando necesitas funciones de la STL  
✅ En la mayoría de los casos (es el contenedor más usado)  

## Resumen

Los vectores son la opción predeterminada para almacenar colecciones de datos en C++ moderno. Ofrecen flexibilidad, seguridad y facilidad de uso, con un rendimiento excelente para la mayoría de aplicaciones.
