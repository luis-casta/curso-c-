# Teoría de Manejo de Archivos en C++

## ¿Qué es el Manejo de Archivos?

El manejo de archivos permite a los programas **leer** y **escribir** datos en archivos del sistema, lo que permite **persistir información** más allá de la ejecución del programa.

## Bibliotecas Necesarias

```cpp
#include <fstream>   // Para archivos (ifstream, ofstream, fstream)
#include <iostream>  // Para entrada/salida estándar
#include <string>    // Para strings
```

## Tipos de Streams de Archivo

| Clase | Uso | Descripción |
|-------|-----|-------------|
| `ifstream` | Lectura | Input File Stream - solo lectura |
| `ofstream` | Escritura | Output File Stream - solo escritura |
| `fstream` | Lectura/Escritura | File Stream - ambas operaciones |

## Escritura en Archivos

### Sintaxis Básica

```cpp
#include <fstream>
using namespace std;

int main() {
    // Crear objeto ofstream
    ofstream archivo_salida;
    
    // Abrir archivo (se crea si no existe)
    archivo_salida.open("datos.txt");
    
    // Verificar si se abrió correctamente
    if (archivo_salida.is_open()) {
        // Escribir en el archivo
        archivo_salida << "Hola Mundo" << endl;
        archivo_salida << "Segunda linea" << endl;
        
        // Cerrar archivo
        archivo_salida.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
    
    return 0;
}
```

### Forma Alternativa (Constructor)

```cpp
ofstream archivo("datos.txt");

if (archivo.is_open()) {
    archivo << "Contenido" << endl;
    archivo.close();
}
```

## Lectura de Archivos

### Leer Línea por Línea

```cpp
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream archivo_entrada("datos.txt");
    string linea;
    
    if (archivo_entrada.is_open()) {
        while (getline(archivo_entrada, linea)) {
            cout << linea << endl;
        }
        archivo_entrada.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
    
    return 0;
}
```

### Leer Palabra por Palabra

```cpp
ifstream archivo("datos.txt");
string palabra;

while (archivo >> palabra) {
    cout << palabra << endl;
}
archivo.close();
```

### Leer Carácter por Carácter

```cpp
ifstream archivo("datos.txt");
char caracter;

while (archivo.get(caracter)) {
    cout << caracter;
}
archivo.close();
```

## Modos de Apertura

```cpp
// ios::out - Escritura (predeterminado para ofstream)
ofstream archivo("datos.txt", ios::out);

// ios::app - Append (agregar al final)
ofstream archivo("datos.txt", ios::app);

// ios::in - Lectura (predeterminado para ifstream)
ifstream archivo("datos.txt", ios::in);

// ios::binary - Modo binario
ofstream archivo("datos.bin", ios::binary);

// ios::trunc - Truncar (borrar contenido existente)
ofstream archivo("datos.txt", ios::trunc);

// Combinar modos con |
fstream archivo("datos.txt", ios::in | ios::out | ios::app);
```

## Verificar Estado del Archivo

```cpp
ifstream archivo("datos.txt");

// Verificar si se abrió
if (archivo.is_open()) {
    cout << "Archivo abierto" << endl;
}

// Verificar si llegó al final
if (archivo.eof()) {
    cout << "Fin del archivo" << endl;
}

// Verificar si hay error
if (archivo.fail()) {
    cout << "Error en la operacion" << endl;
}

// Verificar si está bien
if (archivo.good()) {
    cout << "Todo bien" << endl;
}
```

## Posicionamiento en Archivos

### Obtener Posición

```cpp
ifstream archivo("datos.txt");

// Posición actual de lectura
int pos = archivo.tellg();

ofstream salida("datos.txt");

// Posición actual de escritura
int pos = salida.tellp();
```

### Mover Posición

```cpp
ifstream archivo("datos.txt");

// Ir al inicio
archivo.seekg(0, ios::beg);

// Ir al final
archivo.seekg(0, ios::end);

// Mover 10 bytes desde la posición actual
archivo.seekg(10, ios::cur);

// Ir a una posición específica
archivo.seekg(50);
```

## Archivos Binarios

### Escribir Datos Binarios

```cpp
struct Persona {
    char nombre[50];
    int edad;
    double salario;
};

int main() {
    ofstream archivo("datos.bin", ios::binary);
    
    Persona p = {"Juan Perez", 30, 50000.0};
    
    archivo.write(reinterpret_cast<char*>(&p), sizeof(Persona));
    archivo.close();
    
    return 0;
}
```

### Leer Datos Binarios

```cpp
ifstream archivo("datos.bin", ios::binary);

Persona p;
archivo.read(reinterpret_cast<char*>(&p), sizeof(Persona));

cout << "Nombre: " << p.nombre << endl;
cout << "Edad: " << p.edad << endl;

archivo.close();
```

## Ejemplo Completo: Sistema de Notas

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void guardar_nota(string nombre, double calificacion) {
    ofstream archivo("notas.txt", ios::app);
    
    if (archivo.is_open()) {
        archivo << nombre << "," << calificacion << endl;
        archivo.close();
        cout << "Nota guardada exitosamente" << endl;
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
}

void mostrar_notas() {
    ifstream archivo("notas.txt");
    string linea;
    
    if (archivo.is_open()) {
        cout << "\n=== NOTAS REGISTRADAS ===" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No hay notas registradas" << endl;
    }
}

int main() {
    int opcion;
    
    do {
        cout << "\n1. Agregar nota" << endl;
        cout << "2. Ver notas" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                string nombre;
                double calificacion;
                
                cin.ignore();
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Calificacion: ";
                cin >> calificacion;
                
                guardar_nota(nombre, calificacion);
                break;
            }
            case 2:
                mostrar_notas();
                break;
        }
    } while(opcion != 0);
    
    return 0;
}
```

## Buenas Prácticas

1. **Siempre verifica** si el archivo se abrió correctamente
2. **Cierra los archivos** después de usarlos
3. **Usa rutas relativas** cuando sea posible
4. **Maneja errores** apropiadamente
5. **Usa `ios::app`** para no sobrescribir datos
6. **Verifica `eof()`** al leer archivos

## Errores Comunes

❌ No verificar si el archivo se abrió  
❌ No cerrar el archivo  
❌ Usar rutas absolutas innecesariamente  
❌ No manejar el fin de archivo  
❌ Sobrescribir datos sin querer  

## Formatos de Archivo Comunes

### CSV (Comma-Separated Values)

```cpp
// Escribir CSV
ofstream csv("datos.csv");
csv << "Nombre,Edad,Ciudad" << endl;
csv << "Juan,25,Madrid" << endl;
csv << "Maria,30,Barcelona" << endl;
csv.close();

// Leer CSV
ifstream csv("datos.csv");
string linea;
while (getline(csv, linea)) {
    // Procesar línea (separar por comas)
}
```

### Archivos de Configuración

```cpp
// config.txt
// nombre=Juan
// edad=25

ifstream config("config.txt");
string linea;

while (getline(config, linea)) {
    size_t pos = linea.find('=');
    string clave = linea.substr(0, pos);
    string valor = linea.substr(pos + 1);
    
    cout << clave << ": " << valor << endl;
}
```

## Resumen

El manejo de archivos es esencial para:
- 💾 **Persistir datos** entre ejecuciones
- 📊 **Procesar grandes cantidades** de información
- 📁 **Compartir datos** entre programas
- 🔄 **Hacer backups** de información
- 📝 **Generar reportes** y logs

Los archivos permiten que tus programas sean más útiles y prácticos al poder guardar y recuperar información.
