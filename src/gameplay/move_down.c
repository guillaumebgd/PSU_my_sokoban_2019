/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include "sokoban.h"
#include <curses.h>

static void basic_down(map_stats_t *map_stats, int x, int y)
{
    if (map_stats->obs_pos[y][x] == 'O') {
        map_stats->map[y + 1][x] = 'P';
        map_stats->map[y][x] = 'O';
        map_stats->player_pos[1] += 1;
        return;
    } if (map_stats->map[y + 1][x] == ' ') {
        swap_char(&map_stats->map[y + 1][x], &map_stats->map[y][x]);
        map_stats->player_pos[1] += 1;
        return;
    } if (map_stats->map[y + 1][x] == 'O') {
        map_stats->map[y + 1][x] = 'P';
        map_stats->map[y][x] = ' ';
        map_stats->player_pos[1] += 1;
        return;
    }
}

static void box_pushed_or_not(map_stats_t *map_stats, int x, int y)
{
    if (map_stats->obs_pos[y][x] == 'O') {
        map_stats->map[y + 1][x] = 'P';
        map_stats->map[y][x] = 'O';
    } if (map_stats->obs_pos[y][x] == 'O') {
        map_stats->map[y + 1][x] = 'P';
        map_stats->map[y][x] = 'O';
    } else {
        map_stats->map[y][x] = ' ';
        map_stats->map[y + 1][x] = 'P';
    }
    map_stats->map[y + 2][x] = 'X';
    map_stats->player_pos[1] += 1;
}

void move_down(map_stats_t *map_stats)
{
    int x = map_stats->player_pos[0];
    int y = map_stats->player_pos[1];

    if (map_stats->map[y + 1][x] == ' ' || map_stats->map[y + 1][x] == 'O') {
        basic_down(map_stats, x, y);
    } else if (map_stats->map[y + 1][x] == 'X') {
        if (map_stats->map[y + 2][x] != '#' && map_stats->map[y + 2][x] != 'X')
            box_pushed_or_not(map_stats, x, y);
    }
}