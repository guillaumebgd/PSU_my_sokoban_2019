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

static int check_for_nearby_char(map_stats_t *map_stats,
                                point_t box,
                                char first_c,
                                char second_c)
{
    if ((map_stats->map[box.y][box.x + 1] == first_c
        && (map_stats->map[box.y + 1][box.x] == second_c
        || map_stats->map[box.y - 1][box.x] == second_c))
        || (map_stats->map[box.y][box.x - 1] == first_c
        && (map_stats->map[box.y + 1][box.x] == second_c
        || map_stats->map[box.y - 1][box.x] == second_c)))
        return (0);
    else
        return (1);
}

static void check_unmoveable(map_stats_t *map_stats,
                            point_t box,
                            int *unmoveable)
{
    if (check_for_nearby_char(map_stats, box, 'X', 'X') == 0
        || check_for_nearby_char(map_stats, box, '#', '#') == 0
        || check_for_nearby_char(map_stats, box, 'X', '#') == 0
        || check_for_nearby_char(map_stats, box, '#', 'X') == 0)
        (*unmoveable) += 1;
}

void check_lose(map_stats_t *map_stats, int *close)
{
    point_t box;
    int unmoveable = 0;

    box.x = 0;
    box.y = 0;
    while (box.y < map_stats->map_lines) {
        if (map_stats->map[box.y][box.x] == 'X')
            check_unmoveable(map_stats, box, &unmoveable);
        if (map_stats->obs_pos[box.y][box.x] == '\n') {
            box.y += 1;
            box.x = 0;
        }
        box.x += 1;
    }
    cmp_unmov_with_boxes(map_stats, unmoveable, close);
}