#include <stdio.h>
#include "artemis.h"
#include "validaciones.h"

static void mostrarMenu(const DatosOrbita *d) {
    printf("\n=========================================\n");
    printf("   ARTEMIS - SITUACION 2: ORBITA LEO\n");
    printf("=========================================\n");
    if (d->cargado) {
        printf("Datos: h=%.0f m | m=%.0f kg | a=%.2f m/s^2 | dt=%.1f s\n",
               d->altitud, d->masaNave, d->aceleracion, d->tiempo);
    } else {
        printf("Datos: (sin cargar)\n");
    }
    printf("-----------------------------------------\n");
    printf("1. Cargar / modificar datos personalizados\n");
    printf("2. Cargar datos por defecto (Mision Orion LEO)\n");
    printf("3. Velocidad orbital \n");
    printf("4. Periodo orbital \n");
    printf("5. Aceleracion centripeta \n");
    printf("6. Pulso lateral \n");
    printf("7. Ver todos los resultados\n");
    printf("0. Salir\n");
    printf("-----------------------------------------\n");
}

int main(void) {
    DatosOrbita datos = {0.0, 0.0, 0.0, 0.0, 0};
    int opcion;

    do {
        mostrarMenu(&datos);
        opcion = leerEnteroEnRango("Elija una opcion: ", 0, 7);

        if (opcion >= 3 && opcion <= 7 && !datos.cargado) {
            printf("\n[Aviso] Primero cargue los datos (opcion 1 o 2).\n");
            esperarEnter();
            continue;
        }

        switch (opcion) {
            case 1: cargarDatos(&datos);           break;
            case 2: cargarDatosPorDefecto(&datos); break;
            case 3: mostrarPuntoA(&datos);         break;
            case 4: mostrarPuntoB(&datos);         break;
            case 5: mostrarPuntoC(&datos);         break;
            case 6: mostrarPuntoD(&datos);         break;
            case 7:
                mostrarPuntoA(&datos);
                mostrarPuntoB(&datos);
                mostrarPuntoC(&datos);
                mostrarPuntoD(&datos);
                break;
            case 0: printf("\nFin del programa. Buen viaje!\n"); break;
        }

        if (opcion != 0) esperarEnter();

    } while (opcion != 0);

    return 0;
}