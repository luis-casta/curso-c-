/*
 * ============================================================================
 * EJERCICIO 1: VERIFICAR SI UN NÚMERO ES PAR O IMPAR (FÁCIL)
 * ============================================================================
 * 
 * OBJETIVO:
 * Usar operadores bit a bit para determinar si un número es par o impar.
 * 
 * CONCEPTO:
 * En binario, todos los números pares terminan en 0 y los impares en 1.
 * Por ejemplo:
 *   4 = 100 (par - último bit es 0)
 *   5 = 101 (impar - último bit es 1)
 * 
 * Podemos usar el operador AND (&) con 1 para verificar el último bit:
 *   numero & 1 == 0  -> número es par
 *   numero & 1 == 1  -> número es impar
 * 
 * VENTAJA:
 * Esta operación es más rápida que usar el operador módulo (%).
 * ============================================================================
 */

#include <iostream>
using namespace std;

// Función para verificar si un número es par usando operadores bit a bit
bool esPar(int numero) {
    // Si el último bit es 0, el número es par
    // Si el último bit es 1, el número es impar
    return (numero & 1) == 0;
}

// Función para mostrar la representación binaria de un número
void mostrarBinario(int numero, int bits = 8) {
    cout << "Binario: ";
    for (int i = bits - 1; i >= 0; i--) {
        // Verificamos cada bit usando desplazamiento y AND
        cout << ((numero >> i) & 1);
        if (i % 4 == 0 && i != 0) cout << " ";  // Separador cada 4 bits
    }
    cout << endl;
}

int main() {
    cout << "============================================" << endl;
    cout << "  EJERCICIO 1: PAR O IMPAR CON BITS       " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Verificar varios números
    cout << "\n--- Verificando números del 0 al 10 ---" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << "\nNúmero: " << i << endl;
        mostrarBinario(i);
        cout << "Último bit: " << (i & 1) << endl;
        cout << "Resultado: " << (esPar(i) ? "PAR" : "IMPAR") << endl;
    }
    
    // Ejemplo 2: Números grandes
    cout << "\n\n--- Números más grandes ---" << endl;
    int numeros[] = {100, 255, 1024, 999, 2048};
    
    for (int i = 0; i < 5; i++) {
        int num = numeros[i];
        cout << "\nNúmero: " << num << endl;
        cout << "Operación: " << num << " & 1 = " << (num & 1) << endl;
        cout << "Resultado: " << (esPar(num) ? "PAR" : "IMPAR") << endl;
    }
    
    // Ejemplo 3: Números negativos
    cout << "\n\n--- Números negativos ---" << endl;
    int negativos[] = {-1, -2, -5, -10};
    
    for (int i = 0; i < 4; i++) {
        int num = negativos[i];
        cout << "\nNúmero: " << num << endl;
        cout << "Último bit: " << (num & 1) << endl;
        cout << "Resultado: " << (esPar(num) ? "PAR" : "IMPAR") << endl;
    }
    
    // Ejemplo 4: Entrada del usuario
    cout << "\n\n--- Prueba con tu propio número ---" << endl;
    int numeroUsuario;
    cout << "Ingresa un número: ";
    cin >> numeroUsuario;
    
    cout << "\nAnálisis de " << numeroUsuario << ":" << endl;
    mostrarBinario(numeroUsuario, 16);
    cout << "Último bit: " << (numeroUsuario & 1) << endl;
    cout << "Resultado: " << (esPar(numeroUsuario) ? "PAR ✓" : "IMPAR ✓") << endl;
    
    // Comparación de rendimiento (conceptual)
    cout << "\n\n--- COMPARACIÓN DE MÉTODOS ---" << endl;
    cout << "Método tradicional: numero % 2 == 0" << endl;
    cout << "Método con bits:    numero & 1 == 0" << endl;
    cout << "\n¡El método con bits es más rápido porque es una operación" << endl;
    cout << "directa a nivel de hardware!" << endl;
    
    return 0;
}
