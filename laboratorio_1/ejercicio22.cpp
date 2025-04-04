
/* Ejercicio 22. Escriba un programa que pida una cantidad entera de segundos y la imprima en
formato horas:minutos:segundos.
Ej: si se ingresa 7777 se debe imprimir:
2:9:37*/

#include <iostream>
using namespace std;

int main()
{
   int segundos, minutos, horas;

   cout << "Ingrese los segundos: ";
   cin >> segundos;

   horas = segundos / 3600;
   segundos = segundos % 3600;

   minutos = segundos / 60;
   segundos = segundos % 60;

   cout << horas << " horas, " << minutos << " minutos, " << segundos << " segundos." << endl;
  
  return 0;
}
