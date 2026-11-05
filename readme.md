#  Simulador de Misiones Artemis

**Trabajo Final Integrador**  
**Cátedra:** Algoritmos y Estructuras de Datos  
**Institución:** Universidad Tecnológica Nacional (UTN) - Facultad Regional Resistencia  

Este proyecto es un simulador interactivo por consola desarrollado íntegramente en lenguaje C, diseñado para modelar los desafíos físicos y operativos de las misiones aeroespaciales del programa Artemis.

##  Integrantes y Comisión

* **Comisión:** [Número/Nombre de la comisión]
* **Equipo:**
  * Flores Nicolas - Legajo: 27180 - 
  * Medina Agustin - Legajo: 26680 - 
  * Garcia Franceschini, Yael Ailen - Legajo: 27429 - 
  * Aguirre Hernan Ezequiel - Legajo: 27179 - 

**Situación - Problema 2: Inserción y Estabilidad en Órbita Terrestre Baja - LEO (MCU y Gravitación)**

* **Descripción:** Tras apagar sus motores de ascenso, la nave Orion es inyectada en una órbita terrestre baja (LEO) de estacionamiento, donde realiza un Movimiento Circular Uniforme (MCU) a una altitud constante de 192,0 km (192.000,0 m) sobre la superficie terrestre. El simulador calcula y analiza parámetros orbitales como la velocidad, la aceleración centrípeta y el período orbital, considerando constantes físicas como la masa de la Tierra y la constante de gravitación universal.

* **Reglas:** El usuario interactúa mediante un menú para ingresar variaciones en los parámetros físicos y el sistema simula y reporta los resultados, respetando estrictas validaciones de datos para evitar cuelgues o ingresos erróneos. El programa responde analíticamente a las consignas físicas, evaluando la estabilidad de la órbita ante encendidos de propulsores auxiliares.

##  Detalle de Funcionamiento y Arquitectura

El proyecto cumple con un diseño modular, dividiendo responsabilidades en distintos archivos:

* `main.c`: Maneja el menú principal de navegación.

* `src/artemis.c` y `include/artemis.h`: Contienen la lógica de negocio, cálculos físicos y estructuras de la simulación.

* `src/validaciones.c` y `include/validaciones.h`: Módulos de seguridad para el ingreso exhaustivo de datos, evitando que el programa finalice por errores del usuario.

##  Instrucciones de Compilación y Ejecución

Para compilar el proyecto, asegúrese de tener instalado el compilador **GCC**. Abra una terminal en la raíz del repositorio y ejecute el siguiente comando para enlazar el `main` junto con los módulos:

```bash
gcc main.c src/artemis.c src/validaciones.c -o simulador
```

Una vez compilado exitosamente, ejecute el programa con:

**En Windows:**

```bash
.\simulador.exe
```

**En Linux / macOS:**

```bash
./simulador
```

##  Registro del Uso de Inteligencia Artificial

Tal como lo solicita la cátedra, a continuación se detalla el uso ético y crítico de herramientas de IA generativa como apoyo durante el desarrollo:

| Herramienta Utilizada | Tarea Específica | Prompt / Consulta Realizada | Validación y Adaptación del Código | 
| ----- | ----- | ----- | ----- | 
| \[Ej: Gemini / ChatGPT\] | \[Ej: Explicación de Git y ramas\] | *"Cómo usamos las ramas para dividir el trabajo..."* | Comprendimos el flujo y adaptamos los comandos a nuestro entorno. | 
| \[...\] | \[...\] | \[...\] | \[...\] | 
| \[...\] | \[...\] | \[...\] | \[...\] |
| \[...\] | \[...\] | \[...\] | \[...\] | 
| \[...\] | \[...\] | \[...\] | \[...\] |
| \[...\] | \[...\] | \[...\] | \[...\] | 
| \[...\] | \[...\] | \[...\] | \[...\] |
| \[...\] | \[...\] | \[...\] | \[...\] | 
| \[...\] | \[...\] | \[...\] | \[...\] |
| \[...\] | \[...\] | \[...\] | \[...\] | 
| \[...\] | \[...\] | \[...\] | \[...\] | 

*Repositorio mantenido para el ciclo lectivo correspondiente.*