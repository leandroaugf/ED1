#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct labirinto Labirinto;
typedef struct posicao Posicao;


Labirinto* alocarLabirinto(int, int);
void leLabirinto(Labirinto*);
void desalocarLabirinto(Labirinto**);
int acharSaida(Labirinto*, Posicao*);
void criaSolucao(char**, int , int);
void printLabirinto(Labirinto*, Posicao*); 
void primeiraPosicao(Labirinto*, int*, int*);
int contador(Labirinto*);
void printCoordenadas(Labirinto*, Posicao*);
Posicao* designaPosicao(int, int);
void desalocarPosicao(Posicao**);


#endif // LABIRINTO_H