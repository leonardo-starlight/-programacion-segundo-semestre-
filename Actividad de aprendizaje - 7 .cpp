#include <iostream>
using namespace std;

int numero;
int main() {

    do {
        cout << "Introduce un numero (0 es para salir): ";
        cin >> numero;

        if (numero == 0) {
            cout << "Programa terminado." << endl;
        }
        else if (numero > 0 && numero < 500) {
            for (int i = 0; i < 100; i++) {
                numero += 5;
                cout << numero << endl;
            }
        }
        else if (numero >= 500 && numero < 1000) {
            for (int i = 0; i < 50; i++) {
                numero += 10;
                cout << numero << endl;
            }
        }
        else {
            cout << "No se puede calcular el valor" << endl;
        }

    } while (numero != 0);

    return 0;
}
