#include <iostream>
#include <string>
using namespace std;

string op;
string limpiar(string texto);
string invertir(string texto);
void imp(string texto);
bool ciclo = true;
bool esNumero(string texto);
bool esPalindromo(string texto);

int main() {
    imp("Este programa determina si una secuencia de caracteres");
    imp("que se lea igual de derecha a izquierda o viceversa");
    imp("si es texto reconoce si es un palíndromo");
    imp("si son numeros reconoce si es un número capicúa\n");

    while (ciclo) {
        string entrada;

        cout << "Ingrese una cadena de texto o una secuencia numerica:\n";
        getline(cin, entrada);

        string limpia = limpiar(entrada);
        string invertida = invertir(limpia);

        cout << "Cadena invertida: " << invertida << endl;

        if (esNumero(limpia)) {
            if (esPalindromo(limpia)) {
                cout << "Es un numero capicua." << endl;
            } else {
                cout << "No es un numero capicua." << endl;
            }
        }
        else {
            if (esPalindromo(limpia)) {
                cout << "Es un palindromo." << endl;
            } else {
                cout << "No es un palindromo." << endl;
            }
        }
        imp("\nPresiona N para salir o Y para continuar: ");
        cin >> op;
        cin.ignore();

        if (op == "N" || op == "n") {
            cout << "Thanks for using my program, bye bye!" << endl;
            ciclo = false;
        }
        else if (op == "Y" || op == "y") {
            ciclo = true; // realmente no es necesario, ya está en true
        }
        else {
            cout << "Opcion no valida, se continuara..." << endl;
        }
    }//fin del ciclo
}//fin del main

// Funcion para limpiar: quitar espacios y convertir a minusculas
string limpiar(string texto) {
    string resultado = "";

    for (int i = 0; i < texto.length(); i++) {

        char c = texto[i];

        // convertir mayuscula a minuscula manualmente
        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }

        // eliminar espacios
        if (c != ' ') {
            resultado += c;
        }
    }

    return resultado;
}
//definicion de funciones
void imp(string text) {
    cout << text << endl;
}
// Funcion para invertir la cadena manualmente
string invertir(string texto){
    string invertida = "";

    for (int i = texto.length() - 1; i >= 0; i--) {
        invertida += texto[i];
    }

    return invertida;
}

// Funcion para verificar si es numero
bool esNumero(string texto) {

    if (texto.length() == 0) return false;

    for (int i = 0; i < texto.length(); i++) {
        if (texto[i] < '0' || texto[i] > '9') {
            return false;
        }
    }

    return true;
}

// Funcion para verificar si es palindromo
bool esPalindromo(string texto) {

    string invertida = invertir(texto);

    if (texto == invertida) {
        return true;
    } else {
        return false;
    }
}