/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include "sokoban.h"
#include <curses.h>

void get_input(map_stats_t *map_stats, int *close)
{
    switch (getch()) {
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
            (*close) = 1;
            clear();
            break;
        default:
            clear();
            break;
    }
}