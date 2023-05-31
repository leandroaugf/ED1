#include "labirinto.h"
#include "posicao.h"
#include "percurso.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // Declaracao de variaveis;
    char **lab; 
    int lins, cols;
    char opcao;
    int x, y; // Posicao inicial do rato
    int cont; // Contador de passos


    scanf("%d %d", &lins, &cols);
    lab = alocarLabirinto(lins, cols);   // Alocacao do labirinto
    getchar();
    scanf("%c", &opcao);
    getchar();

    switch (opcao)
    {   
        // Imprime o labirinto com os pontilhados;
        case 'p':
          leLabirinto(lab, lins, cols);
          primeiraPosicao(lab, lins, cols, &x, &y);
          acharSaida(lab, x, y, lins, cols);
          cont = contador(lab, lins, cols);
          if(cont < 0){ // Contador retorna negativo se o labirinto nao tiver saida
            printf("EPIC FAIL!\n");   
            break;
          }
          printf("Numero de passos:%d\n", cont);
          printf("Caminho da saida:\n");
          printLabirinto(lab, lins, cols, x, y);
        break;

        // Imprime as coordenadas ate o destinho;
        case 'c':
          leLabirinto(lab, lins, cols);
          primeiraPosicao(lab, lins, cols, &x, &y);
          acharSaida(lab, x, y, lins, cols);
          cont = contador(lab, lins, cols);
          if(cont < 0){  // Contador retorna negativo se o labirinto nao tiver saida
            printf("EPIC FAIL!\n");
            break;
          }
          printf("Numero de passos:%d\n", cont);
          printf("Coordenadas ate a saida: \n");
          printCoordenadas(lab, lins, cols, x, y);
        break;
    }
  
  desalocarLabirinto(lab, lins);

  return 0;

}