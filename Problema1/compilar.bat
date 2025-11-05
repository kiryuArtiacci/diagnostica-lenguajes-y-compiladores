@echo off
echo Compilando Problema 1: Validacion FEN...
gcc -o fen_validator.exe fen_validator.c
if %errorlevel% equ 0 (
    echo Compilacion exitosa!
    echo Ejecute: fen_validator.exe
) else (
    echo Error en la compilacion
)
pause