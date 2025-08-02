#include <stdio.h>
#include <stdlib.h>

float addition(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}

void show_menu()
{
    printf("=============================\n");
    printf("         calculator         \n");
    printf("1. addition\n");
    printf("2. subtract\n");
    printf("3. multiply\n");
    printf("4. divide\n");
    printf("=============================\n");
}

int ask_data(float data[])
{
    printf("enter the first number: ");
    if (scanf("%f", &data[0]) != 1)
    {
        printf("invalid entry.\n");
        while (getchar() != '\n')
            return 0;
    }

    printf("enter the second number: ");
    if (scanf("%f", &data[1]) != 1)
    {
        printf("invalid entry.\n");
        while (getchar() != '\n')
            return 0;
    }
    return 1;
}

int main()
{
    int option = 0;
    float data[2];
    float result;

    while (option != 5)
    {
        show_menu();
        printf("option: ");

        if (scanf("%d", &option) != 1 || option < 1 || option > 5)
        {
            printf("invalid entry.\n");
            while (getchar() != '\n')
                continue;
        }

        switch (option)
        {
        case 1:
            if (ask_data(data))
            {
                result = addition(data[0], data[1]);
                printf("result: %.2f", result);
            }
            break;

        case 2:
            if (ask_data(data))
            {
                result = subtract(data[0], data[1]);
                printf("result: %.2f", result);
            }
            break;

        case 3:
            if (ask_data(data))
            {
                result = multiply(data[0], data[1]);
                printf("result: %.2f", result);
            }
            break;

        case 4:
            if (ask_data(data))
            {
                result = divide(data[0], data[1]);
                printf("result: %.2f", result);
            }
            break;

        case 5:
            printf("leaving.");
            break;

        default:
            printf("fatal error.\n");
            break;
        }
        return 0;
    }
}