/*
 * EJERCICIO ESTRUCTURAS 4: VECTOR DE ESTRUCTURAS - BIBLIOTECA (NIVEL MEDIO-DIFÍCIL)
 * 
 * Descripción:
 * Sistema de biblioteca usando vector de estructuras con funciones de búsqueda.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio_publicacion;
    string isbn;
    bool esta_disponible;
    int numero_paginas;
};

void agregar_libro(vector<Libro>& biblioteca) {
    Libro nuevo_libro;
    
    cin.ignore();
    cout << "\n--- AGREGAR NUEVO LIBRO ---" << endl;
    cout << "Titulo: ";
    getline(cin, nuevo_libro.titulo);
    cout << "Autor: ";
    getline(cin, nuevo_libro.autor);
    cout << "Año de publicacion: ";
    cin >> nuevo_libro.anio_publicacion;
    cin.ignore();
    cout << "ISBN: ";
    getline(cin, nuevo_libro.isbn);
    cout << "Numero de paginas: ";
    cin >> nuevo_libro.numero_paginas;
    nuevo_libro.esta_disponible = true;
    
    biblioteca.push_back(nuevo_libro);
    cout << "\n¡Libro agregado exitosamente!" << endl;
}

void mostrar_libros(const vector<Libro>& biblioteca) {
    if(biblioteca.empty()) {
        cout << "\nLa biblioteca esta vacia." << endl;
        return;
    }
    
    cout << "\n=== CATALOGO DE LIBROS ===" << endl;
    for(size_t indice = 0; indice < biblioteca.size(); indice++) {
        cout << "\nLibro " << (indice + 1) << ":" << endl;
        cout << "  Titulo: " << biblioteca[indice].titulo << endl;
        cout << "  Autor: " << biblioteca[indice].autor << endl;
        cout << "  Año: " << biblioteca[indice].anio_publicacion << endl;
        cout << "  ISBN: " << biblioteca[indice].isbn << endl;
        cout << "  Paginas: " << biblioteca[indice].numero_paginas << endl;
        cout << "  Estado: " << (biblioteca[indice].esta_disponible ? "DISPONIBLE" : "PRESTADO") << endl;
    }
}

void buscar_por_titulo(const vector<Libro>& biblioteca) {
    string titulo_buscar;
    cin.ignore();
    cout << "\nIngrese el titulo a buscar: ";
    getline(cin, titulo_buscar);
    
    bool encontrado = false;
    for(const auto& libro : biblioteca) {
        if(libro.titulo.find(titulo_buscar) != string::npos) {
            cout << "\n¡Libro encontrado!" << endl;
            cout << "Titulo: " << libro.titulo << endl;
            cout << "Autor: " << libro.autor << endl;
            cout << "Estado: " << (libro.esta_disponible ? "DISPONIBLE" : "PRESTADO") << endl;
            encontrado = true;
        }
    }
    
    if(!encontrado) {
        cout << "\nNo se encontraron libros con ese titulo." << endl;
    }
}

void prestar_libro(vector<Libro>& biblioteca) {
    mostrar_libros(biblioteca);
    
    int indice;
    cout << "\nIngrese el numero de libro a prestar: ";
    cin >> indice;
    indice--; // Ajustar a índice 0
    
    if(indice >= 0 && indice < biblioteca.size()) {
        if(biblioteca[indice].esta_disponible) {
            biblioteca[indice].esta_disponible = false;
            cout << "\n¡Libro prestado exitosamente!" << endl;
        } else {
            cout << "\nEste libro ya esta prestado." << endl;
        }
    } else {
        cout << "\nNumero de libro invalido." << endl;
    }
}

void devolver_libro(vector<Libro>& biblioteca) {
    cout << "\n--- LIBROS PRESTADOS ---" << endl;
    bool hay_prestados = false;
    
    for(size_t i = 0; i < biblioteca.size(); i++) {
        if(!biblioteca[i].esta_disponible) {
            cout << (i + 1) << ". " << biblioteca[i].titulo << endl;
            hay_prestados = true;
        }
    }
    
    if(!hay_prestados) {
        cout << "No hay libros prestados." << endl;
        return;
    }
    
    int indice;
    cout << "\nIngrese el numero de libro a devolver: ";
    cin >> indice;
    indice--;
    
    if(indice >= 0 && indice < biblioteca.size()) {
        if(!biblioteca[indice].esta_disponible) {
            biblioteca[indice].esta_disponible = true;
            cout << "\n¡Libro devuelto exitosamente!" << endl;
        }
    }
}

int main() {
    vector<Libro> biblioteca;
    int opcion;
    
    do {
        cout << "\n=== SISTEMA DE BIBLIOTECA ===" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Mostrar todos los libros" << endl;
        cout << "3. Buscar libro por titulo" << endl;
        cout << "4. Prestar libro" << endl;
        cout << "5. Devolver libro" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                agregar_libro(biblioteca);
                break;
            case 2:
                mostrar_libros(biblioteca);
                break;
            case 3:
                buscar_por_titulo(biblioteca);
                break;
            case 4:
                prestar_libro(biblioteca);
                break;
            case 5:
                devolver_libro(biblioteca);
                break;
            case 0:
                cout << "\n¡Hasta luego!" << endl;
                break;
            default:
                cout << "\nOpcion invalida." << endl;
        }
    } while(opcion != 0);
    
    return 0;
}

/*
 * EXPLICACIÓN:
 * - Usamos vector<Libro> para almacenar dinámicamente libros
 * - Las funciones reciben el vector por referencia para modificarlo
 * - Usamos const& cuando solo leemos el vector
 * - Demostramos búsqueda, préstamo y devolución de libros
 */
