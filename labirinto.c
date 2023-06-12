#include "labirinto.h"

#include <stdio.h>
#include <stdlib.h>

struct labirinto{

  char **lab;
  int lins;
  int cols;

};

struct posicao{

  int x;
  int y;

};

struct percurso{

  Posicao** posicao_saida;
  int tamanho;

};



// Funcao que imprime pontilhados ate o final do lab;
void printLabirinto(Labirinto *labirinto, Posicao *posicao) {
  for (int i = 0; i < labirinto->lins; i++) {
    for (int j = 0; j < labirinto->cols; j++) {
      
      // Volta a colocar o 'M' na posicao inicial ja que a funcao acharSaida o substitui por pontilhado
      if(i == posicao->x && j == posicao->y){
        labirinto->lab[i][j] = 'M';
      }
      printf("%c", labirinto->lab[i][j]);
    }
    printf("\n");
  }
}

// Funcao que aloca memoria
Labirinto* alocarLabirinto(int lins, int cols) {
  Labirinto* labirinto = malloc(sizeof(Labirinto));
  
  labirinto->lins = lins;
  labirinto->cols = cols;

  labirinto->lab = malloc(lins * sizeof(char*));
  for(int i = 0; i < lins; i++){
    labirinto->lab[i] = malloc(cols * sizeof(char));
  }

  return labirinto;
}

Posicao* designaPosicao(int x, int y){
  Posicao* posicao = malloc(sizeof(Posicao));

  posicao->x = x;
  posicao->y = y;

  return posicao;
}

// Funcao que faz a leitura do labirinto
void leLabirinto(Labirinto *labirinto) {

  for (int i = 0; i < labirinto->lins; i++) {
    for (int j = 0; j < labirinto->cols; j++) {
      scanf("%c", &labirinto->lab[i][j]);
    }
    // Getchar para ler os espacos no labirinto 
    getchar();
  }
}

// Funcao para identificar a primeira localizacao do rato
void primeiraPosicao(Labirinto* labirinto, int* x, int* y){

    for(int i = 0; i < labirinto->lins; i++){
        for(int j = 0; j < labirinto->cols; j++){
            if(labirinto->lab[i][j] == 'M'){
                *x = i;
                *y = j;
                return;
            }
        }
    }
}


// Funcao que retorna a quantidade de passos ate o final do labirinto
int contador(Labirinto* labirinto){

    int contador = 0;

    for(int i = 0; i < labirinto->lins; i++){
        for(int j = 0; j < labirinto->cols; j++){
            if(labirinto->lab[i][j] == '.'){
                contador++;
            }        
        }
    }

    return contador - 1;
}

Percurso* alocarPercurso(Labirinto* labirinto, int x, int y){
  Percurso* percurso = malloc(sizeof(Percurso));

  int cont;
  cont = contador(labirinto);
  percurso->tamanho = cont;
  percurso->posicao_saida = (Posicao**)malloc(cont * sizeof(Posicao*));

  for(int i = 0; i < cont; i++){
    percurso->posicao_saida[i] = designaPosicao(x, y);
  }

  return percurso;

}

// Funcao que imprime as coordenadas ate o final do labirinto;
void designaCoordenadas(Labirinto* labirinto, Percurso* percurso, Posicao* posicao){

    for(int k = 0; k < percurso->tamanho; k++){
      percurso->posicao_saida[k]->x = -1;   // Inicializa as coordenadas com valor invalido (-1,-1)
      percurso->posicao_saida[k]->y = -1;
    }

    for(int i = 0; i < labirinto->lins; i++) {
      for(int j = 0; j < labirinto->cols; j++) {
        if(i == posicao->x && j == posicao->y){
        labirinto->lab[i][j] = 'M';
        }
        if(labirinto->lab[i][j] == '.') {
          for(int k = 0; k < percurso->tamanho; k++){
            if(percurso->posicao_saida[k]->x == -1 && percurso->posicao_saida[k]->y == -1){
              percurso->posicao_saida[k]->x = i;
              percurso->posicao_saida[k]->y = j;
              break;
            }
          }
        }
      }
    }
}

void printCoordenadas(Labirinto* labirinto, Percurso* percurso){

  if(percurso->tamanho >= 0){  
    printf("Coordenadas ate a saida: \n");
    for(int i = 0; i < percurso->tamanho; i++){
      printf("%d, %d\n", percurso->posicao_saida[i]->x, percurso->posicao_saida[i]->y);
    }
  }
}

// Funcao para achar o menor caminho atraves de recursao
int acharSaida(Labirinto* labirinto, Posicao* posicao){
  int x = posicao->x;
  int y = posicao->y;  
  // Verifica se está fora dos limites do labirinto ou encontrou um obstáculo
  if(x < 0 || x >= labirinto->lins || y < 0 || y >= labirinto->cols || labirinto->lab[x][y] == '*' || labirinto->lab[x][y] == '.' || labirinto->lab[x][y] == '#'){
    return 0;
  }

  // Verifica se chegou a uma borda do labirinto
  if(x == 0 || x == labirinto->lins - 1 || y == 0 || y == labirinto->cols - 1){
    labirinto->lab[x][y] = '.';
    return 1;
  }

  // Marca a posicao atual como visitada
  labirinto->lab[x][y] = '.';

  Posicao* nova_posicao;
  nova_posicao = designaPosicao(x, y);

  // Tenta mover para cima
  nova_posicao->x = x - 1;
  nova_posicao->y = y;
  if(acharSaida(labirinto, nova_posicao)){
    return 1;
  }

  // Tenta mover pra baixo
  nova_posicao->x = x+1;
  nova_posicao->y = y;
  if(acharSaida(labirinto, nova_posicao)){
    return 1;
  }

  // Tenta mover pra esquerda
  nova_posicao->x = x;
  nova_posicao->y = y-1;
  if(acharSaida(labirinto, nova_posicao)){
    return 1;
  }

  // Tenta mover pra direita
  nova_posicao->x = x;
  nova_posicao->y = y+1;
  if(acharSaida(labirinto, nova_posicao)){
    return 1;
  }

  // Marca atual posicao como nao visitada (backtracking)
  labirinto->lab[x][y] = ' ';

  return 0;
  
}

void passosAteSaida(Percurso* percurso){
  
  if(percurso->tamanho < 0){
    printf("EPIC FAIL!\n"); 
  } else {
    printf("Numero de passos:%d\n", percurso->tamanho);
  }
}

// Funcao para desalocar memoria
void desalocarLabirinto(Labirinto** labirinto){

    for(int i = 0; i < (*labirinto)->lins; i++){
        free((*labirinto)->lab[i]);
    }

      free((*labirinto)->lab);
      free(*labirinto);
}

void desalocarPosicao(Posicao** posicao){
  
  free(*posicao);

}

void desalocarPercurso(Percurso** percurso) {
   
  for(int i = 0; i < (*percurso)->tamanho; i++){
    desalocarPosicao(&(*percurso)->posicao_saida[i]);
  }
  
  free((*percurso)->posicao_saida);
  free(*percurso);
}