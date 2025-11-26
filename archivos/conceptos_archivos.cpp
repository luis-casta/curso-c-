/*
 * CONCEPTOS BÁSICOS DE MANEJO DE ARCHIVOS
 * 
 * Este archivo demuestra los conceptos fundamentales del manejo de archivos:
 * - Escritura en archivos
 * - Lectura de archivos
 * - Modos de apertura
 * - Verificación de errores
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ============================================
// CONCEPTO 1: ESCRIBIR EN UN ARCHIVO
// ============================================
void concepto_escribir_archivo() {
    cout << "\n=== CONCEPTO 1: ESCRIBIR EN ARCHIVO ===" << endl;
    
    // Crear objeto ofstream (output file stream)
    ofstream archivo_salida;
    
    // Abrir archivo (se crea si no existe)
    archivo_salida.open("ejemplo_escritura.txt");
    
    // Verificar si se abrió correctamente
    if(archivo_salida.is_open()) {
        cout << "Archivo abierto exitosamente" << endl;
        
        // Escribir contenido en el archivo
        archivo_salida << "Esta es la primera linea" << endl;
        archivo_salida << "Esta es la segunda linea" << endl;
        archivo_salida << "Numero: " << 42 << endl;
        archivo_salida << "Decimal: " << 3.14159 << endl;
        
        // Cerrar el archivo
        archivo_salida.close();
        cout << "Datos escritos y archivo cerrado" << endl;
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
}

// ============================================
// CONCEPTO 2: LEER DE UN ARCHIVO
// ============================================
void concepto_leer_archivo() {
    cout << "\n=== CONCEPTO 2: LEER DE ARCHIVO ===" << endl;
    
    // Crear objeto ifstream (input file stream)
    ifstream archivo_entrada("ejemplo_escritura.txt");
    
    if(archivo_entrada.is_open()) {
        string linea_leida;
        int numero_linea = 1;
        
        // Leer línea por línea
        while(getline(archivo_entrada, linea_leida)) {
            cout << "Linea " << numero_linea << ": " << linea_leida << endl;
            numero_linea++;
        }
        
        archivo_entrada.close();
        cout << "Archivo leido y cerrado" << endl;
    } else {
        cout << "Error: No se pudo abrir el archivo" << endl;
    }
}

// ============================================
// CONCEPTO 3: MODO APPEND (AGREGAR AL FINAL)
// ============================================
void concepto_modo_append() {
    cout << "\n=== CONCEPTO 3: MODO APPEND ===" << endl;
    
    // ios::app - Agregar al final sin borrar contenido existente
    ofstream archivo("ejemplo_escritura.txt", ios::app);
    
    if(archivo.is_open()) {
        archivo << "Esta linea se agrega al final" << endl;
        archivo << "Sin borrar el contenido anterior" << endl;
        archivo.close();
        
        cout << "Contenido agregado al final del archivo" << endl;
    }
}

// ============================================
// CONCEPTO 4: VERIFICAR EXISTENCIA DE ARCHIVO
// ============================================
void concepto_verificar_existencia() {
    cout << "\n=== CONCEPTO 4: VERIFICAR EXISTENCIA ===" << endl;
    
    string nombre_archivo;
    cout << "Ingrese nombre de archivo a verificar: ";
    cin >> nombre_archivo;
    
    ifstream archivo(nombre_archivo);
    
    if(archivo.good()) {
        cout << "El archivo '" << nombre_archivo << "' EXISTE" << endl;
        archivo.close();
    } else {
        cout << "El archivo '" << nombre_archivo << "' NO EXISTE" << endl;
    }
}

// ============================================
// CONCEPTO 5: CONTAR LÍNEAS EN UN ARCHIVO
// ============================================
void concepto_contar_lineas() {
    cout << "\n=== CONCEPTO 5: CONTAR LINEAS ===" << endl;
    
    ifstream archivo("ejemplo_escritura.txt");
    
    if(archivo.is_open()) {
        string linea;
        int contador_lineas = 0;
        
        while(getline(archivo, linea)) {
            contador_lineas++;
        }
        
        cout << "El archivo tiene " << contador_lineas << " lineas" << endl;
        archivo.close();
    }
}

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================
int main() {
    int opcion;
    
    do {
        cout << "\n========================================" << endl;
        cout << "    CONCEPTOS DE MANEJO DE ARCHIVOS" << endl;
        cout << "========================================" << endl;
        cout << "1. Escribir en archivo" << endl;
        cout << "2. Leer de archivo" << endl;
        cout << "3. Modo append (agregar)" << endl;
        cout << "4. Verificar existencia" << endl;
        cout << "5. Contar lineas" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                concepto_escribir_archivo();
                break;
            case 2:
                concepto_leer_archivo();
                break;
            case 3:
                concepto_modo_append();
                break;
            case 4:
                concepto_verificar_existencia();
                break;
            case 5:
                concepto_contar_lineas();
                break;
            case 0:
                cout << "\n¡Adios!" << endl;
                break;
            default:
                cout << "\nOpcion invalida" << endl;
        }
        
    } while(opcion != 0);
    
    return 0;
}

/*
 * NOTAS IMPORTANTES:
 * 
 * 1. SIEMPRE verifica si el archivo se abrió con is_open()
 * 2. SIEMPRE cierra los archivos con close()
 * 3. Usa ios::app para agregar sin borrar
 * 4. Usa getline() para leer líneas completas
 * 5. Los archivos se crean en el mismo directorio del ejecutable
 */
