#ifndef FUNCTION_H
#define FUNCTION_H
typedef struct
{
    char description[100];
    int completed;
} Task;

extern int number_tasks;

void show_menu();

void add_tasks();

void tick_completed();

void show_tasks();

void delete_task();

void load_task();

void save_task();

#endif