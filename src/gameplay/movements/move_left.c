/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** moves the player to the left
*/

#include "sokoban.h"

static void basic_left(map_stats_t *map_stats, int x, int y)
{
    if (map_stats->obs_pos[y][x] == 'O') {
        map_stats->map[y][x - 1] = 'P';
        map_stats->map[y][x] = 'O';
        map_stats->player_pos[0] -= 1;
        return;
    } if (map_stats->map[y][x - 1] == ' ') {
        swap_char(&map_stats->map[y][x - 1], &map_stats->map[y][x]);
        map_stats->player_pos[0] -= 1;
        return;
    } if (map_stats->map[y][x - 1] == 'O') {
        map_stats->map[y][x - 1] = 'P';
        map_stats->map[y][x] = ' ';
        map_stats->player_pos[0] -= 1;
        return;
    }
}

static void box_pushed_or_not(map_stats_t *map_stats, int x, int y)
{
    if (map_stats->obs_pos[y][x] == 'O') {
        map_stats->map[y][x - 1] = 'P';
        map_stats->map[y][x] = 'O';
    } if (map_stats->obs_pos[y][x] == 'O') {
        map_stats->map[y][x - 1] = 'P';
        map_stats->map[y][x] = 'O';
    } else {
        map_stats->map[y][x] = ' ';
        map_stats->map[y][x - 1] = 'P';
    }
    map_stats->map[y][x - 2] = 'X';
    map_stats->player_pos[0] -= 1;
}

void move_left(map_stats_t *map_stats)
{
    int x = map_stats->player_pos[0];
    int y = map_stats->player_pos[1];

    if (map_stats->map[y][x - 1] == ' ' || map_stats->map[y][x - 1] == 'O') {
        basic_left(map_stats, x, y);
    } else if (map_stats->map[y][x - 1] == 'X') {
        if (map_stats->map[y][x - 2] != '#' && map_stats->map[y][x - 2] != 'X')
            box_pushed_or_not(map_stats, x, y);
    }
}