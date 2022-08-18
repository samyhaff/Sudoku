#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "game.h"

int main(int argc, char *argv[]) {
    int grid[N*N];
    if (argc < 2) {
        fprintf(stderr, "Usage : ./solver [grid_file]\n");
        exit(EXIT_FAILURE);
    }
    load_grid(argv[1], grid);
    print_grid(grid);

    return EXIT_SUCCESS;
}
