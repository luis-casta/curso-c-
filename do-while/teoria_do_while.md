# Teoría de Do-While en C++

## ¿Qué es Do-While?

`do-while` es un bucle que **ejecuta el código al menos una vez** y luego verifica la condición. A diferencia de `while`, que verifica la condición antes de ejecutar, `do-while` verifica **después** de ejecutar.

## Sintaxis

```cpp
do {
    // Código a ejecutar
} while (condicion);
```

**Nota**: El punto y coma `;` después del `while` es obligatorio.

## Diferencia con While

### While (verifica primero)
```cpp
int x = 10;
while (x < 5) {
    cout << "Esto nunca se ejecuta" << endl;
}
// No imprime nada
```

### Do-While (ejecuta primero)
```cpp
int x = 10;
do {
    cout << "Esto se ejecuta una vez" << endl;
} while (x < 5);
// Imprime una vez, aunque la condición sea falsa
```

## Cuándo Usar Do-While

✅ **Menús interactivos** - mostrar al menos una vez  
✅ **Validación de entrada** - pedir dato al menos una vez  
✅ **Juegos** - ejecutar al menos una ronda  
✅ **Confirmaciones** - preguntar al menos una vez  

## Ejemplo: Validación de Entrada

```cpp
int numero;

do {
    cout << "Ingrese un numero entre 1 y 10: ";
    cin >> numero;
    
    if (numero < 1 || numero > 10) {
        cout << "Numero invalido. Intente nuevamente." << endl;
    }
} while (numero < 1 || numero > 10);

cout << "Numero valido: " << numero << endl;
```

## Ejemplo: Menú

```cpp
int opcion;

do {
    cout << "\n=== MENU ===" << endl;
    cout << "1. Opcion 1" << endl;
    cout << "2. Opcion 2" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione: ";
    cin >> opcion;
    
    switch (opcion) {
        case 1:
            cout << "Ejecutando opcion 1" << endl;
            break;
        case 2:
            cout << "Ejecutando opcion 2" << endl;
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
    }
} while (opcion != 0);
```

## Do-While vs While vs For

| Característica | do-while | while | for |
|----------------|----------|-------|-----|
| Ejecución mínima | 1 vez | 0 veces | 0 veces |
| Verifica condición | Al final | Al inicio | Al inicio |
| Uso típico | Menús, validación | Condición desconocida | Contador conocido |

## Buenas Prácticas

1. **Usa para menús** que deben mostrarse al menos una vez
2. **Usa para validación** de entrada del usuario
3. **Asegura que la condición eventualmente sea falsa**
4. **No olvides el punto y coma** después del while

## Resumen

Do-while garantiza al menos una ejecución del código, perfecto para menús y validaciones donde necesitas ejecutar el bloque antes de verificar la condición.
