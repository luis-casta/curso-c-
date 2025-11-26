
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Estructura para representar un libro
struct Libro {
    int id;
    string titulo;
    string autor;
    string genero;
    int anio;
    bool disponible;
};

// Clase para manejar la biblioteca
class Biblioteca {
private:
    vector<Libro> libros;
    int siguienteId;

public:
    Biblioteca() : siguienteId(1) {}

    // Agregar un nuevo libro
    void agregarLibro() {
        Libro nuevoLibro;
        nuevoLibro.id = siguienteId++;

        cout << "\n=== AGREGAR NUEVO LIBRO ===" << endl;
        cout << "Título: ";
        cin.ignore();
        getline(cin, nuevoLibro.titulo);


        cout << "Autor: ";
        getline(cin, nuevoLibro.autor);

        cout << "Género: ";
        getline(cin, nuevoLibro.genero);

        cout << "Año: ";
        cin >> nuevoLibro.anio;

        nuevoLibro.disponible = true;

        libros.push_back(nuevoLibro);
        cout << "✓ Libro agregado exitosamente (ID: " << nuevoLibro.id << ")" << endl;
    }

    // Mostrar todos los libros
    // ReSharper disable once CppMemberFunctionMayBeConst
    void mostrarLibros() {
        if (libros.empty()) {
            cout << "\nNo hay libros en la biblioteca." << endl;
            return;
        }

        cout << "\n=== LISTA DE LIBROS ===" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << left << setw(5) << "ID" << setw(25) << "TITULO" << setw(20) << "AUTOR"
             << setw(15) << "GENERO" << setw(8) << "AÑO" << setw(12) << "ESTADO" << endl;
        cout << "----------------------------------------------------------------------------" << endl;

        for (const auto& libro : libros) {
            cout << left << setw(5) << libro.id
                 << setw(25) << (libro.titulo.length() > 24 ? libro.titulo.substr(0, 24) + "." : libro.titulo)
                 << setw(20) << (libro.autor.length() > 19 ? libro.autor.substr(0, 19) + "." : libro.autor)
                 << setw(15) << libro.genero
                 << setw(8) << libro.anio
                 << setw(12) << (libro.disponible ? "Disponible" : "Prestado") << endl;
        }
    }

    // Buscar libro por título
    // ReSharper disable once CppMemberFunctionMayBeConst
    void buscarPorTitulo() {
        string titulo;
        cout << "\nTítulo a buscar: ";
        cin.ignore();
        getline(cin, titulo);

        bool encontrado = false;

        cout << "\n=== RESULTADOS DE BÚSQUEDA ===" << endl;
        for (const auto& libro : libros) {
            if (libro.titulo.find(titulo) != string::npos) {
                if (!encontrado) {
                    cout << "ID\tTITULO\t\t\tAUTOR\t\tESTADO" << endl;
                    cout << "------------------------------------------------" << endl;
                }
                cout << libro.id << "\t"
                     << (libro.titulo.length() > 15 ? libro.titulo.substr(0, 15) + "..." : libro.titulo) << "\t"
                     << libro.autor << "\t"
                     << (libro.disponible ? "Disponible" : "Prestado") << endl;
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No se encontraron libros con ese título." << endl;
        }
    }

    // Prestar un libro
    void prestarLibro() {
        int id;
        cout << "\nID del libro a prestar: ";
        cin >> id;

        for (auto& libro : libros) {
            if (libro.id == id) {
                if (libro.disponible) {
                    libro.disponible = false;
                    cout << "✓ Libro prestado exitosamente: " << libro.titulo << endl;
                } else {
                    cout << "✗ El libro ya está prestado." << endl;
                }
                return;
            }
        }
        cout << "✗ No se encontró un libro con ID " << id << endl;
    }

    // Devolver un libro
    void devolverLibro() {
        int id;
        cout << "\nID del libro a devolver: ";
        cin >> id;

        for (auto& libro : libros) {
            if (libro.id == id) {
                if (!libro.disponible) {
                    libro.disponible = true;
                    cout << "✓ Libro devuelto exitosamente: " << libro.titulo << endl;
                } else {
                    cout << "✗ El libro ya está disponible." << endl;
                }
                return;
            }
        }
        cout << "✗ No se encontró un libro con ID " << id << endl;
    }

    // Mostrar estadísticas
    // ReSharper disable once CppMemberFunctionMayBeConst
    void mostrarEstadisticas() {
        int total = libros.size();
        int disponibles = 0;
        int prestados = 0;

        for (const auto& libro : libros) {
            if (libro.disponible) {
                disponibles++;
            } else {
                prestados++;
            }
        }

        cout << "\n=== ESTADÍSTICAS ===" << endl;
        cout << "Total de libros: " << total << endl;
        cout << "Libros disponibles: " << disponibles << endl;
        cout << "Libros prestados: " << prestados << endl;

        if (total > 0) {
            cout << "Porcentaje disponible: " << fixed << setprecision(1)
                 << (disponibles * 100.0 / total) << "%" << endl;
        }
    }
};

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n=== SISTEMA DE GESTIÓN DE BIBLIOTECA ===" << endl;
    cout << "1. Agregar libro" << endl;
    cout << "2. Mostrar todos los libros" << endl;
    cout << "3. Buscar libro por título" << endl;
    cout << "4. Prestar libro" << endl;
    cout << "5. Devolver libro" << endl;
    cout << "6. Estadísticas" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    Biblioteca biblioteca;
    int opcion;

    // Datos de ejemplo
    biblioteca.agregarLibro(); // Puedes agregar datos manualmente o quitar esta línea

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                biblioteca.agregarLibro();
                break;
            case 2:
                biblioteca.mostrarLibros();
                break;
            case 3:
                biblioteca.buscarPorTitulo();
                break;
            case 4:
                biblioteca.prestarLibro();
                break;
            case 5:
                biblioteca.devolverLibro();
                break;
            case 6:
                biblioteca.mostrarEstadisticas();
                break;
            case 7:
                cout << "\n¡Gracias por usar el sistema de biblioteca!" << endl;
                break;
            default:
                cout << "\nOpción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 7);

    return 0;
}
