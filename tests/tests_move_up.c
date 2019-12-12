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

Test(move_up, simple_up_move)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_up/map_up", &map_stats);
    move_up(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###\n");
    cr_expect_str_eq(map_stats.map[1], "# #\n");
    cr_expect_str_eq(map_stats.map[2], "# #\n");
    cr_expect_str_eq(map_stats.map[3], "#O#\n");
    cr_expect_str_eq(map_stats.map[4], "#X#\n");
    cr_expect_str_eq(map_stats.map[5], "#P#\n");
    cr_expect_str_eq(map_stats.map[6], "# #\n");
    cr_expect_str_eq(map_stats.map[7], "###\n");
    free_resources(map_stats);
}

Test(move_up, wall_block)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_up/map_up_wall", &map_stats);
    move_up(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###\n");
    cr_expect_str_eq(map_stats.map[1], "#P#\n");
    cr_expect_str_eq(map_stats.map[2], "# #\n");
    cr_expect_str_eq(map_stats.map[3], "#O#\n");
    cr_expect_str_eq(map_stats.map[4], "# #\n");
    cr_expect_str_eq(map_stats.map[5], "# #\n");
    cr_expect_str_eq(map_stats.map[6], "#X#\n");
    cr_expect_str_eq(map_stats.map[7], "###\n");
    free_resources(map_stats);
}

Test(move_up, map_up_obs_cover)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_up/map_up", &map_stats);
    move_up(&map_stats);
    move_up(&map_stats);
    move_up(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###\n");
    cr_expect_str_eq(map_stats.map[1], "# #\n");
    cr_expect_str_eq(map_stats.map[2], "#X#\n");
    cr_expect_str_eq(map_stats.map[3], "#P#\n");
    cr_expect_str_eq(map_stats.map[4], "# #\n");
    cr_expect_str_eq(map_stats.map[5], "# #\n");
    cr_expect_str_eq(map_stats.map[6], "# #\n");
    cr_expect_str_eq(map_stats.map[7], "###\n");
    free_resources(map_stats);
}

Test(move_up, map_left_obs_recover)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_up/map_up", &map_stats);
    move_up(&map_stats);
    move_up(&map_stats);
    move_up(&map_stats);
    move_up(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###\n");
    cr_expect_str_eq(map_stats.map[1], "#X#\n");
    cr_expect_str_eq(map_stats.map[2], "#P#\n");
    cr_expect_str_eq(map_stats.map[3], "#O#\n");
    cr_expect_str_eq(map_stats.map[4], "# #\n");
    cr_expect_str_eq(map_stats.map[5], "# #\n");
    cr_expect_str_eq(map_stats.map[6], "# #\n");
    cr_expect_str_eq(map_stats.map[7], "###\n");
    free_resources(map_stats);
}