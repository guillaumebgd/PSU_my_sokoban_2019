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

Test(move_left, map_left_simple_box_move_on_hole)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left_box_move", &map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#   XP        #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_left, map_left_get_hole_back_box)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left_box_move", &map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "# XPO         #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_left, move_box_to_wall)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left_box_move", &map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#XP O         #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_left, double_boxes_to_push)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left_dbl_boxes", &map_stats);
    move_left(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#  OOXXP      #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}