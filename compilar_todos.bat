@echo off
echo ======================================
echo    COMPILADOR PROGRAMA UNIFICADO
echo ======================================
echo.

echo Compilando todos los archivos juntos...
gcc -o main.exe main.c Problema1/fen_validator.c Problema2/polinomio_pascal.c Problema3/reconocimiento_patrones.c Problema4/traductor_c.c

if %errorlevel% equ 0 (
    echo.
    echo =======================================
    echo COMPILACION EXITOSA!
    echo =======================================
    echo Programa principal generado: main.exe
    echo.
    echo Ejecute: main.exe
) else (
    echo.
    echo =======================================
    echo ERROR EN LA COMPILACION
    echo =======================================
)

pause