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

void leLabirinto() {
  char **lab;
  int lins, cols;
  scanf("%d %d", &lins, &cols);
  lab = alocarLabirinto(lins, cols); 
  getchar();
  //[LEITURA DO LABIRINTO]
  for (int i = 0; i < lins; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%c", &lab[i][j]);
    }
    getchar();
  }

  printLabirinto(lab, lins, cols);
}


int main(void) {
  leLabirinto();
  return 0;
}