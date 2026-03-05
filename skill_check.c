#include <stdio.h>
#include <stdlib.h>
#include "config.h"

int main()
{
    int option;
    while (1)
    {
        print_menu();
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
            initialize_game();
            break;
        case 2:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option\n");
            continue;
        }
    }
}