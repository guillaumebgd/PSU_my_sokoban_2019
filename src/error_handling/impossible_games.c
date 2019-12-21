/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** checks if a map is valid
*/

#include "sokoban.h"
#include "my.h"
#include <stdlib.h>

static void init_counters(obj_count_t *counters)
{
    counters->count_player = 0;
    counters->count_boxes = 0;
    counters->count_holes = 0;
}

static void count_objects(char c, obj_count_t *counters)
{
    if (c == 'P')
        counters->count_player += 1;
    if (c == 'X')
        counters->count_boxes += 1;
    if (c == 'O')
        counters->count_holes += 1;
}

static char *add_line_breaker(char *map, int map_len)
{
    char *new_map = malloc(sizeof(char) * (map_len + 2));

    new_map = my_strcpy(map, new_map);
    free(map);
    return (new_map);
}

static int check_objects_count(obj_count_t *counters,
                                char **map,
                                int i,
                                int *map_lines)
{
    if (counters->count_player != 1
        || counters->count_boxes != counters->count_holes)
        return (84);
    if ((*map)[i - 1] != '\n') {
        (*map) = add_line_breaker((*map), i);
        (*map_lines) += 1;
    }
    return (0);
}

int check_map_and_lines(map_stats_t *map_stats, char **map, int *map_lines)
{
    obj_count_t counters;
    int i = 0;

    init_counters(&counters);
    while ((*map)[i] != '\0') {
        if ((*map)[i] == '\n')
            (*map_lines) += 1;
        else if ((*map)[i] != 'P' && (*map)[i] != 'O'
                && (*map)[i] != 'X' && (*map)[i] != '#' && (*map)[i] != ' ') {
                return (84);
                }
        count_objects((*map)[i], &counters);
        i += 1;
    }
    if (check_objects_count(&counters, map, i, map_lines) == 84)
        return (84);
    map_stats->boxes_nb = counters.count_boxes;
    return (0);
}