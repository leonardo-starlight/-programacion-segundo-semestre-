#include <iostream>
#include <string>

using namespace std;

void imp(string text);
bool esValidoYConvierte(string num, int base, unsigned long &resultado);

int main() {
    string valor, salida;
    int origen, destino;

    while (true) {
        imp("\n--- Conversor Numérico Universal ---");
        imp("Sistemas: 2 (Binario), 8 (Octal), 10 (Decimal), 16 (Hexadecimal)");

        cout << "Base de origen (0 para salir): ";
        cin >> origen;
        if (origen == 0) break;

        cout << "Valor a convertir: ";
        cin >> valor;

        unsigned long decimal = 0;
        // Validamos y convertimos a decimal
        if (!esValidoYConvierte(valor, origen, decimal)) {
            imp("Error: Valor invalido para la base seleccionada.");
            continue;
        }

        cout << "Base de destino: ";
        cin >> destino;

        // Convertir de Decimal a la Base de Destino
        if (destino == 10) {
            salida = to_string(decimal);
        } else if (destino == 2 || destino == 8 || destino == 16) {
            salida = "";
            if (decimal == 0) salida = "0";

            string caracteres = "0123456789ABCDEF";
            while (decimal > 0) {
                salida = caracteres[decimal % destino] + salida;
                decimal /= destino;
            }
        } else {
            imp("Error: Base de destino no soportada.");
            continue;
        }

        imp("Resultado: " + salida);
    }

    imp("Programa finalizado.");
    return 0;
}

void imp(string text) {
    cout << text << endl;
}

// Esta función hace dos trabajos: valida y transforma a decimal (Base 10)
bool esValidoYConvierte(string num, int base, unsigned long &resultado) {
    resultado = 0;
    for (int i = 0; i < num.length(); i++) {
        char c = num[i];
        int valorDigito = -1;

        if (c >= '0' && c <= '9') valorDigito = c - '0';
        else if (c >= 'a' && c <= 'f') valorDigito = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F') valorDigito = c - 'A' + 10;

        // Si el caracter es inválido o mayor/igual a la base, error
        if (valorDigito == -1 || valorDigito >= base) return false;

        // Desplazamiento de base manual: decimal = (decimal * base) + nuevo_digito
        resultado = (resultado * base) + valorDigito;
    }
    return true;
}