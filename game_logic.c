#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_logic.h"

int rock = 1;
int paper = 2;
int scissors = 3;

int get_computer_choice()
{
    int random_num = rand() % 3;
    return random_num + 1;
}

void run_game()
{
    int user_choice;

    do
    {
        printf("play: ");
        if (scanf("%d", &user_choice) != 1)
        {
            printf("Error.\n");
            while (getchar() != '\n')
                continue;
        }
    } while (user_choice < 1 || user_choice > 3);

    int comp_choice = get_computer_choice();

    printf("your selection: ");
    print_choice(user_choice);
    printf("\ncpu selection: ");
    print_choice(comp_choice);
    printf("\n\n");

    int winner = determine_winner(user_choice, comp_choice);

    if (winner == 1)
    {
        printf("You win!!!\n");
    }
    else if (winner == -1)
    {
        printf("you lose...\n");
    }
    else
    {
        printf("draw ._.\n");
    }
}

int determine_winner(int user_choice, int comp_choice)
{
    if (user_choice == comp_choice)
    {
        return 0; // tie
    }

    else if ((user_choice == 1 && comp_choice == 3) ||
             (user_choice == 2 && comp_choice == 1) ||
             (user_choice == 3 && comp_choice == 2))
    {
        return 1; // win
    }
    else
    {
        return -1;
    }
}

void print_choice(int choice)
{
    switch (choice)
    {
    case 1:
        printf("rock");
        break;
    case 2:
        printf("Paper");
        break;
    case 3:
        printf("Scissors");
        break;
    default:
        printf("invalid choice");
        break;
    }
}

void print_menu()
{
    printf("=============================\n");
    printf(" Welcome to PRS \n");
    printf("1. Play\n");
    printf("2. Exit\n");
    printf("TIP: rock = 1, paper = 2, scissors = 3\n");
    printf("=============================\n");
}