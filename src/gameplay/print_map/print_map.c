/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include <ncurses.h>
#include "sokoban.h"

void print_map(map_stats_t *map_stats)
{
    int i = 0;

    clear();
    while (i < map_stats->map_lines) {
        printw(map_stats->map[i]);
        i += 1;
    }
    refresh();
}
