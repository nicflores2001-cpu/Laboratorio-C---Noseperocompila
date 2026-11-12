#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "validaciones.h"

#define TAM_BUFFER 64

// Lee una línea completa. Devuelve 1 si OK, 0 si era demasiado larga.
static int leerLinea(char *buffer, int tam) {
    if (fgets(buffer, tam, stdin) == NULL) {
        printf("\nEntrada cerrada. Saliendo del programa.\n");
        exit(1);
    }
    if (strchr(buffer, '\n') == NULL) {      // la línea no entró completa
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }   // descarta el resto
        return 0;
    }
    return 1;
}

double leerDoubleEnRango(const char *mensaje, double min, double max) {
    char buffer[TAM_BUFFER];
    char *fin;
    double valor;

    while (1) {
        printf("%s", mensaje);

        if (!leerLinea(buffer, TAM_BUFFER)) {
            printf("  [Error] Entrada demasiado larga.\n");
            continue;
        }

        for (char *p = buffer; *p != '\0'; p++) {   // acepta "0,5" como "0.5"
            if (*p == ',') *p = '.';
        }

        valor = strtod(buffer, &fin);

        if (fin == buffer) {
            printf("  [Error] Ingrese un numero valido (no letras).\n");
            continue;
        }
        while (*fin == ' ' || *fin == '\t' || *fin == '\n') fin++;
        if (*fin != '\0') {
            printf("  [Error] Hay caracteres no validos despues del numero.\n");
            continue;
        }
        if (!isfinite(valor)) {
            printf("  [Error] Valor no valido.\n");
            continue;
        }
        if (valor < min || valor > max) {
            printf("  [Error] El valor debe estar entre %.2f y %.2f.\n", min, max);
            continue;
        }
        return valor;
    }
}

int leerEnteroEnRango(const char *mensaje, int min, int max) {
    char buffer[TAM_BUFFER];
    char *fin;
    long valor;

    while (1) {
        printf("%s", mensaje);

        if (!leerLinea(buffer, TAM_BUFFER)) {
            printf("  [Error] Entrada demasiado larga.\n");
            continue;
        }

        valor = strtol(buffer, &fin, 10);

        if (fin == buffer) {
            printf("  [Error] Ingrese un numero entero (no letras).\n");
            continue;
        }
        while (*fin == ' ' || *fin == '\t' || *fin == '\n') fin++;
        if (*fin != '\0') {
            printf("  [Error] Ingrese solo un numero entero.\n");
            continue;
        }
        if (valor < min || valor > max) {
            printf("  [Error] Elija una opcion entre %d y %d.\n", min, max);
            continue;
        }
        return (int)valor;
    }
}

void esperarEnter(void) {
    char buffer[TAM_BUFFER];
    printf("\nPresione Enter para continuar...");
    leerLinea(buffer, TAM_BUFFER);
}