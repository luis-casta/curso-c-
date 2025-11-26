/*
 * EJERCICIO ESTRUCTURAS 1: INFORMACIÓN DE ESTUDIANTE (NIVEL FÁCIL)
 * 
 * Descripción:
 * Este programa crea una estructura para almacenar información de un estudiante
 * y muestra cómo acceder y modificar sus miembros.
 * 
 * Conceptos que aprenderás:
 * - Definición de estructuras
 * - Creación de variables de estructura
 * - Acceso a miembros con el operador punto
 * - Asignación de valores a miembros
 */

#include <iostream>
#include <string>
using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    string nombre_completo;
    int edad_anios;
    double promedio_calificaciones;
    string carrera_estudiada;
    int semestre_actual;
};

int main() {
    // Crear una variable de tipo Estudiante
    Estudiante alumno_principal;
    
    cout << "=== REGISTRO DE ESTUDIANTE ===" << endl;
    
    // Solicitar información al usuario
    cout << "\nIngrese el nombre completo: ";
    getline(cin, alumno_principal.nombre_completo);
    
    cout << "Ingrese la edad: ";
    cin >> alumno_principal.edad_anios;
    
    cout << "Ingrese el promedio: ";
    cin >> alumno_principal.promedio_calificaciones;
    
    cin.ignore(); // Limpiar el buffer
    cout << "Ingrese la carrera: ";
    getline(cin, alumno_principal.carrera_estudiada);
    
    cout << "Ingrese el semestre actual: ";
    cin >> alumno_principal.semestre_actual;
    
    // Mostrar la información almacenada
    cout << "\n--- INFORMACION DEL ESTUDIANTE ---" << endl;
    cout << "Nombre: " << alumno_principal.nombre_completo << endl;
    cout << "Edad: " << alumno_principal.edad_anios << " años" << endl;
    cout << "Promedio: " << alumno_principal.promedio_calificaciones << endl;
    cout << "Carrera: " << alumno_principal.carrera_estudiada << endl;
    cout << "Semestre: " << alumno_principal.semestre_actual << endl;
    
    // Determinar el estado académico
    cout << "\n--- ESTADO ACADEMICO ---" << endl;
    if(alumno_principal.promedio_calificaciones >= 9.0) {
        cout << "Estado: EXCELENTE" << endl;
    } else if(alumno_principal.promedio_calificaciones >= 8.0) {
        cout << "Estado: MUY BUENO" << endl;
    } else if(alumno_principal.promedio_calificaciones >= 7.0) {
        cout << "Estado: BUENO" << endl;
    } else if(alumno_principal.promedio_calificaciones >= 6.0) {
        cout << "Estado: APROBADO" << endl;
    } else {
        cout << "Estado: NECESITA MEJORAR" << endl;
    }
    
    return 0;
}

/*
 * EJEMPLO DE SALIDA:
 * 
 * === REGISTRO DE ESTUDIANTE ===
 * 
 * Ingrese el nombre completo: Juan Carlos Perez
 * Ingrese la edad: 20
 * Ingrese el promedio: 8.5
 * Ingrese la carrera: Ingenieria en Sistemas
 * Ingrese el semestre actual: 4
 * 
 * --- INFORMACION DEL ESTUDIANTE ---
 * Nombre: Juan Carlos Perez
 * Edad: 20 años
 * Promedio: 8.5
 * Carrera: Ingenieria en Sistemas
 * Semestre: 4
 * 
 * --- ESTADO ACADEMICO ---
 * Estado: MUY BUENO
 * 
 * EXPLICACIÓN:
 * - Definimos una estructura con 5 miembros de diferentes tipos
 * - Creamos una variable de tipo Estudiante
 * - Usamos el operador punto (.) para acceder a cada miembro
 * - Asignamos valores ingresados por el usuario
 * - Leemos los valores para mostrarlos y hacer cálculos
 */
