/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-navy-albane.merian
** File description:
** send_pos
*/

#include "include/navy.h"

void send_letter(char na)
{
    for (int letter = 64; letter < na; letter++) {
        kill(g.p2, SIGUSR1);
        usleep(100);
    }
    kill(g.p2, SIGUSR2);
    usleep(100);
}

void send_number(char na)
{
    for (int number = 48; number < na; number++) {
        kill(g.p2, SIGUSR1);
        usleep(100);
    }
    kill(g.p2, SIGUSR2);
}
