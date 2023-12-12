#include "couleursPrintf.h"

void printfCouleur(const char* str, COULEUR couleur) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch(couleur) {
        case rouge :
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("%s", str);
            break;
        case vert :
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s", str);
            break;
        case bleu :
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("%s", str);
            break;
        case jaune :
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            printf("%s", str);
            break;
        case cyan :
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
            printf("%s", str);
            break;
        case magenta :
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
            printf("%s", str);
            break;
        default : printf("Ya un pb là");
    }
}