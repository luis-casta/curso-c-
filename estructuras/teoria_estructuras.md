# Teoría de Estructuras (struct) en C++

## ¿Qué es una Estructura?

Una **estructura** (`struct`) es un tipo de dato definido por el usuario que permite agrupar variables de diferentes tipos bajo un mismo nombre. Es ideal para representar entidades del mundo real que tienen múltiples atributos.

## Sintaxis Básica

```cpp
struct NombreEstructura {
    tipo1 miembro1;
    tipo2 miembro2;
    tipo3 miembro3;
    // ... más miembros
};
```

## Declaración de una Estructura

```cpp
struct Estudiante {
    string nombre;
    int edad;
    double promedio;
    string carrera;
};
```

## Crear Variables de una Estructura

```cpp
// Método 1: Declaración simple
Estudiante alumno1;

// Método 2: Inicialización con valores
Estudiante alumno2 = {"Juan Perez", 20, 8.5, "Ingenieria"};

// Método 3: Inicialización por miembros (C++11)
Estudiante alumno3 = {
    .nombre = "Maria Lopez",
    .edad = 22,
    .promedio = 9.2,
    .carrera = "Medicina"
};
```

## Acceso a Miembros

Se usa el operador punto (`.`) para acceder a los miembros:

```cpp
Estudiante alumno;

// Asignar valores
alumno.nombre = "Carlos Ruiz";
alumno.edad = 21;
alumno.promedio = 8.7;
alumno.carrera = "Derecho";

// Leer valores
cout << "Nombre: " << alumno.nombre << endl;
cout << "Edad: " << alumno.edad << endl;
cout << "Promedio: " << alumno.promedio << endl;
```

## Estructuras Anidadas

Una estructura puede contener otras estructuras:

```cpp
struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    string nombre;
    int edad;
    Fecha fecha_nacimiento;  // Estructura anidada
};

// Uso
Persona persona1;
persona1.nombre = "Ana";
persona1.edad = 25;
persona1.fecha_nacimiento.dia = 15;
persona1.fecha_nacimiento.mes = 3;
persona1.fecha_nacimiento.anio = 1998;
```

## Arrays de Estructuras

```cpp
struct Producto {
    string nombre;
    double precio;
    int stock;
};

// Array de 5 productos
Producto inventario[5];

// Asignar valores
inventario[0].nombre = "Laptop";
inventario[0].precio = 15000.00;
inventario[0].stock = 10;

// Recorrer el array
for(int i = 0; i < 5; i++) {
    cout << inventario[i].nombre << endl;
}
```

## Vectores de Estructuras

```cpp
#include <vector>

vector<Estudiante> lista_estudiantes;

// Agregar estudiantes
Estudiante nuevo = {"Pedro", 19, 8.0, "Fisica"};
lista_estudiantes.push_back(nuevo);

// Recorrer
for(const auto& est : lista_estudiantes) {
    cout << est.nombre << endl;
}
```

## Paso de Estructuras a Funciones

### Por Valor (copia)

```cpp
void mostrar_estudiante(Estudiante est) {
    cout << "Nombre: " << est.nombre << endl;
    cout << "Edad: " << est.edad << endl;
}
```

### Por Referencia (sin copia)

```cpp
void modificar_promedio(Estudiante& est, double nuevo_promedio) {
    est.promedio = nuevo_promedio;
}
```

### Por Referencia Constante (lectura sin copia)

```cpp
void mostrar_estudiante(const Estudiante& est) {
    cout << "Nombre: " << est.nombre << endl;
    // No se puede modificar est
}
```

## Retornar Estructuras desde Funciones

```cpp
Estudiante crear_estudiante(string nombre, int edad) {
    Estudiante nuevo;
    nuevo.nombre = nombre;
    nuevo.edad = edad;
    nuevo.promedio = 0.0;
    nuevo.carrera = "Sin definir";
    return nuevo;
}

// Uso
Estudiante alumno = crear_estudiante("Luis", 20);
```

## Comparación de Estructuras

Las estructuras NO se pueden comparar directamente con `==`:

```cpp
// ❌ Incorrecto
if(alumno1 == alumno2) { }

// ✅ Correcto: comparar miembro por miembro
if(alumno1.nombre == alumno2.nombre && 
   alumno1.edad == alumno2.edad) {
    // Son iguales
}
```

## Estructuras con Funciones Miembro (C++)

En C++, las estructuras pueden tener funciones:

```cpp
struct Rectangulo {
    double ancho;
    double alto;
    
    // Función miembro
    double calcular_area() {
        return ancho * alto;
    }
    
    double calcular_perimetro() {
        return 2 * (ancho + alto);
    }
};

// Uso
Rectangulo rect;
rect.ancho = 5.0;
rect.alto = 3.0;
cout << "Area: " << rect.calcular_area() << endl;
```

## typedef con Estructuras

```cpp
// Sin typedef
struct Punto {
    int x;
    int y;
};
Punto p1;  // Necesitas escribir "struct" en C

// Con typedef
typedef struct {
    int x;
    int y;
} Punto;

Punto p1;  // Más limpio
```

## Ventajas de las Estructuras

✅ **Organización**: Agrupa datos relacionados  
✅ **Legibilidad**: Código más claro y mantenible  
✅ **Reutilización**: Define una vez, usa muchas veces  
✅ **Modelado**: Representa entidades del mundo real  
✅ **Flexibilidad**: Puede contener cualquier tipo de dato  

## Struct vs Class

En C++, `struct` y `class` son casi idénticos:

| Característica | struct | class |
|----------------|--------|-------|
| Miembros públicos por defecto | Sí | No |
| Puede tener funciones | Sí | Sí |
| Puede tener constructores | Sí | Sí |
| Herencia | Sí | Sí |
| Uso típico | Datos simples | POO completa |

## Ejemplo Completo

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio;
    double precio;
};

void mostrar_libro(const Libro& libro) {
    cout << "Titulo: " << libro.titulo << endl;
    cout << "Autor: " << libro.autor << endl;
    cout << "Año: " << libro.anio << endl;
    cout << "Precio: $" << libro.precio << endl;
}

int main() {
    // Crear libro
    Libro libro1 = {
        "El Quijote",
        "Miguel de Cervantes",
        1605,
        299.99
    };
    
    // Mostrar
    mostrar_libro(libro1);
    
    // Vector de libros
    vector<Libro> biblioteca;
    biblioteca.push_back(libro1);
    
    return 0;
}
```

## Buenas Prácticas

1. **Usa nombres descriptivos** para la estructura y sus miembros
2. **Pasa por referencia constante** cuando solo lees
3. **Pasa por referencia** cuando modificas
4. **Inicializa siempre** los miembros
5. **Agrupa datos relacionados** lógicamente
6. **Usa struct para datos simples**, class para POO completa

## Casos de Uso Comunes

- 📊 Representar registros de bases de datos
- 🎮 Coordenadas en juegos (x, y, z)
- 📅 Fechas y tiempos
- 👤 Información de personas
- 📦 Productos en inventarios
- 📈 Datos estadísticos
- 🗺️ Puntos geográficos

## Resumen

Las estructuras son fundamentales en C++ para organizar datos relacionados. Son perfectas para representar entidades del mundo real y hacen tu código más legible y mantenible.
