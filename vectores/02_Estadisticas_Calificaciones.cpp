/*
 * EJERCICIO VECTORES 2: ESTADÍSTICAS DE CALIFICACIONES (NIVEL FÁCIL-MEDIO)
 * 
 * Descripción:
 * Programa que calcula estadísticas de calificaciones usando vectores.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    vector<double> calificaciones;
    int cantidad_estudiantes;
    
    cout << "=== ESTADISTICAS DE CALIFICACIONES ===" << endl;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidad_estudiantes;
    
    // Ingresar calificaciones
    for(int i = 0; i < cantidad_estudiantes; i++) {
        double calificacion;
        cout << "Calificacion del estudiante " << (i + 1) << ": ";
        cin >> calificacion;
        calificaciones.push_back(calificacion);
    }
    
    // Calcular promedio
    double suma = 0;
    for(double cal : calificaciones) {
        suma += cal;
    }
    double promedio = suma / calificaciones.size();
    
    // Encontrar máximo y mínimo
    double maximo = *max_element(calificaciones.begin(), calificaciones.end());
    double minimo = *min_element(calificaciones.begin(), calificaciones.end());
    
    // Contar aprobados y reprobados
    int aprobados = 0;
    int reprobados = 0;
    for(double cal : calificaciones) {
        if(cal >= 60) {
            aprobados++;
        } else {
            reprobados++;
        }
    }
    
    // Mostrar resultados
    cout << fixed << setprecision(2);
    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Calificacion maxima: " << maximo << endl;
    cout << "Calificacion minima: " << minimo << endl;
    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;
    
    return 0;
}
