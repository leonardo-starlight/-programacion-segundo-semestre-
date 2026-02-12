#include <iostream>
#include <string>
using namespace std;

//declaracion de funciones
void imp(string texto);
void imp(int num);
void cambia(int &n1);
int sum (int num, int num2);
//variable global
int n1 = 10, n2 = 105;

int main () {
    imp("programa de funciones");
    imp("Leonardo Daniel. Ing. Computación");
    imp(10);
    imp (sum(n1,n2));
    cambia(n1);
    imp (sum(n1,n2));

    imp(10+15);
    imp (15+20);
}

//definicion de funciones
//funcion de imprimir texto en pantalla
void imp(string texto){
    cout << texto << endl;
}//fin de imp
//funcion para imprimir numeros enteros
//se llama sobre carga de funciones
void imp(int num){
    cout << num << endl;
}//fin de imp
//funcion suma con paso de parametros por valor
int sum (int num, int num2) {
    int result;
    result = num + num2;
    return result;
}//fin suma
// forma corta: int sum (int num, int num2) {
    // return num + num2;
// }fin suma
//funcion suma con paso de parametros por referencia
void cambia(int &n1) {
    n1= 30;
}