#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int esNotacionCientifica(const char *cadena)
{
    int i = 0;
    int tienePunto = 0;
    int tieneExponente = 0;
    int tieneDigitosAntes = 0;

    if (cadena[i] == '+' || cadena[i] == '-')
        i++;

    while (cadena[i] != '\0' && cadena[i] != 'e' && cadena[i] != 'E')
    {
        if (isdigit(cadena[i]))
        {
            if (!tienePunto)
                tieneDigitosAntes = 1;
        }
        else if (cadena[i] == '.')
        {
            if (tienePunto)
                return 0;
            tienePunto = 1;
        }
        else
            return 0;
        i++;
    }

    if (!tieneDigitosAntes)
        return 0;

    if (cadena[i] == 'e' || cadena[i] == 'E')
    {
        tieneExponente = 1;
        i++;
        if (cadena[i] == '+' || cadena[i] == '-')
            i++;
        if (!isdigit(cadena[i]))
            return 0;
        while (isdigit(cadena[i]))
            i++;
    }

    return (cadena[i] == '\0' && tieneExponente);
}

int esIP(const char *cadena)
{
    int a, b, c, d;
    char extra;

    if (sscanf(cadena, "%d.%d.%d.%d%c", &a, &b, &c, &d, &extra) != 4)
        return 0;

    return (a >= 0 && a <= 255 && b >= 0 && b <= 255 &&
            c >= 0 && c <= 255 && d >= 0 && d <= 255);
}

int esEmail(const char *cadena)
{
    int i = 0;
    int tieneArroba = 0;
    int tienePuntoDespuesArroba = 0;
    int longitudDominio = 0;

    if (!isalnum(cadena[i]) && cadena[i] != '.' && cadena[i] != '_' && cadena[i] != '-')
        return 0;

    while (cadena[i] != '\0')
    {
        if (cadena[i] == '@')
        {
            if (tieneArroba)
                return 0;
            tieneArroba = 1;
            if (i == 0 || cadena[i + 1] == '\0')
                return 0;
        }
        else if (cadena[i] == '.')
        {
            if (tieneArroba)
            {
                tienePuntoDespuesArroba = 1;
                longitudDominio = 0;
            }
            if (i == 0 || cadena[i + 1] == '\0' || cadena[i + 1] == '.')
                return 0;
        }
        else if (!isalnum(cadena[i]) && cadena[i] != '-' && cadena[i] != '_')
            return 0;

        if (tieneArroba && cadena[i] != '@' && cadena[i] != '.')
            longitudDominio++;
        i++;
    }

    return (tieneArroba && tienePuntoDespuesArroba && longitudDominio >= 2);
}

void problema3()
{
    char cadena[100];

    printf("=== RECONOCIMIENTO DE PATRONES ===\n");
    printf("Ejemplos:\n");
    printf("- Cientifica: 1.23e+10, -4.56E-5\n");
    printf("- IP: 192.168.1.1, 8.8.8.8\n");
    printf("- Email: usuario@correo.com, nombre@empresa.org\n");
    printf("Ingrese cadena: ");
    getchar();
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = 0;

    printf("\nAnalisis de: \"%s\"\n", cadena);
    printf("================================\n");

    int cientifica = esNotacionCientifica(cadena);
    int ip = esIP(cadena);
    int email = esEmail(cadena);

    printf("Notacion cientifica: %s\n", cientifica ? " SI" : " NO");
    printf("Direccion IP: %s\n", ip ? " SI" : " NO");
    printf("Correo electronico: %s\n", email ? " SI" : " NO");

    if (!cientifica && !ip && !email)
    {
        printf("\nLa cadena no coincide con ningun patron reconocido.\n");
    }
}
