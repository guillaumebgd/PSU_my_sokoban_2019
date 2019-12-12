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

Test(move_right, simple_right_move)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_right/map_right", &map_stats);
    move_right(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#    PXO      #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_right, wall_block)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_right/map_right_wall_block", &map_stats);
    move_right(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#   O X      P#\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_right, map_right_obs_cover)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_right/map_right", &map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#     PX      #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_right, map_right_obs_recover)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_right/map_right", &map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#      OPX    #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_right, map_right_obs_player_cov)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_right/map_right", &map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#      OPX    #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}