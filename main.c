#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "game_logic.h"

int main()
{
    int option;
    srand(time(NULL));
    while (1)
    {
        print_menu();

        printf("Option: ");
        if (scanf("%d", &option) != 1)
        {
            printf("Invalid entry\n");
            while (getchar() != '\n')
                continue;
        }
        switch (option)
        {
        case 1:
            printf("===Starting!===\n");
            run_game();
            break;
        case 2:
            printf("===Leaving the game===\n");
            return 0;
            break;
        default:
            printf("error\n");
            return 0;
        }
    }
}