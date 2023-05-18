#include "labirinto.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char **lab;
    int lins, cols;

    scanf("%d %d", &lins, &cols);
    lab = alocarLabirinto(lins, cols); 
    getchar();

    leLabirinto(lab, lins, cols);

    desalocarLabirinto(lab, lins);

  return 0;
}