#include <stdio.h>
#include "include/artemis.h"

int main() {
    demostrarIgualdadFuerzas(); // Tu función de demostración

    printf("Calculando la fisica completa de la mision...\n");

    // PUNTOS A y B (Tu lógica)
    double velocidad = calcularVelocidadOrbital();
    double periodoSeg = calcularPeriodoOrbital(velocidad);
    double periodoMin = periodoSeg / 60.0;

    // PUNTO C (La lógica de tu compañero)
    double acelCentripeta = calcularAceleracionCentripeta();
    double acelGravitatoria = calcularAceleracionGravitatoria();

    // PUNTO D (La lógica de tu compañero)
    double velLateral = calcularVelocidadLateral();
    double despLateral = calcularDesviacionLateral();
    
    // ATENCION ACA: Como usó un puntero, le pasamos la dirección de memoria de la variable con "&"
    double grados;
    double rad = calcularDesviacionAngular(&grados);

    // IMPRESION DE LA PANTALLA FINAL
    printf("\n--- RESULTADOS SITUACION 2 (ORBITA LEO) ---\n");
    printf("a) Velocidad Orbital:       %.2f m/s\n", velocidad);
    printf("b) Periodo Orbital:         %.2f seg (%.2f min)\n", periodoSeg, periodoMin);
    
    printf("\nc) Aceleraciones:\n");
    printf("   - Centripeta:            %.4f m/s^2\n", acelCentripeta);
    printf("   - Gravitatoria:          %.4f m/s^2\n", acelGravitatoria);
    
    printf("\nd) Pulso de desvio:\n");
    printf("   - Velocidad lateral:     %.2f m/s\n", velLateral);
    printf("   - Desplazamiento lateral:%.2f m\n", despLateral);
    printf("   - Desviacion angular:    %.6f rad (%.4f grados)\n", rad, grados);
    printf("-------------------------------------------\n");

    return 0;
}