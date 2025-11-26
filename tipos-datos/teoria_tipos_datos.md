# Teoría de Tipos de Datos en C++

## Tipos de Datos Fundamentales

C++ proporciona varios tipos de datos fundamentales para almacenar diferentes tipos de información.

## 1. Tipos Enteros

### int (Entero)
```cpp
int edad = 25;
int temperatura = -10;
```
- **Tamaño**: Típicamente 4 bytes (32 bits)
- **Rango**: -2,147,483,648 a 2,147,483,647
- **Uso**: Números enteros generales

### short (Entero Corto)
```cpp
short cantidad = 100;
```
- **Tamaño**: 2 bytes (16 bits)
- **Rango**: -32,768 a 32,767
- **Uso**: Cuando necesitas ahorrar memoria

### long (Entero Largo)
```cpp
long poblacion = 7800000000;
```
- **Tamaño**: 4 u 8 bytes
- **Rango**: Depende del sistema
- **Uso**: Números enteros muy grandes

### long long (Entero Muy Largo)
```cpp
long long distancia = 9223372036854775807;
```
- **Tamaño**: 8 bytes (64 bits)
- **Rango**: -9,223,372,036,854,775,808 a 9,223,372,036,854,775,807
- **Uso**: Números extremadamente grandes

### unsigned (Sin Signo)
```cpp
unsigned int positivo = 4000000000;
```
- Solo valores positivos (0 y mayores)
- Duplica el rango positivo

## 2. Tipos de Punto Flotante

### float (Flotante Simple)
```cpp
float precio = 19.99f;
float pi = 3.14159f;
```
- **Tamaño**: 4 bytes
- **Precisión**: ~7 dígitos decimales
- **Uso**: Decimales con precisión moderada

### double (Flotante Doble)
```cpp
double pi_preciso = 3.14159265358979;
```
- **Tamaño**: 8 bytes
- **Precisión**: ~15 dígitos decimales
- **Uso**: Cálculos científicos, precisión alta

### long double (Flotante Extendido)
```cpp
long double muy_preciso = 3.141592653589793238L;
```
- **Tamaño**: 8, 12 o 16 bytes (depende del sistema)
- **Precisión**: Máxima disponible
- **Uso**: Cálculos que requieren máxima precisión

## 3. Tipo Carácter

### char (Carácter)
```cpp
char letra = 'A';
char simbolo = '@';
```
- **Tamaño**: 1 byte
- **Rango**: -128 a 127 (o 0 a 255 si es unsigned)
- **Uso**: Caracteres individuales, texto

## 4. Tipo Booleano

### bool (Booleano)
```cpp
bool es_mayor = true;
bool esta_activo = false;
```
- **Tamaño**: 1 byte
- **Valores**: `true` (1) o `false` (0)
- **Uso**: Condiciones lógicas

## 5. Tipo Cadena

### string (Cadena de Texto)
```cpp
#include <string>
string nombre = "Juan";
string mensaje = "Hola Mundo";
```
- **Tamaño**: Variable
- **Uso**: Texto de longitud variable

## 6. Tipo Void

### void (Vacío)
```cpp
void funcion() {
    // No retorna nada
}
```
- **Uso**: Funciones sin valor de retorno

## Tabla Resumen de Tipos

| Tipo | Tamaño | Rango Aproximado | Uso |
|------|--------|------------------|-----|
| `char` | 1 byte | -128 a 127 | Caracteres |
| `short` | 2 bytes | -32K a 32K | Enteros pequeños |
| `int` | 4 bytes | -2B a 2B | Enteros generales |
| `long` | 4-8 bytes | Variable | Enteros grandes |
| `long long` | 8 bytes | -9Q a 9Q | Enteros muy grandes |
| `float` | 4 bytes | ±3.4e38 | Decimales |
| `double` | 8 bytes | ±1.7e308 | Decimales precisos |
| `bool` | 1 byte | true/false | Lógica |

## Modificadores de Tipo

### signed (Con Signo)
- Permite valores negativos y positivos
- Es el predeterminado para int

### unsigned (Sin Signo)
- Solo valores positivos (0 y mayores)
- Duplica el rango positivo

```cpp
unsigned int edad = 25;      // Solo positivos
signed int temperatura = -5; // Positivos y negativos
```

## Conversión de Tipos (Casting)

### Conversión Implícita
```cpp
int x = 10;
double y = x;  // int -> double automático
```

### Conversión Explícita
```cpp
double pi = 3.14159;
int entero = (int)pi;           // C-style cast
int entero2 = static_cast<int>(pi); // C++ cast
```

## sizeof() - Tamaño de Tipos

```cpp
cout << "Tamaño de int: " << sizeof(int) << " bytes" << endl;
cout << "Tamaño de double: " << sizeof(double) << " bytes" << endl;
```

## Constantes

### const
```cpp
const double PI = 3.14159;
const int MAX_ESTUDIANTES = 30;
```

### constexpr (C++11)
```cpp
constexpr int TAMANO = 100;
```

## Auto (C++11)

Deduce automáticamente el tipo:
```cpp
auto x = 10;        // int
auto y = 3.14;      // double
auto nombre = "Juan"; // const char*
```

## Buenas Prácticas

1. **Usa el tipo más apropiado** para tus datos
2. **Usa `int` por defecto** para enteros
3. **Usa `double` por defecto** para decimales
4. **Usa `unsigned`** solo cuando sea necesario
5. **Usa `const`** para valores que no cambian
6. **Usa `auto`** cuando el tipo es obvio

## Límites de Tipos

```cpp
#include <limits>
cout << "Max int: " << numeric_limits<int>::max() << endl;
cout << "Min int: " << numeric_limits<int>::min() << endl;
```
