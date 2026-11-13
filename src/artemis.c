#include <stdio.h>
#include <math.h>
#include "artemis.h"
#include "validaciones.h"

//carga de datos personalizada.
void cargarDatos(DatosOrbita *d) {
    if (d == NULL) return;

    CampoEntrada campos[] = {
        {"Altitud orbital en metros (160000 a 2000000): ", 160000.0, 2000000.0, &d->altitud},
        {"Masa de la nave en kg (1000 a 1000000): ",       1000.0,   1000000.0, &d->masaNave},
        {"Aceleracion del pulso en m/s^2 (0.01 a 10): ",   0.01,     10.0,      &d->aceleracion},
        {"Duracion del pulso en segundos (0.1 a 600): ",   0.1,      600.0,     &d->tiempo}
    };
    int n = sizeof(campos) / sizeof(campos[0]);

    printf("\n--- CARGA DE DATOS ---\n");
    for (int i = 0; i < n; i++) {
        *campos[i].destino = leerDoubleEnRango(campos[i].mensaje,
                                               campos[i].min, campos[i].max);
    }
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
void guardarEnHistorial(Historial *h, const DatosOrbita *d) {
    if (h == NULL || d == NULL) return;

    if (h->cantidad > 0) {                       // evita duplicar la última carga
        const DatosOrbita *u = &h->simulaciones[h->cantidad - 1];
        if (u->altitud == d->altitud && u->masaNave == d->masaNave &&
            u->aceleracion == d->aceleracion && u->tiempo == d->tiempo) {
            return;
        }
    }

    if (h->cantidad == MAX_HISTORIAL) {          // lleno: descarta la más vieja
        for (DatosOrbita *p = h->simulaciones; p < h->simulaciones + MAX_HISTORIAL - 1; p++) {
            *p = *(p + 1);
        }
        h->cantidad--;
    }
    h->simulaciones[h->cantidad] = *d;
    h->cantidad++;
}

void mostrarHistorial(const Historial *h) {
    printf("\n--- HISTORIAL DE SIMULACIONES ---\n");
    if (h == NULL || h->cantidad == 0) {
        printf("Todavia no hay simulaciones guardadas.\n");
        return;
    }
    printf("%-3s %-12s %-10s %-12s %-10s\n", "N", "Altitud(m)", "v(m/s)", "T(min)", "Desv.(m)");

    const DatosOrbita *p = h->simulaciones;
    for (int i = 0; i < h->cantidad; i++, p++) {
        double minutos;
        calcularPeriodoOrbital(p->altitud, &minutos);
        printf("%-3d %-12.0f %-10.2f %-12.2f %-10.2f\n",
               i + 1, p->altitud, calcularVelocidadOrbital(p->altitud), minutos,
               calcularDesviacionLateral(p->aceleracion, p->tiempo));
    }
}
void mostrarTablaAltitudes(void) {
    const double altitudes[] = {160000.0, 192000.0, 400000.0, 800000.0, 2000000.0};
    int n = sizeof(altitudes) / sizeof(altitudes[0]);

    printf("\n--- COMPARACION DE ORBITAS ---\n");
    printf("%-12s %-10s %-10s %-10s\n", "Altitud(m)", "v(m/s)", "T(min)", "a_c(m/s^2)");

    for (const double *p = altitudes; p < altitudes + n; p++) {
        double minutos;
        calcularPeriodoOrbital(*p, &minutos);
        printf("%-12.0f %-10.2f %-10.2f %-10.4f\n",
               *p, calcularVelocidadOrbital(*p), minutos, calcularAceleracionCentripeta(*p));
    }
}