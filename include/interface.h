#ifndef INTERFACE_H
#define INTERFACE_H

#include "tarefa.h"

typedef struct {
    char bufferTexto[MAX_TEXT];
    int letterCount;
} StatusInterface;

void interf_initiate(StatusInterface *status);
void interf_text_input(StatusInterface *status);
void interf_draw_text(StatusInterface *status);
void interf_add_button(StatusInterface *status, ListTasks *lista);
void interf_draw_list(ListTasks *list);
void interf_clear_button(ListTasks *list);


#endif