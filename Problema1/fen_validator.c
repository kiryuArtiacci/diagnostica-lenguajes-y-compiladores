#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarFEN(const char *fen)
{
    int fila = 0, columna = 0, espacios = 0;
    int reyes_blancos = 0, reyes_negros = 0;

    for (int i = 0; fen[i] != '\0'; i++)
    {
        char c = fen[i];

        if (c == ' ')
        {
            espacios++;
            continue;
        }

        if (espacios == 0)
        {
            if (c == '/')
            {
                if (columna != 8)
                    return 0;
                fila++;
                columna = 0;
            }
            else if (isdigit(c))
            {
                int num = c - '0';
                if (num < 1 || num > 8)
                    return 0;
                columna += num;
            }
            else if (strchr("KkQqRrBbNnPp", c))
            {
                if (c == 'K')
                    reyes_blancos++;
                if (c == 'k')
                    reyes_negros++;
                columna++;
            }
            else
            {
                return 0;
            }

            if (columna > 8)
                return 0;
        }
    }

    if (fila != 7 || columna != 8)
        return 0;
    if (reyes_blancos != 1 || reyes_negros != 1)
        return 0;

    return 1;
}

void problema1()
{
    char fen[200];

    printf("=== VALIDACION DE NOTACION FEN ===\n");
    printf("Ejemplo valido: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR\n");
    printf("Ingrese cadena FEN: ");
    getchar();
    fgets(fen, sizeof(fen), stdin);
    fen[strcspn(fen, "\n")] = 0;

    if (validarFEN(fen))
    {
        printf("\n FEN VALIDO\n");
        printf("- 8 filas y 8 columnas correctas\n");
        printf("- 1 rey blanco y 1 rey negro presentes\n");
        printf("- Formato de piezas correcto\n");
    }
    else
    {
        printf("\n FEN INVALIDO\n");
        printf("- Error en la estructura del tablero\n");
    }
}
