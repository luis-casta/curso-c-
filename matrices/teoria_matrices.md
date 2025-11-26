# Teoría de Matrices en C++

## ¿Qué es una Matriz?

Una **matriz** (o arreglo bidimensional) es una estructura de datos que organiza elementos en filas y columnas, formando una tabla rectangular. En C++, una matriz es esencialmente un arreglo de arreglos.

### Representación Visual

```
    Col0  Col1  Col2  Col3
Fila0  1     2     3     4
Fila1  5     6     7     8
Fila2  9    10    11    12
```

## Declaración de Matrices

### Sintaxis Básica

```cpp
tipo_dato nombre_matriz[numero_filas][numero_columnas];
```

### Ejemplos de Declaración

```cpp
// Matriz de enteros de 3x4 (3 filas, 4 columnas)
int matriz[3][4];

// Matriz de flotantes de 5x5
float temperaturas[5][5];

// Matriz de caracteres de 2x10
char letras[2][10];
```

## Inicialización de Matrices

### Inicialización en la Declaración

```cpp
// Inicialización completa
int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Inicialización parcial (resto se llena con 0)
int matriz2[3][3] = {
    {1, 2},
    {3}
};

// Inicialización con todos ceros
int matriz3[3][3] = {0};
```

### Inicialización Manual

```cpp
int matriz[2][3];

// Asignar valores uno por uno
matriz[0][0] = 10;
matriz[0][1] = 20;
matriz[0][2] = 30;
matriz[1][0] = 40;
matriz[1][1] = 50;
matriz[1][2] = 60;
```

## Acceso a Elementos

Para acceder a un elemento específico, usamos dos índices:
- **Primer índice**: número de fila (comienza en 0)
- **Segundo índice**: número de columna (comienza en 0)

```cpp
int valor = matriz[fila][columna];
matriz[fila][columna] = nuevo_valor;
```

### Ejemplo

```cpp
int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

cout << matriz[0][0]; // Imprime: 1
cout << matriz[1][2]; // Imprime: 6
cout << matriz[2][1]; // Imprime: 8
```

## Recorrido de Matrices

### Bucles Anidados

Para recorrer todos los elementos de una matriz, necesitamos dos bucles anidados:

```cpp
// Recorrido por filas
for(int fila = 0; fila < numero_filas; fila++) {
    for(int columna = 0; columna < numero_columnas; columna++) {
        // Acceder a matriz[fila][columna]
    }
}
```

### Ejemplo Completo

```cpp
int matriz[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// Imprimir todos los elementos
for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
        cout << matriz[i][j] << " ";
    }
    cout << endl; // Nueva línea después de cada fila
}
```

## Operaciones Comunes con Matrices

### 1. Suma de Matrices

Dos matrices **A** y **B** se pueden sumar si tienen las mismas dimensiones. El resultado es una matriz **C** donde cada elemento es:

```
C[i][j] = A[i][j] + B[i][j]
```

### 2. Multiplicación por un Escalar

Multiplicar cada elemento de la matriz por un número:

```
C[i][j] = k * A[i][j]
```

### 3. Matriz Transpuesta

La transpuesta de una matriz **A** es una matriz **A^T** donde las filas se convierten en columnas:

```
A^T[i][j] = A[j][i]
```

**Ejemplo:**
```
A = [1 2 3]      A^T = [1 4]
    [4 5 6]            [2 5]
                       [3 6]
```

### 4. Multiplicación de Matrices

Para multiplicar dos matrices **A** (m×n) y **B** (n×p), el número de columnas de **A** debe ser igual al número de filas de **B**. El resultado es una matriz **C** (m×p):

```
C[i][j] = Σ(A[i][k] * B[k][j]) para k = 0 hasta n-1
```

### 5. Búsqueda de Elementos

- **Elemento máximo/mínimo**: Recorrer toda la matriz comparando valores
- **Búsqueda de un valor específico**: Recorrer hasta encontrarlo

### 6. Diagonal Principal y Secundaria

En una matriz cuadrada (n×n):
- **Diagonal principal**: elementos donde i == j (matriz[0][0], matriz[1][1], ...)
- **Diagonal secundaria**: elementos donde i + j == n - 1

## Matrices Especiales

### Matriz Cuadrada
Tiene el mismo número de filas y columnas (n×n)

### Matriz Identidad
Matriz cuadrada con 1s en la diagonal principal y 0s en el resto:
```
[1 0 0]
[0 1 0]
[0 0 1]
```

### Matriz Simétrica
Una matriz es simétrica si A[i][j] = A[j][i] para todo i, j

### Matriz Triangular Superior
Todos los elementos debajo de la diagonal principal son 0:
```
[1 2 3]
[0 4 5]
[0 0 6]
```

### Matriz Triangular Inferior
Todos los elementos encima de la diagonal principal son 0:
```
[1 0 0]
[2 3 0]
[4 5 6]
```

## Paso de Matrices a Funciones

### Sintaxis

```cpp
void funcion(int matriz[][COLUMNAS], int filas) {
    // Código
}
```

**Nota importante**: Al pasar una matriz a una función, **debemos especificar el número de columnas**, pero el número de filas puede ser un parámetro.

### Ejemplo

```cpp
const int COLS = 4;

void imprimirMatriz(int mat[][COLS], int filas) {
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriz[3][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    imprimirMatriz(matriz, 3);
    return 0;
}
```

## Matrices Dinámicas

Para matrices de tamaño variable en tiempo de ejecución, podemos usar punteros:

```cpp
// Crear matriz dinámica
int** matriz = new int*[filas];
for(int i = 0; i < filas; i++) {
    matriz[i] = new int[columnas];
}

// Usar la matriz...

// Liberar memoria
for(int i = 0; i < filas; i++) {
    delete[] matriz[i];
}
delete[] matriz;
```

## Ventajas de las Matrices

1. **Organización lógica**: Representan datos tabulares de forma natural
2. **Acceso directo**: Acceso O(1) a cualquier elemento
3. **Eficiencia en memoria**: Almacenamiento contiguo
4. **Aplicaciones reales**: Imágenes, tablas, juegos (tableros), cálculos científicos

## Desventajas de las Matrices

1. **Tamaño fijo**: En matrices estáticas, el tamaño debe conocerse en compilación
2. **Desperdicio de memoria**: Si no se usan todos los elementos
3. **Inserción/eliminación costosa**: Requiere reorganizar elementos

## Aplicaciones Prácticas

- **Procesamiento de imágenes**: Cada píxel es un elemento
- **Juegos**: Tableros de ajedrez, sudoku, tres en raya
- **Matemáticas**: Álgebra lineal, sistemas de ecuaciones
- **Gráficos por computadora**: Transformaciones 2D y 3D
- **Bases de datos**: Representación de tablas
- **Inteligencia artificial**: Redes neuronales, algoritmos de búsqueda

## Complejidad Temporal

| Operación | Complejidad |
|-----------|-------------|
| Acceso a elemento | O(1) |
| Búsqueda | O(n×m) |
| Recorrido completo | O(n×m) |
| Suma de matrices | O(n×m) |
| Multiplicación de matrices | O(n³) |

Donde n y m son las dimensiones de la matriz.

## Consejos de Programación

1. **Usa constantes** para las dimensiones de las matrices
2. **Verifica límites** antes de acceder a elementos
3. **Inicializa siempre** las matrices antes de usarlas
4. **Usa nombres descriptivos** para índices (fila, columna en lugar de i, j)
5. **Comenta tu código** especialmente en operaciones complejas
6. **Libera memoria** si usas matrices dinámicas

## Ejemplo Completo

```cpp
#include <iostream>
using namespace std;

const int FILAS = 3;
const int COLUMNAS = 3;

void llenarMatriz(int mat[][COLUMNAS], int filas) {
    cout << "Ingrese los elementos de la matriz:" << endl;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void mostrarMatriz(int mat[][COLUMNAS], int filas) {
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int matriz[FILAS][COLUMNAS];
    
    llenarMatriz(matriz, FILAS);
    cout << "\nMatriz ingresada:" << endl;
    mostrarMatriz(matriz, FILAS);
    
    return 0;
}
```
