#include <stdio.h>
#include <stdlib.h>

float num1;
float num2;
int opcion;
float resultado;
char letra;

int main()
{
    while (opcion != 5)
{    
printf("==============================\n");
printf("          calculadora         \n");
printf(".Seleccione una operacion\n");
printf("1.Suma\n");
printf("2.Resta\n");
printf("3.Multiplicacion\n");
printf("4.Division\n");
printf("5.Salir\n");
printf("==============================\n");
printf(".opcion: ");
scanf("%d", &opcion);

while (opcion < 1 || opcion > 5)
{
    printf("opcion no valida\n");
    printf("opcion:");
    scanf("%d", &opcion);
}

switch (opcion)
{
    case 1:
    printf("ingrese el primer numero: ");
    scanf("%f", &num1);

    printf("ingrese el segundo numero: ");
    scanf("%f", &num2);
        resultado = num1 + num2;
        printf("resultado de la suma: %f\n", resultado);
        break;

    case 2:
    printf("ingrese rl primer numero:");
    scanf("%f", &num1);

    printf("ingrese el segundo numero:");
    scanf("%f", &num2);
        resultado = num1 - num2;
        printf("resultado de la resta: %f\n", resultado);
        break;

    case 3:
    printf("ingrese el primer numero:");
    scanf("%f", &num1);

    printf("ingrese el segundo numero:");
    scanf("%f", &num2);
        resultado = num1 * num2;
        printf("resultado de la multiplicacion: %f\n", resultado);
        break;

    case 4:
    printf("ingrese el primer numero:");
    scanf("%f", &num1);

    printf("ingrese el segundo numero:");
    scanf("%f", &num2);
        resultado = num1 / num2;
        printf("resultado de la division: %f\n", resultado);
        break;
    
    case 5:
    printf("saliste de la calculadora\n");
    return 0;
    
    default: printf("caracter no valido");
    return 0;
    break;   
}
}
}