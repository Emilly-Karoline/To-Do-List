#include <interface.h>
#include <string.h>

const Rectangle addButton ={348, 166 , 101 , 19};
const Rectangle removeButton ={22, 519 , 123 , 23};
const Rectangle clearButton ={360, 519 , 123 , 23};

const Rectangle inputText = { 50, 160, 280, 20 };
const Rectangle listArea = { 46, 200, 408, 340 }; 

char textDig[MAX_TEXT] = "\0";
int contLatter = 0;
int selecTask = -1; 

void initiateInterf(TextureBack *back){
    InitWindow(500,600, "My To-Do list");
    SetTargetFPS(60);

    back->main=LoadTexture("assets/main_layout.png");
    back->clikAdd=LoadTexture("assets/add_cliked.png");
    back->clikRemove= LoadTexture("assets/remove_cliked.png");
    back->clikClear= LoadTexture("assets/clear_cliked.png");

}

void updateInterf(ScreenState *state, float *timer, ListTasks *mytask){
    Vector2 mousePos = GetMousePosition();
 
    int key=GetCharPressed();
    while (key>0)
    {
        if ((key>= 32)&& (key<=125) && (contLatter<MAX_TEXT-1)){
        textDig[contLatter]= (char)key;
        textDig[contLatter+1]= '\0';
        contLatter++;}
        
            key=GetCharPressed();}
    
    if (IsKeyPressed(KEY_BACKSPACE)&& contLatter>0){
        contLatter--;
        textDig[contLatter]= '\0';}
    

    if (*state ==  Main_Screen){
      
        if (CheckCollisionPointRec(mousePos, addButton)&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {  
            *state = Add_b_Screen;
        *timer = 0.50f;
            if (list_add(mytask, textDig)){
                textDig[0]='\0';
                contLatter=0; } }
    

        else if (CheckCollisionPointRec(mousePos,removeButton)&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                *state = Remove_b_Screen;
            *timer = 0.5f;
            if(selecTask!= -1){
                    list_remove(mytask,selecTask);
                selecTask=1;} }
        
        else if(CheckCollisionPointRec(mousePos, clearButton)&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            *state = Clear_b_Screen;
            *timer = 0.50f;
                list_clear(mytask);
            selecTask=-1;}
    
        for (int i = 0; i < mytask->quantity; i++){
            int posY= listArea.y + (i*30);
            Rectangle checkButton= {listArea.x, posY +2,16,16};
            if(CheckCollisionPointRec(mousePos,checkButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                list_completed(mytask, i); } 
            else if(CheckCollisionPointRec(mousePos,listArea)&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                selecTask=i; } }
     }
    else{
        *timer -= GetFrameTime();
        if(*timer <=0.0f){ *state = Main_Screen; } }
    
}

void drawInterf(TextureBack back , ScreenState state,ListTasks mytask){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (state == Add_b_Screen){
        DrawTexture(back.clikAdd,0,0,WHITE);}

    else if(state== Remove_b_Screen){
        DrawTexture(back.clikRemove,0,0,WHITE);}

    else if (state== Clear_b_Screen){
        DrawTexture(back.clikClear,0,0,WHITE);  }
    
    else{
        DrawTexture(back.main,0,0,WHITE); }

    // Bordas de ajuste: mostram as areas reais usadas na colisao do mouse.
   
    DrawRectangleLinesEx(inputText, 1, PINK);
    
    DrawText(textDig, inputText.x +5,inputText.y +2,16,DARKBLUE);

    for (int i = 0; i < mytask.quantity; i++) {
        int posY= listArea.y +(i*30);

        Rectangle checkButton ={listArea.x,posY+2,16,16};
        
        Color colorButtonAll =WHITE;
        Color colorButtonLine =DARKGRAY;
        Color colorText= DARKBLUE;

        if(mytask.taskk[i].completed){
            colorButtonAll=PINK;
            colorButtonLine=MAROON;
            colorText= PINK; }
        if (i== selecTask)  {
            colorText=PINK;}

        DrawRectangleRec(checkButton,colorButtonAll);
        DrawRectangleRoundedLinesEx(checkButton,1,1,1,colorButtonLine);
        DrawText(mytask.taskk[i].description,listArea.x+25,posY+2,16,colorText);
        if (mytask.taskk[i].completed){
            int textWidth=MeasureText(mytask.taskk[i].description,16);
                DrawLine(listArea.x+25,posY+10,listArea.x+25+textWidth,posY+10,MAROON); }
        
    }
    
    EndDrawing();
}

void endInterf(TextureBack back){
    UnloadTexture(back.clikAdd);
    UnloadTexture(back.clikClear);
    UnloadTexture(back.clikRemove);
    UnloadTexture(back.main);
    CloseWindow();}
