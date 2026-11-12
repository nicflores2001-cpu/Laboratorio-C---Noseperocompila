#include <stdio.h>
#include "include/artemis.h" // Incluimos tu cabecera con las constantes y prototipos



int main() {

    demostrarIgualdadFuerzas();
    printf("Iniciando prueba de calculo...\n");

    // 1. Llamamos a la función que armamos en artemis.c
    double velocidad = calcularVelocidadOrbital();

    

    // 2. Imprimimos el resultado. 
    // El "%.2f" le dice a C que imprima un número double pero solo con 2 decimales.
    printf("\n--- RESULTADOS SITUACION 2 ---\n");
    printf("Velocidad Orbital: %.2f m/s\n", velocidad);
    printf("------------------------------\n\n");
    double ac = calcularAceleracionCentripeta();
    double ag = calcularAceleracionGravitatoria();

    printf("c) Aceleracion centripeta: %.4f m/s^2\n", ac);
    printf("   Verificacion G*M/r^2:   %.4f m/s^2\n", ag);
    
    double grados;
    double vlat = calcularVelocidadLateral();
    double desv = calcularDesviacionLateral();
    double rad  = calcularDesviacionAngular(&grados);

    printf("d) Velocidad lateral:   %.2f m/s\n", vlat);
    printf("   Desviacion lateral:  %.2f m\n", desv);
    printf("   Giro de la velocidad: %.6f rad (%.4f grados)\n", rad, grados);
    return 0;
}