/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include "sokoban.h"
#include <unistd.h>
#include <stdlib.h>

static int alloc_whole_maps(map_stats_t *map_stats)
{
    map_stats->map = malloc(sizeof(char *) * (map_stats->map_lines));
    map_stats->obs_pos = malloc(sizeof(char *) * (map_stats->map_lines));
    if (map_stats->map == NULL || map_stats->obs_pos == NULL)
        return (84);
    return (0);
}

int allocate_maps(char *first_map, map_stats_t *map_stats)
{
    int offset = 0;
    int size = 0;
    int lines = 0;

    if (alloc_whole_maps(map_stats) == 84)
        return (84);
    while (lines < map_stats->map_lines) {
        while (first_map[offset + size] != '\n')
            size += 1;
        map_stats->map[lines] = malloc(sizeof(char) * (size + 2));
        map_stats->obs_pos[lines] = malloc(sizeof(char) * (size + 2));
        if (map_stats->map[lines] == NULL || map_stats->obs_pos[lines] == NULL)
            return (84);
        offset += size + 1;
        map_stats->obs_pos[lines][size + 1] = '\0';
        map_stats->map[lines][size + 1] = '\0';
        size = 0;
        lines += 1;
    }
    return (0);
}