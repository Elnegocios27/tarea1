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

void enable_ansi()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, mode);
}

void delay_ms(int milliseconds)
{
    Sleep(milliseconds); // Defino una función que no devuelve nada y que, al ser llamada, pausa la ejecución del programa durante la cantidad de milisegundos indicada
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
    run_skill_check();
}

void update_difficulty()
{
    int total_success = succes_count + perfect_count;
    int reduction = perfect_count / 3;
    current_great_zone = INITIAL_GREAT_ZONE - reduction;
    if (current_great_zone < 1)
    {
        current_great_zone = 1; // clamp, evita que la zona de exito desaparezca o rompa el programa//
    }

    int speed_increase = total_success * 5; // multiplica la velocidad del juego por la cantidad de aciertos
    current_move_delay = INITIAL_MOVE_DELAY_MS - speed_increase;
    if (current_move_delay < 10)
    {
        current_move_delay = 10;
    }
}

void draw_bar(int position, int success_start, int success_end, int great_start, int great_end, int current_zone_size)
{
    printf("\r[");
    for (int i = 0; i < BAR_LENGHT; i++)
    {
        if (i == position)
        {
            printf("^");
        }
        else if (i >= great_start && i < great_end)
        {
            printf("%s=%s", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
        }
        else if (i >= success_start && i < success_end)
        {
            printf("%s-%s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
        }
        else
        {
            printf("-");
        }
    }
    printf("]");
    fflush(stdout);
}

int run_skill_check()
{
    int success_start;
    int great_start;
    int hit_position = -1;
    int key_press;

    update_difficulty();
    success_start = rand() % (BAR_LENGHT - current_zone_size);
    great_start = success_start + (current_zone_size / 2) - (current_great_zone / 2);
    int success_end = success_start + current_zone_size;
    int great_end = great_start + current_great_zone;

    for (int current_pos = 0; current_pos < BAR_LENGHT; current_pos++)
    {
        draw_bar(current_pos, success_start, success_end, great_start, great_end, current_zone_size);
        if (kbhit())
        {
            key_press = getch();
            hit_position = current_pos;
            break;
        }
        delay_ms(current_move_delay);
    }
    printf("\n");
    if (hit_position != -1)
    {
        if (hit_position >= great_start && hit_position < great_end)
        {
            printf("%sRESULTADO: ¡ÉXITO EXCELENTE! (Perfecto)%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
            perfect_count++;
            return 2;
        }
        else if (hit_position >= success_start && hit_position < success_end)
        {
            printf("RESULTADO: ÉXITO (Normal)\n");
            succes_count++;
            return 1;
        }
        else
        {
            printf("%sRESULTADO: ¡FALLO! (Fuera de zona)%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
            fall_count++;
            return -1;
        }
    }
    else
    {
        printf("%sRESULTADO: ¡FALLO! (No presionaste ninguna tecla)%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
        fall_count++;
        return -1;
    }
}