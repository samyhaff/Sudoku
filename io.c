#include <stdlib.h>
#include <stdio.h>
#include "constants.h"

void load_grid(char *path, int *grid) {
    FILE *fptr;
    char ch;
    int i = 0;

    fptr = fopen(path, "r");
    if (!fptr) {
        fprintf(stderr, "Error opening grid file\n");
        exit(EXIT_FAILURE);
    }

    do {
        ch = fgetc(fptr);
        if (ch != '\n') grid[i++] = ch - '0';
    } while (ch != EOF);

    fclose(fptr);
}

void print_grid(int *grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", grid[N * i + j]);
        printf("\n");
    }
}
