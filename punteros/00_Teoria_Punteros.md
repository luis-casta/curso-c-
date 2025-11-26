# Punteros en C++

## ¿Qué es un puntero?
Un **puntero** es una variable que almacena la **dirección de memoria** de otra variable. En lugar de contener un valor de datos (como un `int` o `char`), contiene la ubicación donde ese dato está almacenado en la memoria.

## ¿Por qué usar punteros?
- **Gestión dinámica de memoria:** Permiten reservar y liberar memoria durante la ejecución.
- **Paso de parámetros por referencia:** Permiten modificar variables originales dentro de funciones sin necesidad de copiar grandes cantidades de datos.
- **Estructuras de datos complejas:** Son la base de listas enlazadas, árboles, grafos, etc.
- **Eficiencia:** Acceder y manipular grandes arrays o estructuras es más rápido mediante punteros.

## Sintaxis Básica

### Declaración
Para declarar un puntero, se usa el operador asterisco `*` antes del nombre de la variable.

```cpp
int* ptr; // Puntero a un entero
char* caracter; // Puntero a un caracter
```

### Operadores Principales
1. **Operador de dirección (`&`):** Obtiene la dirección de memoria de una variable.
2. **Operador de desreferencia (`*`):** Accede al valor almacenado en la dirección que tiene el puntero.

### Ejemplo Básico

```cpp
#include <iostream>

int main() {
    int numero = 10;
    int* puntero = &numero; // 'puntero' guarda la dirección de 'numero'

    std::cout << "Valor de numero: " << numero << std::endl;
    std::cout << "Direccion de numero (&numero): " << &numero << std::endl;
    std::cout << "Valor del puntero (puntero): " << puntero << std::endl;
    std::cout << "Valor apuntado (*puntero): " << *puntero << std::endl;

    // Modificar el valor a través del puntero
    *puntero = 20;
    std::cout << "Nuevo valor de numero: " << numero << std::endl;

    return 0;
}
```

## Punteros y Arrays
El nombre de un array actúa como un puntero al primer elemento del array.

```cpp
int arr[3] = {10, 20, 30};
int* p = arr; // Apunta a arr[0]

std::cout << *p << std::endl;       // Imprime 10
std::cout << *(p + 1) << std::endl; // Imprime 20 (Aritmética de punteros)
```

## Memoria Dinámica (`new` y `delete`)
Podemos pedir memoria al sistema operativo en tiempo de ejecución.

```cpp
int* p = new int; // Reserva memoria para un entero
*p = 5;
delete p; // Libera la memoria

// Arrays dinámicos
int* arr = new int[10]; // Array de 10 enteros
delete[] arr; // Liberar array
```

---
¡Ahora intenta resolver los ejercicios prácticos en esta carpeta para afianzar tus conocimientos!
