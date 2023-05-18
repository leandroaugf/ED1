#include <stdio.h>

#define N 5 // Tamanho do labirinto

int labirinto[N][N] = {
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

int solucao[N][N]; // Matriz para armazenar a solução

int encontrarCaminho(int x, int y) {
    // Verificar se chegamos ao final
    if (x == N - 1 && y == N - 1) {
        solucao[x][y] = 1;
        return 1;
    }

    // Verificar se a posição atual é válida
    if (x >= 0 && y >= 0 && x < N && y < N && labirinto[x][y] == 1) {
        // Marcar a posição atual como parte da solução
        solucao[x][y] = 1;

        // Mover para a direita
        if (encontrarCaminho(x, y + 1))
            return 1;

        // Mover para baixo
        if (encontrarCaminho(x + 1, y))
            return 1;

        // Se nenhuma direção leva ao final, marcar a posição como não parte da solução
        solucao[x][y] = 0;
        return 0;
    }

    return 0;
}

void imprimirLabirinto() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", labirinto[i][j]);
        }
        printf("\n");
    }
}

void imprimirSolucao() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", solucao[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Labirinto:\n");
    imprimirLabirinto();
    
    printf("\nEncontrando a solução...\n");
    if (encontrarCaminho(0, 0)) {
        printf("Solução encontrada!\n\n");
        printf("Solução:\n");
        imprimirSolucao();
    } else {
        printf("Nenhuma solução encontrada.\n");
    }

    return 0;
}
