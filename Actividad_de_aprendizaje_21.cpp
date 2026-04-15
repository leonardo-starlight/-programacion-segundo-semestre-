#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//funciones
void dibujarAhorcado(int intentos);
bool verificarLetra(char letra, string palabra, string &progreso);
void imp(string text);

int main() {
    // Semilla para aleatoriedad basada en el tiempo
    srand(time(0));

    // Arreglo de strings
    string bancoPalabras[] = {"ALGORITMO", "PROGRAMA", "VARIABLE", "MATRIZ", "COMPILADOR", "LOGICA"};
    char jugarDeNuevo;

    do {
        // Selección aleatoria (0 a 5)
        string palabraSecreta = bancoPalabras[rand() % 6];

        // Inicializar progreso con guiones bajos
        string progreso = "";
        for(int i = 0; i < palabraSecreta.length(); i++) {
            progreso += "_";
        }

        string fallidas = "";
        int intentosFallidos = 0;
        const int MAX_INTENTOS = 7;

        while (intentosFallidos < MAX_INTENTOS && progreso != palabraSecreta) {
            // Limpiar consola (funciona en la mayoría de terminales)
            cout << "\033[2J\033[1;1H";

            imp("--- PRÁCTICA: JUEGO DEL AHORCADO ---");
            dibujarAhorcado(intentosFallidos);

            cout << "\nPalabra: ";
            for(int i = 0; i < progreso.length(); i++) {
                cout << progreso[i] << " ";
            }

            cout << "\n\nLetras fallidas: " << fallidas;
            cout << "\nIntentos restantes: " << MAX_INTENTOS - intentosFallidos;

            cout << "\n\nIngresa una letra: ";
            char letra;
            cin >> letra;
            letra = toupper(letra); // Convertir a mayúscula

            // Lógica de verificación
            if (!verificarLetra(letra, palabraSecreta, progreso)) {
                // Verificar si la letra ya estaba en fallidas para no penalizar doble
                if (fallidas.find(letra) == string::npos) {
                    fallidas += letra;
                    fallidas += " ";
                    intentosFallidos++;
                }
            }
        }

        // Resultado final
        cout << "\033[2J\033[1;1H";
        dibujarAhorcado(intentosFallidos);

        if (progreso == palabraSecreta) {
            imp("\n¡GANASTE! Adivinaste: " + palabraSecreta);
        } else {
            imp("\nPERDISTE. La palabra era: " + palabraSecreta);
        }

        cout << "\n¿Deseas jugar de nuevo? (s/n): ";
        cin >> jugarDeNuevo;

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    imp("Programa finalizado.");
    return 0;
}

// --- Implementación de Funciones ---

void imp(string text) {
    cout << text << endl;
}

void dibujarAhorcado(int intentos) {
    // Usamos un arreglo de strings para las fases del dibujo
    string fases[] = {
        "  +---+\n      |\n      |\n      |\n     ===",    // 0 fallos
        "  +---+\n  O   |\n      |\n      |\n     ===",    // 1 fallo
        "  +---+\n  O   |\n  |   |\n      |\n     ===",    // 2 fallos
        "  +---+\n  O   |\n /|   |\n      |\n     ===",    // 3 fallos
        "  +---+\n  O   |\n /|\\  |\n      |\n     ===",    // 4 fallos
        "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",    // 5 fallos
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ===",    // 6 fallos
        "  +---+\n [X]  |\n /|\\  |\n / \\  |\n     ==="     // 7 fallos (Final)
    };
    cout << fases[intentos] << endl;
}

bool verificarLetra(char letra, string palabra, string &progreso) {
    bool encontrada = false;
    for (int i = 0; i < palabra.length(); i++) {
        if (palabra[i] == letra) {
            progreso[i] = letra;
            encontrada = true;
        }
    }
    return encontrada;
}