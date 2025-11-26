/*
 * ============================================================================
 * EJERCICIO 3: CONTAR BITS ACTIVADOS (MEDIO)
 * ============================================================================
 * 
 * OBJETIVO:
 * Contar cuántos bits están en 1 (activados) en la representación binaria
 * de un número entero.
 * 
 * CONCEPTO:
 * Existen varios métodos para contar bits:
 * 
 * 1. Método simple: Verificar cada bit con desplazamiento
 * 2. Método Brian Kernighan: Eliminar el bit menos significativo en cada paso
 *    usando la operación: n = n & (n - 1)
 * 
 * APLICACIONES:
 * - Cálculo de la distancia de Hamming
 * - Verificación de paridad
 * - Optimización de algoritmos
 * - Compresión de datos
 * ============================================================================
 */

#include <iostream>
#include <bitset>
using namespace std;

// Función para mostrar la representación binaria
void mostrarBinario(int numero) {
    cout << "Binario: ";
    bitset<16> bits(numero);
    cout << bits << " (decimal: " << numero << ")" << endl;
}

// Método 1: Verificar cada bit con desplazamiento
int contarBitsMetodo1(int numero) {
    int contador = 0;
    int numeroOriginal = numero;
    
    cout << "\n--- Método 1: Verificación bit por bit ---" << endl;
    mostrarBinario(numero);
    
    // Recorremos cada bit (asumiendo 32 bits)
    for (int i = 0; i < 32; i++) {
        // Verificamos si el bit menos significativo es 1
        if (numero & 1) {
            contador++;
            cout << "Bit " << i << ": 1 ✓ (contador = " << contador << ")" << endl;
        }
        // Desplazamos a la derecha para verificar el siguiente bit
        numero >>= 1;
        
        // Si ya no quedan bits, terminamos
        if (numero == 0) break;
    }
    
    return contador;
}

// Método 2: Brian Kernighan (más eficiente)
int contarBitsMetodo2(int numero) {
    int contador = 0;
    int numeroOriginal = numero;
    
    cout << "\n--- Método 2: Brian Kernighan (optimizado) ---" << endl;
    mostrarBinario(numero);
    
    int paso = 1;
    while (numero != 0) {
        cout << "Paso " << paso << ": ";
        mostrarBinario(numero);
        
        // Esta operación elimina el bit 1 más a la derecha
        numero = numero & (numero - 1);
        contador++;
        
        cout << "  Después de n & (n-1): ";
        mostrarBinario(numero);
        
        paso++;
    }
    
    cout << "\n¡Solo se necesitaron " << (paso - 1) << " iteraciones!" << endl;
    
    return contador;
}

// Método 3: Usando tabla de búsqueda (muy rápido)
int contarBitsMetodo3(int numero) {
    // Tabla para contar bits en números de 0 a 255
    int tabla[256];
    tabla[0] = 0;
    for (int i = 1; i < 256; i++) {
        tabla[i] = tabla[i / 2] + (i & 1);
    }
    
    int contador = 0;
    
    // Procesamos el número en bloques de 8 bits
    contador += tabla[numero & 0xff];           // Primeros 8 bits
    contador += tabla[(numero >> 8) & 0xff];    // Siguientes 8 bits
    contador += tabla[(numero >> 16) & 0xff];   // Siguientes 8 bits
    contador += tabla[(numero >> 24) & 0xff];   // Últimos 8 bits
    
    return contador;
}

// Función para calcular la distancia de Hamming entre dos números
int distanciaHamming(int a, int b) {
    // La distancia de Hamming es el número de bits diferentes
    // Usamos XOR para encontrar los bits diferentes
    int diferencia = a ^ b;
    
    cout << "\nCalculando distancia de Hamming:" << endl;
    cout << "a = " << a << " -> ";
    mostrarBinario(a);
    cout << "b = " << b << " -> ";
    mostrarBinario(b);
    cout << "a ^ b = " << diferencia << " -> ";
    mostrarBinario(diferencia);
    
    // Contamos los bits en 1 en la diferencia
    int distancia = 0;
    while (diferencia) {
        diferencia &= (diferencia - 1);
        distancia++;
    }
    
    return distancia;
}

int main() {
    cout << "============================================" << endl;
    cout << "  EJERCICIO 3: CONTAR BITS ACTIVADOS      " << endl;
    cout << "============================================" << endl;
    
    // Ejemplo 1: Contar bits con método simple
    cout << "\n=== EJEMPLO 1: Método simple ===" << endl;
    int num1 = 29;  // 11101 en binario
    cout << "Número: " << num1 << endl;
    int resultado1 = contarBitsMetodo1(num1);
    cout << "\n✓ Total de bits en 1: " << resultado1 << endl;
    
    // Ejemplo 2: Método Brian Kernighan
    cout << "\n\n=== EJEMPLO 2: Método Brian Kernighan ===" << endl;
    int num2 = 255;  // 11111111 en binario
    cout << "Número: " << num2 << endl;
    int resultado2 = contarBitsMetodo2(num2);
    cout << "\n✓ Total de bits en 1: " << resultado2 << endl;
    
    // Ejemplo 3: Comparación de eficiencia
    cout << "\n\n=== EJEMPLO 3: Comparación de métodos ===" << endl;
    int num3 = 1024;  // 10000000000 en binario (solo 1 bit activado)
    cout << "Número: " << num3 << endl;
    mostrarBinario(num3);
    
    cout << "\nMétodo 1 (simple): " << contarBitsMetodo1(num3) << " bits" << endl;
    cout << "\nMétodo 2 (Kernighan): " << contarBitsMetodo2(num3) << " bits" << endl;
    cout << "Método 3 (tabla): " << contarBitsMetodo3(num3) << " bits" << endl;
    
    // Ejemplo 4: Distancia de Hamming
    cout << "\n\n=== EJEMPLO 4: Distancia de Hamming ===" << endl;
    int a = 15;  // 1111
    int b = 10;  // 1010
    int distancia = distanciaHamming(a, b);
    cout << "\n✓ Distancia de Hamming entre " << a << " y " << b << ": " << distancia << endl;
    cout << "(Hay " << distancia << " bits diferentes entre ambos números)" << endl;
    
    // Ejemplo 5: Números potencia de 2
    cout << "\n\n=== EJEMPLO 5: Potencias de 2 ===" << endl;
    cout << "Las potencias de 2 tienen exactamente 1 bit activado:" << endl;
    for (int i = 0; i <= 10; i++) {
        int potencia = 1 << i;  // 2^i
        cout << "2^" << i << " = " << potencia << " -> ";
        mostrarBinario(potencia);
        cout << "  Bits activados: " << contarBitsMetodo3(potencia) << endl;
    }
    
    // Ejemplo 6: Entrada del usuario
    cout << "\n\n=== EJEMPLO 6: Prueba con tu número ===" << endl;
    int numeroUsuario;
    cout << "Ingresa un número entero: ";
    cin >> numeroUsuario;
    
    cout << "\nAnálisis de " << numeroUsuario << ":" << endl;
    mostrarBinario(numeroUsuario);
    
    int bitsActivados = contarBitsMetodo3(numeroUsuario);
    cout << "\n✓ Bits activados (en 1): " << bitsActivados << endl;
    cout << "✓ Bits desactivados (en 0): " << (32 - bitsActivados) << endl;
    
    // Información adicional
    cout << "\n\n--- APLICACIONES PRÁCTICAS ---" << endl;
    cout << "• Verificación de paridad en comunicaciones" << endl;
    cout << "• Cálculo de similitud entre datos binarios" << endl;
    cout << "• Optimización de algoritmos de búsqueda" << endl;
    cout << "• Detección de errores en transmisión de datos" << endl;
    
    return 0;
}
