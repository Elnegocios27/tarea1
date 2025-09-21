#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main()
{
    load_task();
    int option;

    while (1)
    {
        show_menu();
        printf("Option: ");
        if (scanf("%d", &option) != 1)
        {
            printf("Invalid entry\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (option)
        {
        case 1:
            add_tasks();
            printf("\n");
            break;

        case 2:
            show_tasks();
            printf("\n");
            break;

        case 3:
            tick_completed();
            printf("\n");
            break;

        case 4:
            delete_task();
            printf("\n");
            break;

        case 5:
            save_task();
            printf("Leaving...\n");
            return 0;

        default:
            printf("Fatal error\n");
            return 0;
        }
    }
}
