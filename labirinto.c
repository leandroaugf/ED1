#include "labirinto.h"

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

void leLabirinto(char **lab, int lins, int cols) {

  //[LEITURA DO LABIRINTO]
  for (int i = 0; i < lins; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%c", &lab[i][j]);
    }
    getchar();
  }

  printLabirinto(lab, lins, cols);
}

void desalocarLabirinto(char **lab, int lins){

    for(int i = 0; i < lins; i++){
        free(lab[i]);
    }

      free(lab);
}