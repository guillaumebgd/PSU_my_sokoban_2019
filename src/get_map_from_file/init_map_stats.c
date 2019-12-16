/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include "sokoban.h"
#include <stdlib.h>

int init_map_stats(map_stats_t *map_stats)
{
    map_stats->map = NULL;
    map_stats->obs_pos = NULL;
    map_stats->player_pos = malloc(sizeof(int) * 2);
    if (map_stats->player_pos == NULL)
        return (84);
    map_stats->map_lines = 0;
    map_stats->game_res = 0;
    map_stats->longest_line = 0;
    map_stats->boxes_nb = 0;
    return (0);
}