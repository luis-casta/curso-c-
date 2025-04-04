
/*Estructura if en C++
La estructura if en C++ se usa para ejecutar un bloque de código si una condición es verdadera.

Sintaxis básica
if (condición) {
    // Código que se ejecuta si la condición es verdadera
}
*/
// verifica si un usuario es mayor de edad y depiendiendo de la edade lo dejas entrar a la fiesta
#include <iostream>

using namespace std;

int main()
{
  int edad;
  cout << "ingesa tu edad: ";
  cin >> edad;

  if (edad >= 18 && edad <= 60)
  {
    cout << "eres mayor de edad, puedes entrar a la fiesta" << endl; 
  
  } 
  else if (edad > 60){
    cout << "no puedes entrar a la fiesta, solo se permiten personas entre los 18 y 60" << endl;

 }
  else{
    cout << "eres menor de edad, no puedes ingresar a la fiesta: " << endl;
  }

  // verifica si un número está en un rango de 1 a 100
  int numero;
  cout << "ingresa un número: ";
  cin >> numero; 

  if (numero >= 1 && numero <= 100){
    cout << "el número está en el rango de 1 a 100" << endl;
  }
  else{
    cout << "Número fuera del rango de 1 a 100" << endl;
  }


  // veridica si un número es positivo, negativo o ceroi
  int num;
  cout << "numero: ";
  cin >> num;

  if (num > 0){
    cout << "El nñumero es positivo" << endl;

  }
  else if (num < 0){
    cout << "El número es negativo" << endl;

  }
  else{
    cout << "El número es cero" << endl;
  }

  return 0;
}