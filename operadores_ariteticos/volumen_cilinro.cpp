
/*volumen superficial del cilindro:
Escribe un programa en C++ que calcule el volumen  superficial de un cilindro
usando la siguiente formula:
A=2×π×r×(r+h)
Donde:
r es el radio del cilindro
h es la altura
π=3.14159
.*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double radio, altura, volumen = 0;
  const double PI = 3.14;

  cout << "Ingrese el radio: ";
  cin >> radio;
  cout << "Ingrese la altura: ";
  cin >> altura;

  volumen = 2 * PI * radio * (radio + altura);

  cout << "El volumen superficial del cilindro es: " << volumen << setprecision(2) << endl;

  return 0;
}
