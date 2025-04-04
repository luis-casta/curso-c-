
/*
   Escriba un programa que lea de la entrada estándar el precio de un producto y muestre la salida
   estandar con el precio del producto aplicandole el iva
*/
#include <iostream>
using namespace std;

int main(){
  const double  IVA = 0.19;
  double precioProducto = 0;

  cout << "ingrese el precio del producto: "; cin >> precioProducto;

  // formula del iva precio original + (precio original * IVA)
  // factorizandolo queda: precio original * (1 + IVA)

  // calcular el IVA
  double productoConIva = precioProducto * (1 + IVA);

  cout << "precio total con el 19% de IVA: " << productoConIva << endl;

  


  return 0;
}