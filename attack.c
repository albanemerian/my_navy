/*
** EPITECH PROJECT, 2024
** navy
** File description:
** attack
*/

#include "include/navy.h"

char **add_cross(char **my_board, navy_t *na)
{
    char start_col = na->let;
    int start_row = na->num - '0';
    int col_index = start_col - 'A';

    if (my_board[start_row - 1][col_index * 2] == '.')
        my_board[start_row - 1][col_index * 2] = 'o';
    if (check_lines(my_board[start_row - 1][col_index * 2], '1', '8'))
        my_board[start_row - 1][col_index * 2] = 'x';
    return my_board;
}

void att_ennemy(char **board, navy_t *na)
{
    char start_col = g.attack[1];
    int start_row = g.attack[2] - '0';
    int col_index = start_col - 'A';

    if (check_lines(board[start_row - 1][col_index * 2], '1', '8')) {
        my_printf("%c%c:hit\n", g.attack[1], g.attack[2]);
        kill(g.p2, SIGUSR2);
    } else {
        my_printf("%c%c:missed\n", g.attack[1], g.attack[2]);
        kill(g.p2, SIGUSR1);
    }
}

void status(navy_t *na)
{
    if (g.stat[4] == 1)
        my_printf("\nresult: %c%c:hit\n", na->l[0], na->l[1]);
    if (g.stat[4] == 0)
        my_printf("\nresult: %c%c:missed\n", na->l[0], na->l[1]);
}

char **attack_ennemy(char **board, char *pos, navy_t *na)
{
    if (!check_lines(na->l[0], 'A', 'H') || !check_lines(na->l[1], '1', '8')) {
        my_printf("\nwrong position\n");
        my_printf("\nattack: ");
        return NULL;
    }
    return board;
}
