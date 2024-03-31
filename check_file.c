/*
** EPITECH PROJECT, 2024
** navy
** File description:
** check_file
*/

#include "include/navy.h"
#include <stdbool.h>

bool check_lines(char ch, char min, char max)
{
    if (ch < min || max < ch)
        return false;
    return true;
}

int colon_cpt(char *line)
{
    int n = 0;

    while (*line) {
        if (*line == ':')
            n++;
        line++;
    }
    return n;
}

int check_buffer(char *line, char i)
{
    if (line == NULL || line[0] == '\0' || line[0] != i
        || !check_lines(line[0], '2', '5'))
        return 84;
    if (!check_lines(line[2], 'A', 'H') || !check_lines(line[5], 'A', 'H'))
        return 84;
    if (!check_lines(line[3], '1', '8') || !check_lines(line[6], '1', '8'))
        return 84;
    if (line[1] != ':' || colon_cpt(line) != 2 || line[4] != ':')
        return 84;
    if (line[2] == line[5] && line[3] == line[6])
        return 84;
    return 0;
}

int check_filepath(char *av)
{
    FILE *f = fopen(av, "r");
    size_t len = 0;
    ssize_t r;
    char *row = NULL;
    char i = '2';
    int k = 0;

    if (f == NULL)
        return 84;
    for (r = getline(&row, &len, f); r != -1;
        r = getline(&row, &len, f)) {
        if (my_strlen(row) == 0 || check_buffer(row, i) == 84)
            return 84;
        i++;
        k++;
    }
    if (k != 4 || fill_board(av) == NULL)
        return 84;
    fclose(f);
    return 0;
}
