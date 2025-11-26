/*
 * EJERCICIO FOR 5: SERIE DE FIBONACCI (NIVEL DIFÍCIL)
 * 
 * Descripción:
 * Este programa genera la serie de Fibonacci hasta un número N de términos
 * y calcula estadísticas sobre la serie. La serie de Fibonacci es una
 * secuencia donde cada número es la suma de los dos anteriores:
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 * 
 * Conceptos que aprenderás:
 * - Serie de Fibonacci
 * - Manejo de secuencias numéricas
 * - Actualización de múltiples variables
 * - Razón áurea (número phi)
 * - Arreglos dinámicos
 * - Análisis de patrones matemáticos
 */

#include <iostream>
#include <iomanip> // Para setprecision
using namespace std;

int main() {
    // Número de términos a generar
    int cantidad_terminos;
    
    // Solicitar cantidad de términos
    cout << "=== SERIE DE FIBONACCI ===" << endl;
    cout << "Ingrese la cantidad de terminos a generar: ";
    cin >> cantidad_terminos;
    
    // Validar entrada
    if(cantidad_terminos < 1) {
        cout << "Error: Debe generar al menos 1 termino" << endl;
        return 1;
    }
    
    // Variables para almacenar los términos de Fibonacci
    long long termino_anterior = 0;      // F(n-2)
    long long termino_actual = 1;        // F(n-1)
    long long termino_siguiente;         // F(n)
    
    // Variables para estadísticas
    long long suma_total = 0;
    long long termino_maximo = 0;
    
    cout << "\n--- SERIE DE FIBONACCI ---" << endl;
    
    // Generar y mostrar la serie
    for(int indice_termino = 1; indice_termino <= cantidad_terminos; indice_termino++) {
        long long termino_a_mostrar;
        
        // Casos especiales para los primeros dos términos
        if(indice_termino == 1) {
            termino_a_mostrar = 0;
        }
        else if(indice_termino == 2) {
            termino_a_mostrar = 1;
        }
        else {
            // Calcular el siguiente término de Fibonacci
            // F(n) = F(n-1) + F(n-2)
            termino_siguiente = termino_anterior + termino_actual;
            termino_a_mostrar = termino_siguiente;
            
            // Actualizar los términos para la siguiente iteración
            // Lo que era actual ahora es anterior
            // Lo que era siguiente ahora es actual
            termino_anterior = termino_actual;
            termino_actual = termino_siguiente;
        }
        
        // Mostrar el término con formato
        cout << "F(" << indice_termino << ") = " << termino_a_mostrar;
        
        // Acumular para estadísticas
        suma_total += termino_a_mostrar;
        if(termino_a_mostrar > termino_maximo) {
            termino_maximo = termino_a_mostrar;
        }
        
        // Salto de línea cada 5 términos para mejor visualización
        if(indice_termino % 5 == 0) {
            cout << endl;
        } else {
            cout << "\t";
        }
    }
    
    cout << endl;
    
    // Mostrar estadísticas
    cout << "\n--- ESTADISTICAS ---" << endl;
    cout << "Cantidad de terminos: " << cantidad_terminos << endl;
    cout << "Suma total: " << suma_total << endl;
    cout << "Termino maximo: " << termino_maximo << endl;
    
    // Calcular promedio
    double promedio = static_cast<double>(suma_total) / cantidad_terminos;
    cout << "Promedio: " << fixed << setprecision(2) << promedio << endl;
    
    // Calcular la razón áurea (phi) usando los últimos dos términos
    if(cantidad_terminos >= 2) {
        cout << "\n--- RAZON AUREA (PHI) ---" << endl;
        cout << "La razon entre terminos consecutivos de Fibonacci" << endl;
        cout << "tiende al numero phi (≈ 1.618033988749895)" << endl << endl;
        
        // Reiniciar variables para recalcular
        termino_anterior = 0;
        termino_actual = 1;
        
        // Mostrar las razones para los últimos términos
        int terminos_a_mostrar = min(10, cantidad_terminos - 1);
        cout << "Ultimas " << terminos_a_mostrar << " razones:" << endl;
        
        // Generar la serie nuevamente para calcular razones
        for(int i = 1; i <= cantidad_terminos; i++) {
            if(i > 2) {
                termino_siguiente = termino_anterior + termino_actual;
                
                // Calcular la razón solo para los últimos términos
                if(i > cantidad_terminos - terminos_a_mostrar) {
                    double razon = static_cast<double>(termino_siguiente) / termino_actual;
                    cout << "F(" << i << ") / F(" << (i-1) << ") = " 
                         << termino_siguiente << " / " << termino_actual 
                         << " = " << fixed << setprecision(15) << razon << endl;
                }
                
                termino_anterior = termino_actual;
                termino_actual = termino_siguiente;
            }
        }
        
        cout << "\nNota: A medida que aumentan los terminos," << endl;
        cout << "la razon se aproxima mas al numero phi." << endl;
    }
    
    // Mostrar propiedades interesantes
    cout << "\n--- PROPIEDADES INTERESANTES ---" << endl;
    cout << "1. Cada numero es la suma de los dos anteriores" << endl;
    cout << "2. La razon entre terminos consecutivos tiende a phi" << endl;
    cout << "3. Aparece en la naturaleza (espirales, flores, etc.)" << endl;
    cout << "4. Suma de los primeros n terminos = F(n+2) - 1" << endl;
    
    // Verificar la propiedad de la suma
    termino_anterior = 0;
    termino_actual = 1;
    for(int i = 3; i <= cantidad_terminos + 2; i++) {
        termino_siguiente = termino_anterior + termino_actual;
        termino_anterior = termino_actual;
        termino_actual = termino_siguiente;
    }
    long long suma_esperada = termino_actual - 1;
    cout << "\nVerificacion: F(" << (cantidad_terminos + 2) << ") - 1 = " 
         << suma_esperada << endl;
    cout << "Suma calculada: " << suma_total << endl;
    if(suma_total == suma_esperada) {
        cout << "¡La propiedad se cumple! ✓" << endl;
    }
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === SERIE DE FIBONACCI ===
 * Ingrese la cantidad de terminos a generar: 15
 * 
 * --- SERIE DE FIBONACCI ---
 * F(1) = 0    F(2) = 1    F(3) = 1    F(4) = 2    F(5) = 3
 * F(6) = 5    F(7) = 8    F(8) = 13   F(9) = 21   F(10) = 34
 * F(11) = 55  F(12) = 89  F(13) = 144 F(14) = 233 F(15) = 377
 * 
 * --- ESTADISTICAS ---
 * Cantidad de terminos: 15
 * Suma total: 986
 * Termino maximo: 377
 * Promedio: 65.73
 * 
 * --- RAZON AUREA (PHI) ---
 * La razon entre terminos consecutivos de Fibonacci
 * tiende al numero phi (≈ 1.618033988749895)
 * 
 * Ultimas 10 razones:
 * F(6) / F(5) = 5 / 3 = 1.666666666666667
 * F(7) / F(6) = 8 / 5 = 1.600000000000000
 * F(8) / F(7) = 13 / 8 = 1.625000000000000
 * F(9) / F(8) = 21 / 13 = 1.615384615384615
 * F(10) / F(9) = 34 / 21 = 1.619047619047619
 * F(11) / F(10) = 55 / 34 = 1.617647058823529
 * F(12) / F(11) = 89 / 55 = 1.618181818181818
 * F(13) / F(12) = 144 / 89 = 1.617977528089888
 * F(14) / F(13) = 233 / 144 = 1.618055555555556
 * F(15) / F(14) = 377 / 233 = 1.618025751072961
 * 
 * Nota: A medida que aumentan los terminos,
 * la razon se aproxima mas al numero phi.
 * 
 * --- PROPIEDADES INTERESANTES ---
 * 1. Cada numero es la suma de los dos anteriores
 * 2. La razon entre terminos consecutivos tiende a phi
 * 3. Aparece en la naturaleza (espirales, flores, etc.)
 * 4. Suma de los primeros n terminos = F(n+2) - 1
 * 
 * Verificacion: F(17) - 1 = 986
 * Suma calculada: 986
 * ¡La propiedad se cumple! ✓
 * 
 * EXPLICACIÓN:
 * - F(1) = 0, F(2) = 1 (valores iniciales)
 * - F(n) = F(n-1) + F(n-2) para n > 2
 * - En cada iteración actualizamos:
 *   anterior = actual
 *   actual = siguiente
 * - La razón áurea (phi) ≈ 1.618033988749895
 * - Es uno de los números más importantes en matemáticas
 * 
 * APLICACIONES:
 * - Naturaleza: espirales de caracoles, girasoles, piñas
 * - Arte: proporciones en arquitectura y pintura
 * - Matemáticas: teoría de números, análisis de algoritmos
 * - Informática: estructuras de datos (árboles de Fibonacci)
 */
