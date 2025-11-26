/*
 * ============================================================================
 * EJERCICIO 5: OPERACIONES AVANZADAS CON BITS (DIFÍCIL)
 * ============================================================================
 * 
 * OBJETIVO:
 * Implementar algoritmos avanzados usando operaciones bit a bit:
 * 1. Encontrar el único número que aparece una vez (todos los demás aparecen dos veces)
 * 2. Invertir bits de un número
 * 3. Verificar si un número es potencia de 2
 * 4. Encontrar el siguiente número con la misma cantidad de bits activados
 * 5. Multiplicación y división rápida usando desplazamientos
 * 6. Extraer y manipular rangos de bits
 * 
 * CONCEPTOS AVANZADOS:
 * - Propiedades del XOR para encontrar elementos únicos
 * - Manipulación de máscaras complejas
 * - Algoritmos de optimización con bits
 * - Operaciones aritméticas con desplazamientos
 * ============================================================================
 */

#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

// Función auxiliar para mostrar binario
void mostrarBinario(int numero, int bits = 16) {
    bitset<32> b(numero);
    string str = b.to_string();
    cout << str.substr(32 - bits) << " (decimal: " << numero << ")";
}

// ============================================================================
// PROBLEMA 1: Encontrar el número único en un arreglo
// ============================================================================
int encontrarNumeroUnico(vector<int> numeros) {
    cout << "\n╔════════════════════════════════════════════════╗" << endl;
    cout << "║  PROBLEMA 1: ENCONTRAR NÚMERO ÚNICO           ║" << endl;
    cout << "╚════════════════════════════════════════════════╝" << endl;
    
    cout << "\nArreglo: [";
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i];
        if (i < numeros.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    cout << "\nConcepto: a ^ a = 0, entonces todos los pares se cancelan" << endl;
    cout << "Proceso:" << endl;
    
    int resultado = 0;
    for (int i = 0; i < numeros.size(); i++) {
        cout << "  Paso " << (i + 1) << ": " << resultado << " ^ " << numeros[i] << " = ";
        resultado ^= numeros[i];
        cout << resultado << endl;
    }
    
    cout << "\n✓ Número único encontrado: " << resultado << endl;
    return resultado;
}

// ============================================================================
// PROBLEMA 2: Invertir bits de un número
// ============================================================================
unsigned int invertirBits(unsigned int numero) {
    cout << "\n╔════════════════════════════════════════════════╗" << endl;
    cout << "║  PROBLEMA 2: INVERTIR BITS                     ║" << endl;
    cout << "╚════════════════════════════════════════════════╝" << endl;
    
    cout << "\nNúmero original: " << numero << endl;
    cout << "Binario original: ";
    mostrarBinario(numero, 16);
    cout << endl;
    
    unsigned int resultado = 0;
    int bits = sizeof(numero) * 8;
    
    cout << "\nProceso de inversión:" << endl;
    for (int i = 0; i < bits; i++) {
        // Extraemos el bit menos significativo
        int bit = numero & 1;
        
        // Lo colocamos en la posición invertida
        resultado = (resultado << 1) | bit;
        
        // Desplazamos el número original
        numero >>= 1;
        
        if (i < 5 || i >= bits - 3) {  // Mostramos solo algunos pasos
            cout << "  Bit " << i << ": " << bit << " → ";
            mostrarBinario(resultado, 16);
            cout << endl;
        } else if (i == 5) {
            cout << "  ..." << endl;
        }
    }
    
    cout << "\nResultado invertido: ";
    mostrarBinario(resultado, 16);
    cout << endl;
    
    return resultado;
}

// ============================================================================
// PROBLEMA 3: Verificar si es potencia de 2
// ============================================================================
bool esPotenciaDe2(int numero) {
    cout << "\n╔════════════════════════════════════════════════╗" << endl;
    cout << "║  PROBLEMA 3: ¿ES POTENCIA DE 2?               ║" << endl;
    cout << "╚════════════════════════════════════════════════╝" << endl;
    
    cout << "\nNúmero: " << numero << endl;
    cout << "Binario: ";
    mostrarBinario(numero, 16);
    cout << endl;
    
    cout << "\nConcepto: Las potencias de 2 tienen exactamente 1 bit activado" << endl;
    cout << "Truco: n & (n-1) == 0 solo si n es potencia de 2" << endl;
    
    if (numero <= 0) {
        cout << "\n✗ No es potencia de 2 (número <= 0)" << endl;
        return false;
    }
    
    cout << "\nVerificación:" << endl;
    cout << "  n     = ";
    mostrarBinario(numero, 16);
    cout << endl;
    cout << "  n - 1 = ";
    mostrarBinario(numero - 1, 16);
    cout << endl;
    cout << "  n & (n-1) = ";
    mostrarBinario(numero & (numero - 1), 16);
    cout << endl;
    
    bool resultado = (numero & (numero - 1)) == 0;
    cout << "\n" << (resultado ? "✓" : "✗") << " " 
         << (resultado ? "SÍ" : "NO") << " es potencia de 2" << endl;
    
    return resultado;
}

// ============================================================================
// PROBLEMA 4: Siguiente número con la misma cantidad de bits activados
// ============================================================================
int siguienteConMismosBits(int numero) {
    cout << "\n╔════════════════════════════════════════════════╗" << endl;
    cout << "║  PROBLEMA 4: SIGUIENTE CON MISMOS BITS        ║" << endl;
    cout << "╚════════════════════════════════════════════════╝" << endl;
    
    cout << "\nNúmero original: " << numero << endl;
    cout << "Binario: ";
    mostrarBinario(numero, 16);
    cout << endl;
    
    // Contamos bits activados en el original
    int bitsOriginales = __builtin_popcount(numero);
    cout << "Bits activados: " << bitsOriginales << endl;
    
    // Algoritmo: encontrar el siguiente número mayor con la misma cantidad de bits
    int c = numero;
    int c0 = 0;  // Contador de 0s a la derecha
    int c1 = 0;  // Contador de 1s a la derecha
    
    // Contamos 0s a la derecha
    int temp = c;
    while (((temp & 1) == 0) && temp != 0) {
        c0++;
        temp >>= 1;
    }
    
    // Contamos 1s después de los 0s
    while ((temp & 1) == 1) {
        c1++;
        temp >>= 1;
    }
    
    // Posición del bit no final más a la derecha que es 0
    int pos = c0 + c1;
    
    // Activamos el bit en la posición pos
    c |= (1 << pos);
    
    // Limpiamos todos los bits a la derecha de pos
    c &= ~((1 << pos) - 1);
    
    // Insertamos (c1-1) unos a la derecha
    c |= (1 << (c1 - 1)) - 1;
    
    cout << "\nSiguiente número: " << c << endl;
    cout << "Binario: ";
    mostrarBinario(c, 16);
    cout << endl;
    cout << "Bits activados: " << __builtin_popcount(c) << endl;
    
    return c;
}

// ============================================================================
// PROBLEMA 5: Multiplicación y división rápida
// ============================================================================
void operacionesAritmeticasRapidas() {
    cout << "\n╔════════════════════════════════════════════════╗" << endl;
    cout << "║  PROBLEMA 5: ARITMÉTICA RÁPIDA CON BITS       ║" << endl;
    cout << "╚════════════════════════════════════════════════╝" << endl;
    
    int numero = 15;
    
    cout << "\nNúmero original: " << numero << endl;
    cout << "Binario: ";
    mostrarBinario(numero, 8);
    cout << endl;
    
    // Multiplicación por potencias de 2
    cout << "\n--- MULTIPLICACIÓN (desplazamiento izquierda) ---" << endl;
    for (int i = 1; i <= 3; i++) {
        int resultado = numero << i;
        cout << numero << " × 2^" << i << " = " << numero << " << " << i 
             << " = " << resultado << " | ";
        mostrarBinario(resultado, 8);
        cout << endl;
    }
    
    // División por potencias de 2
    cout << "\n--- DIVISIÓN (desplazamiento derecha) ---" << endl;
    numero = 120;
    cout << "\nNúmero original: " << numero << endl;
    for (int i = 1; i <= 3; i++) {
        int resultado = numero >> i;
        cout << numero << " ÷ 2^" << i << " = " << numero << " >> " << i 
             << " = " << resultado << " | ";
        mostrarBinario(resultado, 8);
        cout << endl;
    }
}

// ============================================================================
// PROBLEMA 6: Extraer y manipular rangos de bits
// ============================================================================
void manipularRangoBits() {
    cout << "\n╔════════════════════════════════════════════════╗" << endl;
    cout << "║  PROBLEMA 6: EXTRAER RANGO DE BITS            ║" << endl;
    cout << "╚════════════════════════════════════════════════╝" << endl;
    
    unsigned int numero = 0b11010110;  // 214 en decimal
    
    cout << "\nNúmero original: " << numero << endl;
    cout << "Binario: ";
    mostrarBinario(numero, 8);
    cout << endl;
    
    // Extraer bits del 2 al 5
    int inicio = 2;
    int fin = 5;
    int longitud = fin - inicio + 1;
    
    cout << "\nExtrayendo bits de la posición " << inicio << " a " << fin << ":" << endl;
    
    // Crear máscara
    unsigned int mascara = ((1 << longitud) - 1) << inicio;
    cout << "Máscara: ";
    mostrarBinario(mascara, 8);
    cout << endl;
    
    // Extraer bits
    unsigned int bitsExtraidos = (numero & mascara) >> inicio;
    cout << "Bits extraídos: ";
    mostrarBinario(bitsExtraidos, longitud);
    cout << endl;
    
    // Reemplazar bits en un rango
    cout << "\n--- Reemplazando bits ---" << endl;
    unsigned int nuevoValor = 0b1111;  // Valor a insertar
    
    cout << "Nuevo valor a insertar: ";
    mostrarBinario(nuevoValor, 4);
    cout << endl;
    
    // Limpiar el rango
    unsigned int numeroLimpio = numero & ~mascara;
    cout << "Después de limpiar rango: ";
    mostrarBinario(numeroLimpio, 8);
    cout << endl;
    
    // Insertar nuevo valor
    unsigned int resultado = numeroLimpio | (nuevoValor << inicio);
    cout << "Después de insertar: ";
    mostrarBinario(resultado, 8);
    cout << endl;
}

// ============================================================================
// MAIN
// ============================================================================
int main() {
    cout << "============================================" << endl;
    cout << "  EJERCICIO 5: OPERACIONES AVANZADAS       " << endl;
    cout << "============================================" << endl;
    
    // Problema 1: Número único
    vector<int> numeros = {4, 1, 2, 1, 2, 5, 4};
    encontrarNumeroUnico(numeros);
    
    // Problema 2: Invertir bits
    invertirBits(13);
    
    // Problema 3: Potencia de 2
    esPotenciaDe2(16);
    esPotenciaDe2(18);
    
    // Problema 4: Siguiente con mismos bits
    siguienteConMismosBits(6);  // 110 → 1001
    
    // Problema 5: Operaciones aritméticas rápidas
    operacionesAritmeticasRapidas();
    
    // Problema 6: Manipular rangos
    manipularRangoBits();
    
    // Menú interactivo
    cout << "\n\n╔════════════════════════════════════════════════╗" << endl;
    cout << "║  MODO INTERACTIVO                              ║" << endl;
    cout << "╚════════════════════════════════════════════════╝" << endl;
    
    int opcion;
    do {
        cout << "\n--- MENÚ DE PROBLEMAS ---" << endl;
        cout << "1. Encontrar número único en arreglo" << endl;
        cout << "2. Invertir bits de un número" << endl;
        cout << "3. Verificar si es potencia de 2" << endl;
        cout << "4. Siguiente número con mismos bits activados" << endl;
        cout << "5. Ver todas las potencias de 2 hasta 2^10" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                int n;
                cout << "¿Cuántos números tendrá el arreglo? ";
                cin >> n;
                vector<int> arr(n);
                cout << "Ingresa los números (todos deben aparecer 2 veces excepto uno):" << endl;
                for (int i = 0; i < n; i++) {
                    cout << "Número " << (i + 1) << ": ";
                    cin >> arr[i];
                }
                encontrarNumeroUnico(arr);
                break;
            }
            case 2: {
                unsigned int num;
                cout << "Ingresa un número: ";
                cin >> num;
                invertirBits(num);
                break;
            }
            case 3: {
                int num;
                cout << "Ingresa un número: ";
                cin >> num;
                esPotenciaDe2(num);
                break;
            }
            case 4: {
                int num;
                cout << "Ingresa un número: ";
                cin >> num;
                siguienteConMismosBits(num);
                break;
            }
            case 5: {
                cout << "\nPotencias de 2:" << endl;
                for (int i = 0; i <= 10; i++) {
                    int potencia = 1 << i;
                    cout << "2^" << i << " = " << potencia << " | ";
                    mostrarBinario(potencia, 16);
                    cout << endl;
                }
                break;
            }
        }
    } while (opcion != 0);
    
    cout << "\n¡Gracias por practicar operaciones avanzadas con bits!" << endl;
    
    return 0;
}
