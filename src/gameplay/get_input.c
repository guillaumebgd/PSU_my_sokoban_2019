/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include "sokoban.h"
#include <curses.h>

static void restart(int *close)
{
    (*close) = 1;
    clear();
}

void get_input(map_stats_t *map_stats, int *close, int key)
{
    switch (key) {
        case KEY_UP:
            move_up(map_stats);
            break;
        case KEY_DOWN:
            move_down(map_stats);
            break;
        case KEY_LEFT:
            move_left(map_stats);
            break;
        case KEY_RIGHT:
            move_right(map_stats);
            break;
        case ' ':
            restart(close);
            break;
        default:
            clear();
            break;
    }
}