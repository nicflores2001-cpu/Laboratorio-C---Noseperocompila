#include <stdio.h>
#include "include/artemis.h" // Incluimos tu cabecera con las constantes y prototipos

int main() {
    printf("Iniciando prueba de calculo...\n");

    // 1. Llamamos a la función que armamos en artemis.c
    double velocidad = calcularVelocidadOrbital();

    // 2. Imprimimos el resultado. 
    // El "%.2f" le dice a C que imprima un número double pero solo con 2 decimales.
    printf("\n--- RESULTADOS SITUACION 2 ---\n");
    printf("Velocidad Orbital: %.2f m/s\n", velocidad);
    printf("------------------------------\n\n");

    return 0;
}