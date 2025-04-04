
#include <iostream>
#include <cmath> 
#include <iomanip>

using namespace std;

int main(){

  // funcion max(), devuelve el mayor de dos números, solo puede compara 2 números a la vez 
  int a = 7, b = 30;
  int numeroMayor; 

  numeroMayor = max(a,b);
  cout << "función max()" << endl;
  cout <<  "El número mayor es: " << numeroMayor << endl;

  // función min(), devuelve el menor entre dos numeros
  int x = 7, y = 30;
  int numeroMenor = min(x,y);

  cout << "función min()" << endl;
  cout << "el número menor es: " << numeroMenor << endl;


  // funcion pow() elevar una base a un exponente dado (sirve para potencias )
  int base = 5, exponente = 3;
  int potencia = pow(base, exponente);

  cout << "función pow()" << endl;
  cout << 5 << "^" << 3 << " = " << potencia << endl;


  // función sqrt(), nos permite calcular la raiz cuadrada
  int numero;
  
  cout << "ingrese un número: "; 
  cin >> numero;

  double raiz = sqrt(numero);

  cout << "función sqrt()" << endl;
  cout << "La raíz cuadrada de " << numero << " es: " << fixed << setprecision(2) << raiz << endl;


  // funcion abs() devuelve el valor absoluto
  int num1; 

  cout << "Ingresa un número: ";
  cin >> num1;

  int absoluto = abs(num1);

  cout << "Función abs()" << endl;
  cout << "el valor absoluto de " << num1 << " es: " << absoluto << endl;


  // función round() redondea un decimal al entero más cercano
  double z;

  cout << "ingresa un número decimal: ";
  cin >> z;

  double resultado = round(z);

  cout << "función round()" << endl;
  cout << "número " << z << " redondeado: " << resultado << endl;

  // función ceil() redondea un número hacia arriba 
  double decimal;

  cout << "ingresa un número decuimal: ";
  cin >> decimal;

  double redondearArriba = ceil(decimal);

  cout << "función ceil()" << endl;
  cout << "número: " << decimal << " redondeado hacia aarriba: " << redondearArriba << endl;


  // función floor() redondea hacia abajo 
  double decimal2;
   
  cout << "ingresa un número decuimal: ";
  cin >> decimal2;

  double  redondeaAbajo = floor(decimal2); 

  cout << "función floor()" << endl;
  cout << "número: " << decimal2 << " redondeado hacia aarriba: " << redondeaAbajo << endl;








  



  return 0;
}