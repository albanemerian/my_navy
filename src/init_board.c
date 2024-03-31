/*
** EPITECH PROJECT, 2024
** navy
** File description:
** init board
*/

#include "../include/navy.h"

char **initboard(void)
{
    char **board = (char **)malloc(8 * sizeof(char *));

    if (board == NULL) {
        write(2, "Error: unsuccessful malloc\n", 28);
        return NULL;
    }
    for (int i = 0; i < 8; i++) {
        board[i] = (char *)malloc(1 + 16 * sizeof(char));
        for (int m = 0; m < 16; m++) {
            board[i][m] = (m % 2 == 0) ? '.' : ' ';
        }
    }
    return board;
}

void display_board(char **b)
{
    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 16; j++) {
            my_printf("%c", b[i][j]);
        }
        my_printf("\n");
    }
}

char **error_board(char **board, int i, char *pos)
{
    int size = pos[0] - '0';
    char start_col = pos[2];
    char end_col = pos[5];

    for (int j = (start_col - 'A') * 2; j <= (end_col - 'A') * 2; j += 2) {
        if (board[i][j] != '.')
            return NULL;
        board[i][j] = size + '0';
    }
    return board;
}

static char **ships_on_board(char **board, char *pos)
{
    int start_row = pos[3] - '0';
    int end_row = pos[6] - '0';
    int start_col = pos[2] - 'A';
    int end_col = pos[5] - 'A';

    if ((end_col - start_col) + (end_row - start_row) + 1 != pos[0] - '0')
        return NULL;
    for (int i = start_row - 1; i < end_row; i++) {
        if (error_board(board, i, pos) == NULL)
            return NULL;
    }
    return board;
}

char **fill_board(char *av)
{
    FILE *f = fopen(av, "r");
    size_t len = 0;
    ssize_t r;
    char *row = NULL;
    char **b = initboard();

    if (f == NULL)
        return NULL;
    for (r = getline(&row, &len, f); r != -1; r = getline(&row, &len, f)) {
        if (ships_on_board(b, row) == NULL)
            return NULL;
    }
    fclose(f);
    return (b);
}
