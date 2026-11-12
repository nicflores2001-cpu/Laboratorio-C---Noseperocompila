#ifndef VALIDACIONES_H
#define VALIDACIONES_H

// Lee un double validado (acepta coma o punto decimal) dentro de [min, max]
double leerDoubleEnRango(const char *mensaje, double min, double max);

// Lee un entero validado dentro de [min, max]
int leerEnteroEnRango(const char *mensaje, int min, int max);

// Pausa hasta que el usuario presione Enter
void esperarEnter(void);

#endif
