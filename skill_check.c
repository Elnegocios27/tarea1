#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option;
    while (1)
    {
        printf("=============================");
        printf("welcome to the skillchek game");
        printf("Best record:");
        printf("1. Play");
        printf("2. Salir");
        printf("=============================");
        printf("option: ");
        if (scanf("%d", &option) != 1)
        {
            printf("Invalid entry\n");
            while (getchar() != '\n')
                ;
        }
        switch (option)
        {
        case 1:
            printf("Playing...\n");
            break;
        case 2:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option\n");
            return 0;
        }
    }
}