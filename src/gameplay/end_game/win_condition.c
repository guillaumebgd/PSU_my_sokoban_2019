/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include "sokoban.h"

static void cmp_holes_with_matches(int matches,
                                    int holes,
                                    int *close)
{
    if (matches == holes)
        (*close = 1);
}

void check_win(map_stats_t *map_stats, int *close)
{
    int holes = 0;
    int matches = 0;
    int x = 0;
    int y = 0;

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