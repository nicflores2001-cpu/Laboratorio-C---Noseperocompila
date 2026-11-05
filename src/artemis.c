#include <stdio.h>
#include <math.h>
// Subimos un nivel de carpeta con "../" para entrar a include
#include "../include/artemis.h" 


//Calculamos la velocidad orbital
double calcularVelocidadOrbital() {
    // Aplicamos la fórmula: v = raiz( G * MasaTierra / RadioOrbital )
    double calculoInterno = (G * MASA_TIERRA) / RADIO_ORBITAL;
    double velocidad = sqrt(calculoInterno);
    
    return velocidad;
}


//Imprime por pantalla la demostracion analitica del punto a)
void demostrarIgualdadFuerzas() {
    printf("\n--- DEMOSTRACION ANALITICA (Punto A) ---\n");
    printf("En una orbita circular, la fuerza de gravedad terrestre es la unica fuerza\n");
    printf("que actua sobre la nave, empujandola hacia el centro de la Tierra.\n");
    printf("Por lo tanto, actua como la fuerza centripeta del sistema.\n\n");
    
    printf("Igualacion de fuerzas (F_g = F_c):\n");
    printf("G * (M_Tierra * m_orion) / r^2 = (m_orion * v^2) / r\n\n");
    
    printf("Al despejar la velocidad (v), la masa de Orion se cancela y un radio se simplifica:\n");
    printf("v = raiz_cuadrada( (G * M_Tierra) / r )\n");
    printf("----------------------------------------\n");
}



// Calculamos el periodo orbital con la velocidad orbital que ya calculamos
double calcularPeriodoOrbital(double velocidad) {
    // Calculamos el perímetro de la órbita (2 * PI * radio)
    double perimetro = 2 * PI * RADIO_ORBITAL;
    
    // El tiempo es distancia sobre velocidad
    double periodo = perimetro / velocidad;
    
    return periodo;
}