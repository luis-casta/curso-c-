
/*Problema 3. Escriba un programa que debe leer un mes y un día de dicho mes para luego decir
si esa combinación de mes y día son válidos. El caso más especial es el 29 de febrero, en dicho caso
imprimir posiblemente año bisiesto.
Nota: el formato de salida debe ser:
14 es un mes invalido.
31/4 es una fecha invalida.
27/4 es una fecha valida.
29/2 es valida en bisiesto.*/

#include <iostream>

using namespace std;

int main()
{
  int mes, dia;
  char separador;

  cout << "Ingrese una fecha en formato (dia/mes): ";
  cin >> dia >> separador >> mes;

  if (mes < 1 || mes > 12)
  {

    cout << "ES un mes invalido" << endl;
    return 0;
  }

  bool fechavalida = false;
  bool bisiesto = false;

  if (mes == 2)
  {
    if (dia >= 1 && dia <= 28)
    {
      fechavalida = true;
    }
    else if (dia == 29)
    {
      bisiesto = true;
      fechavalida = true;
    }
  }
  else if (mes == 4 || mes == 6 || mes == 11)
  {

    if (dia >= 1 && dia <= 30)
    {
      fechavalida = true;
    }
  }
  else
  {
    if (dia >= 1 && dia <= 31)
    {
      fechavalida = true;
    }
  }

  if (fechavalida == true)
  {

    if (bisiesto == true)
    {

      cout << dia << "/" << mes << " posiblemenete año bisiesto" << endl;
    }
    else
    {
      cout << dia << "/" << mes << " ES una fecha valida" << endl;
    }
  }
  else
  {
    cout << dia << "/" << mes << " Es una fecha invalida" << endl;
  }

  return 0;
}
