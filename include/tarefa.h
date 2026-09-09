#ifndef TAREFA_H
#define TAREFA_H

#include <stdbool.h>

#define MAX_TASKS  100   // capacidade máxima da lista
#define MAX_TEXT    128   // tamanho máximo do texto de uma tarefa


// Estrutura para representar uma tarefa , que contém uma descrição e um status de conclusão
typedef struct {
    char description[MAX_TEXT];
    bool completed;
} Tasks;

// Estrutura para armazenar a lista de tarefas
typedef struct {
    Tasks taskk[MAX_TASKS];
    int quantity;
} ListTasks;



void list_initiate(ListTasks *list);

bool list_save(const ListTasks *list);

bool list_load(ListTasks *list);

bool list_add(ListTasks *list, const char *description);

bool list_remove(ListTasks *list, int indice);

bool list_completed(ListTasks *list, int indice);

void list_clear(ListTasks *list);

#endif