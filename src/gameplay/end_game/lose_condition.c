/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include <stdlib.h>
#include "sokoban.h"

static void cmp_unmov_with_boxes(map_stats_t *map_stats,
                                int unmoveable,
                                int *close)
{
    if (unmoveable == map_stats->boxes_nb) {
        map_stats->game_res = 1;
        (*close = 1);
    }
}

static void check_unmoveable(map_stats_t *map_stats,
                            int x,
                            int y,
                            int *unmoveable)
{
    if (((map_stats->map[y][x + 1] == 'X' && (map_stats->map[y + 1][x] == 'X'
        || map_stats->map[y - 1][x] == 'X'))
        || (map_stats->map[y][x - 1] == 'X' && (map_stats->map[y + 1][x] == 'X'
        || map_stats->map[y - 1][x] == 'X')))
        || ((map_stats->map[y][x + 1] == '#' && (map_stats->map[y + 1][x] == '#'
        || map_stats->map[y - 1][x] == '#'))
        || (map_stats->map[y][x - 1] == '#' && (map_stats->map[y + 1][x] == '#'
        || map_stats->map[y - 1][x] == '#'))))
        (*unmoveable) += 1;
}

void check_lose(map_stats_t *map_stats, int *close)
{
    int x = 0;
    int y = 0;
    int unmoveable = 0;

    while (y < map_stats->map_lines) {
        if (map_stats->map[y][x] == 'X')
            check_unmoveable(map_stats, x, y, &unmoveable);
        if (map_stats->obs_pos[y][x] == '\n') {
            y += 1;
            x = 0;
        }
        x += 1;
    }
    cmp_unmov_with_boxes(map_stats, unmoveable, close);
}