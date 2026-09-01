#include "tarefa.h"
#include <string.h>

void list_initiate(ListTasks *list)
{
    list->quantity = 0;
}

bool list_add(ListTasks *list, const char *description)


{
    if (list->quantity >= MAX_TASKS) {
        return false; // Lista cheia
    }
   
    if (description[0] == '\0') {
        return false;
    }

    if (list->quantity > 0) {
        for (int i = 0; i < list->quantity; i++) {
            if (strcmp(list->task[i].description, description) == 0) {
                return false;
            }
        }
    }
    else {
        strncpy(list->task[list->quantity].description, description, MAX_TEXT - 1);
        list->task[list->quantity].description[MAX_TEXT - 1] = '\0'; 
        list->task[list->quantity].completed = false;
        list->quantity++;
    }

    return true;
}

bool list_remove(ListTasks *list, int indice)
{
    if (indice < 0 || indice >= list->quantity) {
        return false;
    }

    for (int i = indice; i < list->quantity - 1; i++) {
        list->task[i] = list->task[i + 1];
    }

    list->quantity--;
    return true;
}