/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** tests move left function
*/

#include "sokoban.h"
#include "ncurses.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

Test(get_map, get_normal_map)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/get_map/normal_getmap", &map_stats);
    cr_expect_str_eq(map_stats.map[0], "#######\n");
    cr_expect_str_eq(map_stats.map[1], "#O X P#\n");
    cr_expect_str_eq(map_stats.map[2], "#######\n");
    free_resources(map_stats);
}

Test(get_map, get_false_map)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    if (get_map("./tests/tests_files/get_map/false_getmap", &map_stats) == 84)
        cr_expect_eq(1, 1);
    else
        cr_expect_eq(1, 0);
    free_resources(map_stats);
}

Test(get_map, no_map)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    if (get_map("./errorfinding", &map_stats) == 84)
        cr_expect_eq(1, 1);
    else
        cr_expect_eq(1, 0);
}

Test(get_map, two_players)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    if (get_map("./tests/tests_files/get_map/two_players", &map_stats) == 84)
        cr_expect_eq(1, 1);
    else
        cr_expect_eq(1, 0);
}

Test(get_map, two_boxes_no_hole)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    if (get_map("./tests/tests_files/get_map/two_boxes_no_hole",
                &map_stats) == 84)
        cr_expect_eq(1, 1);
    else
        cr_expect_eq(1, 0);
}