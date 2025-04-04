
// Datos derivados 
/*
  Datos Derivados
En C++, los "datos derivados" pueden referirse a datos que son el resultado de una operación o transformación, como el cálculo de valores a partir de otros datos. Estos datos derivados también pueden ser objetos o valores que se derivan de una clase base a través de la herencia, en el contexto de la Programación Orientada a Objetos (POO).
*/

/*/
    Dato Derivado por Herencia (POO)
Definición: Un dato derivado es una clase que hereda de otra clase (clase base) y extiende su funcionalidad.
*/
class Animal {
 public:
     void sonido() { cout << "Sonido genérico." << endl; }
 };
 
 class Perro : public Animal {
 public:
     void sonido() { cout << "Ladra." << endl; }
 };
 
 int main() {
     Perro p;
     p.sonido();  // Llama al método de la clase derivada
 }

 /*
  Dato Derivado por Cálculos
Definición: Un dato derivado es un valor calculado a partir de otros datos.
 */
int calcularSuma(int a, int b) {
 return a + b;  // La suma es un dato derivado
}

int main() {
 int resultado = calcularSuma(5, 3);
}

/*
  Dato Derivado por Punteros
Definición: Un dato derivado es un valor que se manipula a través de punteros o referencias.
*/
void incrementar(int* p) { *p = *p + 1; }

int main() {
    int x = 5;
    incrementar(&x);  // El valor de x se modifica a través de un puntero
}
