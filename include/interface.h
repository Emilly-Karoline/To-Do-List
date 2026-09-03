#ifndef INTERFACE_H
#define INTERFACE_H

#include "tarefa.h"
#include "raylib.h"

typedef enum{
    Main_Screen,
    Add_b_Screen,
    Remove_b_Screen,
    Clear_b_Screen

} ScreenState;

typedef struct
{
    Texture2D main;
    Texture2D clikAdd;
    Texture2D clikRemove;
    Texture2D clikClear;

}TextureBack;

void initiateInterf(TextureBack *back);
void updateInterf(ScreenState *state, float *timer, ListTasks *mytask);
void drawInterf(TextureBack back , ScreenState state,ListTasks mytask);
void endInterf(TextureBack back);



#endif