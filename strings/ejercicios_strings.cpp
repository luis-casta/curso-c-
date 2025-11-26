// EJERCICIOS STRINGS: Colección completa de 5 ejercicios progresivos

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ============================================
// EJERCICIO 1: OPERACIONES BÁSICAS (FÁCIL)
// ============================================
void ejercicio1_operaciones_basicas() {
    string nombre_completo, nombre, apellido;
    
    cout << "\n=== EJERCICIO 1: OPERACIONES BASICAS ===" << endl;
    
    cin.ignore();
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "Ingrese su apellido: ";
    getline(cin, apellido);
    
    // Concatenación
    nombre_completo = nombre + " " + apellido;
    
    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Nombre completo: " << nombre_completo << endl;
    cout << "Longitud total: " << nombre_completo.length() << " caracteres" << endl;
    cout << "Primera letra: " << nombre_completo[0] << endl;
    cout << "Ultima letra: " << nombre_completo[nombre_completo.length() - 1] << endl;
    
    // Convertir a mayúsculas
    string nombre_mayusculas = nombre_completo;
    transform(nombre_mayusculas.begin(), nombre_mayusculas.end(), 
              nombre_mayusculas.begin(), ::toupper);
    cout << "En mayusculas: " << nombre_mayusculas << endl;
}

// ============================================
// EJERCICIO 2: BÚSQUEDA Y REEMPLAZO (FÁCIL-MEDIO)
// ============================================
void ejercicio2_busqueda_reemplazo() {
    string texto_original, palabra_buscar, palabra_reemplazar;
    
    cout << "\n=== EJERCICIO 2: BUSQUEDA Y REEMPLAZO ===" << endl;
    
    cin.ignore();
    cout << "Ingrese un texto: ";
    getline(cin, texto_original);
    cout << "Palabra a buscar: ";
    getline(cin, palabra_buscar);
    cout << "Palabra de reemplazo: ";
    getline(cin, palabra_reemplazar);
    
    // Buscar
    size_t posicion_encontrada = texto_original.find(palabra_buscar);
    
    if(posicion_encontrada != string::npos) {
        cout << "\n¡Palabra encontrada en posicion " << posicion_encontrada << "!" << endl;
        
        // Reemplazar
        string texto_modificado = texto_original;
        texto_modificado.replace(posicion_encontrada, palabra_buscar.length(), 
                                palabra_reemplazar);
        
        cout << "Texto original: " << texto_original << endl;
        cout << "Texto modificado: " << texto_modificado << endl;
    } else {
        cout << "\nPalabra no encontrada en el texto" << endl;
    }
}

// ============================================
// EJERCICIO 3: ANÁLISIS DE TEXTO (MEDIO)
// ============================================
void ejercicio3_analisis_texto() {
    string texto_analizar;
    
    cout << "\n=== EJERCICIO 3: ANALISIS DE TEXTO ===" << endl;
    
    cin.ignore();
    cout << "Ingrese un texto: ";
    getline(cin, texto_analizar);
    
    // Contar caracteres
    int total_caracteres = texto_analizar.length();
    int cantidad_espacios = 0;
    int cantidad_vocales = 0;
    int cantidad_consonantes = 0;
    int cantidad_digitos = 0;
    
    for(char caracter_actual : texto_analizar) {
        if(caracter_actual == ' ') {
            cantidad_espacios++;
        } else if(isdigit(caracter_actual)) {
            cantidad_digitos++;
        } else if(isalpha(caracter_actual)) {
            char letra_minuscula = tolower(caracter_actual);
            if(letra_minuscula == 'a' || letra_minuscula == 'e' || 
               letra_minuscula == 'i' || letra_minuscula == 'o' || 
               letra_minuscula == 'u') {
                cantidad_vocales++;
            } else {
                cantidad_consonantes++;
            }
        }
    }
    
    // Contar palabras (aproximado)
    int cantidad_palabras = 1;
    for(char c : texto_analizar) {
        if(c == ' ') cantidad_palabras++;
    }
    
    cout << "\n--- ESTADISTICAS ---" << endl;
    cout << "Total de caracteres: " << total_caracteres << endl;
    cout << "Espacios: " << cantidad_espacios << endl;
    cout << "Palabras (aprox): " << cantidad_palabras << endl;
    cout << "Vocales: " << cantidad_vocales << endl;
    cout << "Consonantes: " << cantidad_consonantes << endl;
    cout << "Digitos: " << cantidad_digitos << endl;
}

// ============================================
// EJERCICIO 4: VALIDADOR DE CONTRASEÑA (MEDIO-DIFÍCIL)
// ============================================
void ejercicio4_validador_contrasena() {
    string contrasena_ingresada;
    
    cout << "\n=== EJERCICIO 4: VALIDADOR DE CONTRASEÑA ===" << endl;
    cout << "\nRequisitos:" << endl;
    cout << "- Minimo 8 caracteres" << endl;
    cout << "- Al menos una mayuscula" << endl;
    cout << "- Al menos una minuscula" << endl;
    cout << "- Al menos un digito" << endl;
    
    cin.ignore();
    cout << "\nIngrese contraseña: ";
    getline(cin, contrasena_ingresada);
    
    // Validaciones
    bool longitud_valida = contrasena_ingresada.length() >= 8;
    bool tiene_mayuscula = false;
    bool tiene_minuscula = false;
    bool tiene_digito = false;
    
    for(char c : contrasena_ingresada) {
        if(isupper(c)) tiene_mayuscula = true;
        if(islower(c)) tiene_minuscula = true;
        if(isdigit(c)) tiene_digito = true;
    }
    
    cout << "\n--- VALIDACION ---" << endl;
    cout << "Longitud >= 8: " << (longitud_valida ? "✓" : "✗") << endl;
    cout << "Tiene mayuscula: " << (tiene_mayuscula ? "✓" : "✗") << endl;
    cout << "Tiene minuscula: " << (tiene_minuscula ? "✓" : "✗") << endl;
    cout << "Tiene digito: " << (tiene_digito ? "✓" : "✗") << endl;
    
    if(longitud_valida && tiene_mayuscula && tiene_minuscula && tiene_digito) {
        cout << "\n¡Contraseña VALIDA!" << endl;
    } else {
        cout << "\nContraseña INVALIDA. Revise los requisitos." << endl;
    }
}

// ============================================
// EJERCICIO 5: PROCESADOR DE TEXTO (DIFÍCIL)
// ============================================
void ejercicio5_procesador_texto() {
    string texto_principal;
    int opcion_menu;
    
    cout << "\n=== EJERCICIO 5: PROCESADOR DE TEXTO ===" << endl;
    
    cin.ignore();
    cout << "Ingrese el texto inicial: ";
    getline(cin, texto_principal);
    
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "Texto actual: \"" << texto_principal << "\"" << endl;
        cout << "\n1. Convertir a mayusculas" << endl;
        cout << "2. Convertir a minusculas" << endl;
        cout << "3. Invertir texto" << endl;
        cout << "4. Contar palabras" << endl;
        cout << "5. Agregar texto" << endl;
        cout << "6. Extraer subcadena" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion_menu;
        
        switch(opcion_menu) {
            case 1: {
                transform(texto_principal.begin(), texto_principal.end(), 
                         texto_principal.begin(), ::toupper);
                cout << "Convertido a mayusculas" << endl;
                break;
            }
            
            case 2: {
                transform(texto_principal.begin(), texto_principal.end(), 
                         texto_principal.begin(), ::tolower);
                cout << "Convertido a minusculas" << endl;
                break;
            }
            
            case 3: {
                reverse(texto_principal.begin(), texto_principal.end());
                cout << "Texto invertido" << endl;
                break;
            }
            
            case 4: {
                int palabras = 1;
                for(char c : texto_principal) {
                    if(c == ' ') palabras++;
                }
                cout << "Numero de palabras: " << palabras << endl;
                break;
            }
            
            case 5: {
                string texto_agregar;
                cin.ignore();
                cout << "Texto a agregar: ";
                getline(cin, texto_agregar);
                texto_principal += " " + texto_agregar;
                cout << "Texto agregado" << endl;
                break;
            }
            
            case 6: {
                int inicio, longitud;
                cout << "Posicion inicial: ";
                cin >> inicio;
                cout << "Longitud: ";
                cin >> longitud;
                
                if(inicio >= 0 && inicio < texto_principal.length()) {
                    string subcadena = texto_principal.substr(inicio, longitud);
                    cout << "Subcadena: \"" << subcadena << "\"" << endl;
                } else {
                    cout << "Posicion invalida" << endl;
                }
                break;
            }
            
            case 0:
                cout << "Saliendo..." << endl;
                break;
                
            default:
                cout << "Opcion invalida" << endl;
        }
        
    } while(opcion_menu != 0);
}

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================
int main() {
    int ejercicio_seleccionado;
    
    do {
        cout << "\n========================================" << endl;
        cout << "       EJERCICIOS DE STRINGS" << endl;
        cout << "========================================" << endl;
        cout << "1. Operaciones basicas" << endl;
        cout << "2. Busqueda y reemplazo" << endl;
        cout << "3. Analisis de texto" << endl;
        cout << "4. Validador de contraseña" << endl;
        cout << "5. Procesador de texto" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione ejercicio: ";
        cin >> ejercicio_seleccionado;
        
        switch(ejercicio_seleccionado) {
            case 1:
                ejercicio1_operaciones_basicas();
                break;
            case 2:
                ejercicio2_busqueda_reemplazo();
                break;
            case 3:
                ejercicio3_analisis_texto();
                break;
            case 4:
                ejercicio4_validador_contrasena();
                break;
            case 5:
                ejercicio5_procesador_texto();
                break;
            case 0:
                cout << "\n¡Adios!" << endl;
                break;
            default:
                cout << "\nEjercicio invalido" << endl;
        }
        
    } while(ejercicio_seleccionado != 0);
    
    return 0;
}
