#include <iostream>
#include <string>
using namespace std;

int main() {
    bool cicloPro = true;
    string op;
    int num, lim, tipoCiclo;

    cout << "=== PROGRAMA DE SERIES ===\n\n";

    while (cicloPro) {

        // Numero inicial
        cout << "Introduce el numero inicial: ";
        cin >> num;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error. Ingresa SOLO numeros: ";
            cin >> num;
        }

        // Valor limite
        cout << "Introduce el valor limite: ";
        cin >> lim;
        while (cin.fail() || lim <= num) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error. El limite debe ser mayor al numero inicial: ";
            cin >> lim;
        }

        // Elegir ciclo
        cout << "\nElige el ciclo a usar:\n";
        cout << "1. for\n";
        cout << "2. while\n";
        cout << "3. do-while\n";
        cout << "Opcion: ";
        cin >> tipoCiclo;

        while (cin.fail() || tipoCiclo < 1 || tipoCiclo > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Opcion invalida. Elige 1, 2 o 3: ";
            cin >> tipoCiclo;
        }

        cout << "\ntu serie fibonacci es:\n";

        int a= 0, b= 1, c;

        // ===== CICLO FOR =====
        if (tipoCiclo == 1) {
            for (; a <= lim;) {
                cout << a << "\t";
                c= a + b;
                a = b;
                b = c;
            }
        }

        // ===== CICLO WHILE =====
        else if (tipoCiclo == 2) {
            while (a <= lim) {
                cout << a << "\t";
                c= a + b;
                a = b;
                b = c;
            }
        }

        // ===== CICLO DO-WHILE =====
        else {
            do {
                cout << a << "\t";
                c= a + b;
                a = b;
                b = c;
            } while (a <= lim);
        }

        cout << "\n\nDeseas salir? (N/n para salir, otra tecla para continuar): ";
        cin >> op;

        if (op == "N" || op == "n") {
            cout << "Terminaste el programa, hasta luego!!\n";
            cicloPro = false;
        }
    }

    return 0;
}
