// user takes turns against existing board.
// for simplicity, this only models one move.
// also for now the board being guessed about is fixed.
// 10 x 10 board, ships with the Hasboro naming scheme

#include <stdio.h>
#include <stdlib.h>

int** make_board() {
    int size = 10;
    // allocate board space
    int* start = calloc(size * size, sizeof(int));
    int** board = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
        board[i] = start + i * size;

    // set board to all 0s
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j] = 0;

    // add ships
    board[1][1] = 1; 
    board[2][1] = 1; // patrol boat
    board[9][1] = 1; 
    board[9][2] = 1;
    board[9][2] = 1; // submarine
    board[1][4] = 1; 
    board[1][5] = 1;
    board[1][6] = 1; // destroyer
    board[6][6] = 1; 
    board[6][7] = 1;
    board[6][8] = 1;
    board[6][9] = 1; // battleship
    board[3][2] = 1; 
    board[4][2] = 1;
    board[5][2] = 1;
    board[6][2] = 1;
    board[7][2] = 1; // carrier
    return board;
}

void free_board(int** board) {
    free(*board);
    free(board);
}

int check_hit(int x, int y, int** board) {
    // treat off-board shots as misses
    if (x < 0 || x > 9 || y < 0 || y > 9) return 0;
    return board[x][y];
}

int main() {
    int** board = make_board();
    int x_guess, y_guess;

    int hit = check_hit(x_guess, y_guess, board);
    // printf("%d", hit);
    free_board(board);
    return 0;
}
