/*
 * ============================================================================
 * EJERCICIO 2: INTERCAMBIAR DOS NÚMEROS SIN VARIABLE TEMPORAL (FÁCIL-MEDIO)
 * ============================================================================
 * 
 * OBJETIVO:
 * Intercambiar los valores de dos variables sin usar una variable temporal,
 * utilizando el operador XOR (^).
 * 
 * CONCEPTO:
 * El operador XOR tiene una propiedad especial:
 *   A ^ A = 0  (cualquier número XOR consigo mismo es 0)
 *   A ^ 0 = A  (cualquier número XOR con 0 es el mismo número)
 *   A ^ B ^ B = A  (XOR es reversible)
 * 
 * ALGORITMO:
 *   a = a ^ b  // a ahora contiene a^b
 *   b = a ^ b  // b = (a^b) ^ b = a ^ (b^b) = a ^ 0 = a
 *   a = a ^ b  // a = (a^b) ^ a = (a^a) ^ b = 0 ^ b = b
 * 
 * VENTAJA:
 * No requiere memoria adicional para una variable temporal.
 * ============================================================================
 */

#include <iostream>
using namespace std;

// Función para mostrar la representación binaria
void mostrarBinario(int numero, string etiqueta = "") {
    if (etiqueta != "") {
        cout << etiqueta << ": ";
    }
    
    cout << numero << " = ";
    
    // Mostramos los 8 bits más significativos
    for (int i = 7; i >= 0; i--) {
        cout << ((numero >> i) & 1);
        if (i == 4) cout << " ";
    }
    cout << endl;
}

// Método tradicional con variable temporal
void intercambiarTradicional(int &a, int &b) {
    cout << "\n--- Método Tradicional (con variable temporal) ---" << endl;
    cout << "Antes: a = " << a << ", b = " << b << endl;
    
    int temp = a;
    a = b;
    b = temp;
    
    cout << "Después: a = " << a << ", b = " << b << endl;
}

// Método con XOR (sin variable temporal)
void intercambiarConXOR(int &a, int &b) {
    cout << "\n--- Método con XOR (sin variable temporal) ---" << endl;
    cout << "Valores iniciales:" << endl;
    mostrarBinario(a, "a");
    mostrarBinario(b, "b");
    
    cout << "\nPaso 1: a = a ^ b" << endl;
    a = a ^ b;
    mostrarBinario(a, "a");
    cout << "(a ahora contiene la combinación XOR de ambos)" << endl;
    
    cout << "\nPaso 2: b = a ^ b" << endl;
    cout << "b = (" << a << ") ^ (" << b << ")" << endl;
    b = a ^ b;
    mostrarBinario(b, "b");
    cout << "(b ahora tiene el valor original de a)" << endl;
    
    cout << "\nPaso 3: a = a ^ b" << endl;
    cout << "a = (" << a << ") ^ (" << b << ")" << endl;
    a = a ^ b;
    mostrarBinario(a, "a");
    cout << "(a ahora tiene el valor original de b)" << endl;
    
    cout << "\n✓ Intercambio completado!" << endl;
}

// Versión simplificada para uso práctico
void swap_XOR(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    cout << "============================================" << endl;
    cout << "  EJERCICIO 2: INTERCAMBIO CON XOR        " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Intercambio detallado
    cout << "\n=== EJEMPLO 1: Intercambio detallado ===" << endl;
    int x = 5, y = 9;
    cout << "Valores originales: x = " << x << ", y = " << y << endl;
    intercambiarConXOR(x, y);
    cout << "\nValores finales: x = " << x << ", y = " << y << endl;
    
    // Ejemplo 2: Comparación con método tradicional
    cout << "\n\n=== EJEMPLO 2: Comparación de métodos ===" << endl;
    int a1 = 15, b1 = 20;
    int a2 = 15, b2 = 20;
    
    intercambiarTradicional(a1, b1);
    
    cout << "\n";
    swap_XOR(a2, b2);
    cout << "Resultado con XOR: a = " << a2 << ", b = " << b2 << endl;
    
    // Ejemplo 3: Números más grandes
    cout << "\n\n=== EJEMPLO 3: Números grandes ===" << endl;
    int num1 = 100, num2 = 200;
    cout << "Antes: num1 = " << num1 << ", num2 = " << num2 << endl;
    swap_XOR(num1, num2);
    cout << "Después: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    // Ejemplo 4: Números negativos
    cout << "\n\n=== EJEMPLO 4: Números negativos ===" << endl;
    int neg1 = -5, neg2 = 10;
    cout << "Antes: neg1 = " << neg1 << ", neg2 = " << neg2 << endl;
    swap_XOR(neg1, neg2);
    cout << "Después: neg1 = " << neg1 << ", neg2 = " << neg2 << endl;
    
    // Ejemplo 5: Entrada del usuario
    cout << "\n\n=== EJEMPLO 5: Prueba con tus números ===" << endl;
    int usuario1, usuario2;
    cout << "Ingresa el primer número: ";
    cin >> usuario1;
    cout << "Ingresa el segundo número: ";
    cin >> usuario2;
    
    cout << "\nAntes del intercambio:" << endl;
    cout << "Número 1: " << usuario1 << endl;
    cout << "Número 2: " << usuario2 << endl;
    
    swap_XOR(usuario1, usuario2);
    
    cout << "\nDespués del intercambio:" << endl;
    cout << "Número 1: " << usuario1 << " ✓" << endl;
    cout << "Número 2: " << usuario2 << " ✓" << endl;
    
    // Explicación adicional
    cout << "\n\n--- NOTA IMPORTANTE ---" << endl;
    cout << "Este método funciona porque XOR tiene estas propiedades:" << endl;
    cout << "  • A ^ A = 0" << endl;
    cout << "  • A ^ 0 = A" << endl;
    cout << "  • A ^ B ^ B = A (es reversible)" << endl;
    cout << "\n¡No se necesita memoria adicional para una variable temporal!" << endl;
    
    return 0;
}
