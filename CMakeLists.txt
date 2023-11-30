cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c personnage.c personnage.h consoleDebug/consoleDebug.c consoleDebug/consoleDebug.h ecranConsole.c ecranConsole.h partie.c partie.h plateau.c plateau.h balle.c balle.h)
add_executable(Exemple exempleTableau.c personnage.h personnage.c consoleDebug/consoleDebug.c consoleDebug/consoleDebug.h ecranConsole.c ecranConsole.h partie.c partie.h plateau.c plateau.h balle.c balle.h)
