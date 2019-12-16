/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include "sokoban.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void get_player_pos(char c, map_stats_t *map_stats, int x, int y)
{
    if (c == 'P') {
        map_stats->player_pos[0] = x;
        map_stats->player_pos[1] = y;
    }
}

static void get_obs_pos(char c, map_stats_t *map_stats, int i, int lines)
{
    if (c == 'O')
        map_stats->obs_pos[lines][i] = 'O';
    else
        map_stats->obs_pos[lines][i] = ' ';
}

static void get_final_map(char *first_map, map_stats_t *map_stats)
{
    int offset = 0;
    int lines = 0;
    int i = 0;

    allocate_maps(first_map, map_stats);
    while (lines < map_stats->map_lines) {
        while (first_map[offset + i] != '\n') {
            get_player_pos(first_map[offset + i], map_stats, i, lines);
            get_obs_pos(first_map[offset + i], map_stats, i, lines);
            map_stats->map[lines][i] = first_map[offset + i];
            i += 1;
        }
        offset += i + 1;
        map_stats->obs_pos[lines][i] = '\n';
        map_stats->map[lines][i] = '\n';
        i = 0;
        lines += 1;
    }
}

int get_map(char const *map_path, map_stats_t *map_stats)
{
    char *first_map = NULL;
    struct stat file_stat;
    int map_size = 0;
    int fd;

    fd = open(map_path, O_RDONLY);
    if (fd == -1)
        return (84);
    if (stat(map_path, &file_stat) < 0)
        return (84);
    first_map = malloc(sizeof(char) * (file_stat.st_size + 1));
    if (first_map == NULL)
        return (84);
    map_size = read(fd, first_map, file_stat.st_size);
    first_map[map_size] = '\0';
    if (check_map_and_lines(first_map, &map_stats->map_lines) == 84)
        return (84);
    get_final_map(first_map, map_stats);
    return (0);
}