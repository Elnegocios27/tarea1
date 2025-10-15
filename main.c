#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "game_logic.h"

int main()
{
    srand(time(NULL));
    while (1)
    {
        print_menu();
        int option;
        printf("Option: ");
        if (scanf("%d", &option))
        {
            printf("Invalid entry\n");
            while (getchar() != '\n')
                continue;
        }
        switch (option)
        {
        case 1:
            printf("===Starting!===");
            run_game();
        case 2:
            printf("===Leaving the game===");
            return 0;
        default:
            printf("error");
            return 0;
        }
    }
}