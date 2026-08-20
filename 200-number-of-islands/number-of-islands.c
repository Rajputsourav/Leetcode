#include <stdio.h>
#include <stdlib.h>

void dfs(char** grid, int gridSize, int* gridColSize, int r, int c) {
    if (r < 0 || r >= gridSize || c < 0 || c >= gridColSize[r] ||
        grid[r][c] != '1') {
        return;
    }

    grid[r][c] = '0';

    dfs(grid, gridSize, gridColSize, r + 1, c);
    dfs(grid, gridSize, gridColSize, r - 1, c);
    dfs(grid, gridSize, gridColSize, r, c + 1);
    dfs(grid, gridSize, gridColSize, r, c - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {

            if (grid[i][j] == '1') {
                count++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }

    return count;
}