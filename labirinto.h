#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct labirinto Labirinto;
typedef struct posicao Posicao;
typedef struct percurso Percurso;

Labirinto* alocarLabirinto(int, int);   ///////1
void leLabirinto(Labirinto*);          //////2
void primeiraPosicao(Labirinto*, int*, int*);     /////3
Posicao* designaPosicao(int, int);         //////4
int acharSaida(Labirinto*, Posicao*);   //////5
Percurso* alocarPercurso(Labirinto*, int, int);   ////6
void passosAteSaida(Percurso*);      ////7
void printLabirinto(Labirinto*, Posicao*);     /////8
void designaCoordenadas(Labirinto*, Percurso*, Posicao*);   /////9
void printCoordenadas(Percurso*);        /////10
void desalocarLabirinto(Labirinto**);    /////11
void desalocarPosicao(Posicao**);        /////12
void desalocarPercurso(Percurso**);      ////13


#endif // LABIRINTO_H