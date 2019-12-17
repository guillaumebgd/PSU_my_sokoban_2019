/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** handles the window actions
*/

#include "sokoban.h"
#include <stdlib.h>
#include <unistd.h>

int game_handler(char **av)
{
    map_stats_t map_stats;

    while (1) {
        if (init_map_stats(&map_stats) == 84)
            return (84);
        if (get_map(av[1], &map_stats) == 84) {
            usage();
            return (84);
        }
        sokoban(&map_stats);
        free_resources(map_stats);
        if (map_stats.game_res != 2)
            break;
    }
    return (map_stats.game_res);
}