@echo off
echo Compilando Problema 4: Traductor C...
gcc -o traductor_c.exe traductor_c.c
if %errorlevel% equ 0 (
    echo Compilacion exitosa!
    echo Ejecute: traductor_c.exe
) else (
    echo Error en la compilacion
)
pause