#include "menu/menu.h"

int main() {
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
    SMALL_RECT windowSize = {0, 0, 90, 70};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    SetConsoleTitle("SNOOPY X");
    afficherMenu();
}