/*
** EPITECH PROJECT, 2023
** my_header
** File description:
** my_ls
*/
#include <stdarg.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#ifndef MY_LS
    #define MY_LS
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_unsigned_nbr(unsigned int n);
int my_positive_nbr(int nb);
int my_isalpha(int a);
int my_isnum(char *nb);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
int my_printf(const char *format, ...);
int *my_revstr(int argc, char **argv);
int printf_d(const char *format, va_list param_infos, int i, int compt);
int printf_i(const char *format, va_list param_infos, int i, int compt);
int printf_s(const char *format, va_list param_infos, int i, int compt);
int printf_c(const char *format, va_list param_infos, int i, int compt);
int printf_o(const char *format, va_list param_infos, int i, int compt);
int printf_u(const char *format, va_list param_infos, int i, int compt);
int printf_x(const char *format, va_list param_infos, int i, int compt);
int printf_xm(const char *format, va_list param_infos, int i, int compt);
int printf_f(const char *format, va_list param_infos, int i, int compt);
int printf_fm(const char *format, va_list param_infos, int i, int compt);
int printf_cross(const char *format, va_list param_infos, int i, int compt);
int printf_l(const char *format, va_list param_infos, int i, int compt);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(const char *src, char *dest);
char *my_strstr(const char *str, int c);
int my_strcmp(char const *s1, char const *s2);
int strcmp_my(char const *s1, char const *s2);
int my_is_even(int nb);
int my_cmp(char const *s1, char const *s2);
int my_getnbr(char const *str);
int cmp_my(char const *s1, char const *s2);
void int_to_str(int nb, char *str);

#endif /* !my_ls */
