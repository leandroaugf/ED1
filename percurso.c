#include "labirinto.h"
#include "posicao.h"
#include "percurso.h"

#include <stdio.h>
#include <stdlib.h>

// Funcao que retorna a quantidade de passos ate o final do labirinto
int contador(char** lab, int lins, int cols){

    int contador = 0;

    for(int i = 0; i < lins; i++){
        for(int j = 0; j < cols; j++){
            if(lab[i][j] == '.'){
                contador++;
            }        
        }
    }

    return contador - 1;
}

// Funcao que imprime as coordenadas ate o final do labirinto;
void printCoordenadas(char** lab, int lins, int cols, int x, int y){

    for(int i = 0; i < lins; i++){
        for(int j = 0; j < cols; j++){
           
           // Volta a colocar o 'M' na posicao inicial ja que a funcao acharSaida o substitui por pontilhado
           if(i == x && j == y){
            lab[i][j] = 'M';
           }

            if(lab[i][j] == '.'){
                printf("%d, %d\n", i, j);
            }
        }
    }
}