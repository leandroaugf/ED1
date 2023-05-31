#include "labirinto.h"
#include "posicao.h"
#include "percurso.h"

#include <stdio.h>
#include <stdlib.h>

void printLabirinto(char **lab, int lins, int cols) {
  for (int i = 0; i < lins; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c", lab[i][j]);
    }
    printf("\n");
  }
}

char** alocarLabirinto(int lins, int cols) {
  char **lab = malloc(lins * sizeof(char*));
  for (int i = 0; i < lins; i++) {
    lab[i] = malloc(cols * sizeof(char));
  }

  return lab;
}

void criaSolucao(char** solucao, int lins, int cols){

    for(int i = 0; i < lins; i++){
      for(int j = 0; j < cols; j++){
        solucao[i][j] = '*';
      }
    }

}


void leLabirinto(char **lab, int lins, int cols) {

  //[LEITURA DO LABIRINTO]

  for (int i = 0; i < lins; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%c", &lab[i][j]);
    }
    getchar();
  }
}

int acharSaida(char** lab, int x, int y, int lins, int cols){  
  // Verifica se está fora dos limites do labirinto ou encontrou um obstáculo
  if(x < 0 || x >= lins || y < 0 || y >= cols || lab[x][y] == '*' || lab[x][y] == '.'){
    return 0;
  }

  // Verifica se chegou a uma borda do labirinto
  if(x == 0 || x == lins - 1 || y == 0 || y == cols - 1){
    lab[x][y] = '.';
    return 1;
  }

  // Marca a posicao atual como visitada
  lab[x][y] = '.';

  // Tenta mover para cima
  if(acharSaida(lab, x-1, y, lins, cols)){
    return 1;
  }

  // Tenta mover pra baixo
  if(acharSaida(lab, x+1, y, lins, cols)){
    return 1;
  }

  // Tenta mover pra esquerda
  if(acharSaida(lab, x, y-1, lins, cols)){
    return 1;
  }

  // Tenta mover pra direita
  if(acharSaida(lab, x, y+1, lins, cols)){
    return 1;
  }

  // Marca atual posicao como nao visitada (backtracking)
  lab[x][y] = ' ';

  return 0;
  
}

void desalocarLabirinto(char **lab, int lins){

    for(int i = 0; i < lins; i++){
        free(lab[i]);
    }

      free(lab);
}