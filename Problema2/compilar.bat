@echo off
echo Compilando Problema 2: Polinomio Pascal...
gcc -o polinomio_pascal.exe polinomio_pascal.c
if %errorlevel% equ 0 (
    echo Compilacion exitosa!
    echo Ejecute: polinomio_pascal.exe
) else (
    echo Error en la compilacion
)
pause