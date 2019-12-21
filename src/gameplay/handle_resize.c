/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** displays a message if the terminal is too small to display
*/

#include "sokoban.h"
#include <ncurses.h>

void handle_resize(map_stats_t *map_stats)
{
    while (COLS < map_stats->longest_line
            || LINES < map_stats->map_lines) {
                clear();
                mvprintw(LINES / 2, COLS / 2 - 13,
                "Enlarge the window to play");
                refresh();
            }
}