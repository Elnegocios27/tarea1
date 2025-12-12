#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "config.h"
#include <windows.h>
#include <time.h>
#include <math.h>

int succes_count = 0;
int fall_count = 0;
int perfect_count = 0;

int current_zone_size = INITIAL_ZONE_SIZE;
int current_great_zone = INITIAL_GREAT_ZONE;
int current_move_delay = INITIAL_MOVE_DELAY_MS;

void delay_ms(int milliseconds)
{
    Sleep(milliseconds);
}

int getchar_nonblocking()
{
    if (_kbhit())
    {
        return _getch();
    }
    return -1; // No key pressed
}

void print_menu()
{
    printf("=============================\n");
    printf("welcome to the skillchek game\n");
    printf("Best puntation: %d\n", succes_count);
    printf("Fails: %d\n", fall_count);
    printf("=============================\n");
    printf("1. Play\n");
    printf("2. Exit\n");
    printf("=============================\n");
    printf("option: \n");
}

void initialize_game()
{
    srand(time(NULL));
    printf("enter any key to try a successful skill check...\n");
    delay_ms(2000);
}
