/*
 * EJERCICIO ESTRUCTURAS 2: CATÁLOGO DE PRODUCTOS (NIVEL FÁCIL-MEDIO)
 * 
 * Descripción:
 * Sistema de catálogo de productos usando un array de estructuras.
 * Permite registrar múltiples productos y mostrar estadísticas.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Estructura para representar un producto
struct Producto {
    string nombre_producto;
    double precio_unitario;
    int cantidad_stock;
    string categoria_producto;
    string codigo_barras;
};

int main() {
    const int CANTIDAD_MAXIMA_PRODUCTOS = 5;
    Producto inventario[CANTIDAD_MAXIMA_PRODUCTOS];
    int productos_registrados = 0;
    
    cout << "=== SISTEMA DE CATALOGO DE PRODUCTOS ===" << endl;
    
    // Registrar productos
    cout << "\nIngrese la cantidad de productos a registrar (max " 
         << CANTIDAD_MAXIMA_PRODUCTOS << "): ";
    cin >> productos_registrados;
    
    if(productos_registrados > CANTIDAD_MAXIMA_PRODUCTOS) {
        productos_registrados = CANTIDAD_MAXIMA_PRODUCTOS;
    }
    
    cin.ignore();
    
    // Ingresar información de cada producto
    for(int indice = 0; indice < productos_registrados; indice++) {
        cout << "\n--- PRODUCTO " << (indice + 1) << " ---" << endl;
        
        cout << "Nombre: ";
        getline(cin, inventario[indice].nombre_producto);
        
        cout << "Precio: $";
        cin >> inventario[indice].precio_unitario;
        
        cout << "Stock: ";
        cin >> inventario[indice].cantidad_stock;
        
        cin.ignore();
        cout << "Categoria: ";
        getline(cin, inventario[indice].categoria_producto);
        
        cout << "Codigo de barras: ";
        getline(cin, inventario[indice].codigo_barras);
    }
    
    // Mostrar catálogo completo
    cout << "\n=== CATALOGO COMPLETO ===" << endl;
    cout << fixed << setprecision(2);
    
    for(int indice = 0; indice < productos_registrados; indice++) {
        cout << "\nProducto " << (indice + 1) << ":" << endl;
        cout << "  Nombre: " << inventario[indice].nombre_producto << endl;
        cout << "  Precio: $" << inventario[indice].precio_unitario << endl;
        cout << "  Stock: " << inventario[indice].cantidad_stock << " unidades" << endl;
        cout << "  Categoria: " << inventario[indice].categoria_producto << endl;
        cout << "  Codigo: " << inventario[indice].codigo_barras << endl;
        
        // Calcular valor total del producto
        double valor_total_producto = inventario[indice].precio_unitario * 
                                      inventario[indice].cantidad_stock;
        cout << "  Valor total en stock: $" << valor_total_producto << endl;
    }
    
    // Calcular estadísticas
    double precio_total = 0;
    double precio_maximo = inventario[0].precio_unitario;
    double precio_minimo = inventario[0].precio_unitario;
    int stock_total = 0;
    int indice_mas_caro = 0;
    int indice_mas_barato = 0;
    
    for(int indice = 0; indice < productos_registrados; indice++) {
        precio_total += inventario[indice].precio_unitario;
        stock_total += inventario[indice].cantidad_stock;
        
        if(inventario[indice].precio_unitario > precio_maximo) {
            precio_maximo = inventario[indice].precio_unitario;
            indice_mas_caro = indice;
        }
        
        if(inventario[indice].precio_unitario < precio_minimo) {
            precio_minimo = inventario[indice].precio_unitario;
            indice_mas_barato = indice;
        }
    }
    
    double precio_promedio = precio_total / productos_registrados;
    
    // Mostrar estadísticas
    cout << "\n=== ESTADISTICAS ===" << endl;
    cout << "Total de productos: " << productos_registrados << endl;
    cout << "Precio promedio: $" << precio_promedio << endl;
    cout << "Stock total: " << stock_total << " unidades" << endl;
    
    cout << "\nProducto mas caro: " << inventario[indice_mas_caro].nombre_producto 
         << " ($" << precio_maximo << ")" << endl;
    cout << "Producto mas barato: " << inventario[indice_mas_barato].nombre_producto 
         << " ($" << precio_minimo << ")" << endl;
    
    return 0;
}

/*
 * EXPLICACIÓN:
 * - Usamos un array de estructuras para almacenar múltiples productos
 * - Cada elemento del array es una estructura completa
 * - Accedemos a los miembros usando: array[indice].miembro
 * - Calculamos estadísticas recorriendo el array
 */
