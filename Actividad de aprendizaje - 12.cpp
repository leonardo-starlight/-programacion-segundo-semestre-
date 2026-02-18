#include <iostream>
#include <chrono>
#include <string>
using namespace std;

string op;
void imp(string texto);
int N;
bool ciclo = true;
void Collatz(int N, int &iteraciones);
//variables globales
int iteraciones = 0;

int main () {
    imp("Este programa cálcula la Conjetura de Collatz.");
    imp("El pograma tiene de limite nuemeros del 1 al 1,000,000");
    imp("imprime la sucecion, su resultado");
    imp("la cantidad de iteraciones resultantes para cada valor dado");
    imp("y el tiempo en el que tarda en hacerlo");

    while (ciclo) { //ciclo para cálcula la Conjetura de Collatz
        imp("Introduce un numero entre 1 y 1,000,000: ");
        cin >> N;

        while (cin.fail() || N < 1 || N >= 1000000) {
            cin.clear();
            cin.ignore(1000, '\n');

            imp("Error. ingresa un valor valido");
            imp("El numero debe estar entre 1 y 1,000,000: ");
            cin >> N;
        }

        auto inicio = chrono::high_resolution_clock::now();

        Collatz(N, iteraciones);
        imp("la secuencia es:"); //mostrar resultados
        cout << iteraciones << endl;

        auto fin = chrono::high_resolution_clock::now();
        auto duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio);

        cout << "Iteraciones: " << iteraciones << endl;
        cout << "Tiempo: " << duracion.count() << "ms" << endl;

        imp("\nPresiona N para salir o cualquier tecla para continuar: ");
        cin >> op;

        if (op == "N" || op == "n") {
            cout << "Thanks for using my program, bye bye!" << endl;
            ciclo = false;
        }
    }
}

//definicion de funciones
void imp(string texto) {
    cout << texto << endl;
}
//funcion para la conjetura
void Collatz(int N, int &iteraciones) {
    while (N != 1) {
        cout << N << " ";

        if (N % 2 == 0)
            N = N / 2;
        else
            N = 3 * N + 1;

        iteraciones++;
    }
    cout << 1 << endl;
}
