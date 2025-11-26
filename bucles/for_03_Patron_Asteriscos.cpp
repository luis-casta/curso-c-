/*
 * EJERCICIO FOR 3: PATRÓN DE ASTERISCOS (NIVEL MEDIO)
 * 
 * Descripción:
 * Este programa genera un patrón triangular de asteriscos usando
 * ciclos for anidados. El usuario ingresa la altura del triángulo.
 * 
 * Conceptos que aprenderás:
 * - Ciclos for anidados
 * - Generación de patrones
 * - Relación entre filas y columnas
 * - Control de espacios y caracteres
 */

#include <iostream>
using namespace std;

int main() {
    // Variable para la altura del triángulo
    int altura_triangulo;
    
    // Solicitar la altura al usuario
    cout << "=== PATRON DE ASTERISCOS ===" << endl;
    cout << "Ingrese la altura del triangulo: ";
    cin >> altura_triangulo;
    
    // Validar entrada
    if(altura_triangulo < 1) {
        cout << "Error: La altura debe ser mayor a 0" << endl;
        return 1;
    }
    
    cout << "\n--- TRIANGULO RECTANGULO ---" << endl;
    
    // Primer patrón: Triángulo rectángulo
    // Cada fila tiene tantos asteriscos como su número de fila
    for(int numero_fila = 1; numero_fila <= altura_triangulo; numero_fila++) {
        // Ciclo interno: imprime asteriscos
        // En la fila 1: 1 asterisco
        // En la fila 2: 2 asteriscos
        // En la fila n: n asteriscos
        for(int numero_asterisco = 1; numero_asterisco <= numero_fila; numero_asterisco++) {
            cout << "* ";
        }
        // Nueva línea después de cada fila
        cout << endl;
    }
    
    cout << "\n--- TRIANGULO INVERTIDO ---" << endl;
    
    // Segundo patrón: Triángulo invertido
    // La primera fila tiene más asteriscos, la última tiene 1
    for(int numero_fila = altura_triangulo; numero_fila >= 1; numero_fila--) {
        // Imprimir asteriscos (tantos como indica numero_fila)
        for(int numero_asterisco = 1; numero_asterisco <= numero_fila; numero_asterisco++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    cout << "\n--- PIRAMIDE CENTRADA ---" << endl;
    
    // Tercer patrón: Pirámide centrada
    for(int numero_fila = 1; numero_fila <= altura_triangulo; numero_fila++) {
        // Imprimir espacios para centrar
        // En la fila 1: (altura-1) espacios
        // En la fila 2: (altura-2) espacios
        int cantidad_espacios = altura_triangulo - numero_fila;
        for(int espacio = 1; espacio <= cantidad_espacios; espacio++) {
            cout << "  "; // Dos espacios para mejor visualización
        }
        
        // Imprimir asteriscos
        // En la fila 1: 1 asterisco
        // En la fila 2: 3 asteriscos (2*2-1)
        // En la fila n: 2*n-1 asteriscos
        int cantidad_asteriscos = 2 * numero_fila - 1;
        for(int asterisco = 1; asterisco <= cantidad_asteriscos; asterisco++) {
            cout << "* ";
        }
        
        cout << endl;
    }
    
    cout << "\n--- ROMBO ---" << endl;
    
    // Cuarto patrón: Rombo (pirámide + pirámide invertida)
    
    // Parte superior del rombo (pirámide)
    for(int numero_fila = 1; numero_fila <= altura_triangulo; numero_fila++) {
        // Espacios
        for(int espacio = 1; espacio <= altura_triangulo - numero_fila; espacio++) {
            cout << "  ";
        }
        // Asteriscos
        for(int asterisco = 1; asterisco <= 2 * numero_fila - 1; asterisco++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    // Parte inferior del rombo (pirámide invertida)
    for(int numero_fila = altura_triangulo - 1; numero_fila >= 1; numero_fila--) {
        // Espacios
        for(int espacio = 1; espacio <= altura_triangulo - numero_fila; espacio++) {
            cout << "  ";
        }
        // Asteriscos
        for(int asterisco = 1; asterisco <= 2 * numero_fila - 1; asterisco++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA (con altura = 5):
 * 
 * === PATRON DE ASTERISCOS ===
 * Ingrese la altura del triangulo: 5
 * 
 * --- TRIANGULO RECTANGULO ---
 * * 
 * * * 
 * * * * 
 * * * * * 
 * * * * * * 
 * 
 * --- TRIANGULO INVERTIDO ---
 * * * * * * 
 * * * * * 
 * * * * 
 * * * 
 * * 
 * 
 * --- PIRAMIDE CENTRADA ---
 *         * 
 *       * * * 
 *     * * * * * 
 *   * * * * * * * 
 * * * * * * * * * 
 * 
 * --- ROMBO ---
 *         * 
 *       * * * 
 *     * * * * * 
 *   * * * * * * * 
 * * * * * * * * * 
 *   * * * * * * * 
 *     * * * * * 
 *       * * * 
 *         * 
 * 
 * EXPLICACIÓN:
 * Los ciclos anidados permiten controlar:
 * - Ciclo externo: controla las filas
 * - Ciclo interno 1: controla los espacios
 * - Ciclo interno 2: controla los asteriscos
 * 
 * Para la pirámide:
 * - Fila 1: 4 espacios, 1 asterisco
 * - Fila 2: 3 espacios, 3 asteriscos
 * - Fila 3: 2 espacios, 5 asteriscos
 * - Fila n: (altura-n) espacios, (2*n-1) asteriscos
 */
