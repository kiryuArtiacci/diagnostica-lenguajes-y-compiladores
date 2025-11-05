#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char ingles[20];
    char espanol[30];
} PalabraReservada;

PalabraReservada diccionario[] = {
    {"auto", "automatico"}, {"break", "romper"}, {"case", "caso"}, {"char", "caracter"}, {"const", "constante"}, {"continue", "continuar"}, {"default", "por_defecto"}, {"do", "hacer"}, {"double", "doble"}, {"else", "si_no"}, {"enum", "enumeracion"}, {"extern", "externo"}, {"float", "flotante"}, {"for", "para"}, {"goto", "ir_a"}, {"if", "si"}, {"int", "entero"}, {"long", "largo"}, {"register", "registro"}, {"return", "retornar"}, {"short", "corto"}, {"signed", "con_signo"}, {"sizeof", "tamano_de"}, {"static", "estatico"}, {"struct", "estructura"}, {"switch", "interruptor"}, {"typedef", "definir_tipo"}, {"union", "union"}, {"unsigned", "sin_signo"}, {"void", "vacio"}, {"volatile", "volatil"}, {"while", "mientras"}};

int esPalabraReservada(const char *palabra)
{
    int total = sizeof(diccionario) / sizeof(diccionario[0]);
    for (int i = 0; i < total; i++)
    {
        if (strcmp(palabra, diccionario[i].ingles) == 0)
            return i;
    }
    return -1;
}

void traducirCodigoC(const char *codigo)
{
    char *buffer = (char *)malloc(strlen(codigo) + 1);
    if (buffer == NULL)
    {
        printf("Error: No se pudo asignar memoria\n");
        return;
    }
    strcpy(buffer, codigo);

    char *token = strtok(buffer, " \t\n(){}[];,+*-/%=&|!<>");

    while (token != NULL)
    {
        int indice = esPalabraReservada(token);
        if (indice != -1)
            printf("%s ", diccionario[indice].espanol);
        else
            printf("%s ", token);
        token = strtok(NULL, " \t\n(){}[];,+*-/%=&|!<>");
    }
    printf("\n");

    free(buffer);
}

void problema4()
{
    char codigo[1000];

    printf("=== TRADUCTOR C -> ESPANOL ===\n");
    printf("Ejemplo: for(int i=0;i<10;i++) { if(x>5) return 1; }\n");
    printf("Ingrese codigo C: ");
    getchar();
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    printf("\n--- TRADUCCION ---\n");
    printf("Original:  %s\n", codigo);
    printf("Traducido: ");
    traducirCodigoC(codigo);

    printf("\n--- DETALLES ---\n");
    printf("- Se preservan operadores y estructura\n");
    printf("- Solo se traducen palabras reservadas\n");
    printf("- Se uso memoria dinamica para el buffer\n");
}
