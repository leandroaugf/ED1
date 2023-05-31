#include "labirinto.h"
#include "posicao.h"
#include "percurso.h"

#include <stdio.h>
#include <stdlib.h>

// Funcao que imprime pontilhados ate o final do lab;
void printLabirinto(char **lab, int lins, int cols, int x, int y) {
  for (int i = 0; i < lins; i++) {
    for (int j = 0; j < cols; j++) {
      
      // Volta a colocar o 'M' na posicao inicial ja que a funcao acharSaida o substitui por pontilhado
      if(i == x && j == y){
        lab[i][j] = 'M';
      }
      printf("%c", lab[i][j]);
    }
    printf("\n");
  }
}

// Funcao que aloca memoria
char** alocarLabirinto(int lins, int cols) {
  char **lab = malloc(lins * sizeof(char*));
  for (int i = 0; i < lins; i++) {
    lab[i] = malloc(cols * sizeof(char));
  }

  return lab;
}

// Funcao que faz a leitura do labirinto
void leLabirinto(char **lab, int lins, int cols) {

  for (int i = 0; i < lins; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%c", &lab[i][j]);
    }
    // Getchar para ler os espacos no labirinto 
    getchar();
  }
}

// Funcao para achar o menor caminho atraves de recursao
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

// Funcao para desalocar memoria
void desalocarLabirinto(char **lab, int lins){

    for(int i = 0; i < lins; i++){
        free(lab[i]);
    }

      free(lab);
}