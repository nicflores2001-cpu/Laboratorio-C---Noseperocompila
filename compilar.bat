@echo off
echo -------------------------------------------
echo     Compilando Simulador Artemis (C)
echo -------------------------------------------

rem Ejecutamos el comando de compilacion con GCC
gcc -Iinclude main.c src/artemis.c src/validaciones.c -o simulador -lm

if %errorlevel% equ 0 (
    simulador.exe
) else (
    echo.
    echo [ERROR] La compilacion fallo. 
    echo Revisa los mensajes del compilador arriba.
    echo.
    echo Recomendacion: asegurate de que no haya un archivo .exe abierto.
)

pause