#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printLabyrinth(char **labyrinth, int lins, int cols) {
    for (int i = 0; i < lins; i++) {
            printf("%s", labyrinth[i]);
    }
}

char** alocarLabirinto(int lins, int cols) {
    char **labirinto = malloc(lins * sizeof(char*));
    for (int i = 0; i < lins; i++) {
        labirinto[i] = malloc(cols * sizeof(char));
    }

    return labirinto;
}

void leLabirinto(int lins, int cols) {
    //char arquivo[30]; //char opt;
    /*printf("Digite o nome do arquivo a ser aberto: ");
    scanf("%s", arquivo);
    FILE *arq = fopen(arquivo);
    fscanf(arquivo ,"%d %d", &lins, &cols);
    char **labirinto = alocarLabirinto(lins, cols);
    fgets(100, labirinto, stdin);*/

    char **labirinto = alocarLabirinto(lins, cols);
    //scanf("%c", &opt);
    for (int i = 0; i < lins + 1; i++) {
        fgets(labirinto[i], sizeof(labirinto[i]), stdin);
    }
    printLabyrinth(labirinto, lins, cols);
}

int main() {
    int lins, cols;
    scanf("%d %d", &lins, &cols);
    getchar();

    leLabirinto(lins, cols);
    
    return 0;
}