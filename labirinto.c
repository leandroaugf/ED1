#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void generateLabyrinth(char labyrinth[HEIGHT][WIDTH]) {
    // Initialize labyrinth with walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            labyrinth[i][j] = '*';
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate labyrinth paths
    for (int i = 1; i < HEIGHT - 1; i += 2) {
        for (int j = 1; j < WIDTH - 1; j += 2) {
            labyrinth[i][j] = ' ';

            if (i < HEIGHT - 2) {
                if (rand() % 2 == 0) {
                    labyrinth[i + 1][j] = ' ';
                } else {
                    labyrinth[i][j + 1] = ' ';
                }
            } else {
                labyrinth[i][j + 1] = ' ';
            }
        }
    }

    // Set the start and end points
    labyrinth[1][0] = 'S';
    labyrinth[HEIGHT - 2][WIDTH - 1] = 'E';
}

void printLabyrinth(char labyrinth[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", labyrinth[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char labyrinth[HEIGHT][WIDTH];

    generateLabyrinth(labyrinth);
    printLabyrinth(labyrinth);

    return 0;
}
