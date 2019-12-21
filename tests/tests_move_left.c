/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** tests move left function
*/

#include "sokoban.h"
#include <criterion/criterion.h>

Test(move_left, simple_left_move)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left", &map_stats);
    move_left(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#   O X    P  #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_left, wall_block)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left_wall_block", &map_stats);
    move_left(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#P  O X       #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_left, map_left_obs_cover)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left_obs_cover", &map_stats);
    move_left(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#   P X       #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_left, map_left_obs_recover)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left_obs_cover", &map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#  PO X       #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_left, map_left_simple_box_move)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left_box_move", &map_stats);
    move_left(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#   OXP       #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}