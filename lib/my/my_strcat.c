/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int x = 0;
    int y = 0;

    while (dest[x] != '\0') {
        x++;
    }
    while (src[y] != '\0') {
            dest[x] = src[y];
            x++;
            y++;
        }
        dest[y] = '\0';
        return (dest);
}
