
/* Ejercicio 4. Escriba un programa que pida dos números A y B e imprima en pantalla el menor.
Ej: si se ingresan 7 y 3 se debe imprimir:
El menor es 3*/

#include <iostream>

using namespace std;

int main()
{
  int a, b;
  cout << "Ingrse el primer número: ";
  cin >> a;

  cout << "-ingrese el segundo número: ";
  cin >> b;

  if (a > b){
    cout << a << " Es mayor" << endl;
  }
  else if (b > a){
    cout << b << " ES mayor" << endl;
  }
  else {
    cout << "Los números son iguales" << endl;
  }

  return 0;
}
