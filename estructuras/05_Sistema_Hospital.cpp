/*
 * EJERCICIO ESTRUCTURAS 5: SISTEMA COMPLETO - HOSPITAL (NIVEL DIFÍCIL)
 * 
 * Descripción:
 * Sistema hospitalario completo con múltiples estructuras, funciones y operaciones.
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Paciente {
    int numero_expediente;
    string nombre_completo;
    int edad_anios;
    string tipo_sangre;
    Fecha fecha_ingreso;
    string diagnostico;
    bool esta_internado;
};

struct Doctor {
    int numero_cedula;
    string nombre_completo;
    string especialidad;
    int anios_experiencia;
    vector<int> pacientes_asignados; // IDs de pacientes
};

struct Cita {
    int id_cita;
    int id_paciente;
    int id_doctor;
    Fecha fecha_cita;
    string hora;
    string motivo;
    bool esta_confirmada;
};

// Variables globales para el sistema
vector<Paciente> lista_pacientes;
vector<Doctor> lista_doctores;
vector<Cita> lista_citas;
int siguiente_expediente = 1000;
int siguiente_cita = 1;

void registrar_paciente() {
    Paciente nuevo;
    nuevo.numero_expediente = siguiente_expediente++;
    
    cin.ignore();
    cout << "\n--- REGISTRO DE PACIENTE ---" << endl;
    cout << "Numero de expediente asignado: " << nuevo.numero_expediente << endl;
    cout << "Nombre completo: ";
    getline(cin, nuevo.nombre_completo);
    cout << "Edad: ";
    cin >> nuevo.edad_anios;
    cin.ignore();
    cout << "Tipo de sangre: ";
    getline(cin, nuevo.tipo_sangre);
    cout << "Diagnostico: ";
    getline(cin, nuevo.diagnostico);
    
    cout << "Fecha de ingreso (dia mes año): ";
    cin >> nuevo.fecha_ingreso.dia >> nuevo.fecha_ingreso.mes >> nuevo.fecha_ingreso.anio;
    
    char respuesta;
    cout << "¿Esta internado? (s/n): ";
    cin >> respuesta;
    nuevo.esta_internado = (respuesta == 's' || respuesta == 'S');
    
    lista_pacientes.push_back(nuevo);
    cout << "\n¡Paciente registrado exitosamente!" << endl;
}

void registrar_doctor() {
    Doctor nuevo;
    
    cin.ignore();
    cout << "\n--- REGISTRO DE DOCTOR ---" << endl;
    cout << "Numero de cedula: ";
    cin >> nuevo.numero_cedula;
    cin.ignore();
    cout << "Nombre completo: ";
    getline(cin, nuevo.nombre_completo);
    cout << "Especialidad: ";
    getline(cin, nuevo.especialidad);
    cout << "Años de experiencia: ";
    cin >> nuevo.anios_experiencia;
    
    lista_doctores.push_back(nuevo);
    cout << "\n¡Doctor registrado exitosamente!" << endl;
}

void agendar_cita() {
    if(lista_pacientes.empty() || lista_doctores.empty()) {
        cout << "\nDebe haber al menos un paciente y un doctor registrados." << endl;
        return;
    }
    
    Cita nueva;
    nueva.id_cita = siguiente_cita++;
    
    cout << "\n--- AGENDAR CITA ---" << endl;
    cout << "ID de cita asignado: " << nueva.id_cita << endl;
    
    // Mostrar pacientes
    cout << "\nPacientes disponibles:" << endl;
    for(size_t i = 0; i < lista_pacientes.size(); i++) {
        cout << i + 1 << ". " << lista_pacientes[i].nombre_completo 
             << " (Exp: " << lista_pacientes[i].numero_expediente << ")" << endl;
    }
    
    int seleccion;
    cout << "Seleccione paciente: ";
    cin >> seleccion;
    nueva.id_paciente = lista_pacientes[seleccion - 1].numero_expediente;
    
    // Mostrar doctores
    cout << "\nDoctores disponibles:" << endl;
    for(size_t i = 0; i < lista_doctores.size(); i++) {
        cout << i + 1 << ". Dr. " << lista_doctores[i].nombre_completo 
             << " (" << lista_doctores[i].especialidad << ")" << endl;
    }
    
    cout << "Seleccione doctor: ";
    cin >> seleccion;
    nueva.id_doctor = lista_doctores[seleccion - 1].numero_cedula;
    
    cout << "\nFecha de la cita (dia mes año): ";
    cin >> nueva.fecha_cita.dia >> nueva.fecha_cita.mes >> nueva.fecha_cita.anio;
    
    cin.ignore();
    cout << "Hora (HH:MM): ";
    getline(cin, nueva.hora);
    cout << "Motivo de la cita: ";
    getline(cin, nueva.motivo);
    
    nueva.esta_confirmada = false;
    
    lista_citas.push_back(nueva);
    cout << "\n¡Cita agendada exitosamente!" << endl;
}

void mostrar_estadisticas() {
    cout << "\n=== ESTADISTICAS DEL HOSPITAL ===" << endl;
    cout << "Total de pacientes: " << lista_pacientes.size() << endl;
    cout << "Total de doctores: " << lista_doctores.size() << endl;
    cout << "Total de citas: " << lista_citas.size() << endl;
    
    int pacientes_internados = 0;
    int suma_edades = 0;
    
    for(const auto& pac : lista_pacientes) {
        if(pac.esta_internado) pacientes_internados++;
        suma_edades += pac.edad_anios;
    }
    
    cout << "\nPacientes internados: " << pacientes_internados << endl;
    if(!lista_pacientes.empty()) {
        double edad_promedio = (double)suma_edades / lista_pacientes.size();
        cout << "Edad promedio de pacientes: " << fixed << setprecision(1) 
             << edad_promedio << " años" << endl;
    }
    
    int citas_confirmadas = 0;
    for(const auto& cita : lista_citas) {
        if(cita.esta_confirmada) citas_confirmadas++;
    }
    cout << "Citas confirmadas: " << citas_confirmadas << endl;
}

int main() {
    int opcion;
    
    cout << "=== SISTEMA HOSPITALARIO ===" << endl;
    
    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Registrar paciente" << endl;
        cout << "2. Registrar doctor" << endl;
        cout << "3. Agendar cita" << endl;
        cout << "4. Ver estadisticas" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                registrar_paciente();
                break;
            case 2:
                registrar_doctor();
                break;
            case 3:
                agendar_cita();
                break;
            case 4:
                mostrar_estadisticas();
                break;
            case 0:
                cout << "\n¡Sistema cerrado!" << endl;
                break;
            default:
                cout << "\nOpcion invalida." << endl;
        }
    } while(opcion != 0);
    
    return 0;
}

/*
 * EXPLICACIÓN:
 * - Sistema completo con múltiples estructuras relacionadas
 * - Usa vectores para almacenar datos dinámicamente
 * - Demuestra relaciones entre estructuras (paciente-doctor-cita)
 * - Incluye validaciones y estadísticas
 * - Ejemplo de aplicación real de estructuras
 */
