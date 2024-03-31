/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-navy-albane.merian
** File description:
** maps_attack
*/

#include "include/navy.h"

char **upt_board(char **my_board, navy_t *na)
{
    char start_col = na->l[0];
    int start_row = na->l[1] - '0';
    int col_index = start_col - 'A';

    if (g.stat[4] == 0) {
        if (my_board[start_row - 1][col_index * 2] == '.')
            my_board[start_row - 1][col_index * 2] = 'o';
    }
    if (g.stat[4] == 1)
        my_board[start_row - 1][col_index * 2] = 'x';
    return my_board;
}

static char **player1_map(navy_t *na, char **my_board)
{
    if (g.stat[1] != 2) {
        my_board = fill_board(na->map1);
        display_board(my_board);
        my_printf("\nenemy navy:\n");
        na->enem = initboard();
        display_board(na->enem);
        who_plays(na, my_board);
        g.stat[1] = 2;
    } else {
        my_board = add_cross(my_board, na);
        display_board(my_board);
        my_printf("\nenemy navy:\n");
        display_board(na->enem);
        who_plays(na, my_board);
    }
    return my_board;
}

char **maps_player1(char **my_board, char **argv, navy_t *na)
{
    g.counter[1] = 0;
    g.counter[2] = 0;
    g.attack[1] = '@';
    g.attack[2] = '0';
    if (na->is_my_turn == true) {
        na->map1 = argv[1];
        my_printf("\nmy navy:\n");
        my_board = player1_map(na, my_board);
    } else {
        who_plays(na, my_board);
    }
    return my_board;
}

static char **player2_map(navy_t *na, char **board)
{
    if (g.stat[0] != 2) {
        board = fill_board(na->map2);
        display_board(board);
        my_printf("\nenemy navy:\n");
        na->enem = initboard();
        display_board(na->enem);
        who_plays(na, board);
        g.stat[0] = 2;
    } else {
        board = add_cross(board, na);
        display_board(board);
        my_printf("\nenemy navy:\n");
        display_board(na->enem);
        who_plays(na, board);
    }
    return board;
}

char **maps_player2(char **board, char **argv, navy_t *na)
{
    g.counter[1] = 0;
    g.counter[2] = 0;
    g.attack[1] = '@';
    g.attack[2] = '0';
    if (na->is_my_turn == false) {
        na->map2 = argv[2];
        my_printf("\nmy navy:\n");
        board = player2_map(na, board);
    } else {
        who_plays(na, board);
    }
    return board;
}
