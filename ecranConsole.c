#include "ecranConsole.h"

void gotoligcol(int lig, int col){
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

void clearConsole(){
    gotoligcol(0, 0);
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 80; j++){
            printf(" ");
        }
    }
}