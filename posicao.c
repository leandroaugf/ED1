#include "labirinto.h"
#include "posicao.h"
#include "percurso.h"

#include <stdio.h>
#include <stdlib.h>


/*Coordenadas* designaCoordenadas(int i, int j){
     
    Coordenadas* coordenadas = malloc(sizeof(Coordenadas));
    
    coordenadas->x = i;
    coordenadas->y = j;

    return coordenadas;

}*/

void primeiraPosicao(char**lab, int lins, int cols, int* x, int* y){

    for(int i = 0; i < lins; i++){
        for(int j = 0; j < cols; j++){
            if(lab[i][j] == 'M'){
                *x = i;
                *y = j;
                return;
            }
        }
    }
}