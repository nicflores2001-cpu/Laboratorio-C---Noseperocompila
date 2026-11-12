#  Simulador Misión Artemis — Situación 2 (Órbita LEO)

Trabajo Práctico Final de Laboratorio desarrollado en lenguaje **C** para la cátedra **Algoritmos y Estructuras de Datos** — **Universidad Tecnológica Nacional, Facultad Regional Resistencia (UTN FRRe)**.

---

##  Descripción del Proyecto

El programa modela y analiza la dinámica orbital de la nave espacial **Orion** en una **Órbita Terrestre Baja (LEO)** bajo las leyes del Movimiento Circular Uniforme (MCU) y la Gravitación Universal, permitiendo tanto simular los parámetros oficiales de la misión como ingresar escenarios personalizados con validación robusta de entrada.

### Problemas físicos resueltos
* **Punto a) Equilibrio orbital y velocidad:** Demostración analítica de la igualdad entre la fuerza de atracción gravitatoria y la fuerza centrípeta ($F_g = F_c$), verificación numérica de ambas fuerzas y cálculo del módulo de la velocidad orbital ($v$).
* **Punto b) Período orbital:** Cálculo del tiempo requerido para completar una órbita alrededor de la Tierra ($T$) expresado en segundos y minutos.
* **Punto c) Aceleración centrípeta:** Cálculo y contraste entre la aceleración centrípeta ($a_c = v^2 / r$) y la aceleración gravitatoria local ($g = G \cdot M_T / r^2$).
* **Punto d) Maniobra de desvío lateral:** Descripción de la trayectoria resultante tras un impulso perpendicular y cálculo de la velocidad lateral adquirida, el desplazamiento lateral instantáneo y la desviación angular (en radianes y grados).

---

##  Constantes y Parámetros de Referencia

| Parámetro | Símbolo | Valor por defecto | Rango personalizado permitido |
| :--- | :---: | :---: | :---: |
| Constante gravitacional | $G$ | $6.674 \times 10^{-11} \text{ N}\cdot\text{m}^2/\text{kg}^2$ | Fija |
| Masa de la Tierra | $M_T$ | $5.972 \times 10^{24} \text{ kg}$ | Fija |
| Radio terrestre | $R_T$ | $6\,371\,000.0 \text{ m}$ | Fija |
| Altitud orbital LEO | $h$ | $192\,000.0 \text{ m}$ ($192 \text{ km}$) | $160\,000.0 \text{ m}$ a $2\,000\,000.0 \text{ m}$ |
| Masa de la nave | $m$ | $33\,000.0 \text{ kg}$ | $1\,000.0 \text{ kg}$ a $1\,000\,000.0 \text{ kg}$ |
| Aceleración del pulso | $a$ | $0.50 \text{ m/s}^2$ | $0.01 \text{ m/s}^2$ a $10.0 \text{ m/s}^2$ |
| Duración del pulso | $\Delta t$ | $10.0 \text{ s}$ | $0.1 \text{ s}$ a $600.0 \text{ s}$ |

---

##  Estructura del Repositorio

```text
Laboratorio-C---Noseperocompila/
├── include/
│   ├── artemis.h          # Constantes, struct DatosOrbita y prototipos físicos/presentación
│   └── validaciones.h     # Prototipos de lectura segura por consola
├── src/
│   ├── artemis.c          # Implementación de fórmulas físicas, carga y reportes
│   └── validaciones.c     # Manejo seguro de buffer (fgets, strtod, strtol)
├── main.c                 # Menú principal interactivo y control de flujo
└── README.md              # Documentación del proyecto
```

---

##  Compilación y Ejecución

### Requisitos
* Compilador **GCC** (en Windows mediante MSYS2 UCRT64 o MinGW; en Linux/macOS nativo).
* Librería matemática estándar de C (`-lm`).

### Compilar desde la raíz del proyecto
Utilizá la bandera `-Iinclude` para enlazar la carpeta de archivos de cabecera y `-lm` para vincular la librería `<math.h>`:

```bash
gcc -Iinclude main.c src/artemis.c src/validaciones.c -o simulador -lm
```

### Ejecutar el simulador
* **En Windows (PowerShell / CMD):**
  ```powershell
  .\simulador.exe
  ```
* **En Linux / macOS:**
  ```bash
  ./simulador
  ```

---

##  Opciones del Menú Interactivo

Al iniciar el programa, se presenta un menú cíclico protegido contra entradas inválidas:

1. **Cargar / modificar datos personalizados:** Permite ingresar altitud, masa, aceleración y duración del pulso validando rangos físicos y aceptando tanto punto como coma decimal.
2. **Cargar datos por defecto (Misión Orion LEO):** Precarga automáticamente los valores oficiales del enunciado ($h = 192\,000\text{ m}$, $m = 33\,000\text{ kg}$, $a = 0.50\text{ m/s}^2$, $\Delta t = 10\text{ s}$).
3. **Velocidad orbital (Punto a):** Muestra la demostración analítica, verifica $F_g = F_c$ y calcula $v$.
4. **Período orbital (Punto b):** Calcula el tiempo de vuelta completa en segundos y minutos.
5. **Aceleración centrípeta (Punto c):** Calcula y contrasta $a_c$ y $g$.
6. **Pulso lateral (Punto d):** Describe la nueva trayectoria y calcula velocidad lateral, desviación y ángulo de giro.
7. **Ver todos los resultados:** Ejecuta de forma secuencial el reporte completo (Puntos a, b, c y d).
0. **Salir:** Finaliza la ejecución del simulador.

---

##  Arquitectura y Buenas Prácticas Implementadas

* **Modularización estricta:** Separación clara entre interfaz (`.h`), lógica de dominio (`artemis.c`), utilidades de entrada (`validaciones.c`) y capa de control (`main.c`).
* **Lectura segura sin desbordamiento de buffer:** Reemplazo de `scanf` por lectura de línea completa (`fgets`) y conversión controlada (`strtod` / `strtol`), evitando bucles infinitos ante caracteres no numéricos.
* **Programación defensiva:** Uso de bandera de estado (`cargado`) en `DatosOrbita` para impedir cálculos sin inicialización previa y uso de calificadores `const` en funciones de solo lectura.