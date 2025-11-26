# Arreglos (Arrays) en C++

## ¿Qué es un Arreglo?
Un **arreglo** (o array) es una estructura de datos que almacena una colección de elementos del **mismo tipo** en ubicaciones de memoria contiguas.

## Declaración e Inicialización

### Declaración
```cpp
tipo nombre_arreglo[tamano];
```
Ejemplo:
```cpp
int numeros[5]; // Arreglo de 5 enteros
```

### Inicialización
```cpp
int numeros[5] = {10, 20, 30, 40, 50};
int pares[] = {2, 4, 6, 8}; // El tamaño se deduce automáticamente
```

## Acceso a Elementos
Los elementos se acceden mediante un **índice**, comenzando desde **0**.

```cpp
int x = numeros[0]; // Primer elemento (10)
numeros[2] = 100;   // Modificar el tercer elemento
```

## Recorrer un Arreglo
Se suele usar un bucle `for` para iterar sobre todos los elementos.

```cpp
for(int i = 0; i < 5; i++) {
    cout << numeros[i] << " ";
}
```

## Arreglos Multidimensionales (Matrices)
Son arreglos de arreglos. El más común es la matriz bidimensional (filas y columnas).

```cpp
int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Acceso: matriz[fila][columna]
int valor = matriz[1][2]; // Fila 1, Columna 2 -> Valor 6
```

---
¡Practica con los ejercicios a continuación!
