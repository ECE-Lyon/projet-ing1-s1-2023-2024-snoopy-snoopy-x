#ifndef PROJET_COULEURSPRINTF_H
#define PROJET_COULEURSPRINTF_H
#include <stdio.h>
#include <windows.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef enum{rouge, vert, jaune, bleu, magenta, cyan}COULEUR;

void printfCouleur(const char* str, COULEUR couleur);

#endif //PROJET_COULEURSPRINTF_H
