#include "tarefa.h"
#include <stdio.h>
#include <string.h>

#define TASKS_FILE "tasks.txt"

void list_initiate(ListTasks *list)
{
    list->quantity = 0;
}

bool list_save(const ListTasks *list)
{
    FILE *file = fopen(TASKS_FILE, "w");
    if (file == NULL) {
        return false;
    }

    for (int i = 0; i < list->quantity; i++) {
        if (fprintf(file, "%d|%s\n", list->taskk[i].completed ? 1 : 0,
                    list->taskk[i].description) < 0) {
            fclose(file);
            return false;
        }
    }

    return fclose(file) == 0;
}

bool list_load(ListTasks *list)
{
    FILE *file = fopen(TASKS_FILE, "r");
    char line[MAX_TEXT + 3];

    if (file == NULL) {
        return true;
    }

    list->quantity = 0;
    while (list->quantity < MAX_TASKS && fgets(line, sizeof(line), file) != NULL) {
        char *separator = strchr(line, '|');
        size_t descriptionLength;

        if (separator == NULL || (line[0] != '0' && line[0] != '1')) {
            continue;
        }

        separator++;
        descriptionLength = strcspn(separator, "\r\n");
        separator[descriptionLength] = '\0';
        if (separator[0] == '\0') {
            continue;
        }

        strncpy(list->taskk[list->quantity].description, separator, MAX_TEXT - 1);
        list->taskk[list->quantity].description[MAX_TEXT - 1] = '\0';
        list->taskk[list->quantity].completed = line[0] == '1';
        list->quantity++;
    }

    fclose(file);
    return true;
}

bool list_add(ListTasks *list, const char *description)


{
    if (list->quantity >= MAX_TASKS) {
        return false;}
   
    if (description[0] == '\0') {
        return false;}

    for (int i = 0; i < list->quantity; i++) {
        if (strcmp(list->taskk[i].description, description) == 0) {
            return false;
        }
    }

    strncpy(list->taskk[list->quantity].description, description, MAX_TEXT - 1);
    list->taskk[list->quantity].description[MAX_TEXT - 1] = '\0';
    list->taskk[list->quantity].completed = false;
    list->quantity++;

    return true;
}

bool list_remove(ListTasks *list, int indice)
{
    if (indice < 0 || indice >= list->quantity) {
        return false; }

    for (int i = indice; i < list->quantity - 1; i++) {
        list->taskk[i] = list->taskk[i + 1];}

    list->quantity--;
    return true;}

bool list_completed(ListTasks *list, int indice)
{
    if (indice < 0 || indice >= list->quantity) {
        return false; }

    list->taskk[indice].completed = true;
    return true;}

void list_clear(ListTasks *list)
{
    list->quantity = 0;}