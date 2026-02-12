/* datos de identificacion*/

//biblioteca de funciones = libreria
#include <iostream>
#include <string>
using namespace std;

int main() {
    bool ciclo = true;
    string opcion;
    int num = 0, contador;

    cout << "Introduccion al programa:\n";
    cout << "Este programa aumenta numeros de 5 en 5 (0 a 500)\n";
    cout << "y de 10 en 10 (500 a 1000)\n\n";

    while (ciclo) {
        contador = 0;

        cout << "Introduce un numero: ";
        cin >> num;

        while (cin.fail()) { //aceptar solo numeros
            cin.clear();                // limpia el error
            cin.ignore(1000, '\n');     // borra letras o simbolos
            cout << "Error. Ingresa SOLO numeros: ";
            cin >> num;
        }

        if (num <= 0 || num >= 1000) {
            cout << "No puedo calcular ese valor" << endl;
        }
        else if (num > 0 && num < 500) {
            for (int i = 0; i < 100; i++) {
                cout << num << "\t";
                num += 5;
                contador++;
            }
            cout << endl;
        }
        else { // entre 500 y 999
            for (int i = 0; i < 50; i++) {
                cout << num << "\t";
                num += 10;
                contador++;
            }
            cout << endl;
        }

        if (contador > 1) {
            cout << "Tu operacion termino en " << contador << " ciclos" << endl;
        }

        cout << "Presiona N para salir o cualquier tecla para continuar: ";
        cin >> opcion;

        if (opcion == "N" || opcion == "n") {
            cout << "Thanks for using my program, bye bye!" << endl;
            ciclo = false;
        }
    }

    return 0;
}
