#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "constants.h"
#include "solver.h"

int main(int argc, char *argv[]) {
    int grid[N*N];
    if (argc < 2) {
        fprintf(stderr, "Usage : ./main [grid_file]\n");
        exit(EXIT_FAILURE);
    }
    load_grid(argv[1], grid);
    if (solve(grid)) print_grid(grid);
    else printf("Unsolvable\n");

    return EXIT_SUCCESS;
}
