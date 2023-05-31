#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "posicao.h"

char** alocarLabirinto(int, int);
void leLabirinto(char **, int , int);
void desalocarLabirinto(char **, int);
int acharSaida(char**, int, int, int, int);
void criaSolucao(char**, int , int);
void printLabirinto(char **, int , int, int, int); 

#endif // LABIRINTO_H