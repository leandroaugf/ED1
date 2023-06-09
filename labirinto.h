#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct labirinto Labirinto;

Labirinto* alocarLabirinto(int, int);
void leLabirinto(Labirinto*);
void desalocarLabirinto(Labirinto**);
int acharSaida(Labirinto*, int, int);
void criaSolucao(char**, int , int);
void printLabirinto(Labirinto*, int, int); 
void primeiraPosicao(Labirinto*, int*, int*);
int contador(Labirinto*);
void printCoordenadas(Labirinto*, int, int);


#endif // LABIRINTO_H