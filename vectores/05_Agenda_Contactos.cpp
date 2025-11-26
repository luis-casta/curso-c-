/*
 * EJERCICIO VECTORES 5: AGENDA DE CONTACTOS (NIVEL DIFÍCIL)
 * 
 * Descripción:
 * Sistema completo de agenda de contactos usando vectores.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Contacto {
    string nombre;
    string telefono;
    string email;
};

void mostrar_menu() {
    cout << "\n=== AGENDA DE CONTACTOS ===" << endl;
    cout << "1. Agregar contacto" << endl;
    cout << "2. Listar contactos" << endl;
    cout << "3. Buscar contacto" << endl;
    cout << "4. Eliminar contacto" << endl;
    cout << "5. Ordenar por nombre" << endl;
    cout << "0. Salir" << endl;
    cout << "Opcion: ";
}

void agregar_contacto(vector<Contacto>& agenda) {
    Contacto nuevo;
    cin.ignore();
    cout << "\nNombre: ";
    getline(cin, nuevo.nombre);
    cout << "Telefono: ";
    getline(cin, nuevo.telefono);
    cout << "Email: ";
    getline(cin, nuevo.email);
    agenda.push_back(nuevo);
    cout << "¡Contacto agregado!" << endl;
}

void listar_contactos(const vector<Contacto>& agenda) {
    if(agenda.empty()) {
        cout << "\nNo hay contactos en la agenda." << endl;
        return;
    }
    
    cout << "\n--- LISTA DE CONTACTOS ---" << endl;
    for(size_t i = 0; i < agenda.size(); i++) {
        cout << "\nContacto " << (i + 1) << ":" << endl;
        cout << "  Nombre: " << agenda[i].nombre << endl;
        cout << "  Telefono: " << agenda[i].telefono << endl;
        cout << "  Email: " << agenda[i].email << endl;
    }
}

void buscar_contacto(const vector<Contacto>& agenda) {
    string busqueda;
    cin.ignore();
    cout << "\nIngrese nombre a buscar: ";
    getline(cin, busqueda);
    
    bool encontrado = false;
    for(const auto& contacto : agenda) {
        if(contacto.nombre.find(busqueda) != string::npos) {
            cout << "\nContacto encontrado:" << endl;
            cout << "  Nombre: " << contacto.nombre << endl;
            cout << "  Telefono: " << contacto.telefono << endl;
            cout << "  Email: " << contacto.email << endl;
            encontrado = true;
        }
    }
    
    if(!encontrado) {
        cout << "No se encontraron contactos." << endl;
    }
}

void eliminar_contacto(vector<Contacto>& agenda) {
    if(agenda.empty()) {
        cout << "\nNo hay contactos para eliminar." << endl;
        return;
    }
    
    listar_contactos(agenda);
    int indice;
    cout << "\nIngrese numero de contacto a eliminar: ";
    cin >> indice;
    
    if(indice >= 1 && indice <= agenda.size()) {
        agenda.erase(agenda.begin() + indice - 1);
        cout << "¡Contacto eliminado!" << endl;
    } else {
        cout << "Indice invalido." << endl;
    }
}

void ordenar_contactos(vector<Contacto>& agenda) {
    sort(agenda.begin(), agenda.end(), [](const Contacto& a, const Contacto& b) {
        return a.nombre < b.nombre;
    });
    cout << "\n¡Contactos ordenados alfabeticamente!" << endl;
}

int main() {
    vector<Contacto> agenda;
    int opcion;
    
    do {
        mostrar_menu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                agregar_contacto(agenda);
                break;
            case 2:
                listar_contactos(agenda);
                break;
            case 3:
                buscar_contacto(agenda);
                break;
            case 4:
                eliminar_contacto(agenda);
                break;
            case 5:
                ordenar_contactos(agenda);
                break;
            case 0:
                cout << "\n¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while(opcion != 0);
    
    return 0;
}
