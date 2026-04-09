#include <iostream>
#include <string>
#include <cmath> // Para calcular el total de movimientos

using namespace std;

// Prototipos de funciones
void imp(string text);
void hanoi(int n, char origen, char destino, char auxiliar, int &contador);

int main() {
    int discos;
    char opcion;

    do {
        int contadorMovimientos = 0;

        imp("--- Práctica: Las Torres de Hanoi ---");
        imp("Ingrese el número de discos (El rango es de 3 a 7): ");
        cin >> discos;

        // Validación del rango solicitado
        if (discos < 3 || discos > 7) {
            imp("Error: Por favor use un rango entre 3 y 7 discos.");
        } else {
            imp("\nIniciando secuencia de movimientos...\n");

            // Llamada a la única función recursiva
            // Torre A: Origen, Torre B: Auxiliar, Torre C: Destino
            hanoi(discos, 'A', 'C', 'B', contadorMovimientos);

            imp("\n========================================");
            cout << "Resolución completada con " << contadorMovimientos << " movimientos." << endl;
            // La fórmula matemática es 2^n - 1
            cout << "Movimientos teóricos esperados: " << pow(2, discos) - 1 << endl;
            imp("========================================\n");
        }

        imp("¿Desea intentar con otro número de discos? (s/n): ");
        cin >> opcion;
        imp(""); // Salto de línea para claridad

    } while (opcion == 's' || opcion == 'S');

    imp("Programa finalizado. ¡Gracias por jugar!");

    return 0;
}

void imp(string text) {
    cout << text << endl;
}

//Función Recursiva Única para Hanoi
//para n Número de discos
//para origen Torre donde empieza el disco
//para destino Torre a donde debe llegar
//para auxiliar Torre de apoyo
//para contador Referencia para llevar el conteo global

void hanoi(int n, char origen, char destino, char auxiliar, int &contador) {
    if (n == 1) {
        contador++;
        cout << "Movimiento " << contador << ": Mover disco 1 de " << origen << " a " << destino << endl;
    } else {
        // Paso 1: Mover n-1 discos de origen al auxiliar usando el destino como apoyo
        hanoi(n - 1, origen, auxiliar, destino, contador);

        // Paso 2: Mover el disco más grande al destino
        contador++;
        cout << "Movimiento " << contador << ": Mover disco " << n << " de " << origen << " a " << destino << endl;

        // Paso 3: Mover los n-1 discos del auxiliar al destino usando el origen como apoyo
        hanoi(n - 1, auxiliar, destino, origen, contador);
    }
}