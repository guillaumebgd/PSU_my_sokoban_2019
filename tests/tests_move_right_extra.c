/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** tests special cases of the move right function
*/

#include "sokoban.h"
#include <criterion/criterion.h>


Test(move_right, map_right_obs_player_cover)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_right/map_right_p_o", &map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#      P  X   #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_right, map_right_obs_player_recover)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_right/map_right_p_o", &map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#      OP X   #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_right, push_box_to_wall)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_right/map_right_p_o", &map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#      O    PX#\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_right, double_boxes_right)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_right/map_right_dbl_boxes", &map_stats);
    move_right(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#PXX   OO     #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}