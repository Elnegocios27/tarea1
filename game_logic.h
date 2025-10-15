#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
extern int rock;
extern int papper;
extern int scissors;

int get_computer_choice();

int determine_winner(int user_choice, int comp_choice);

void print_choice(int choice);

void run_game();

void print_menu();

#endif