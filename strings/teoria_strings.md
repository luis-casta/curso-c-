# Teoría de Strings en C++

## ¿Qué es un String?

Un **string** es una secuencia de caracteres que representa texto. En C++, usamos la clase `std::string` de la biblioteca estándar.

## Incluir la Biblioteca

```cpp
#include <string>
using namespace std;
```

## Declaración e Inicialización

```cpp
string nombre;                          // String vacío
string saludo = "Hola";                // Inicialización directa
string mensaje("Bienvenido");          // Constructor
string copia = saludo;                 // Copia de otro string
```

## Operaciones Básicas

### Concatenación (+)
```cpp
string nombre = "Juan";
string apellido = "Perez";
string completo = nombre + " " + apellido;  // "Juan Perez"
```

### Longitud
```cpp
string texto = "Hola Mundo";
int longitud = texto.length();    // 10
int tamaño = texto.size();        // 10 (igual que length)
```

### Acceso a Caracteres
```cpp
string palabra = "Hola";
char primera = palabra[0];        // 'H'
char ultima = palabra[palabra.length() - 1];  // 'a'
```

### Comparación
```cpp
string a = "abc";
string b = "abc";
string c = "xyz";

if (a == b) {  // true
    cout << "Iguales" << endl;
}

if (a < c) {  // true (orden alfabético)
    cout << "a viene antes que c" << endl;
}
```

## Métodos Importantes

### append() - Agregar al final
```cpp
string texto = "Hola";
texto.append(" Mundo");  // "Hola Mundo"
```

### substr() - Extraer subcadena
```cpp
string frase = "Hola Mundo";
string sub = frase.substr(0, 4);  // "Hola" (desde pos 0, 4 caracteres)
```

### find() - Buscar
```cpp
string texto = "Hola Mundo";
size_t pos = texto.find("Mundo");  // 5
if (pos != string::npos) {
    cout << "Encontrado en posicion " << pos << endl;
}
```

### replace() - Reemplazar
```cpp
string texto = "Hola Mundo";
texto.replace(5, 5, "C++");  // "Hola C++" (desde pos 5, 5 caracteres)
```

### insert() - Insertar
```cpp
string texto = "Hola";
texto.insert(4, " Mundo");  // "Hola Mundo"
```

### erase() - Eliminar
```cpp
string texto = "Hola Mundo";
texto.erase(4, 6);  // "Hola" (desde pos 4, 6 caracteres)
```

### clear() - Vaciar
```cpp
string texto = "Hola";
texto.clear();  // ""
```

### empty() - Verificar si está vacío
```cpp
string texto = "";
if (texto.empty()) {
    cout << "String vacio" << endl;
}
```

## Conversiones

### String a Número
```cpp
string numero_str = "12345";
int numero = stoi(numero_str);        // String to int
double decimal = stod("3.14159");     // String to double
long largo = stol("9876543210");      // String to long
```

### Número a String
```cpp
int numero = 42;
string texto = to_string(numero);     // "42"

double pi = 3.14159;
string pi_str = to_string(pi);        // "3.141590"
```

## Entrada y Salida

### cin (una palabra)
```cpp
string palabra;
cin >> palabra;  // Lee hasta el primer espacio
```

### getline (línea completa)
```cpp
string linea;
getline(cin, linea);  // Lee toda la línea incluyendo espacios
```

## Iteración sobre Strings

### Con índice
```cpp
string texto = "Hola";
for (int i = 0; i < texto.length(); i++) {
    cout << texto[i] << endl;
}
```

### Con rango (C++11)
```cpp
string texto = "Hola";
for (char c : texto) {
    cout << c << endl;
}
```

## Tabla de Métodos Comunes

| Método | Descripción | Ejemplo |
|--------|-------------|---------|
| `length()` | Longitud del string | `s.length()` |
| `empty()` | Verifica si está vacío | `s.empty()` |
| `clear()` | Vacía el string | `s.clear()` |
| `append(str)` | Agrega al final | `s.append("texto")` |
| `substr(pos, len)` | Extrae subcadena | `s.substr(0, 5)` |
| `find(str)` | Busca subcadena | `s.find("hola")` |
| `replace(pos, len, str)` | Reemplaza | `s.replace(0, 4, "nuevo")` |
| `insert(pos, str)` | Inserta | `s.insert(5, "texto")` |
| `erase(pos, len)` | Elimina | `s.erase(0, 3)` |
| `c_str()` | Convierte a C-string | `s.c_str()` |

## Ejemplo Completo

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    
    string saludo = "Hola, " + nombre + "!";
    cout << saludo << endl;
    
    cout << "Longitud: " << saludo.length() << endl;
    
    if (saludo.find(nombre) != string::npos) {
        cout << "El nombre esta en el saludo" << endl;
    }
    
    return 0;
}
```

## Buenas Prácticas

1. **Usa `getline()`** para leer texto con espacios
2. **Verifica `find()` con `npos`** antes de usar el resultado
3. **Usa `empty()`** en lugar de `length() == 0`
4. **Prefiere `+=`** sobre `append()` para concatenar
5. **Usa referencias** al pasar strings a funciones

## Resumen

Los strings en C++ son poderosos y fáciles de usar. La clase `std::string` proporciona muchos métodos útiles para manipular texto de forma eficiente y segura.
