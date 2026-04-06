#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void imp(string text);
void manual(int matriz[10][10]);
void aleatorio(int matriz[10][10]);
void mostrarMenu();
void menuOperaciones();
void pausa();
void mostrarMatriz();
void suma();
void resta();
void multiplicacion();
void division();

// Variables globales
int matriz1[10][10];
int matriz2[10][10];
int filas = 0;
int columnas = 0;

int main() {

    imp("Este programa permite hacer operaciones con dos matrices cuadradas");
    imp("El usuario determina el tamaño de la matriz");
    imp("Tambien escoge si el llenado es manual o aleatorio");

    srand(time(0));

    int opcion;
    int operacion;

    // MENU DE LLENADO
    mostrarMenu();

    while(true) {
        cin >> opcion;

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

    switch(opcion) {

        case 1:
            imp("Llenado de la matriz 1");
            manual(matriz1);

            imp("Llenado de la matriz 2");
            manual(matriz2);
            break;

        case 2:
            imp("Llenado de la matriz 1");
            aleatorio(matriz1);

            imp("Llenado de la matriz 2");
            aleatorio(matriz2);
            break;

        case 3:
            return 0;
    }

    // MENU DE OPERACIONES
    do {
         menuOperaciones();

        while(true) {
            cin >> operacion;

            if(cin.fail()) {
                imp("Error: Solo se permiten numeros.");
                cin.clear();
                cin.ignore(1000,'\n');
            }
            else {
                cin.ignore(1000,'\n');
                break;
            }
        }

        switch(operacion) {

            case 1:
                suma();
                break;

            case 2:
                resta();
                break;

            case 3:
                multiplicacion();
                break;

            case 4:
                division();
                break;
        }

        pausa();

    } while(operacion != 5);

}

// FUNCIONES

void imp(string text) {
    cout << text << endl;
}

void mostrarMenu() {

    imp("\n--- METODO DE LLENADO ---");
    imp("1. Llenado manual");
    imp("2. Llenado aleatorio");
    imp("3. Salir");

    cout << "Seleccione una opcion:\n ";
}

void menuOperaciones() {

    imp("\n--- OPERACIONES ---");
    imp("1. Sumar matrices");
    imp("2. Restar matrices");
    imp("3. Multiplicar matrices");
    imp("4. Division escalar");
    imp("5. Salir");

    cout << "Seleccione una opcion:\n ";
}

void pausa() {

    cout << "\nPresione ENTER para continuar...";
    cin.ignore(1000,'\n');
    cin.get();
}

// LLENADO MANUAL
void manual(int matriz[10][10]) {

    if(filas == 0) {

        while(true) {
            cout << "Ingrese numero de filas (1-10): ";
            cin >> filas;

            if(cin.fail()) {
                imp("Error: Solo numeros.");
                cin.clear();
                cin.ignore(1000,'\n');
            }
            else if(filas <=0 || filas >10) {
                imp("Error: Tamaño invalido.");
                cin.ignore(1000,'\n');
            }
            else {
                cin.ignore(1000,'\n');
                break;
            }
        }

        while(true) {
            cout << "Ingrese numero de columnas (1-10): ";
            cin >> columnas;

            if(cin.fail()) {
                imp("Error: Solo numeros.");
                cin.clear();
                cin.ignore(1000,'\n');
            }
            else if(columnas <=0 || columnas >10) {
                imp("Error: Tamaño invalido.");
                cin.ignore(1000,'\n');
            }
            else {
                cin.ignore(1000,'\n');
                break;
            }
        }
    }

    int opcion;

    for(int i=0;i<filas;i++) {
        for(int j=0;j<columnas;j++) {

            while(true) {

                cout << "\nPosicion ["<<i<<"]["<<j<<"]\n";
                cout << "1. Ingresar manual\n";
                cout << "2. Generar aleatorio\n";
                cout << "3. Saltar posicion\n";
                cout << "Seleccione opcion: ";

                cin >> opcion;

                if(cin.fail()) {
                    imp("Error: Solo numeros.");
                    cin.clear();
                    cin.ignore(1000,'\n');
                    continue;
                }

                if(opcion == 1) {

                    cout<<"Ingrese valor: ";

                    while(true){

                        cin>>matriz[i][j];

                        if(cin.fail()){
                            imp("Solo numeros.");
                            cin.clear();
                            cin.ignore(1000,'\n');
                        }
                        else{
                            break;
                        }

                    }

                    break;

                }
                else if(opcion == 2) {

                    matriz[i][j] = rand()%201 - 100;
                    cout<<"Valor generado: "<<matriz[i][j]<<endl;
                    break;

                }
                else if(opcion == 3) {

                    matriz[i][j] = 0;
                    break;

                }
                else {

                    imp("Opcion invalida.");
                }

            }

        }
    }

    imp("Matriz llenada correctamente.");
}

// LLENADO ALEATORIO
void aleatorio(int matriz[10][10]) {

    if(filas == 0) {

        while(true){

            cout<<"Ingrese numero de filas (1-10): ";
            cin>>filas;

            if(filas>0 && filas<=10) break;

            imp("Tamaño invalido.");
        }

        while(true){

            cout<<"Ingrese numero de columnas (1-10): ";
            cin>>columnas;

            if(columnas>0 && columnas<=10) break;

            imp("Tamaño invalido.");
        }
    }

    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            matriz[i][j] = rand()%201 - 100;

    imp("Matriz llenada aleatoriamente.");
}

// MOSTRAR MATRICES
void mostrarMatriz() {

    imp("\nMATRIZ 1");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++)
            cout<<matriz1[i][j]<<"\t";
        cout<<endl;
    }

    imp("\nMATRIZ 2");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++)
            cout<<matriz2[i][j]<<"\t";
        cout<<endl;
    }
}

// SUMA
void suma() {

    mostrarMatriz();

    int resultado[10][10];

    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];

    imp("\nRESULTADO SUMA");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++)
            cout<<resultado[i][j]<<"\t";
        cout<<endl;
    }
}

// RESTA
void resta() {

    mostrarMatriz();

    int resultado[10][10];

    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];

    imp("\nRESULTADO RESTA");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++)
            cout<<resultado[i][j]<<"\t";
        cout<<endl;
    }
}

// MULTIPLICACION
void multiplicacion() {

    mostrarMatriz();

    int resultado[10][10];

    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++){

            resultado[i][j] = 0;

            for(int k=0;k<columnas;k++)
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
        }

    imp("\nRESULTADO MULTIPLICACION");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++)
            cout<<resultado[i][j]<<"\t";
        cout<<endl;
    }
}

// DIVISION ESCALAR
void division() {

    mostrarMatriz();

    float escalar;
    int opcion;

    cout<<"Seleccione matriz (1 o 2): ";
    cin>>opcion;

    if(opcion!=1 && opcion!=2){
        imp("Opcion invalida.");
        return;
    }

    cout<<"Ingrese escalar: ";
    cin>>escalar;

    if(escalar==0){
        imp("No se puede dividir entre 0");
        return;
    }

    imp("\nRESULTADO");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){

            if(opcion==1)
                cout<<matriz1[i][j]/escalar<<"\t";
            else
                cout<<matriz2[i][j]/escalar<<"\t";

        }
        cout<<endl;
    }
}