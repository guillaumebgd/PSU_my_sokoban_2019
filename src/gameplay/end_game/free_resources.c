/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** frees resources allocated
*/

#include "sokoban.h"
#include <stdlib.h>

void free_resources(map_stats_t map_stats)
{
    int i = 0;

    while (i < map_stats.map_lines) {
        free(map_stats.map[i]);
        free(map_stats.obs_pos[i]);
        i += 1;
    }
    free(map_stats.map);
    free(map_stats.obs_pos);
}