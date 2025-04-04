
/* Ejercicio 26. Escriba un programa que pida tres números e imprima el tipo de triangulo (isósce-
les, equilátero, escaleno) que se formaría, si sus lados tienen la longitud definida por los números
ingresados. Tenga en cuenta el caso en que los números ingresados no forman un triángulo.
Ej: si se ingresan 3, 3 y 5 se debe imprimir:
Se forma un triangulo isosceles.
y si se ingresan 3, 3 y 6 se debe imprimir:
Las longitudes ingresadas no forman un triangulo.*/

#include <iostream>
using namespace std;

int main()
{
  int num1, num2, num3;

  cout << "Ingrese el primer número: ";
  cin >> num1;

  cout << "Ingrese el segundonúmero: ";
  cin >> num2;

  cout << "Ingrese el tercer número: ";
  cin >> num3;

  if (num1 + num2 > num3 & num1 + num3 > num2 &  num2 + num3 > num1){

    if(num1 == num2 & num2 == num3){
      cout << num1 << "," << num2 << "," << num3 << " Forman un triangulo Equilatero" << endl;
    }
    else if (num1 == num2 || num1 == num3 || num2 == num3 ){
      cout << num1 << "," << num2 << "," << num3 << " Forman un triangulo Isósceles: " << endl;

    }
    else {
      cout << num1 << "," << num2 << "," << num3 << " Forman un triangulo Escaleno: " << endl;
    }
  
    
  }
  else {
    cout << num1 << "," << num2 << "," << num3 << " no forman un triangulo " << endl;
  }

return 0;;

}
