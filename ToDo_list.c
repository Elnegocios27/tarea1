#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 100

typedef struct
{
    char description[100];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int number_tasks = 0;

void show_menu()
{
    printf("=============================\n");
    printf(" Task List:\n");
    printf("=============================\n");
    printf("1. add task.\n");
    printf("2. show tasks.\n");
    printf("3. mark task completed\n");
    printf("4. delete task.\n");
    printf("5. exit.\n");
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

void save_tasks()
{
    FILE *archivo = fopen("tasks.txt", "w");
    if (archivo == NULL)
    {
        printf("fatal error.\n");
        return;
    }

    int i = 0;
    while (tasks[i].description[0] != '\0')
    {
        fprintf(archivo, "%s - %d\n", tasks[i].description, tasks[i].completed);
        i++;
    }
    fclose(archivo);
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
    printf("=============================\n");
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

int main()
{
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
            printf("Leaving...\n");
            return 0;

        default:
            printf("Fatal error\n");
            return 0;
        }
    }
}
