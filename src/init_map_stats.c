/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include "sokoban.h"
#include <stddef.h>

void init_map_stats(map_stats_t *map_stats)
{
    map_stats->map = NULL;
    map_stats->map_lines = 0;
}