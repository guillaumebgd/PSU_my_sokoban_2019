/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include <curses.h>
#include "sokoban.h"
#include "my.h"

static void display_map(map_stats_t *map_stats, int *close)
{
    int i = 0;

    while (i < map_stats->map_lines) {
        printw(map_stats->map[i]);
        i += 1;
    }
    get_input(close);
}

void sokoban(map_stats_t *map_stats)
{
    int close = 0;

    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    while (close == 0)
        display_map(map_stats, &close);
    refresh();
    endwin();
}