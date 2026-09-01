#include <raylib.h>
#include <tarefa.h>
#include <interface.h>
#include <stdio.h>

int main()
{
    ListTasks list;

    list_initiate(&list);

    printf("Quantidade: %d\n", list.quantity);

    return 0;
}