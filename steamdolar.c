#include <stdio.h>
#include <stdlib.h>

double dolar;
double iva;
double cotizacion = 1220.98;
double pesos;
int opcion;


int main()
{
    while (opcion != 3)
    {
        printf("==============================\n");
        printf("          STEAMDOLAR         \n");
        printf(".Seleccione una opcion\n");
        printf("1.Dolares a Pesos\n");
        printf("2.Pesos a Dolares 'para hinchar'\n");
        printf("3.Salir\n");
        printf("==============================\n");
        printf(".opcion: ");
        if (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3)
        {
            printf("Opcion invalida\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcion)
        {
            case 1:
                printf("escriba la cantidad de dolares: ");
                if (scanf("%lf", &dolar) != 1)
                {
                    printf("opcion no valida, volviendo al menu\n");
                    while (getchar() != '\n');
                    continue;
                }

                pesos = dolar * cotizacion;
                iva = pesos * 1.21;
                printf("resultado: %f\n", iva);
                break;

            case 2:
                printf("escriba la cantidad de pesos: ");
                if (scanf("%lf", &pesos) != 1)
                {
                    printf("opcion no valida, volviendo al menu\n");
                    while (getchar() != '\n');
                    continue;
                }
                dolar = pesos / cotizacion;
                printf("resultado: %f\n", dolar);
                break;
            
            case 3:
                printf("saliendo de steamdolar\n.");
                return 0;
            
            default:
                printf("opcion no valida, algo maliosal\n");
                continue;
        }

    }
}