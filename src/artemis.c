#include <math.h>
// Subimos un nivel de carpeta con "../" para entrar a include
#include "../include/artemis.h" 

double calcularVelocidadOrbital() {
    // Aplicamos la fórmula: v = raiz( G * MasaTierra / RadioOrbital )
    double calculoInterno = (G * MASA_TIERRA) / RADIO_ORBITAL;
    double velocidad = sqrt(calculoInterno);
    
    return velocidad;
}