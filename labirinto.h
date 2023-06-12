#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct labirinto Labirinto;
typedef struct posicao Posicao;
typedef struct percurso Percurso;

Labirinto* alocarLabirinto(int, int);
void leLabirinto(Labirinto*);
void desalocarLabirinto(Labirinto**);
int acharSaida(Labirinto*, Posicao*);
void criaSolucao(char**, int , int);
void printLabirinto(Labirinto*, Posicao*); 
void primeiraPosicao(Labirinto*, int*, int*);
int contador(Labirinto*);
void designaCoordenadas(Labirinto*, Percurso*, Posicao*);
void printCoordenadas(Labirinto*, Percurso*);
Posicao* designaPosicao(int, int);
void desalocarPosicao(Posicao**);
Percurso* alocarPercurso(Labirinto*, int, int);
void desalocarPercurso(Percurso**);
void passosAteSaida(Percurso*);


#endif // LABIRINTO_H