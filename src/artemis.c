#include <stdio.h>
#include <math.h>
#include "artemis.h"
#include "validaciones.h"

//carga de datos personalizada.
void cargarDatos(DatosOrbita *d) {
    if (d == NULL) return;

    printf("\n--- CARGA DE DATOS ---\n");
    d->altitud     = leerDoubleEnRango("Altitud orbital en metros (160000 a 2000000): ",
                                       160000.0, 2000000.0);
    d->masaNave    = leerDoubleEnRango("Masa de la nave en kg (1000 a 1000000): ",
                                       1000.0, 1000000.0);
    d->aceleracion = leerDoubleEnRango("Aceleracion del pulso lateral en m/s^2 (0.01 a 10): ",
                                       0.01, 10.0);
    d->tiempo      = leerDoubleEnRango("Duracion del pulso en segundos (0.1 a 600): ",
                                       0.1, 600.0);
    d->cargado = 1;
    printf("\nDatos cargados correctamente.\n");
}
//carga los datos por defecto, con los valores por defecto que nos dieron del trabajo integrador.
void cargarDatosPorDefecto(DatosOrbita *d) {
    if (d == NULL) return;

    d->altitud     = ALTITUD_ORION_DEF;
    d->masaNave    = MASA_ORION_DEF;
    d->aceleracion = ACEL_PULSO_DEF;
    d->tiempo      = TIEMPO_PULSO_DEF;
    d->cargado     = 1;

    printf("\nDatos por defecto de la mision Orion (LEO) cargados correctamente.\n");
}

double calcularRadioOrbital(double altitud) {
    return RADIO_TIERRA + altitud;
}

double calcularVelocidadOrbital(double altitud) {
    return sqrt((G * MASA_TIERRA) / calcularRadioOrbital(altitud));
}

double calcularFuerzaGravitatoria(double altitud, double masa) {
    double r = calcularRadioOrbital(altitud);
    return (G * MASA_TIERRA * masa) / (r * r);
}

double calcularFuerzaCentripeta(double altitud, double masa) {
    double v = calcularVelocidadOrbital(altitud);
    return (masa * v * v) / calcularRadioOrbital(altitud);
}

double calcularPeriodoOrbital(double altitud, double *minutos) {
    double periodo = (2.0 * PI * calcularRadioOrbital(altitud)) / calcularVelocidadOrbital(altitud);
    if (minutos != NULL) {
        *minutos = periodo / 60.0;
    }
    return periodo;
}

double calcularAceleracionCentripeta(double altitud) {
    double v = calcularVelocidadOrbital(altitud);
    return (v * v) / calcularRadioOrbital(altitud);
}

double calcularAceleracionGravitatoria(double altitud) {
    double r = calcularRadioOrbital(altitud);
    return (G * MASA_TIERRA) / (r * r);
}

double calcularVelocidadLateral(double aceleracion, double tiempo) {
    return aceleracion * tiempo;
}

double calcularDesviacionLateral(double aceleracion, double tiempo) {
    return 0.5 * aceleracion * tiempo * tiempo;
}

double calcularDesviacionAngular(double altitud, double aceleracion,
                                 double tiempo, double *grados) {
    double v   = calcularVelocidadOrbital(altitud);
    double rad = atan(calcularVelocidadLateral(aceleracion, tiempo) / v);
    if (grados != NULL) {
        *grados = rad * 180.0 / PI;
    }
    return rad;
}
void demostrarIgualdadFuerzas(void) {
    printf("\n--- DEMOSTRACION ANALITICA ---\n");
    printf("En una orbita circular, la fuerza de gravedad terrestre es la unica fuerza\n");
    printf("que actua sobre la nave, empujandola hacia el centro de la Tierra.\n");
    printf("Por lo tanto, actua como la fuerza centripeta del sistema.\n\n");

    printf("Igualacion de fuerzas (F_g = F_c):\n");
    printf("G * (M_Tierra * m_orion) / r^2 = (m_orion * v^2) / r\n\n");

    printf("Al despejar v, la masa de Orion se cancela y un radio se simplifica:\n");
    printf("v = raiz_cuadrada( (G * M_Tierra) / r )\n");
    printf("----------------------------------------\n");
}

/* ---------- Presentación ---------- */

void mostrarPuntoA(const DatosOrbita *d) {
    demostrarIgualdadFuerzas();
    double v  = calcularVelocidadOrbital(d->altitud);
    double fg = calcularFuerzaGravitatoria(d->altitud, d->masaNave);
    double fc = calcularFuerzaCentripeta(d->altitud, d->masaNave);

    printf("\n--- VELOCIDAD ORBITAL ---\n");
    printf("Radio orbital:            %.1f m\n", calcularRadioOrbital(d->altitud));
    printf("Fuerza gravitatoria:      %.2f N\n", fg);
    printf("Fuerza centripeta m*v^2/r: %.2f N\n", fc);
    printf("Diferencia entre ambas:   %.6f N (la gravedad actua como fuerza centripeta)\n", fabs(fg - fc));
    printf("Velocidad orbital:        %.2f m/s (%.3f km/s)\n", v, v / 1000.0);
}

void mostrarPuntoB(const DatosOrbita *d) {
    double minutos;
    double segundos = calcularPeriodoOrbital(d->altitud, &minutos);

    printf("\n--- PERIODO ORBITAL ---\n");
    printf("Periodo: %.2f s (%.2f min)\n", segundos, minutos);
}

void mostrarPuntoC(const DatosOrbita *d) {
    printf("\n---ACELERACION CENTRIPETA ---\n");
    printf("a = v^2/r:   %.4f m/s^2\n", calcularAceleracionCentripeta(d->altitud));
    printf("a = G*M/r^2: %.4f m/s^2 (verificacion)\n", calcularAceleracionGravitatoria(d->altitud));
}

void mostrarPuntoD(const DatosOrbita *d) {
    double grados;
    double rad = calcularDesviacionAngular(d->altitud, d->aceleracion, d->tiempo, &grados);

    printf("\n--- PULSO LATERAL  ---\n");
    printf("Trayectoria resultante: Al aplicar un impulso perpendicular a la velocidad\n");
    printf("orbital, la nave abandona su orbita circular original y describe una\n");
    printf("nueva orbita eliptica (que localmente se aproxima como una parabola).\n\n");
    printf("Velocidad lateral ganada: %.2f m/s\n", calcularVelocidadLateral(d->aceleracion, d->tiempo));
    printf("Desviacion lateral:       %.2f m\n", calcularDesviacionLateral(d->aceleracion, d->tiempo));
    printf("Giro de la velocidad:     %.6f rad (%.4f grados)\n", rad, grados);
}