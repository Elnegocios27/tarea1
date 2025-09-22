#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 100

Task tasks[MAX_TASKS];
int number_tasks = 0;

void show_menu()
{
    printf("=============================\n");
    printf("    welcome to ToDo list!   \n");
    printf("1. Add tasks.\n");
    printf("2. Show tasks.\n");
    printf("3. Tick completed.\n");
    printf("4. Delete tasks.\n");
    printf("5. Exit.\n");
    printf("=============================\n");
}

void add_tasks()
{
    if (number_tasks >= MAX_TASKS)
    {
        printf("No more tasks can be added");
        return;
    }

    printf("enter the task description: ");
    while (getchar() != '\n')
        ;

    fgets(tasks[number_tasks].description, sizeof(tasks[number_tasks].description), stdin);

    size_t len = strlen(tasks[number_tasks].description);
    if (len > 0 && tasks[number_tasks].description[len - 1] == '\n')
    {
        tasks[number_tasks].description[len - 1] = '\0';
    }

    tasks[number_tasks].completed = 0;
    number_tasks++;

    printf("task added\n");
}

void show_tasks()
{
    if (number_tasks == 0)
    {
        printf("There are no registered tasks.\n");
        return;
    }

    printf("========= ToDo list =========\n");

    for (int i = 0; i < number_tasks; i++)
    {
        printf("%d. [%c] %s\n", i + 1,
               tasks[i].completed ? 'x' : ' ',
               tasks[i].description);
    }
}

void tick_completed()
{
    if (number_tasks == 0)
    {
        printf("there are no tasks");
        return;
    }

    int index;
    while (1)
    {
        printf("=============================\n");
        show_tasks();
        printf("task tick: ");

        if (scanf("%d", &index) != 1)
        {
            printf("invalid entry\n");
            while (getchar() != '\n')
                continue;
        }

        if (index < 1 || index > number_tasks)
        {
            printf("number out of range\n");
            continue;
        }

        index = index - 1;

        if (tasks[index].completed)
        {
            printf("the task is marked as completed\n");
        }

        else
        {
            tasks[index].completed = 1;
            printf("the task was marked as completed!\n");
        }
        break;
    }
}

void delete_task()
{
    int index;
    printf("=============================\n");
    show_tasks();
    printf("Select the task:");
    if (scanf("%d", &index) != 1)
    {
        printf("invalid entry\n");
        while (getchar() != '\n')
            continue;
    }

    if (index < 1 || index > number_tasks)
    {
        printf("number out of range\n");
        return;
    }

    for (int i = index - 1; i < number_tasks - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }

    number_tasks--;

    printf("task deleted\n");
}

void save_task()
{
    FILE *archivo = fopen("tasks.txt", "w");
    if (archivo == NULL)
    {
        printf("fatal error.\n");
        return;
    }

    for (int i = 0; i < number_tasks; i++)
    {
        fprintf(archivo, "%s - %d\n", tasks[i].description, tasks[i].completed);
    }
    fclose(archivo);
}

void load_task()
{
    FILE *archivo = fopen("tasks.txt", "r");
    if (archivo == NULL)
    {
        printf("no previous tasks.\n");
        return;
    }

    int i = 0;

    while (fscanf(archivo, " %[^-] - %d\n", tasks[i].description, &tasks[i].completed) == 2)
    {
        i++;
    }
    fclose(archivo);
    number_tasks = i;
}
