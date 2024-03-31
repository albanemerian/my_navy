/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-navy-albane.merian
** File description:
** helper
*/

#include "include/navy.h"

g_t g = {0};

void helper(int argc, char **argv)
{
    my_putstr("\x1B[1;32mUSAGE\n");
    my_putstr("    ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    first_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player.\n");
    my_putstr("    navy_positions: file representing the position of");
    my_putstr(" the ships.\n\x1B[00;37m");
}
