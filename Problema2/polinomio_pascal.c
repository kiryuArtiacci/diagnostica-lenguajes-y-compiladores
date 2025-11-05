#include <stdio.h>
#include <stdlib.h>

int *generarCoeficientes(int n)
{
    int *coef = (int *)malloc((n + 1) * sizeof(int));
    if (coef == NULL)
        return NULL;

    coef[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        coef[i] = 1;
        for (int j = i - 1; j > 0; j--)
        {
            coef[j] = coef[j] + coef[j - 1];
        }
    }

    return coef;
}

double calcularPolinomio(int *coef, int n, double x)
{
    double resultado = 0;
    double potencia_x = 1;

    printf("Calculo paso a paso para x = %.2f:\n", x);
    for (int i = 0; i <= n; i++)
    {
        double termino = coef[i] * potencia_x;
        printf("  %d * %.2f^%d = %.2f\n", coef[i], x, i, termino);
        resultado += termino;
        potencia_x *= x;
    }

    return resultado;
}

void problema2()
{
    int n;
    double x;

    printf("Ingrese n (entero no negativo): ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Error: n debe ser no negativo\n");
        return;
    }

    printf("Ingrese x: ");
    scanf("%lf", &x);

    int *coef = generarCoeficientes(n);
    if (coef == NULL)
    {
        printf("Error: No se pudo asignar memoria\n");
        return;
    }

    printf("\nCoeficientes del polinomio (x+1)^%d:\n", n);
    for (int i = 0; i <= n; i++)
    {
        printf("a%d = %d\n", i, coef[i]);
    }

    printf("\nPolinomio: ");
    for (int i = n; i >= 0; i--)
    {
        if (coef[i] != 0)
        {
            if (i == n)
                printf("%dx^%d", coef[i], i);
            else if (i == 1)
                printf(" + %dx", coef[i]);
            else if (i == 0)
                printf(" + %d", coef[i]);
            else
                printf(" + %dx^%d", coef[i], i);
        }
    }
    printf("\n\n");

    double resultado = calcularPolinomio(coef, n, x);
    printf("\nResultado final: f(%.2f) = %.2f\n", x, resultado);

    free(coef);
}
