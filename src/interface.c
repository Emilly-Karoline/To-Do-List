#include <interface.h>
#include <tarefa.h>
#include <raylib.h>

void interf_initiate(StatusInterface *status)
{
    status->letterCount = 0;
    status->bufferTexto[0] = '\0';
}

void interf_text_input(StatusInterface *status)
{
    int key = GetCharPressed();
    while (key > 0) {
        if (key >= 32 && key <= 125 && status->letterCount < MAX_TEXT - 1) {
            status->bufferTexto[status->letterCount] = (char)key;
            status->letterCount++;
            status->bufferTexto[status->letterCount] = '\0';
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE) && status->letterCount > 0) {
        status->letterCount--;
        status->bufferTexto[status->letterCount] = '\0';
    }
}

void interf_draw_text(StatusInterface *status)
{
    DrawRectangle(50, 50, 300, 30, LIGHTGRAY);
    DrawText(status->bufferTexto, 55, 55, 20, BLACK);
}

void interf_add_button(StatusInterface *status, ListTasks *lista)
{
    Rectangle buttonRect = { 360, 50, 100, 30 };
    Color buttonColor = LIGHTGRAY;

    Vector2 mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, buttonRect)) {
        buttonColor = GRAY;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ENTER)) {
            if (list_add(lista, status->bufferTexto)) {
                status->letterCount = 0;
                status->bufferTexto[0] = '\0';
            }
        }
    }

    DrawRectangleRec(buttonRect, buttonColor);
    DrawText("Adicionar", buttonRect.x + 10, buttonRect.y + 5, 20, BLACK);
}

void interf_draw_list(ListTasks *list)
{
    for (int i = 0; i < list->quantity; i++) {
        int y = 100 + i * 40;
        DrawText(list->task[i].description, 50, y, 20, BLACK);

        Rectangle completeButtonRect = { 360, y, 80, 30 };
        Color completeButtonColor = LIGHTGRAY;
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, completeButtonRect)) {
            completeButtonColor = GRAY;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                list_completed(list, i);
            }
        }
        DrawRectangleRec(completeButtonRect, completeButtonColor);
        DrawText("Concluir", completeButtonRect.x + 10, completeButtonRect.y + 5, 20, BLACK);

        Rectangle removeButtonRect = { 450, y, 80, 30 };
        Color removeButtonColor = LIGHTGRAY;
        if (CheckCollisionPointRec(mousePoint, removeButtonRect)) {
            removeButtonColor = GRAY;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                list_remove(list, i);
                break; // Break to avoid issues with changing indices
            }
        }
        DrawRectangleRec(removeButtonRect, removeButtonColor);
        DrawText("Remover", removeButtonRect.x + 10, removeButtonRect.y + 5, 20, BLACK);
    }
}

void interf_clear_button(ListTasks *list)
{
    Rectangle clearButtonRect = { 50, 500, 150, 30 };
    Color clearButtonColor = LIGHTGRAY;

    Vector2 mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, clearButtonRect)) {
        clearButtonColor = GRAY;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            list_clear(list);
        }
    }

    DrawRectangleRec(clearButtonRect, clearButtonColor);
    DrawText("Limpar Lista", clearButtonRect.x + 10, clearButtonRect.y + 5, 20, BLACK);
}