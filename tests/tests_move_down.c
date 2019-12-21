/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** tests move up function
*/

#include "sokoban.h"
#include <criterion/criterion.h>

Test(move_down, simple_down_move)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_down/map_down", &map_stats);
    move_down(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###\n");
    cr_expect_str_eq(map_stats.map[1], "# #\n");
    cr_expect_str_eq(map_stats.map[2], "#P#\n");
    cr_expect_str_eq(map_stats.map[3], "#X#\n");
    cr_expect_str_eq(map_stats.map[4], "#O#\n");
    cr_expect_str_eq(map_stats.map[5], "# #\n");
    cr_expect_str_eq(map_stats.map[6], "# #\n");
    cr_expect_str_eq(map_stats.map[7], "###\n");
    free_resources(map_stats);
}

Test(move_down, wall_block)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_down/map_down_2", &map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###\n");
    cr_expect_str_eq(map_stats.map[1], "# #\n");
    cr_expect_str_eq(map_stats.map[2], "# #\n");
    cr_expect_str_eq(map_stats.map[3], "#O####\n");
    cr_expect_str_eq(map_stats.map[4], "#  X  #\n");
    cr_expect_str_eq(map_stats.map[5], "#     #\n");
    cr_expect_str_eq(map_stats.map[6], "#P####\n");
    cr_expect_str_eq(map_stats.map[7], "###\n");
    free_resources(map_stats);
}

Test(move_down, map_down_obs_cover)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_down/map_down", &map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###\n");
    cr_expect_str_eq(map_stats.map[1], "# #\n");
    cr_expect_str_eq(map_stats.map[2], "# #\n");
    cr_expect_str_eq(map_stats.map[3], "# #\n");
    cr_expect_str_eq(map_stats.map[4], "#O#\n");
    cr_expect_str_eq(map_stats.map[5], "#P#\n");
    cr_expect_str_eq(map_stats.map[6], "#X#\n");
    cr_expect_str_eq(map_stats.map[7], "###\n");
    free_resources(map_stats);
}

Test(move_down, test_box_box)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_down/map_down_3", &map_stats);
    move_down(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "########\n");
    cr_expect_str_eq(map_stats.map[1], "#O    P#\n");
    cr_expect_str_eq(map_stats.map[2], "#OOX  X#\n");
    cr_expect_str_eq(map_stats.map[3], "#     X#\n");
    cr_expect_str_eq(map_stats.map[4], "########\n");
    free_resources(map_stats);
}

Test(move_down, wall_box)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_down/map_down_4", &map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    move_down(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###\n");
    cr_expect_str_eq(map_stats.map[1], "# #\n");
    cr_expect_str_eq(map_stats.map[2], "# #\n");
    cr_expect_str_eq(map_stats.map[3], "#O####\n");
    cr_expect_str_eq(map_stats.map[4], "#     #\n");
    cr_expect_str_eq(map_stats.map[5], "#P    #\n");
    cr_expect_str_eq(map_stats.map[6], "#X####\n");
    cr_expect_str_eq(map_stats.map[7], "###\n");
    free_resources(map_stats);
}