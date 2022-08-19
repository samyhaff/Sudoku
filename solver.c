#include "constants.h"

int valid(int *grid, int pos, int value) {
    int row = pos / N, col = pos % N;
    int y0 = N_BLOCKS * row / N, x0 = N_BLOCKS * col / N;

    for (int i = 0; i < N; i++) {
        if (grid[N * row + i] == value) return 0;
        if (grid[N * i + col] == value) return 0;
    }

    for (int j = 0; j < N / N_BLOCKS; j++) {
        for (int i = 0; i < N / N_BLOCKS; i++) {
            pos = N * (N / N_BLOCKS * y0 + j) + N / N_BLOCKS * x0 + i;
            if (grid[pos] == value) return 0;
        }
    }

    return 1;
}

int solve(int *grid) {
    for (int i = 0; i < N*N; i++) {
        if (grid[i] == 0) {
            for (int v = 1; v <= MAX_VAL; v++) {
                if (valid(grid, i, v)) {
                    grid[i] = v;
                    if (solve(grid)) return 1;
                    grid[i] = 0;
                }
            }
            return 0;
        }
    }
    return 1;
}
