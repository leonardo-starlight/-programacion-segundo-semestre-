#include <iostream>
#include <string>

using namespace std;
int edad;
string clima, comida;
int mul;
 int año;
float suma;
int main() {


    cout << "¿Cual es tu edad?" << endl;
    cin >> edad;
    cout << "Edad: " << edad << endl;
    cout << "¿Cual es tu estacion del año favorita?" << endl;
    cin >> clima;
    cout << "Estacion favorita: " << clima << endl;
    cout << "Resuelve la siguiente multiplicacion: 15 * 5" << endl;
    cin >> mul;
    cout << "Resultado multiplicacion: " << mul << endl;
    cout << "¿En que año naciste?" << endl;
    cin >> año;
    cout << "Año de nacimiento: " << año << endl;
    cout << "¿Cual es tu comida favorita?" << endl;
    cin >> comida;
    cout << "Comida favorita: " << comida << endl;
    cout << "Resuelve la siguiente suma: 12.5 + 11" << endl;
    cin >> suma;
    cout << "Resultado suma: " << suma << endl;

    return 0;
}
