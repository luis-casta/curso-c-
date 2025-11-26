/*
 * EJERCICIO WHILE 2: JUEGO DE ADIVINANZA (NIVEL FÁCIL-MEDIO)
 * 
 * Descripción:
 * Este programa implementa un juego donde el usuario debe adivinar un
 * número secreto. El programa da pistas si el número es mayor o menor
 * y cuenta los intentos realizados.
 * 
 * Conceptos que aprenderás:
 * - Ciclo while con condición de parada
 * - Contador de intentos
 * - Condicionales dentro de ciclos
 * - Lógica de juego simple
 * - Generación de números aleatorios (opcional)
 */

#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
using namespace std;

int main() {
    // Inicializar generador de números aleatorios
    srand(static_cast<unsigned int>(time(0)));
    
    // Generar número secreto entre 1 y 100
    const int NUMERO_MINIMO = 1;
    const int NUMERO_MAXIMO = 100;
    int numero_secreto = rand() % NUMERO_MAXIMO + NUMERO_MINIMO;
    
    // Variables del juego
    int numero_intento;           // Número que ingresa el usuario
    int cantidad_intentos = 0;    // Contador de intentos
    bool numero_adivinado = false; // Bandera para saber si adivinó
    
    // Mostrar instrucciones
    cout << "=== JUEGO DE ADIVINANZA ===" << endl;
    cout << "He pensado un numero entre " << NUMERO_MINIMO 
         << " y " << NUMERO_MAXIMO << endl;
    cout << "¡Intenta adivinarlo!" << endl << endl;
    
    // Ciclo principal del juego
    // Continúa mientras NO haya adivinado el número
    while(!numero_adivinado) {
        // Incrementar contador de intentos
        cantidad_intentos++;
        
        // Solicitar intento al usuario
        cout << "Intento #" << cantidad_intentos << " - Ingrese un numero: ";
        cin >> numero_intento;
        
        // Verificar si el número está en el rango válido
        if(numero_intento < NUMERO_MINIMO || numero_intento > NUMERO_MAXIMO) {
            cout << "¡Atencion! El numero debe estar entre " << NUMERO_MINIMO 
                 << " y " << NUMERO_MAXIMO << endl;
            cantidad_intentos--; // No contar este intento inválido
            continue; // Saltar a la siguiente iteración
        }
        
        // Comparar con el número secreto
        if(numero_intento == numero_secreto) {
            // ¡Adivinó!
            numero_adivinado = true;
            cout << "\n¡¡¡FELICITACIONES!!!" << endl;
            cout << "¡Adivinaste el numero!" << endl;
        }
        else if(numero_intento < numero_secreto) {
            // El número es muy bajo
            cout << "Muy bajo. El numero secreto es MAYOR." << endl;
            
            // Dar pista adicional si está muy lejos
            int diferencia = numero_secreto - numero_intento;
            if(diferencia > 30) {
                cout << "Pista: Estas MUY lejos..." << endl;
            } else if(diferencia > 10) {
                cout << "Pista: Estas algo lejos." << endl;
            } else {
                cout << "Pista: ¡Estas CERCA!" << endl;
            }
        }
        else {
            // El número es muy alto
            cout << "Muy alto. El numero secreto es MENOR." << endl;
            
            // Dar pista adicional si está muy lejos
            int diferencia = numero_intento - numero_secreto;
            if(diferencia > 30) {
                cout << "Pista: Estas MUY lejos..." << endl;
            } else if(diferencia > 10) {
                cout << "Pista: Estas algo lejos." << endl;
            } else {
                cout << "Pista: ¡Estas CERCA!" << endl;
            }
        }
        
        cout << endl;
    }
    
    // Mostrar estadísticas del juego
    cout << "--- ESTADISTICAS ---" << endl;
    cout << "Numero secreto: " << numero_secreto << endl;
    cout << "Intentos realizados: " << cantidad_intentos << endl;
    
    // Evaluar el desempeño
    if(cantidad_intentos == 1) {
        cout << "¡INCREIBLE! ¡Lo adivinaste al primer intento!" << endl;
    } else if(cantidad_intentos <= 5) {
        cout << "¡EXCELENTE! Muy pocos intentos." << endl;
    } else if(cantidad_intentos <= 10) {
        cout << "¡MUY BIEN! Buen desempeño." << endl;
    } else if(cantidad_intentos <= 15) {
        cout << "BIEN. Puedes mejorar." << endl;
    } else {
        cout << "Necesitaste muchos intentos. ¡Practica mas!" << endl;
    }
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === JUEGO DE ADIVINANZA ===
 * He pensado un numero entre 1 y 100
 * ¡Intenta adivinarlo!
 * 
 * Intento #1 - Ingrese un numero: 50
 * Muy bajo. El numero secreto es MAYOR.
 * Pista: Estas algo lejos.
 * 
 * Intento #2 - Ingrese un numero: 75
 * Muy alto. El numero secreto es MENOR.
 * Pista: Estas algo lejos.
 * 
 * Intento #3 - Ingrese un numero: 65
 * Muy bajo. El numero secreto es MAYOR.
 * Pista: ¡Estas CERCA!
 * 
 * Intento #4 - Ingrese un numero: 70
 * Muy bajo. El numero secreto es MAYOR.
 * Pista: ¡Estas CERCA!
 * 
 * Intento #5 - Ingrese un numero: 72
 * 
 * ¡¡¡FELICITACIONES!!!
 * ¡Adivinaste el numero!
 * 
 * --- ESTADISTICAS ---
 * Numero secreto: 72
 * Intentos realizados: 5
 * ¡EXCELENTE! Muy pocos intentos.
 * 
 * EXPLICACIÓN:
 * - El ciclo while continúa mientras numero_adivinado sea false
 * - En cada iteración:
 *   1. Se incrementa el contador de intentos
 *   2. Se solicita un número al usuario
 *   3. Se compara con el número secreto
 *   4. Se dan pistas (mayor/menor y distancia)
 * - El ciclo termina cuando el usuario adivina el número
 * 
 * NÚMEROS ALEATORIOS:
 * - srand(time(0)): Inicializa el generador con la hora actual
 * - rand() % 100 + 1: Genera número entre 1 y 100
 * 
 * ESTRATEGIA ÓPTIMA:
 * - Usar búsqueda binaria: comenzar en 50
 * - Si es mayor, probar 75; si es menor, probar 25
 * - Continuar dividiendo el rango a la mitad
 * - Garantiza encontrar el número en máximo 7 intentos
 */
