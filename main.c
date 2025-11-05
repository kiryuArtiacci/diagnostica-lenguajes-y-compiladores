#include <stdio.h>
#include <string.h>
#include "Problema1/fen_validator.h"
#include "Problema2/polinomio_pascal.h"
#include "Problema3/reconocimiento_patrones.h"
#include "Problema4/traductor_c.h"

int main()
{
    int opcion;

    printf("=========================================\n");
    printf("   LENGUAJES Y COMPILADORES\n");
    printf("=========================================\n\n");

    do
    {
        printf("=== MENU PRINCIPAL ===\n");
        printf("1. Validacion FEN (Ajedrez)\n");
        printf("2. Polinomio (x+1)^n con Pascal\n");
        printf("3. Reconocimiento de Patrones\n");
        printf("4. Traductor C -> Espanol\n");
        printf("0. Salir\n");
        printf("Seleccione opcion: ");

        if (scanf("%d", &opcion) != 1)
        {
            printf("Entrada invalida.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (opcion)
        {
        case 1:
            printf("\n--- PROBLEMA 1: VALIDACION FEN ---\n");
            problema1();
            break;
        case 2:
            printf("\n--- PROBLEMA 2: POLINOMIO PASCAL ---\n");
            problema2();
            break;
        case 3:
            printf("\n--- PROBLEMA 3: RECONOCIMIENTO PATRONES ---\n");
            problema3();
            break;
        case 4:
            printf("\n--- PROBLEMA 4: TRADUCTOR C ---\n");
            problema4();
            break;
        case 0:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida. Intente nuevamente.\n");
        }

        if (opcion != 0)
        {
            printf("\nPresione Enter para continuar...");
            getchar();
            getchar();
        }

    } while (opcion != 0);

    return 0;
}