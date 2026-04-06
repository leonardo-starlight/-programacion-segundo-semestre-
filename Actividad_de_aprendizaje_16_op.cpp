#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void imp(string text);
void manual(int matriz[10][10]);
void aleatorio(int matriz[10][10]);
void mostrarUnaMatriz(int matriz[10][10]);
void mostrarMenu();
void menuOperaciones();
void pausa();
void mostrarMatriz();
void suma();
void resta();
void multiplicacion();
void division();

int matriz1[10][10];
int matriz2[10][10];
int filas = 0;
int columnas = 0;

int main() {

    imp("Este programa permite hacer operaciones con dos matrices");
    imp("El usuario determina el tamaño de la matriz");
    imp("Tambien escoge si el llenado es manual o aleatorio");

    srand(time(0));
    int opcion, operacion;

    mostrarMenu();

    while(!(cin>>opcion)){
        imp("Error: Solo numeros.");
        cin.clear();
        cin.ignore(1000,'\n');
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

    do{

        menuOperaciones();

        while(!(cin>>operacion)){
            imp("Error: Solo numeros.");
            cin.clear();
            cin.ignore(1000,'\n');
        }

        switch(operacion){

            case 1: suma(); break;
            case 2: resta(); break;
            case 3: multiplicacion(); break;
            case 4: division(); break;

        }

        pausa();

    }while(operacion!=5);

}

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

void menuOperaciones(){

    imp("\n--- OPERACIONES ---");
    imp("1. Sumar matrices");
    imp("2. Restar matrices");
    imp("3. Multiplicar matrices");
    imp("4. Division escalar");
    imp("5. Salir");

    cout<<"Seleccione opcion: ";
}

void pausa(){
    cout<<"\nPresione ENTER para continuar...";
    cin.ignore(1000,'\n');
    cin.get();
}

void pedirTamano(){

    if(filas!=0) return;

    do{
        cout<<"Filas (1-10): ";
        cin>>filas;
    }while(filas<1 || filas>10);

    do{
        cout<<"Columnas (1-10): ";
        cin>>columnas;
    }while(columnas<1 || columnas>10);
}

void manual(int matriz[10][10]){

    pedirTamano();

    int opcion;

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){

            cout<<"\n["<<i<<"]["<<j<<"]\n";
            cout<<"1.Manual\n2.Aleatorio\n3.Saltar\n";
            cout<<"Opcion: ";

            cin>>opcion;

            switch(opcion){

                case 1:
                    cout<<"Valor: ";
                    while(!(cin>>matriz[i][j])){
                        imp("Solo numeros.");
                        cin.clear();
                        cin.ignore(1000,'\n');
                    }
                break;

                case 2:
                    matriz[i][j]=rand()%201-100;
                    cout<<"Generado: "<<matriz[i][j]<<endl;
                break;

                default:
                    matriz[i][j]=0;
            }

        }
    }

    imp("Matriz llenada correctamente.");
}

void aleatorio(int matriz[10][10]){

    pedirTamano();

    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            matriz[i][j]=rand()%201-100;

    imp("Matriz llenada aleatoriamente.");
}

void mostrarUnaMatriz(int matriz[10][10]){

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++)
            cout<<matriz[i][j]<<"\t";
        cout<<endl;
    }

}

void mostrarMatriz(){

    imp("\nMATRIZ 1");
    mostrarUnaMatriz(matriz1);

    imp("\nMATRIZ 2");
    mostrarUnaMatriz(matriz2);

}

void suma(){

    mostrarMatriz();

    int r[10][10];

    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            r[i][j]=matriz1[i][j]+matriz2[i][j];

    imp("\nRESULTADO");

    mostrarUnaMatriz(r);
}

void resta(){

    mostrarMatriz();

    int r[10][10];

    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            r[i][j]=matriz1[i][j]-matriz2[i][j];

    imp("\nRESULTADO");

    mostrarUnaMatriz(r);
}

void multiplicacion(){

    mostrarMatriz();

    int r[10][10];

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){

            r[i][j]=0;

            for(int k=0;k<columnas;k++)
                r[i][j]+=matriz1[i][k]*matriz2[k][j];
        }
    }

    imp("\nRESULTADO");

    mostrarUnaMatriz(r);
}

void division(){

    mostrarMatriz();

    float escalar;
    int opcion;

    cout<<"Seleccione matriz (1 o 2): ";
    cin>>opcion;

    if(opcion!=1 && opcion!=2){
        imp("Opcion invalida.");
        return;
    }

    cout<<"Escalar: ";
    cin>>escalar;

    if(escalar==0){
        imp("No se puede dividir entre 0");
        return;
    }

    imp("\nRESULTADO");

    int (*m)[10] = (opcion==1)? matriz1 : matriz2;

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++)
            cout<<m[i][j]/escalar<<"\t";
        cout<<endl;
    }

}