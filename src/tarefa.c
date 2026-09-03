#include "tarefa.h"
#include <string.h>

void list_initiate(ListTasks *list)
{
    list->quantity = 0;
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