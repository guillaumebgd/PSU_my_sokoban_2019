/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include <stdlib.h>
#include "sokoban.h"

static int check_objects_count(int player, int boxes, int holes)
{
    if (player != 1 || boxes != holes)
        return (84);
    return (0);
}

static void count_objects(char c, int *player, int *boxes, int *holes)
{
    if (c == 'P')
        (*player) += 1;
    if (c == 'X')
        (*boxes) += 1;
    if (c == 'O')
        (*holes) += 1;
}

int check_map_and_lines(char *map, int *map_lines)
{
    int count_player = 0;
    int count_boxes = 0;
    int count_holes = 0;
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == '\n')
            (*map_lines) += 1;
        else if (map[i] != 'P' && map[i] != 'O'
                && map[i] != 'X' && map[i] != '#'
                && map[i] != ' ') {
                return (84);
                }
        count_objects(map[i], &count_player, &count_boxes, &count_holes);
        i += 1;
    }
    if (check_objects_count(count_player, count_boxes, count_holes) == 84)
        return (84);
    return (0);
}