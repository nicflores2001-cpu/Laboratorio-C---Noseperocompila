// Definimos las variables y constantes para el punto a)
#ifndef ARTEMIS_H
#define ARTEMIS_H

// Constantes físicas universales y del planeta Tierra
#define G 6.674e-11             // Constante de gravitación universal en N*m^2/kg^2[cite: 3]
#define MASA_TIERRA 5.972e24    // Masa de la Tierra en kg[cite: 3]
#define RADIO_TIERRA 6371000.0  // Radio terrestre medio en metros[cite: 3]
#define PI 3.14159265359

// Constantes de la misión Orion en órbita LEO
#define MASA_ORION 33000.0      // Masa total de la nave Orion en kg[cite: 3]
#define ALTITUD_LEO 192000.0    // Altitud constante sobre la superficie en metros[cite: 3]
#define RADIO_ORBITAL 6563000.0 // Radio orbital total (Tierra + Altitud) en metros[cite: 3]
#define ACEL_PULSO   0.50   // m/s^2
#define TIEMPO_PULSO 10.0   // s


// 3. Prototipos de Funciones
//Punto a-
double calcularVelocidadOrbital();
void demostrarIgualdadFuerzas();

//Punto b-
double calcularPeriodoOrbital(double velocidad);

//Punto c-
double calcularAceleracionCentripeta(void);
double calcularAceleracionGravitatoria(void);

//Punto d-
double calcularVelocidadLateral(void);                 // v_perp = a*dt
double calcularDesviacionLateral(void);                // d = 1/2 a dt^2
double calcularDesviacionAngular(double *grados);      // devuelve rad, grados por puntero

#endif



