
/*Área de un rectangulo: 
 Crea un programa que pida al usuario la base y la altura de un rectangulo y calcule su área 
 usando la formula:
 Area=base×altura


*/
#include <iostream>
#include <iomanip>
using namespace std;  

int main(){
  double base, altura, area = 0; 
  cout << "\n---------- Área del Rectangulo----------- \n";
  cout << "Ingrese el área: "; cin >> altura; 
  cout << "Ingrese la base: "; cin >> base;

  area = base * altura;
  
  cout << "El Área del rectangulo es: " << fixed << setprecision(2) << area <<  endl;





  return 0;
}