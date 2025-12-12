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