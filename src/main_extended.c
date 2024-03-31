/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-navy-albane.merian
** File description:
** main_extended
*/

#include "../include/navy.h"

static void last_display(navy_t *na, char **board)
{
    my_printf("\nmy navy:\n");
    display_board(board);
    my_printf("\nenemy navy:\n");
    display_board(na->enem);
}

static int display_last(navy_t *na, char **board)
{
    if (g.stat[2] == 1) {
        last_display(na, board);
        my_printf("\nEnemy won\n");
        return 1;
    }
    return 0;
}

static void is_finished(navy_t *na, char **board)
{
    if (lose_condition(na->enem) == 0) {
        kill(g.p2, SIGUSR2);
        usleep(100);
        last_display(na, board);
        my_printf("\nI won\n");
        g.stat[2] = 0;
        na->isfinished = true;
    } else {
        kill(g.p2, SIGUSR1);
        g.stat[2] = 0;
    }
}

static void handle_pos(navy_t *na)
{
    send_letter(na->l[0]);
    usleep(100);
    send_number(na->l[1]);
    pause();
    status(na);
}

static void defense(navy_t *na, char **board)
{
    my_printf("\nwaiting for enemy's attack...\n");
    my_printf("\nresult: ");
    while (g.counter[2] != 2);
    att_ennemy(board, na);
    na->let = g.attack[1];
    na->num = g.attack[2];
    g.stat[4] = 0;
    na->is_my_turn = true;
}

void who_plays(navy_t *na, char **board)
{
    if (na->is_my_turn) {
        if (display_last(na, board) == 1) {
            na->isfinished = true;
            return;
        }
        g.stat[3] = 1;
        my_printf("\nattack: ");
        getline(&na->l, &na->len1, stdin);
        while (attack_ennemy(board, na->l, na) == NULL)
            getline(&na->l, &na->len1, stdin);
        handle_pos(na);
        na->enem = upt_board(na->enem, na);
        is_finished(na, board);
        na->is_my_turn = false;
    } else {
        defense(na, board);
    }
}

int allow_connection(char **argv, navy_t *na)
{
    struct sigaction signo;
    char **board = 0;

    na->enem = initboard();
    na->is_my_turn = false;
    signo.sa_flags = SA_SIGINFO;
    signo.sa_sigaction = handleplay_2;
    sigaction(SIGUSR1, &signo, NULL);
    sigaction(SIGUSR2, &signo, NULL);
    g.p1 = getpid();
    my_printf("my pid %i\n", g.p1);
    kill(my_getnbr(argv[1]), SIGUSR2);
    pause();
    while (!na->isfinished) {
        usleep(1000);
        board = maps_player2(board, argv, na);
    }
    return 0;
}

void player(char **argv, navy_t *na)
{
    struct sigaction sig;
    char **board = 0;

    na->enem = initboard();
    na->isfinished = false;
    na->is_my_turn = true;
    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = handleplay_1;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    my_printf("my pid %i\n", g.p1);
    my_printf("\nwaiting for enemy connection. . .\n");
    kill(g.p2, SIGUSR1);
    pause();
    na->let = 0;
    na->num = 0;
    while (!na->isfinished) {
        usleep(1000);
        board = maps_player1(board, argv, na);
    }
}
