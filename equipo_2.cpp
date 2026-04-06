/*#include <iostream>

// Función recursiva para calcular base^exponente
int calcularPotencia(int base, int exponente) {

    // 1. CASO BASE: Cualquier número elevado a la 0 es 1. Aquí nos detenemos.
    if (exponente == 0) {
        return 1;
    }

    // 2. CASO RECURSIVO: Multiplicamos la base por la función misma,
    // pero restándole 1 al exponente para acercarnos al caso base.
    else {
        return base * calcularPotencia(base, exponente - 1);
    }
}

int main() {
    int miBase = 2;
    int miExponente = 3;

    int resultado = calcularPotencia(miBase, miExponente);

    std::cout << miBase << " elevado a la " << miExponente << " es: " << resultado << std::endl;
    // El programa imprimirá: 2 elevado a la 3 es: 8

    return 0;
}*/

/*#include <iostream>

// Función que suma los números desde 'n' hasta 0
int sumarNumeros(int n) {

    // 1. CASO BASE: Si llegamos a 0, ya no hay nada que sumar.
    if (n <= 0) {
        return 0;
    }

    // 2. CASO RECURSIVO: Sumamos el número actual (n) y llamamos a la función con el anterior (n - 1)
    return n + sumarNumeros(n - 1);
}

int main() {
    int resultado = sumarNumeros(5);
    std::cout << "La suma es: " << resultado << std::endl; // Imprime: 15
    return 0;
}*/

#include <iostream>
#include <sys/resource.h>

// --- MODIFICA ESTE VALOR ---
const int VALOR_N = 50;
// ---------------------------

long long fibonacci(int n) {
    if (n <= 1) return n;
    // Doble llamado a función: genera un árbol binario de ejecución
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void reportarRecursos() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    std::cout << "\n--- Reporte de Recursos ---" << std::endl;
    // ru_maxrss devuelve el pico máximo de RAM usado por el proceso en KB
    std::cout << "Memoria RAM (Max RSS): " << usage.ru_maxrss << " KB" << std::endl;
}

int main() {
    std::cout << "Calculando Fibonacci para n = " << VALOR_N << "..." << std::endl;

    long long resultado = fibonacci(VALOR_N);

    std::cout << "Resultado: " << resultado << std::endl;

    reportarRecursos();

    return 0;
}