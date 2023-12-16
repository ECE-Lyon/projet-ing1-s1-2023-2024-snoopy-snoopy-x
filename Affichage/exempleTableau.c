#include <stdio.h>
#include "../niveaux/Niveau1/Niveau1.h"

int main() {
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
    SMALL_RECT windowSize = {0, 0, 90, 70};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    SetConsoleTitle("SNOOPY X");
    NIVEAU niveau1;
    niveau1 = initNiveau(1);
    while(1);
}
