#include <iostream>
#include <string>
using namespace std;

string op;
int N;

void esprimo (int N, int &suma);
bool ciclo = true;
void imp(string texto);
//variable global
int suma = 0;

int main () {
    imp("Este programa crea una suma de los numeros primos del numero que colocaste");
    imp("Se mostraran los numeros primos y el resultado de su suma");

    while (ciclo) { //ciclo para la suma de primos
        imp("Introduce un numero mayor a 2");
        cin >> N;

        while (cin.fail() || N < 2) {
            cin.clear();
            cin.ignore(1000, '\n');

            imp("Error. ingresa un valor valido");
            imp("El numero debe ser mayor a 2");
            cin >> N;
        }


        esprimo (N,suma);

        imp("las suma de los primos es:"); //mostrar resultados
        cout << suma << endl;
        imp("\nPresiona N para salir o cualquier tecla para continuar: ");
        cin >> op;

        if (op == "N" || op == "n") {
            cout << "gracias por usar mi codigo!!" << endl;
            ciclo = false;
        }
    }//fin del ciclo
}//fin del int

//definicion de funciones
void imp(string texto) {
    cout << texto << endl;
}
//funcion para la suma de primos 
void esprimo (int N, int &suma) {

    for (int i = 2; i <= N; i++) {
        bool primo = true;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                primo = false;
                break;
            }
        }

        if (primo) {
             cout << i << " + ";
            suma += i;
        }
    }
}