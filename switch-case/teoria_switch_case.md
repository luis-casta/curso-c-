# Teoría de Switch-Case en C++

## ¿Qué es Switch-Case?

`switch-case` es una estructura de control que permite ejecutar diferentes bloques de código basándose en el valor de una expresión. Es una alternativa más limpia a múltiples `if-else` cuando comparamos una variable con varios valores constantes.

## Sintaxis Básica

```cpp
switch (expresion) {
    case valor1:
        // Código si expresion == valor1
        break;
    case valor2:
        // Código si expresion == valor2
        break;
    case valor3:
        // Código si expresion == valor3
        break;
    default:
        // Código si ningún caso coincide
        break;
}
```

## Ejemplo Básico

```cpp
int dia = 3;

switch (dia) {
    case 1:
        cout << "Lunes" << endl;
        break;
    case 2:
        cout << "Martes" << endl;
        break;
    case 3:
        cout << "Miercoles" << endl;
        break;
    default:
        cout << "Dia invalido" << endl;
        break;
}
```

## La Importancia de `break`

El `break` es crucial porque **detiene la ejecución** del switch. Sin `break`, el código continúa ejecutando los siguientes casos (fall-through).

```cpp
int opcion = 2;

// SIN break (fall-through)
switch (opcion) {
    case 1:
        cout << "Uno" << endl;
    case 2:
        cout << "Dos" << endl;    // Se ejecuta
    case 3:
        cout << "Tres" << endl;   // También se ejecuta!
}
// Salida: Dos\nTres

// CON break
switch (opcion) {
    case 1:
        cout << "Uno" << endl;
        break;
    case 2:
        cout << "Dos" << endl;    // Se ejecuta
        break;                     // Y se detiene aquí
    case 3:
        cout << "Tres" << endl;
        break;
}
// Salida: Dos
```

## Casos Múltiples

Puedes agrupar varios casos que ejecutan el mismo código:

```cpp
char calificacion = 'B';

switch (calificacion) {
    case 'A':
    case 'a':
        cout << "Excelente" << endl;
        break;
    case 'B':
    case 'b':
        cout << "Muy bien" << endl;
        break;
    case 'C':
    case 'c':
        cout << "Bien" << endl;
        break;
    default:
        cout << "Calificacion no reconocida" << endl;
        break;
}
```

## Default Case

El `default` es opcional pero recomendado. Se ejecuta cuando ningún caso coincide:

```cpp
int numero = 100;

switch (numero) {
    case 1:
        cout << "Uno" << endl;
        break;
    case 2:
        cout << "Dos" << endl;
        break;
    default:
        cout << "Otro numero" << endl;
        break;
}
```

## Tipos de Datos Permitidos

Switch solo funciona con tipos **enteros** y **caracteres**:

✅ `int`, `short`, `long`, `long long`  
✅ `char`  
✅ `enum`  
❌ `float`, `double`  
❌ `string`  

```cpp
// ✅ Válido
int x = 5;
switch (x) { }

char c = 'A';
switch (c) { }

// ❌ NO válido
string nombre = "Juan";
switch (nombre) { }  // ERROR

double precio = 19.99;
switch (precio) { }  // ERROR
```

## Switch vs If-Else

### Cuándo usar Switch
✅ Comparar una variable con múltiples valores constantes  
✅ Valores discretos y conocidos  
✅ Código más limpio y legible  

### Cuándo usar If-Else
✅ Condiciones complejas  
✅ Rangos de valores  
✅ Comparaciones con strings  
✅ Expresiones booleanas  

```cpp
// Switch - mejor para valores discretos
switch (dia_semana) {
    case 1: cout << "Lunes"; break;
    case 2: cout << "Martes"; break;
    // ...
}

// If-else - mejor para rangos
if (edad < 18) {
    cout << "Menor de edad";
} else if (edad < 65) {
    cout << "Adulto";
} else {
    cout << "Adulto mayor";
}
```

## Ejemplo Completo: Calculadora

```cpp
#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operador;
    
    cout << "Ingrese primer numero: ";
    cin >> num1;
    cout << "Ingrese operador (+, -, *, /): ";
    cin >> operador;
    cout << "Ingrese segundo numero: ";
    cin >> num2;
    
    switch (operador) {
        case '+':
            cout << "Resultado: " << (num1 + num2) << endl;
            break;
        case '-':
            cout << "Resultado: " << (num1 - num2) << endl;
            break;
        case '*':
            cout << "Resultado: " << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Resultado: " << (num1 / num2) << endl;
            } else {
                cout << "Error: Division por cero" << endl;
            }
            break;
        default:
            cout << "Operador invalido" << endl;
            break;
    }
    
    return 0;
}
```

## Buenas Prácticas

1. **Siempre usa `break`** (a menos que quieras fall-through intencional)
2. **Incluye `default`** para manejar casos inesperados
3. **Usa constantes** para valores de case
4. **Comenta** si usas fall-through intencionalmente
5. **Mantén los casos simples** - lógica compleja va en funciones

## Resumen

Switch-case es ideal para menús, opciones discretas y cuando necesitas comparar una variable con múltiples valores constantes. Es más limpio y eficiente que múltiples if-else para estos casos.
