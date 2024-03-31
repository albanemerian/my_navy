/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-navy-albane.merian
** File description:
** handler
*/

#include "include/navy.h"

void counter(int sign)
{
    if (sign == SIGUSR1)
        g.counter[1]++;
    if (sign == SIGUSR2)
        g.counter[2]++;
}

void return_play(int sign)
{
    if (sign == SIGUSR2 && g.stat[3] == 1) {
        g.stat[2] = 1;
        g.stat[4] = 1;
        g.stat[3] = 0;
        return;
    }
    if (sign == SIGUSR1 && g.stat[3] == 1) {
        g.stat[4] = 0;
        g.stat[3] = 0;
        return;
    }
    if (sign == SIGUSR2 && g.stat[2] == 1) {
        g.stat[2] = 2;
        return;
    }
}

void handleplay_2(int sign, siginfo_t *info, void *context)
{
    if (sign == 10 && g.stat[0] == 0) {
        my_printf("\nsuccessfully connected\n");
        g.p2 = info->si_pid;
        g.stat[0] = 1;
    }
    counter(sign);
    if (sign == SIGUSR2 && g.counter[2] == 1) {
        g.attack[1] = g.attack[1] + g.counter[1];
        g.counter[1] = 0;
    }
    if (sign == SIGUSR2 && g.counter[2] == 2) {
        g.attack[2] = g.attack[2] + g.counter[1];
        g.counter[1] = 0;
        g.stat[3] = 1;
        return;
    }
    return_play(sign);
}

void handleplay_1(int sign, siginfo_t *info, void *context)
{
    if (sign == 12 && g.stat[1] == 0) {
        my_printf("\nenemy connected\n");
        g.p2 = info->si_pid;
        g.stat[1] = 1;
        kill(info->si_pid, SIGUSR1);
    }
    counter(sign);
    if (sign == SIGUSR2 && g.counter[2] == 1) {
        g.attack[1] = g.attack[1] + g.counter[1];
        g.counter[1] = 0;
    }
    if (sign == SIGUSR2 && g.counter[2] == 2) {
        g.attack[2] = g.attack[2] + g.counter[1];
        g.counter[1] = 0;
        g.stat[3] = 1;
        return;
    }
    return_play(sign);
}
