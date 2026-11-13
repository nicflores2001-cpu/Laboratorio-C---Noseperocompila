#ifndef ARTEMIS_H
#define ARTEMIS_H

// Constantes físicas
#define G            6.674e-11
#define MASA_TIERRA  5.972e24
#define RADIO_TIERRA 6371000.0
#define PI           3.14159265358979323846

// Valores por defecto de la Misión Orion (Situación 2)
#define ALTITUD_ORION_DEF 192000.0  // m (192 km)
#define MASA_ORION_DEF    33000.0   // kg
#define ACEL_PULSO_DEF    0.50      // m/s^2
#define TIEMPO_PULSO_DEF  10.0      // s
#define MAX_HISTORIAL 5


// Datos que carga el usuario
typedef struct {
    double altitud;     // m
    double masaNave;    // kg
    double aceleracion; // m/s^2 (pulso lateral)
    double tiempo;      // s     (duración del pulso)
    int    cargado;     // 0 = todavía no se cargaron datos
} DatosOrbita;
// Un campo a cargar: mensaje, rango válido y puntero a la variable destino
typedef struct {
    const char *mensaje;
    double min;
    double max;
    double *destino;
} CampoEntrada;

// Arreglo de simulaciones guardadas
typedef struct {
    DatosOrbita simulaciones[MAX_HISTORIAL];
    int cantidad;
} Historial;

// Carga de datos con validación y carga por defecto
void cargarDatos(DatosOrbita *d);
void cargarDatosPorDefecto(DatosOrbita *d);


// Cálculos
double calcularRadioOrbital(double altitud);
double calcularVelocidadOrbital(double altitud);                           // a)
double calcularFuerzaGravitatoria(double altitud, double masa);            // a)
double calcularFuerzaCentripeta(double altitud, double masa);              // a)
double calcularPeriodoOrbital(double altitud, double *minutos);            // b)
double calcularAceleracionCentripeta(double altitud);                      // c)
double calcularAceleracionGravitatoria(double altitud);                    // c)
double calcularVelocidadLateral(double aceleracion, double tiempo);        // d)
double calcularDesviacionLateral(double aceleracion, double tiempo);       // d)
double calcularDesviacionAngular(double altitud, double aceleracion,
                                 double tiempo, double *grados);           // d)

// Presentación de resultados
void mostrarPuntoA(const DatosOrbita *d);
void mostrarPuntoB(const DatosOrbita *d);
void mostrarPuntoC(const DatosOrbita *d);
void mostrarPuntoD(const DatosOrbita *d);
void demostrarIgualdadFuerzas(void);



void guardarEnHistorial(Historial *h, const DatosOrbita *d);
void mostrarHistorial(const Historial *h);
void mostrarTablaAltitudes(void);
#endif // ARTEMIS_H





