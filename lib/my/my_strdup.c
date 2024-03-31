/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** my_strdup
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int my_strlendup(char const *str)
{
    size_t length = 0;

    for (size_t c = 0; str[c] != '\0'; c = c + 1) {
        length = length +1;
    }
    return (length);
}

char *my_strdup(char const *src)
{
    int src_size;
    static char *strd;
    char *strd_off;

    src_size = my_strlendup(src);
    strd = (char *)malloc(sizeof(char)*src_size + 1);
    if (strd == NULL)
        return NULL;
    strd_off = strd;
    while (*src) {
        *strd_off = *src;
        strd_off++;
        src++;
    }
    if (strd == 0) {
        return (NULL);
    }
    *strd_off = '\0';
    return (strd);
}
