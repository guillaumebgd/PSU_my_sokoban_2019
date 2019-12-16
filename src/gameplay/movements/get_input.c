/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include "sokoban.h"
#include <curses.h>

static void restart(map_stats_t *map_stats, int *close)
{
    map_stats->game_res = 2;
    (*close) = 1;
    clear();
}

void get_input(map_stats_t *map_stats, int *close, int key)
{
    if (key == KEY_UP) {
        move_up(map_stats);
        clear();
    } if (key == KEY_DOWN) {
        move_down(map_stats);
        clear();
    } if (key == KEY_LEFT) {
        move_left(map_stats);
        clear();
    } if (key == KEY_RIGHT) {
        move_right(map_stats);
        clear();
    } if (key == ' ')
        restart(map_stats, close);
}