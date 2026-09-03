#include "tarefa.h"
#include "interface.h"



int main(void) {
    TextureBack back;
    ScreenState state= Main_Screen;
    float VisualTimer = 0.0f;

    ListTasks mytask;
    list_initiate(&mytask);
    initiateInterf(&back);
    while (!WindowShouldClose())
    {
        updateInterf(&state,&VisualTimer,&mytask);
        drawInterf(back,state,mytask);
    }
    endInterf(back);
    
   

    return 0;
}