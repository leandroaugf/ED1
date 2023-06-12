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
    Percurso *percurso;
    int x, y;
    int lins, cols;
    char opcao;

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
          percurso = alocarPercurso(labirinto, x, y);
          passosAteSaida(percurso);
          printf("Caminho da saida:\n");
          printLabirinto(labirinto, posicao);
        break;

        // Imprime as coordenadas ate o destinho;
        case 'c':
          leLabirinto(labirinto);
          primeiraPosicao(labirinto, &x, &y);
          posicao = designaPosicao(x, y);
          acharSaida(labirinto, posicao);
          percurso = alocarPercurso(labirinto, x, y);
          passosAteSaida(percurso);
          designaCoordenadas(labirinto, percurso, posicao);
          printCoordenadas(labirinto, percurso);
        break;
    }
  
  desalocarLabirinto(&labirinto);
  desalocarPosicao(&posicao);
  desalocarPercurso(&percurso);

  fim = clock();
  tempo_exec = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
  printf("\nTempo de execucao: %fs\n", tempo_exec);

  return 0;

}