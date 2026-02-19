#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string op;
string text;
char c;
bool ciclo = true;
void imp(string texto);
//variables para detectar lo los caracteres
int Vol (string &text);
int Cons(string &text);
int Pal(string &text);
int Num (string &text);

int main () {
    imp("este programa solicita que el usuario ingrese");
    imp("una cadena de texto para ser analizada");
    imp("lo que analizara sera:");
    imp("-Total de caracteres (incluyendo espacios).");
    imp("-Cantidad de vocales, tanto mayúsculas como minúsculas.");
    imp("-Cantidad de consonantes, palabras y numeros (si es que ahi)");

    while (ciclo) {
        imp("Introduce una palabra u oración ");
        getline (cin, text);
        cout << "Vocales: " << Vol(text) << endl;
        cout << "Consonantes: " << Cons(text) << endl;
        cout << "Palabras: " << Pal(text) << endl;
        cout << "Numeros: " << Num(text) << endl;
        cout << "El total de caracteres: " << text.length();
        // text.length lee el total de caracteres junto al espacio
        //es de la libreria de string

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

//definicion de funciones
void imp(string text) {
    cout << text << endl;
}
//funcion para detectar las vocales (con mayusculas y minusculas)
int Vol(string &text) {
    int vocales = 0;

    for (char c : text) {
        c = tolower(c); //es para convertir mayusculas a minusculas
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
            vocales++;
        }
    }
    return vocales;
}
//funcion para detectar consonantes
int Cons(string &text) {
    int consonantes = 0;

    for (char c : text) {
        c = tolower(c);
        if (isalpha(c)){//detecta que sea letra
            if(c!='a'&& c!='e'&& c!='i'&& c!='o'&& c!='u') {
                consonantes++;
            }
        }
    }
    return consonantes;
}
//funcion para detectar las palabras
int Pal(string &text) {
    int palabras = 0;
    bool dentro = false;

    for (char c : text) {
        if (!isspace(c) && !dentro) { //es para saber si es espacio
            palabras++;
            dentro = true;
        } else if (isspace(c)) {
            dentro = false;
        }
    }
    return palabras;
}

//funcion para detectar los numeros
int Num (string &text) {
    int numeros = 0;

    for (char c : text) {

        if(isdigit(c)){ //cuenta los numeros si es que tiene
        numeros++;
        }
    }
    return numeros;
}
