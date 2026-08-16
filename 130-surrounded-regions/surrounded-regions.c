/**
 * Return the board by modifying it in-place.
 */

void dfs(char** board, int row, int col, int rows, int cols) {
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        return;

    if (board[row][col] != 'O')
        return;

    board[row][col] = '#';

    dfs(board, row + 1, col, rows, cols);
    dfs(board, row - 1, col, rows, cols);
    dfs(board, row, col + 1, rows, cols);
    dfs(board, row, col - 1, rows, cols);
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0)
        return;

    int rows = boardSize;
    int cols = boardColSize[0];

    for (int i = 0; i < rows; i++) {
        if (board[i][0] == 'O')
            dfs(board, i, 0, rows, cols);

        if (board[i][cols - 1] == 'O')
            dfs(board, i, cols - 1, rows, cols);
    }

    for (int j = 0; j < cols; j++) {
        if (board[0][j] == 'O')
            dfs(board, 0, j, rows, cols);

        if (board[rows - 1][j] == 'O')
            dfs(board, rows - 1, j, rows, cols);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
}