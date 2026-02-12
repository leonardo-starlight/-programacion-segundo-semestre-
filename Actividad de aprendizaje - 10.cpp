#include <iostream>
#include <string>
using namespace std;

string op;
int N;
bool ciclo = true;
void imp(string texto);
void sumMultiplos(int N, int &suma3, int &suma5);
//variables globales
int suma3 = 0;
int suma5 = 0;

int main () {
    imp("Este programa crea 2 sumas de los multiplos del numero que escribas");
    imp("La suma seran de los multiplos de 3 y 5 de ese numero");
    imp("Cada suma estara separada y dara su resultado");

    while (ciclo) { //ciclo para la suma de multiplos
        imp("Introduce un numero entre 0 y 1000: ");
        cin >> N;

        while (cin.fail() || N < 0 || N >= 1000) {
            cin.clear();
            cin.ignore(1000, '\n');

            imp("Error. ingresa un valor valido");
            imp("El numero debe estar entre 0 y 1000: ");
            cin >> N;
        }

        sumMultiplos(N, suma3, suma5);

        imp("las sumas son:"); //mostrar resultados
        cout << "Suma de multiplos de 3: " << suma3 << endl;
        cout << "Suma de multiplos de 5: " << suma5 << endl;

        imp("\nPresiona N para salir o cualquier tecla para continuar: ");
        cin >> op;

        if (op == "N" || op == "n") {
            cout << "Thanks for using my program, bye bye!" << endl;
            ciclo = false;
        }

    } //fin del ciclo

} //fin del int

//definicion de funciones
void imp(string texto){
    cout << texto << endl;
}
//funcion para la suma de multiplos de 3 y 5
void sumMultiplos(int N, int &suma3, int &suma5) {

    for (int i = 1; i <= N; i++) {

        if (i % 3 == 0) {
            suma3 += i;
        }

        if (i % 5 == 0) {
            suma5 += i;
        }
    }
}