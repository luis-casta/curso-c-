# Teoría de Manejo de Excepciones en C++

## ¿Qué son las Excepciones?

Las **excepciones** son un mecanismo para manejar errores y situaciones excepcionales en tiempo de ejecución. Permiten separar el código de manejo de errores del código normal del programa.

## Sintaxis Básica

```cpp
try {
    // Código que puede lanzar una excepción
} catch (tipo_excepcion& e) {
    // Código para manejar la excepción
}
```

## Palabras Clave

| Palabra | Uso |
|---------|-----|
| `try` | Bloque donde puede ocurrir una excepción |
| `catch` | Bloque que maneja la excepción |
| `throw` | Lanza una excepción |

## Ejemplo Básico

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int edad = -5;
        
        if (edad < 0) {
            throw "La edad no puede ser negativa";
        }
        
        cout << "Edad: " << edad << endl;
        
    } catch (const char* mensaje) {
        cout << "Error: " << mensaje << endl;
    }
    
    return 0;
}
```

## Tipos de Excepciones

### 1. Excepciones de Tipos Primitivos

```cpp
try {
    throw 42;           // int
    throw 3.14;         // double
    throw 'A';          // char
    throw "Error";      // const char*
} catch (int e) {
    cout << "Error numero: " << e << endl;
} catch (double e) {
    cout << "Error decimal: " << e << endl;
} catch (const char* e) {
    cout << "Error: " << e << endl;
}
```

### 2. Excepciones Estándar

C++ proporciona excepciones predefinidas en `<stdexcept>`:

```cpp
#include <stdexcept>

try {
    throw runtime_error("Error en tiempo de ejecucion");
} catch (runtime_error& e) {
    cout << "Error: " << e.what() << endl;
}
```

**Excepciones estándar comunes:**

| Excepción | Uso |
|-----------|-----|
| `runtime_error` | Errores en tiempo de ejecución |
| `logic_error` | Errores lógicos |
| `invalid_argument` | Argumento inválido |
| `out_of_range` | Fuera de rango |
| `overflow_error` | Desbordamiento |
| `underflow_error` | Subdesbordamiento |

### 3. Excepciones Personalizadas

```cpp
class MiExcepcion : public exception {
private:
    string mensaje;
    
public:
    MiExcepcion(string msg) : mensaje(msg) {}
    
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Uso
try {
    throw MiExcepcion("Error personalizado");
} catch (MiExcepcion& e) {
    cout << "Error: " << e.what() << endl;
}
```

## Múltiples Bloques Catch

```cpp
try {
    // Código que puede lanzar diferentes excepciones
    
} catch (invalid_argument& e) {
    cout << "Argumento invalido: " << e.what() << endl;
    
} catch (out_of_range& e) {
    cout << "Fuera de rango: " << e.what() << endl;
    
} catch (exception& e) {
    // Captura cualquier excepción estándar
    cout << "Error general: " << e.what() << endl;
    
} catch (...) {
    // Captura CUALQUIER excepción
    cout << "Error desconocido" << endl;
}
```

## Relanzar Excepciones

```cpp
try {
    try {
        throw runtime_error("Error interno");
    } catch (runtime_error& e) {
        cout << "Manejando internamente..." << endl;
        throw; // Relanza la misma excepción
    }
} catch (runtime_error& e) {
    cout << "Manejado externamente: " << e.what() << endl;
}
```

## Especificación de Excepciones (C++11)

### noexcept

Indica que una función no lanza excepciones:

```cpp
void funcion_segura() noexcept {
    // Esta función no lanza excepciones
}

void otra_funcion() noexcept(false) {
    // Esta función puede lanzar excepciones
}
```

## Ejemplo Completo: División Segura

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

double dividir(double numerador, double denominador) {
    if (denominador == 0) {
        throw invalid_argument("Division por cero no permitida");
    }
    return numerador / denominador;
}

int main() {
    double a, b;
    
    cout << "Ingrese numerador: ";
    cin >> a;
    cout << "Ingrese denominador: ";
    cin >> b;
    
    try {
        double resultado = dividir(a, b);
        cout << "Resultado: " << resultado << endl;
        
    } catch (invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        cout << "Por favor, use un denominador diferente de cero" << endl;
    }
    
    return 0;
}
```

## Ejemplo: Validación de Edad

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

class EdadInvalidaException : public exception {
private:
    string mensaje;
    
public:
    EdadInvalidaException(int edad) {
        mensaje = "Edad invalida: " + to_string(edad);
    }
    
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

void validar_edad(int edad) {
    if (edad < 0) {
        throw EdadInvalidaException(edad);
    }
    if (edad > 150) {
        throw out_of_range("Edad fuera de rango razonable");
    }
}

int main() {
    int edad;
    cout << "Ingrese edad: ";
    cin >> edad;
    
    try {
        validar_edad(edad);
        cout << "Edad valida: " << edad << endl;
        
    } catch (EdadInvalidaException& e) {
        cout << "Error: " << e.what() << endl;
        
    } catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
```

## Ventajas de las Excepciones

✅ **Separación de código**: Error handling separado de lógica  
✅ **Propagación automática**: Las excepciones suben por la pila  
✅ **Código más limpio**: Sin necesidad de verificar cada operación  
✅ **Manejo centralizado**: Un solo lugar para manejar errores  
✅ **Información detallada**: Mensajes descriptivos de error  

## Desventajas

❌ **Overhead**: Pequeño costo en rendimiento  
❌ **Complejidad**: Puede hacer el flujo menos obvio  
❌ **Recursos**: Puede complicar la gestión de recursos  

## Cuándo Usar Excepciones

✅ Errores excepcionales (no esperados frecuentemente)  
✅ Errores que no se pueden manejar localmente  
✅ Constructores (no pueden retornar códigos de error)  
✅ Operadores sobrecargados  
✅ Validación de entrada  

## Cuándo NO Usar Excepciones

❌ Control de flujo normal  
❌ Situaciones esperadas frecuentemente  
❌ Código crítico en rendimiento  
❌ Validaciones simples  

## Buenas Prácticas

1. **Captura por referencia** para evitar copias
   ```cpp
   catch (exception& e) { }  // ✅ Correcto
   catch (exception e) { }   // ❌ Hace copia
   ```

2. **Usa excepciones estándar** cuando sea posible
   ```cpp
   throw invalid_argument("mensaje");  // ✅ Mejor
   throw "mensaje";                    // ❌ Menos informativo
   ```

3. **Captura de más específico a más general**
   ```cpp
   catch (invalid_argument& e) { }  // Primero
   catch (exception& e) { }         // Después
   catch (...) { }                  // Al final
   ```

4. **Documenta qué excepciones lanza** una función

5. **Libera recursos** en caso de excepción (usa RAII)

## RAII (Resource Acquisition Is Initialization)

```cpp
class Archivo {
private:
    FILE* archivo;
    
public:
    Archivo(const char* nombre) {
        archivo = fopen(nombre, "r");
        if (!archivo) {
            throw runtime_error("No se pudo abrir el archivo");
        }
    }
    
    ~Archivo() {
        if (archivo) {
            fclose(archivo);  // Se cierra automáticamente
        }
    }
};

// Uso
try {
    Archivo f("datos.txt");
    // Usar archivo
} catch (runtime_error& e) {
    cout << "Error: " << e.what() << endl;
}
// El archivo se cierra automáticamente, incluso si hay excepción
```

## Resumen

Las excepciones son una herramienta poderosa para manejar errores de forma elegante y robusta. Permiten separar la lógica del programa del manejo de errores, haciendo el código más limpio y mantenible.
