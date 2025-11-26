// EJERCICIOS DE MANEJO DE ARCHIVOS: Colección completa de 5 ejercicios progresivos

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ============================================
// EJERCICIO 1: AGENDA DE CONTACTOS (FÁCIL)
// ============================================
void ejercicio1_agenda_contactos() {
    cout << "\n=== EJERCICIO 1: AGENDA DE CONTACTOS ===" << endl;
    
    int opcion;
    do {
        cout << "\n1. Agregar contacto" << endl;
        cout << "2. Ver contactos" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                string nombre_contacto, telefono_contacto;
                
                cin.ignore();
                cout << "Nombre: ";
                getline(cin, nombre_contacto);
                cout << "Telefono: ";
                getline(cin, telefono_contacto);
                
                // Abrir archivo en modo append
                ofstream archivo_contactos("contactos.txt", ios::app);
                
                if(archivo_contactos.is_open()) {
                    archivo_contactos << nombre_contacto << "," << telefono_contacto << endl;
                    archivo_contactos.close();
                    cout << "¡Contacto guardado!" << endl;
                } else {
                    cout << "Error al abrir el archivo" << endl;
                }
                break;
            }
            
            case 2: {
                ifstream archivo_contactos("contactos.txt");
                
                if(archivo_contactos.is_open()) {
                    string linea;
                    int numero_contacto = 1;
                    
                    cout << "\n--- LISTA DE CONTACTOS ---" << endl;
                    while(getline(archivo_contactos, linea)) {
                        // Separar nombre y teléfono
                        size_t posicion_coma = linea.find(',');
                        string nombre = linea.substr(0, posicion_coma);
                        string telefono = linea.substr(posicion_coma + 1);
                        
                        cout << numero_contacto << ". " << nombre 
                             << " - " << telefono << endl;
                        numero_contacto++;
                    }
                    archivo_contactos.close();
                } else {
                    cout << "No hay contactos guardados" << endl;
                }
                break;
            }
        }
    } while(opcion != 0);
}

// ============================================
// EJERCICIO 2: REGISTRO DE CALIFICACIONES (FÁCIL-MEDIO)
// ============================================
void ejercicio2_registro_calificaciones() {
    cout << "\n=== EJERCICIO 2: REGISTRO DE CALIFICACIONES ===" << endl;
    
    int opcion;
    do {
        cout << "\n1. Registrar calificacion" << endl;
        cout << "2. Ver calificaciones" << endl;
        cout << "3. Calcular promedio" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                string nombre_estudiante;
                double calificacion_obtenida;
                
                cin.ignore();
                cout << "Nombre del estudiante: ";
                getline(cin, nombre_estudiante);
                cout << "Calificacion: ";
                cin >> calificacion_obtenida;
                
                ofstream archivo_notas("calificaciones.txt", ios::app);
                if(archivo_notas.is_open()) {
                    archivo_notas << nombre_estudiante << "," 
                                 << calificacion_obtenida << endl;
                    archivo_notas.close();
                    cout << "¡Calificacion registrada!" << endl;
                }
                break;
            }
            
            case 2: {
                ifstream archivo_notas("calificaciones.txt");
                
                if(archivo_notas.is_open()) {
                    string linea;
                    cout << "\n--- CALIFICACIONES ---" << endl;
                    cout << left << setw(20) << "Estudiante" << "Calificacion" << endl;
                    cout << "--------------------------------" << endl;
                    
                    while(getline(archivo_notas, linea)) {
                        size_t pos = linea.find(',');
                        string nombre = linea.substr(0, pos);
                        string calificacion = linea.substr(pos + 1);
                        
                        cout << left << setw(20) << nombre << calificacion << endl;
                    }
                    archivo_notas.close();
                }
                break;
            }
            
            case 3: {
                ifstream archivo_notas("calificaciones.txt");
                
                if(archivo_notas.is_open()) {
                    string linea;
                    double suma_calificaciones = 0;
                    int cantidad_estudiantes = 0;
                    
                    while(getline(archivo_notas, linea)) {
                        size_t pos = linea.find(',');
                        string calificacion_str = linea.substr(pos + 1);
                        double calificacion = stod(calificacion_str);
                        
                        suma_calificaciones += calificacion;
                        cantidad_estudiantes++;
                    }
                    
                    if(cantidad_estudiantes > 0) {
                        double promedio = suma_calificaciones / cantidad_estudiantes;
                        cout << "\nPromedio del grupo: " << fixed 
                             << setprecision(2) << promedio << endl;
                    }
                    archivo_notas.close();
                }
                break;
            }
        }
    } while(opcion != 0);
}

// ============================================
// EJERCICIO 3: INVENTARIO DE PRODUCTOS (MEDIO)
// ============================================
void ejercicio3_inventario_productos() {
    cout << "\n=== EJERCICIO 3: INVENTARIO DE PRODUCTOS ===" << endl;
    
    struct Producto {
        string codigo;
        string nombre;
        int cantidad;
        double precio;
    };
    
    int opcion;
    do {
        cout << "\n1. Agregar producto" << endl;
        cout << "2. Ver inventario" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Valor total del inventario" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                Producto nuevo_producto;
                
                cin.ignore();
                cout << "Codigo: ";
                getline(cin, nuevo_producto.codigo);
                cout << "Nombre: ";
                getline(cin, nuevo_producto.nombre);
                cout << "Cantidad: ";
                cin >> nuevo_producto.cantidad;
                cout << "Precio: $";
                cin >> nuevo_producto.precio;
                
                ofstream archivo("inventario.txt", ios::app);
                if(archivo.is_open()) {
                    archivo << nuevo_producto.codigo << ","
                           << nuevo_producto.nombre << ","
                           << nuevo_producto.cantidad << ","
                           << nuevo_producto.precio << endl;
                    archivo.close();
                    cout << "¡Producto agregado!" << endl;
                }
                break;
            }
            
            case 2: {
                ifstream archivo("inventario.txt");
                
                if(archivo.is_open()) {
                    string linea;
                    cout << "\n--- INVENTARIO ---" << endl;
                    cout << left << setw(10) << "Codigo" 
                         << setw(20) << "Nombre"
                         << setw(10) << "Cantidad"
                         << "Precio" << endl;
                    cout << "------------------------------------------------" << endl;
                    
                    while(getline(archivo, linea)) {
                        size_t pos1 = linea.find(',');
                        size_t pos2 = linea.find(',', pos1 + 1);
                        size_t pos3 = linea.find(',', pos2 + 1);
                        
                        string codigo = linea.substr(0, pos1);
                        string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
                        string cantidad = linea.substr(pos2 + 1, pos3 - pos2 - 1);
                        string precio = linea.substr(pos3 + 1);
                        
                        cout << left << setw(10) << codigo
                             << setw(20) << nombre
                             << setw(10) << cantidad
                             << "$" << precio << endl;
                    }
                    archivo.close();
                }
                break;
            }
            
            case 3: {
                string codigo_buscar;
                cin.ignore();
                cout << "Ingrese codigo a buscar: ";
                getline(cin, codigo_buscar);
                
                ifstream archivo("inventario.txt");
                bool encontrado = false;
                
                if(archivo.is_open()) {
                    string linea;
                    while(getline(archivo, linea)) {
                        if(linea.find(codigo_buscar) == 0) {
                            cout << "\n¡Producto encontrado!" << endl;
                            cout << linea << endl;
                            encontrado = true;
                            break;
                        }
                    }
                    
                    if(!encontrado) {
                        cout << "Producto no encontrado" << endl;
                    }
                    archivo.close();
                }
                break;
            }
            
            case 4: {
                ifstream archivo("inventario.txt");
                double valor_total = 0;
                
                if(archivo.is_open()) {
                    string linea;
                    while(getline(archivo, linea)) {
                        size_t pos2 = linea.find(',');
                        pos2 = linea.find(',', pos2 + 1);
                        size_t pos3 = linea.find(',', pos2 + 1);
                        
                        int cantidad = stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1));
                        double precio = stod(linea.substr(pos3 + 1));
                        
                        valor_total += cantidad * precio;
                    }
                    
                    cout << "\nValor total del inventario: $" << fixed 
                         << setprecision(2) << valor_total << endl;
                    archivo.close();
                }
                break;
            }
        }
    } while(opcion != 0);
}

// ============================================
// EJERCICIO 4: DIARIO PERSONAL (MEDIO-DIFÍCIL)
// ============================================
void ejercicio4_diario_personal() {
    cout << "\n=== EJERCICIO 4: DIARIO PERSONAL ===" << endl;
    
    int opcion;
    do {
        cout << "\n1. Escribir entrada" << endl;
        cout << "2. Leer todas las entradas" << endl;
        cout << "3. Buscar por fecha" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                string fecha, titulo, contenido;
                
                cin.ignore();
                cout << "Fecha (DD/MM/AAAA): ";
                getline(cin, fecha);
                cout << "Titulo: ";
                getline(cin, titulo);
                cout << "Contenido: ";
                getline(cin, contenido);
                
                ofstream diario("diario.txt", ios::app);
                if(diario.is_open()) {
                    diario << "FECHA: " << fecha << endl;
                    diario << "TITULO: " << titulo << endl;
                    diario << "CONTENIDO: " << contenido << endl;
                    diario << "----------------------------" << endl;
                    diario.close();
                    cout << "¡Entrada guardada!" << endl;
                }
                break;
            }
            
            case 2: {
                ifstream diario("diario.txt");
                
                if(diario.is_open()) {
                    string linea;
                    cout << "\n=== DIARIO PERSONAL ===" << endl;
                    while(getline(diario, linea)) {
                        cout << linea << endl;
                    }
                    diario.close();
                } else {
                    cout << "No hay entradas en el diario" << endl;
                }
                break;
            }
            
            case 3: {
                string fecha_buscar;
                cin.ignore();
                cout << "Ingrese fecha a buscar: ";
                getline(cin, fecha_buscar);
                
                ifstream diario("diario.txt");
                bool encontrado = false;
                
                if(diario.is_open()) {
                    string linea;
                    while(getline(diario, linea)) {
                        if(linea.find("FECHA: " + fecha_buscar) != string::npos) {
                            cout << "\n" << linea << endl;
                            encontrado = true;
                            
                            // Leer las siguientes 3 líneas
                            for(int i = 0; i < 3; i++) {
                                getline(diario, linea);
                                cout << linea << endl;
                            }
                            break;
                        }
                    }
                    
                    if(!encontrado) {
                        cout << "No hay entradas para esa fecha" << endl;
                    }
                    diario.close();
                }
                break;
            }
        }
    } while(opcion != 0);
}

// ============================================
// EJERCICIO 5: SISTEMA DE LOGS (DIFÍCIL)
// ============================================
void ejercicio5_sistema_logs() {
    cout << "\n=== EJERCICIO 5: SISTEMA DE LOGS ===" << endl;
    
    // Función para obtener timestamp
    auto obtener_timestamp = []() -> string {
        time_t ahora = time(0);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&ahora));
        return string(buffer);
    };
    
    // Función para registrar log
    auto registrar_log = [&](string nivel, string mensaje) {
        ofstream log_file("sistema.log", ios::app);
        if(log_file.is_open()) {
            log_file << "[" << obtener_timestamp() << "] "
                    << "[" << nivel << "] "
                    << mensaje << endl;
            log_file.close();
        }
    };
    
    int opcion;
    do {
        cout << "\n1. Registrar INFO" << endl;
        cout << "2. Registrar WARNING" << endl;
        cout << "3. Registrar ERROR" << endl;
        cout << "4. Ver logs" << endl;
        cout << "5. Filtrar por nivel" << endl;
        cout << "6. Limpiar logs" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
            case 2:
            case 3: {
                string mensaje;
                string nivel;
                
                if(opcion == 1) nivel = "INFO";
                else if(opcion == 2) nivel = "WARNING";
                else nivel = "ERROR";
                
                cin.ignore();
                cout << "Mensaje: ";
                getline(cin, mensaje);
                
                registrar_log(nivel, mensaje);
                cout << "Log registrado" << endl;
                break;
            }
            
            case 4: {
                ifstream log_file("sistema.log");
                
                if(log_file.is_open()) {
                    string linea;
                    int numero_linea = 1;
                    
                    cout << "\n=== LOGS DEL SISTEMA ===" << endl;
                    while(getline(log_file, linea)) {
                        cout << numero_linea << ". " << linea << endl;
                        numero_linea++;
                    }
                    log_file.close();
                } else {
                    cout << "No hay logs registrados" << endl;
                }
                break;
            }
            
            case 5: {
                string nivel_filtro;
                cin.ignore();
                cout << "Nivel (INFO/WARNING/ERROR): ";
                getline(cin, nivel_filtro);
                
                ifstream log_file("sistema.log");
                
                if(log_file.is_open()) {
                    string linea;
                    bool encontrado = false;
                    
                    cout << "\n=== LOGS FILTRADOS ===" << endl;
                    while(getline(log_file, linea)) {
                        if(linea.find("[" + nivel_filtro + "]") != string::npos) {
                            cout << linea << endl;
                            encontrado = true;
                        }
                    }
                    
                    if(!encontrado) {
                        cout << "No hay logs de ese nivel" << endl;
                    }
                    log_file.close();
                }
                break;
            }
            
            case 6: {
                ofstream log_file("sistema.log", ios::trunc);
                log_file.close();
                cout << "Logs limpiados" << endl;
                break;
            }
        }
    } while(opcion != 0);
}

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================
int main() {
    int ejercicio;
    
    do {
        cout << "\n========================================" << endl;
        cout << "   EJERCICIOS DE MANEJO DE ARCHIVOS" << endl;
        cout << "========================================" << endl;
        cout << "1. Agenda de contactos" << endl;
        cout << "2. Registro de calificaciones" << endl;
        cout << "3. Inventario de productos" << endl;
        cout << "4. Diario personal" << endl;
        cout << "5. Sistema de logs" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione ejercicio: ";
        cin >> ejercicio;
        
        switch(ejercicio) {
            case 1:
                ejercicio1_agenda_contactos();
                break;
            case 2:
                ejercicio2_registro_calificaciones();
                break;
            case 3:
                ejercicio3_inventario_productos();
                break;
            case 4:
                ejercicio4_diario_personal();
                break;
            case 5:
                ejercicio5_sistema_logs();
                break;
            case 0:
                cout << "\n¡Adios!" << endl;
                break;
            default:
                cout << "\nEjercicio invalido" << endl;
        }
    } while(ejercicio != 0);
    
    return 0;
}
