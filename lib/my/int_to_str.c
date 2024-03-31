/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-navy-albane.merian
** File description:
** int_to_str
*/

#include "my.h"

int count_nb(int nb)
{
    int count = 1;
    int m = nb / 10;

    while (m != 0) {
        count++;
        m /= 10;
    }
    return (count);
}

void int_to_str(int nb, char *str)
{
    int nb_length = count_nb(nb);

    for (int x = nb_length - 1; x >= 0; x--) {
        str[x] = '0' + (nb % 10);
        nb /= 10;
    }
    str[nb_length] = '\0';
}
