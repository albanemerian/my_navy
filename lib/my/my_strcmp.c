/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** my_strcmp
*/
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int a = my_strlen(s1);
    int b = my_strlen(s2);

    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] == s2[i] && a == b) {
            return (1);
        }
    }
    return 0;
}

int strcmp_my(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return (0);
        }
    }
    return 1;
}

int my_cmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[i]) {
            return (1);
        }
    }
    return 0;
}

int cmp_my(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] > s2[i]) {
            return (1);
            }
        if (s1[i] < s2[i]) {
            return (-1);
        }
    }
}
