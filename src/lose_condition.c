/*
** EPITECH PROJECT, 2024
** navy
** File description:
** lose_condition
*/

#include "../include/my.h"

int if_num(char c, int x)
{
    if (c == 'x')
        x++;
    return x;
}

int lose_condition(char **board)
{
    int x = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 16; j++) {
            x = if_num(board[i][j], x);
        }
    }
    if (x != 14)
        return 1;
    return 0;
}
