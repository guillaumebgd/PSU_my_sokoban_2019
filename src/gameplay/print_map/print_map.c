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
        mvprintw(LINES / 2 + i - map_stats->map_lines / 2,
                COLS / 2 - map_stats->longest_line / 2,
                map_stats->map[i]);
        i += 1;
    }
    refresh();
}
