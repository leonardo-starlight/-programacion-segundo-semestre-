#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void imp(string text);
void mostrarMenu();
void manual();
void aleatorio();
void mostrarMatriz();
void pausa();

// Variables globales
int matriz[10][10];
int filas = 0;
int columnas = 0;

int main() {

    imp("Este programa permite gestionar una matriz cuadrada");
    imp("El usuario determina el tamaño de la matriz");
    imp("Tambien escoge si el llenado es manual o aleatorio");
    imp("Por ultimo muestra la matriz creada");

    srand(time(0));//ayuda a siempre dar las variables aleatorias

    int opcion;

    do {
        mostrarMenu();

        // VALIDAR OPCION
        while(true) {
            cin >> opcion;

            if(cin.fail()) {
                imp("Error: Solo se permiten numeros.");
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                cin.ignore(1000, '\n'); // limpiar ENTER
                break;
            }
        }

        switch(opcion) {
            case 1:
                manual();
                pausa();
                break;
            case 2:
                aleatorio();
                pausa();
                break;
            case 3:
                mostrarMatriz();
                pausa();
                break;
            case 4:
                imp("Programa terminado");
                break;
            default:
                imp("Opcion no valida");
                pausa();
        }

    } while(opcion != 4);

    return 0;
}//fin del main

//declaracion de funciones

void imp(string text) {
    cout << text << endl;
}

void mostrarMenu() {
    imp("\n--- MENU ---");
    imp("1. Llenado manual");
    imp("2. Llenado aleatorio");
    imp("3. Mostrar matriz");
    imp("4. Salir");
    cout << "Seleccione una opcion: ";
}

//funcion para el manual
void manual() {

    // VALIDAR FILAS
    while(true) {
        cout << "Ingrese numero de filas (1-10): ";
        cin >> filas;

        if(cin.fail()) {
            imp("Error: Solo se permiten numeros.");
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(filas <= 0 || filas > 10) {
            imp("Error: Tamaño invalido (1 a 10).");
            cin.ignore(1000, '\n');
        }
        else {
            cin.ignore(1000, '\n');
            break;
        }
    }

    // VALIDAR COLUMNAS
    while(true) {
        cout << "Ingrese numero de columnas (1-10): ";
        cin >> columnas;

        if(cin.fail()) {
            imp("Error: Solo se permiten numeros.");
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(columnas <= 0 || columnas > 10) {
            imp("Error: Tamaño invalido (1 a 10).");
            cin.ignore(1000, '\n');
        }
        else {
            cin.ignore(1000, '\n');
            break;
        }
    }

    // LLENADO MANUAL
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {

            while(true) {
                cout << "Ingrese valor [" << i << "][" << j << "]: ";
                cin >> matriz[i][j];

                if(cin.fail()) {
                    imp("Error: Solo se permiten numeros.");
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else {
                    cin.ignore(1000, '\n');
                    break;
                }
            }
        }
    }

    imp("Se lleno la matriz correctamente.");
}

//funcion para el random
void aleatorio() {

    // VALIDAR FILAS
    while(true) {
        cout << "Ingrese numero de filas (1-10): ";
        cin >> filas;

        if(cin.fail()) {
            imp("Error: Solo se permiten numeros.");
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(filas <= 0 || filas > 10) {
            imp("Error: Tamaño invalido (1 a 10).");
            cin.ignore(1000, '\n');
        }
        else {
            cin.ignore(1000, '\n');
            break;
        }
    }

    // VALIDAR COLUMNAS
    while(true) {
        cout << "Ingrese numero de columnas (1-10): ";
        cin >> columnas;

        if(cin.fail()) {
            imp("Error: Solo se permiten numeros.");
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(columnas <= 0 || columnas > 10) {
            imp("Error: Tamaño invalido (1 a 10).");
            cin.ignore(1000, '\n');
        }
        else {
            cin.ignore(1000, '\n');
            break;
        }
    }

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 201 - 100;
        }
    }

    imp("Se creo tu matriz correctamente.");
}

//funcion para matriz
void mostrarMatriz() {

    if(filas == 0 || columnas == 0) {
        imp("Primero debes llenar la matriz.");
        return;
    }

    cout << "\nMatriz actual:\n";

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

//funcion para la pausa
void pausa() {
    cout << "\nPresiona ENTER para volver al menu...";
    cin.get();
}