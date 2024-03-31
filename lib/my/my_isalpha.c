/*
** EPITECH PROJECT, 2023
** my_isalpha
** File description:
** my_isalpha
*/

#include "my.h"

int my_isalpha(int a)
{
    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
        return (1);
    } else {
        return (0);
    }
}
