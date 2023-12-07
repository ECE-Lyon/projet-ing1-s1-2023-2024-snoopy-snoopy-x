cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c entitees/personnage.h entitees/personnage.c consoleDebug/consoleDebug.c consoleDebug/consoleDebug.h ecranConsole.c ecranConsole.h partie.c partie.h plateau.c plateau.h entitees/balle.c entitees/balle.h entitees/blocs.c entitees/blocs.h menu.c menu.h)
add_executable(Exemple exempleTableau.c entitees/personnage.h entitees/personnage.c consoleDebug/consoleDebug.c consoleDebug/consoleDebug.h ecranConsole.c ecranConsole.h partie.c partie.h plateau.c plateau.h entitees/balle.c entitees/balle.h entitees/blocs.c entitees/blocs.h menu.c menu.h)
