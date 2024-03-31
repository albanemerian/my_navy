/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-navy-albane.merian
** File description:
** navy
*/

#include "my.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <ucontext.h>

#ifndef NAVY_H_
    #define NAVY_H_
    #define _GNU_SOURCE
    #define _SOURCE_XOPEN_ 700

typedef struct g_s {
    pid_t p1;
    pid_t p2;
    int stat[4];
    int attack[2];
    int counter[2];
} g_t;

typedef struct navy_s {
    char *buffer;
    bool isfinished;
    bool is_my_turn;
    char *l;
    size_t len1;
    ssize_t read;
    char *pos;
    char *map1;
    char *map2;
    int let;
    int num;
    int enemylet;
    int enmunum;
    char **enem;
} navy_t;

extern g_t g;

void helper(int argc, char **argv);
int check_filepath(char *f);
bool check_lines(char ch, char min, char max);
char **attack_ennemy(char **board, char *pos, navy_t *na);
char **fill_board(char *av);
void display_board(char **b);
char **initboard(void);
char **maps_player1(char **board, char **argv, navy_t *na);
char **maps_player2(char **board, char **argv, navy_t *na);
void who_plays(navy_t *na, char **board);
void send_letter(char na);
void send_number(char na);
void att_ennemy(char **board, navy_t *na);
char **add_cross(char **board, navy_t *na);
int lose_condition(char **board);
int check_buffer(char *line, char i);
int colon_cpt(char *line);
int allow_connection(char **argv, navy_t *na);
void player(char **argv, navy_t *na);
void handleplay_2(int sign, siginfo_t *info, void *context);
void handleplay_1(int sign, siginfo_t *info, void *context);
void status(navy_t *na);
char **upt_board(char **my_board, navy_t *na);

#endif /* !NAVY_H_ */
