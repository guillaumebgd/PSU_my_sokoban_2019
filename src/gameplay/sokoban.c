/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include <curses.h>
#include "sokoban.h"
#include "my.h"

static void print_map(map_stats_t *map_stats)
{
    int i = 0;

    while (i < map_stats->map_lines) {
        printw(map_stats->map[i]);
        i += 1;
    }
}

static void display_map(map_stats_t *map_stats, int *close)
{
    print_map(map_stats);
    get_input(map_stats, close);
}

static void cmp_holes_with_matches(int matches,
                                    int holes,
                                    int *close)
{
    if (matches == holes) {
        clear();
        (*close = 1);
    }
}

static void check_win(map_stats_t *map_stats, int *close)
{
    int holes = 0;
    int matches = 0;
    int y = 0;
    int x = 0;

    while (y < map_stats->map_lines) {
        if (map_stats->obs_pos[y][x] == 'O') {
            if (map_stats->map[y][x] == 'X')
                matches += 1;
            holes += 1;
        }
        if (map_stats->obs_pos[y][x] == '\n') {
            y += 1;
            x = 0;
        }
        x += 1;
    }
    cmp_holes_with_matches(matches, holes, close);
}

void sokoban(map_stats_t *map_stats)
{
    int close = 0;

    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    while (close == 0) {
        display_map(map_stats, &close);
        check_win(map_stats, &close);
    }
    display_map(map_stats, &close);
    print_map(map_stats);
    refresh();
    endwin();
}