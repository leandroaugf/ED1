#include "labirinto.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    double tempo_exec;
    clock_t inicio, fim;

    inicio = clock();

    srand(time(NULL));

    // Declaracao de variaveis;
    Labirinto *labirinto;
    Posicao *posicao;
    int x, y;
    int lins, cols;
    char opcao;
    int cont; // Contador de passos


    scanf("%d %d", &lins, &cols);
    labirinto = alocarLabirinto(lins, cols);   // Alocacao do labirinto
    getchar();
    scanf("%c", &opcao);
    getchar();

    switch (opcao)
    {   
        // Imprime o labirinto com os pontilhados;
        case 'p':
          leLabirinto(labirinto);
          primeiraPosicao(labirinto, &x, &y);
          posicao = designaPosicao(x, y);
          acharSaida(labirinto, posicao);
          cont = contador(labirinto);
          if(cont < 0){ // Contador retorna negativo se o labirinto nao tiver saida
            printf("EPIC FAIL!\n");   
            break;
          }
          printf("Numero de passos:%d\n", cont);
          printf("Caminho da saida:\n");
          printLabirinto(labirinto, posicao);
        break;

        // Imprime as coordenadas ate o destinho;
        case 'c':
          leLabirinto(labirinto);
          primeiraPosicao(labirinto, &x, &y);
          posicao = designaPosicao(x, y);
          acharSaida(labirinto, posicao);
          cont = contador(labirinto);
          if(cont < 0){  // Contador retorna negativo se o labirinto nao tiver saida
            printf("EPIC FAIL!\n");
            break;
          }
          printf("Numero de passos:%d\n", cont);
          printf("Coordenadas ate a saida: \n");
          printCoordenadas(labirinto, posicao);
        break;
    }
  
  desalocarLabirinto(&labirinto);
  desalocarPosicao(&posicao);

  fim = clock();
  tempo_exec = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
  printf("\nTempo de execucao: %fs\n", tempo_exec);

  return 0;

}