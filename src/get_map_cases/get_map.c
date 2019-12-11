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

static void allocate_maps(char *first_map, map_stats_t *map_stats)
{
    int offset = 0;
    int size = 0;
    int lines = 0;

    map_stats->map = malloc(sizeof(char *) * (map_stats->map_lines));
    map_stats->obs_pos = malloc(sizeof(char *) * (map_stats->map_lines));
    if (map_stats->map == NULL || map_stats->obs_pos == NULL)
        error_handler();
    while (lines < map_stats->map_lines) {
        while (first_map[offset + size] != '\n')
            size += 1;
        map_stats->map[lines] = malloc(sizeof(char) * (size + 2));
        map_stats->obs_pos[lines] = malloc(sizeof(char) * (size + 2));
        if (map_stats->map[lines] == NULL || map_stats->obs_pos[lines] == NULL)
            error_handler();
        offset += size + 1;
        map_stats->obs_pos[lines][size + 1] = '\0';
        map_stats->map[lines][size + 1] = '\0';
        size = 0;
        lines += 1;
    }
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
    free(first_map);
}

void get_map(char const *map_path, map_stats_t *map_stats)
{
    char *first_map;
    struct stat file_stat;
    int map_size = 0;
    int fd;

    fd = open(map_path, O_RDONLY);
    if (fd == -1)
        error_handler();
    if (stat(map_path, &file_stat) < 0)
        error_handler();
    first_map = malloc(sizeof(char) * (file_stat.st_size + 1));
    if (first_map == NULL)
        error_handler();
    map_size = read(fd, first_map, file_stat.st_size);
    first_map[map_size] = '\0';
    check_map_and_lines(first_map, &map_stats->map_lines);
    get_final_map(first_map, map_stats);
}