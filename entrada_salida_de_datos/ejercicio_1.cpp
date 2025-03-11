
/*Escriba un programa que lea de la entrada estandar dos números y muestre la salida 
estandar su suma, resta, multiplicacioón y división*/

#include <iostream>
using namespace std;

int main(){
  int n1, n2; 
  int suma = 0, resta = 0, multiplicacion = 0; 
  double division = 0;
  cout << "ingresa el primer número: ";  cin >> n1; 
  cout << "Ingresa el segundo número: "; cin >> n2; 

  suma = n1 + n2;
  resta = n1- n2;
  multiplicacion = n1 * n2;
  division = (double) n1 / n2; // convertimos los numeros int a double 

  cout << "Suma: " << suma << endl;
  cout << "Resta: " << resta << endl;
  cout << "Multiplicación: " << multiplicacion << endl;
  cout << "División: " << division << endl;

  return 0;
}
