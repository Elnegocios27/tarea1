#include <stdio.h>
#include <stdlib.h>

float sumar(float a, float b)
{
    return a + b;
}

float restar(float a, float b)
{
    return a - b;
}

float multiplicar(float a, float b)
{
    return a * b;
}

float dividir(float a, float b)
{
    return a / b;
}

void mostrar_menu()
{
    printf("=============================\n");
    printf("         calculadora         \n");
    printf("1. sumar\n");
    printf("2. restar\n");
    printf("3. multiplicar\n");
    printf("4. dividir\n");
    printf("=============================\n");
}

int pedir_datos(float datos[])
{
    printf("ingrese el primer numero: ");
    if (scanf("%f", &datos[0]) != 1)
    {
        printf("entrada invalida.\n");
        while (getchar() != '\n')
            return 0;
    }

    printf("ingrese el segundo numero: ");
    if (scanf("%f", &datos[1]) != 1)
    {
        printf("entrada invalida.\n");
        while (getchar() != '\n')
            return 0;
    }
    return 1;
}

int main()
{
    int opcion = 0;
    float datos[2];
    float resultado;

    while (opcion != 5)
    {
        mostrar_menu();
        printf("opcion: ");

        if (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5)
        {
            printf("entrada invalida.\n");
            while (getchar() != '\n')
                continue;
        }

        switch (opcion)
        {
        case 1:
            if (pedir_datos(datos))
            {
                resultado = sumar(datos[0], datos[1]);
                printf("resultado: %.2f", resultado);
            }
            break;

        case 2:
            if (pedir_datos(datos))
            {
                resultado = restar(datos[0], datos[1]);
                printf("resultado: %.2f", resultado);
            }
            break;

        case 3:
            if (pedir_datos(datos))
            {
                resultado = multiplicar(datos[0], datos[1]);
                printf("resultado: %.2f", resultado);
            }
            break;

        case 4:
            if (pedir_datos(datos))
            {
                resultado = dividir(datos[0], datos[1]);
                printf("resultado: %.2f", resultado);
            }
            break;

        case 5:
            printf("saliendo de la calculadora.");
            break;

        default:
            printf("fatal error.\n");
            break;
        }
        return 0;
    }
}