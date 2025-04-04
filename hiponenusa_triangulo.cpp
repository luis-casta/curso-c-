
#include <iostream>
#include <cmath>  // Necesario para sqrt()
#include <iomanip>

using namespace std;

int main() {
    double a, b, hipotenusa;

    
    cout << "Ingrese el primer cateto: ";
    cin >> a;
    cout << "Ingrese el segundo cateto: ";
    cin >> b;

    
    hipotenusa = sqrt(pow(a, 2) + pow(b, 2));

    
    cout << "La hipotenusa es: " << fixed << setprecision(2) << hipotenusa << endl;

    return 0;
}
