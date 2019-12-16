/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include <stdlib.h>
#include <unistd.h>
#include "sokoban.h"
#include "my.h"

int main(int ac, char **av, char **env)
{
    map_stats_t map_stats;

    if (ac != 2 || env[0] == NULL) {
        usage();
        return (84);
    } if (av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2) {
        usage();
        return (0);
    }
    return (game_handler(map_stats, av));
}