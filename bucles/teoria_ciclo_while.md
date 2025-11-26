# Teoría del Ciclo WHILE en C++

## ¿Qué es un Ciclo WHILE?

El **ciclo while** es una estructura de control iterativa que ejecuta un bloque de código **mientras** una condición sea verdadera. A diferencia del `for`, el `while` es ideal cuando **no sabemos de antemano** cuántas veces se repetirá el ciclo.

## Sintaxis Básica

```cpp
while (condición) {
    // Código a repetir
}
```

### Componentes del Ciclo WHILE

1. **Condición**: Se evalúa antes de cada iteración. Si es `true`, el ciclo continúa; si es `false`, el ciclo termina.
2. **Cuerpo del ciclo**: El código entre llaves `{}` que se ejecuta mientras la condición sea verdadera.

## Ejemplo Básico

```cpp
int contador = 0;

while (contador < 5) {
    cout << "Contador: " << contador << endl;
    contador++;
}
```

**Salida:**
```
Contador: 0
Contador: 1
Contador: 2
Contador: 3
Contador: 4
```

## Flujo de Ejecución

1. Se evalúa la **condición**
2. Si la condición es `true`:
   - Se ejecuta el **cuerpo del ciclo**
   - Se vuelve al paso 1
3. Si la condición es `false`, el ciclo termina

## Diferencia con DO-WHILE

### WHILE (evalúa primero)

```cpp
int x = 10;
while (x < 5) {
    cout << "Esto nunca se ejecuta" << endl;
}
// No imprime nada porque la condición es falsa desde el inicio
```

### DO-WHILE (ejecuta primero, evalúa después)

```cpp
int x = 10;
do {
    cout << "Esto se ejecuta al menos una vez" << endl;
} while (x < 5);
// Imprime una vez, aunque la condición sea falsa
```

## Sintaxis DO-WHILE

```cpp
do {
    // Código a repetir
} while (condición);
```

**Nota**: El punto y coma `;` después del `while` es obligatorio en `do-while`.

## Ejemplos de Uso del WHILE

### 1. Contador Simple

```cpp
int i = 1;
while (i <= 10) {
    cout << i << " ";
    i++;
}
// Salida: 1 2 3 4 5 6 7 8 9 10
```

### 2. Suma de Números hasta un Límite

```cpp
int suma = 0;
int numero = 1;

while (suma < 100) {
    suma += numero;
    numero++;
}

cout << "Suma: " << suma << endl;
cout << "Último número sumado: " << (numero - 1) << endl;
```

### 3. Validación de Entrada

```cpp
int edad;
cout << "Ingrese su edad (1-120): ";
cin >> edad;

while (edad < 1 || edad > 120) {
    cout << "Edad inválida. Intente nuevamente: ";
    cin >> edad;
}

cout << "Edad válida: " << edad << endl;
```

### 4. Búsqueda en un Arreglo

```cpp
int numeros[] = {10, 20, 30, 40, 50};
int buscar = 30;
int indice = 0;
bool encontrado = false;

while (indice < 5 && !encontrado) {
    if (numeros[indice] == buscar) {
        encontrado = true;
    } else {
        indice++;
    }
}

if (encontrado) {
    cout << "Número encontrado en posición: " << indice << endl;
}
```

### 5. Lectura hasta Fin de Archivo

```cpp
int numero;
cout << "Ingrese números (0 para terminar): ";
cin >> numero;

while (numero != 0) {
    cout << "Número ingresado: " << numero << endl;
    cin >> numero;
}
```

## Ciclo WHILE Infinito

Un ciclo que nunca termina:

```cpp
while (true) {
    cout << "Este ciclo nunca termina" << endl;
    // Necesitas un break para salir
}
```

**Uso práctico con break:**

```cpp
while (true) {
    cout << "Ingrese un número (0 para salir): ";
    int num;
    cin >> num;
    
    if (num == 0) {
        break; // Sale del ciclo
    }
    
    cout << "Procesando: " << num << endl;
}
```

## Sentencias de Control

### 1. break - Salir del ciclo

```cpp
int contador = 0;
while (contador < 100) {
    if (contador == 10) {
        break; // Sale cuando contador es 10
    }
    cout << contador << " ";
    contador++;
}
// Salida: 0 1 2 3 4 5 6 7 8 9
```

### 2. continue - Saltar a la siguiente iteración

```cpp
int contador = 0;
while (contador < 10) {
    contador++;
    if (contador % 2 == 0) {
        continue; // Salta los números pares
    }
    cout << contador << " ";
}
// Salida: 1 3 5 7 9
```

## Ciclos WHILE Anidados

```cpp
int fila = 1;
while (fila <= 3) {
    int columna = 1;
    while (columna <= 3) {
        cout << "(" << fila << "," << columna << ") ";
        columna++;
    }
    cout << endl;
    fila++;
}
```

**Salida:**
```
(1,1) (1,2) (1,3) 
(2,1) (2,2) (2,3) 
(3,1) (3,2) (3,3) 
```

## Ventajas del Ciclo WHILE

✅ **Flexible**: Ideal cuando no sabes cuántas iteraciones necesitas  
✅ **Condiciones complejas**: Puede evaluar condiciones más elaboradas  
✅ **Validación de entrada**: Perfecto para validar datos del usuario  
✅ **Lectura de archivos**: Útil para leer hasta el final de un archivo  
✅ **Búsquedas**: Excelente para buscar elementos hasta encontrarlos  

## Desventajas del Ciclo WHILE

❌ **Más verboso**: Requiere más líneas de código que `for`  
❌ **Riesgo de ciclos infinitos**: Si olvidas actualizar la condición  
❌ **Variable de control externa**: Debe declararse fuera del ciclo  

## Cuándo Usar el Ciclo WHILE

- ✅ Cuando no conoces el número de iteraciones
- ✅ Para validar entrada del usuario
- ✅ Para leer datos hasta una condición específica
- ✅ Para implementar menús interactivos
- ✅ Para búsquedas con condición de parada
- ✅ Para procesar datos hasta fin de archivo

## Errores Comunes

### 1. Olvidar actualizar la condición (ciclo infinito)

```cpp
// ❌ Ciclo infinito: contador nunca cambia
int contador = 0;
while (contador < 10) {
    cout << "Hola" << endl;
    // Falta: contador++;
}
```

### 2. Condición inicial incorrecta

```cpp
// ❌ Nunca se ejecuta porque la condición es falsa desde el inicio
int i = 10;
while (i < 5) {
    cout << i << endl;
    i++;
}
```

### 3. Modificar la variable de control incorrectamente

```cpp
// ❌ Puede causar comportamiento inesperado
int i = 0;
while (i < 10) {
    i += 2;
    i--; // Contradice el incremento
}
```

### 4. Usar asignación en lugar de comparación

```cpp
// ❌ Asignación (=) en lugar de comparación (==)
int x = 5;
while (x = 10) { // Siempre true, ciclo infinito
    cout << x << endl;
}

// ✅ Correcto
while (x == 10) {
    cout << x << endl;
}
```

## Buenas Prácticas

### 1. Inicializa las variables antes del ciclo

```cpp
int contador = 0; // Inicialización clara
while (contador < 10) {
    cout << contador << endl;
    contador++;
}
```

### 2. Asegúrate de que la condición eventualmente sea falsa

```cpp
// ✅ La condición eventualmente será falsa
int intentos = 0;
const int MAX_INTENTOS = 3;

while (intentos < MAX_INTENTOS) {
    // Código
    intentos++; // Garantiza que el ciclo termine
}
```

### 3. Usa nombres descriptivos

```cpp
// ❌ Poco descriptivo
int x = 0;
while (x < 10) { x++; }

// ✅ Descriptivo
int numero_intentos = 0;
const int MAXIMO_INTENTOS = 10;
while (numero_intentos < MAXIMO_INTENTOS) {
    numero_intentos++;
}
```

### 4. Evita condiciones complejas

```cpp
// ❌ Difícil de leer
while (a < 10 && b > 5 || c == 3 && d != 7) { }

// ✅ Más claro
bool condicion_valida = (a < 10 && b > 5) || (c == 3 && d != 7);
while (condicion_valida) {
    // Código
    condicion_valida = (a < 10 && b > 5) || (c == 3 && d != 7);
}
```

### 5. Considera usar do-while cuando sea apropiado

```cpp
// Si necesitas ejecutar al menos una vez, usa do-while
int opcion;
do {
    cout << "1. Opción 1" << endl;
    cout << "2. Opción 2" << endl;
    cout << "0. Salir" << endl;
    cin >> opcion;
} while (opcion != 0);
```

## Patrones Comunes

### Patrón de Validación

```cpp
int numero;
bool es_valido = false;

while (!es_valido) {
    cout << "Ingrese un número positivo: ";
    cin >> numero;
    
    if (numero > 0) {
        es_valido = true;
    } else {
        cout << "Error: el número debe ser positivo" << endl;
    }
}
```

### Patrón de Menú

```cpp
int opcion = -1;

while (opcion != 0) {
    cout << "\n=== MENÚ ===" << endl;
    cout << "1. Opción 1" << endl;
    cout << "2. Opción 2" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione: ";
    cin >> opcion;
    
    switch (opcion) {
        case 1:
            cout << "Ejecutando opción 1" << endl;
            break;
        case 2:
            cout << "Ejecutando opción 2" << endl;
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción inválida" << endl;
    }
}
```

### Patrón de Acumulación

```cpp
int suma = 0;
int numero;

cout << "Ingrese números (0 para terminar): ";
cin >> numero;

while (numero != 0) {
    suma += numero;
    cin >> numero;
}

cout << "Suma total: " << suma << endl;
```

## Comparación: WHILE vs FOR

| Característica | WHILE | FOR |
|----------------|-------|-----|
| Uso principal | Condición desconocida | Número conocido de iteraciones |
| Sintaxis | Más simple | Más compacta |
| Variable de control | Fuera del ciclo | Dentro del ciclo |
| Legibilidad | Mejor para condiciones complejas | Mejor para contadores |
| Flexibilidad | Más flexible | Menos flexible |

## Ejemplos Prácticos

### Adivinar un Número

```cpp
int numero_secreto = 42;
int intento;
bool adivinado = false;

while (!adivinado) {
    cout << "Adivina el número: ";
    cin >> intento;
    
    if (intento == numero_secreto) {
        cout << "¡Correcto!" << endl;
        adivinado = true;
    } else if (intento < numero_secreto) {
        cout << "Muy bajo" << endl;
    } else {
        cout << "Muy alto" << endl;
    }
}
```

### Calcular Factorial

```cpp
int n = 5;
int factorial = 1;
int i = 1;

while (i <= n) {
    factorial *= i;
    i++;
}

cout << "Factorial de " << n << " = " << factorial << endl;
```

### Invertir un Número

```cpp
int numero = 12345;
int invertido = 0;

while (numero > 0) {
    int digito = numero % 10;
    invertido = invertido * 10 + digito;
    numero /= 10;
}

cout << "Número invertido: " << invertido << endl; // 54321
```

## Resumen

El ciclo `while` es una herramienta poderosa que te permite:
- Repetir código mientras una condición sea verdadera
- Validar entrada del usuario
- Implementar búsquedas y algoritmos complejos
- Crear menús interactivos
- Procesar datos hasta una condición específica

**Regla de oro**: Usa `while` cuando la condición de parada sea más importante que el número de iteraciones, y `for` cuando sepas exactamente cuántas veces necesitas iterar.
