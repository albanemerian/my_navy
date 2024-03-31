/*
** EPITECH PROJECT, 2023
** printf_u
** File description:
** printf_u
*/
#include "my.h"
#include <stdarg.h>
static int nb_length(int n)
{
    int len = 1;

    while (n > 9) {
        n = n / 10;
        len ++;
    }
    return (len);
}

int printf_u(const char *format,
    va_list param_infos, int i, int compt)
{
    unsigned int j = va_arg(param_infos, unsigned int);

    if (j >= 0) {
        my_unsigned_nbr(j);
    }
    return (nb_length(j));
}
