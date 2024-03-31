/*
** EPITECH PROJECT, 2023
** printf_p
** File description:
** printf_p
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

static int nb_length(int n)
{
    int len = 1;

    while (n > 9) {
        n = n / 10;
        len ++;
    }
    return (len);
}

int printf_p(const char *format,
    va_list param_infos, int i, int compt)
{
    my_putstr("0x");
    printf_xp(format, param_infos, i, compt);
}
