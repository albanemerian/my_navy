/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-navy-albane.merian
** File description:
** main
*/

#include "include/navy.h"

int error_handling(int argc)
{
    if (argc < 2) {
        write(2, "Not enough arguments\n", 22);
        return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    navy_t na = {0};

    g.p1 = getpid();
    if (error_handling(argc) == 84)
        return 84;
    if (argc == 2) {
        if (check_filepath(argv[1]) == 84)
            return 84;
        player(argv, &na);
        if (g.stat[2] == 1)
            return 1;
    }
    if (argc == 3) {
        if (check_filepath(argv[2]) == 84)
            return 84;
        allow_connection(argv, &na);
        if (g.stat[2] == 1)
            return 1;
    }
    return 0;
}
