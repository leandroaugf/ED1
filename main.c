#include "labirinto.h"
#include "posicao.h"
#include "percurso.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char **lab; //**labSolucao;
    int lins, cols;
    char opcao;
    //Coordenadas* coordenadas;
    int x, y;
    int contador;


    scanf("%d %d", &lins, &cols);
    lab = alocarLabirinto(lins, cols); 
    //labSolucao = alocarLabirinto(lins, cols);
    getchar();
    scanf("%c", &opcao);
    getchar();

    switch (opcao)
    { 
        case 'p':
          leLabirinto(lab, lins, cols);
          //criaSolucao(labSolucao, lins, cols);
          primeiraPosicao(lab, lins, cols, &x, &y);
          printf("Caminho da saida:\n");
          acharSaida(lab, x, y, lins, cols);
          printLabirinto(lab, lins, cols);
        break;
      }


    desalocarLabirinto(lab, lins);
    //desalocarLabirinto(labSolucao, lins);

  return 0;

}