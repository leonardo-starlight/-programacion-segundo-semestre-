#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void imp(string text);
void mostrarMenu();
void pedirTamaño();
void manual();
void aleatorio();
void mostrarMatriz();
void analizarPropiedades();
void pausa();

//variables globales
int matriz1[10][10];
int filas = 0;
int columnas = 0;

int main() {

    srand(time(0));//ayuda a que siempre tengamos diferentes convinaciones aleatorias

    imp("Este programa solicita que ingreses una matriz cuadrada");
    imp("mostrara si la matriz es:");
    imp("Reflexiva, simetrica, antisimetrica y transitiva");
    imp("tambien demuestra si es relacion equivalente o de orden parcial");

    int opcion;

    do {
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
                manual();
                mostrarMatriz();
                analizarPropiedades();
                pausa();
                break;

            case 2:
                aleatorio();
                mostrarMatriz();
                analizarPropiedades();
                pausa();
                break;

            case 3:
                imp("Programa terminado");
                break;

            default:
                imp("Opcion no valida");
                pausa();
        }

    } while(opcion != 3);

    return 0;
}//fin del main

void imp(string text){
    cout<<text<<endl;
}

void mostrarMenu(){

    imp("\n--- METODO DE LLENADO ---");
    imp("1. Llenado manual");
    imp("2. Llenado aleatorio");
    imp("3. Salir");

    cout<<"Seleccione opcion: ";
}

void pedirTamaño(){

    do{
        cout<<"Filas (1-10): ";
        cin>>filas;
    }while(filas<1 || filas>10);

    columnas = filas; // matriz cuadrada
}

void manual(){

    pedirTamaño();

    imp("Ingrese valores (solo 0 o 1):");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){

            while(true){

                cout<<"["<<i<<"]["<<j<<"]: ";
                cin>>matriz1[i][j];

                if(cin.fail()){
                    imp("Error: solo se permiten numeros.");
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
                else if(matriz1[i][j]!=0 && matriz1[i][j]!=1){
                    imp("Error: solo se permite 0 o 1.");
                }
                else{
                    break;
                }

            }

        }
    }
}

void aleatorio(){

    pedirTamaño();

    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            matriz1[i][j]=rand()%2;

    imp("Matriz llenada aleatoriamente.");
}

void mostrarMatriz(){

    imp("\nMatriz:");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<" "<<matriz1[i][j]<<" ";
        }
        cout<<endl;
    }
}

void analizarPropiedades(){

    bool reflexiva=true;
    bool simetrica=true;
    bool antisimetrica=true;
    bool transitiva=true;

    // REFLEXIVA
    for(int i=0;i<filas;i++)
        if(matriz1[i][i]!=1)
            reflexiva=false;

    // SIMETRICA
    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            if(matriz1[i][j]!=matriz1[j][i])
                simetrica=false;

    // ANTISIMETRICA
    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            if(i!=j && matriz1[i][j]==1 && matriz1[j][i]==1)
                antisimetrica=false;

    // TRANSITIVA
    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            for(int k=0;k<columnas;k++)
                if(matriz1[i][j]==1 && matriz1[j][k]==1 && matriz1[i][k]!=1)
                    transitiva=false;

    imp("\n--- PROPIEDADES ---");

    cout<<"Reflexiva: "<<(reflexiva ? "SI":"NO")<<endl;
    cout<<"Simetrica: "<<(simetrica ? "SI":"NO")<<endl;
    cout<<"Antisimetrica: "<<(antisimetrica ? "SI":"NO")<<endl;
    cout<<"Transitiva: "<<(transitiva ? "SI":"NO")<<endl;

    imp("\n--- CLASIFICACION ---");

    if(reflexiva && simetrica && transitiva)
        imp("Es una RELACION DE EQUIVALENCIA");

    else if(reflexiva && antisimetrica && transitiva)
        imp("Es un ORDEN PARCIAL");

    else
        imp("No es relacion de equivalencia ni orden parcial");
}

void pausa(){
    imp("\nPresione ENTER para continuar...");
    cin.get();
}