#include <iostream>
#include <string>
using namespace std;

int main() {
    bool ciclo = true;
    string op;
    int N, cua, conta;

    while (ciclo) {
        cua = 0;
        conta = 0;

        cout << "Ingresa el numero que deseas usar:\n";
        cin >> N;

        while (cin.fail() || N <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error. Ingresa un numero valido: ";
            cin >> N;
        }

        cout << "\nCuadrados: ";

        for (int i = 1; i <= N; i++) {
            int cuadrado = i * i;
            cout << i << cuadrado;

            cua += cuadrado;
            conta++;

            if (i < N) {
                cout << " + ";
            }
        }

        cout << "\nLa suma de los cuadrados es: " << cua << endl;

        cout << "\nPresiona N para salir o cualquier tecla para continuar: ";
        cin >> op;

        if (op == "N" || op == "n") {
            cout << "Thanks for using my program, bye bye!" << endl;
            ciclo = false;
        }
    }

}
