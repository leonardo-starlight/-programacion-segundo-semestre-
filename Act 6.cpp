#include <stdio.h>

int edad;
char clima[10], comida[10];
int mul;
int año;
float suma;

int main() {
    printf("¿Cuál es tu edad?\n");
    scanf("%d", &edad);
    printf("Edad: %d\n", edad);

    printf("¿Cuál es tu estación del año favorita?\n");
    scanf("%s", clima);
    printf("Estación favorita: %s\n", clima);

    printf("Resuelve la siguiente multiplicación: 15 * 5\n");
    scanf("%d", &mul);
    printf("Resultado multiplicación: %d\n", mul);

    printf("¿En qué año naciste?\n");
    scanf("%d", &año);
    printf("Año de nacimiento: %d\n", año);

    printf("¿Cuál es tu comida favorita?\n");
    scanf("%s", comida);
    printf("Comida favorita: %s\n", comida);

    printf("Resuelve la siguiente suma: 12.5 + 11\n");
    scanf("%f", &suma);
    printf("Resultado suma: %.2f\n", suma);

    return 0;
}
