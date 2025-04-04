
/*Ejercicio: Registro detallado de datos personales
Escribe un programa en C++ que solicite al usuario los siguientes datos personales:
 Nombre completo
 Edad (en años)
 Peso (en kilogramos con decimales)
 Altura (en metros con dos decimales)
 Género (Masculino/Femenino/Otro)
 Ocupación (Ejemplo: estudiante, ingeniero, médico, etc.)
 País de residencia

Después de leer los datos, el programa debe mostrar toda la información en un formato organizado.*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
  string nombre, genero, ocupacion, pais;
  int edad; 
  double peso, estatura;
  
  cout << "Nombre Completo: "; getline(cin, nombre);
  cout << "Edad: "; cin >> edad;
  cout << "Peso: "; cin >> peso;
  cout << "Altura: "; cin >> estatura;
  cout << "Género: "; cin >> genero; 
  cout << "Ocupación: "; cin >> ocupacion;
  cout << "Pais: "; cin >> pais;

  cout << "Nombre: " << nombre << endl;
  cout << "Edad: " << edad << endl;
  cout << "Peso: " << fixed << setprecision(2) << peso << endl;
  cout << "Altura: " << fixed << setprecision(2) << endl;
  cout << "Género: " << genero << endl;
  cout << "Ocupación: " << ocupacion << endl;
  cout << "Pais: " << pais << endl; 





  return 0;
}