#include <iostream>
using namespace std;

// Ejercicio 5: Estadísticas de un Arreglo (Nivel: Difícil)
// Objetivo: Pasar arreglos a funciones y devolver múltiples resultados por referencia.

// Declaración de la función
// 'arr[]' recibe el arreglo. 'tamano' es necesario porque los arreglos no saben su tamaño.
// 'suma', 'maximo', 'minimo' son pasados por referencia para devolver los resultados.
void calcularEstadisticas(const int arr[], int tamano, int &suma, int &maximo, int &minimo);

int main() {
    int n;

    cout << "=== Ejercicio 5: Estadísticas de Arreglo ===" << endl;
    cout << "¿Cuántos números deseas ingresar? ";
    cin >> n;

    if (n <= 0) {
        cout << "El tamaño debe ser mayor a 0." << endl;
        return 1;
    }

    // Crear el arreglo dinámicamente o con un tamaño fijo grande si no se ha visto 'new'
    // Para simplificar y evitar gestión de memoria dinámica compleja si es nivel básico,
    // usaremos un vector o un array de tamaño fijo grande, pero el ejercicio pide arreglos.
    // Usaremos un array de tamaño fijo con un límite seguro para este ejercicio.
    const int MAX_TAMANO = 100;
    int numeros[MAX_TAMANO];

    if (n > MAX_TAMANO) {
        cout << "Por favor ingresa un tamaño menor a " << MAX_TAMANO << endl;
        return 1;
    }

    // Llenar el arreglo
    for (int i = 0; i < n; ++i) {
        cout << "Número " << (i + 1) << ": ";
        cin >> numeros[i];
    }

    int suma, max, min;

    // Llamada a la función
    calcularEstadisticas(numeros, n, suma, max, min);

    // Mostrar resultados
    cout << "\n--- Resultados ---" << endl;
    cout << "Suma total: " << suma << endl;
    cout << "Promedio: " << (double)suma / n << endl;
    cout << "Máximo: " << max << endl;
    cout << "Mínimo: " << min << endl;

    return 0;
}

// Definición de la función
void calcularEstadisticas(const int arr[], int tamano, int &suma, int &maximo, int &minimo) {
    // Inicializar variables
    suma = 0;
    maximo = arr[0]; // Asumimos que el primero es el máximo inicial
    minimo = arr[0]; // Asumimos que el primero es el mínimo inicial

    for (int i = 0; i < tamano; ++i) {
        suma += arr[i]; // Acumular suma

        // Actualizar máximo
        if (arr[i] > maximo) {
            maximo = arr[i];
        }

        // Actualizar mínimo
        if (arr[i] < minimo) {
            minimo = arr[i];
        }
    }
}
