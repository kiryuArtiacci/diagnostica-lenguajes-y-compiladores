@echo off
echo Compilando Problema 3: Reconocimiento de Patrones...
gcc -o reconocimiento_patrones.exe reconocimiento_patrones.c
if %errorlevel% equ 0 (
    echo Compilacion exitosa!
    echo Ejecute: reconocimiento_patrones.exe
) else (
    echo Error en la compilacion
)
pause