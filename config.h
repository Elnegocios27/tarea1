#ifndef CONFIG_H
#define CONFIG_H

// constantes del juego
#define BAR_LENGHT 50
#define INITIAL_ZONE_SIZE 10
#define INITIAL_GREAT_ZONE 3
#define INITIAL_MOVE_DELAY_MS 50

// codigos de color
#define ANSI_COLOR_RED "\x1b[31m"   // para zona peligrosa
#define ANSI_COLOR_GREEN "\x1b[32m" // para zona segura
#define ANSI_COLOR_RESET "\x1b[0m"  // reset de color

// definicion de funciones
void initialize_game();
int run_skill_check();
void update_dificulty();
void drow_bar(int position, int success_start, int success_end, int great_start, int great_end, int current_zone_size);
void print_menu();
#endif