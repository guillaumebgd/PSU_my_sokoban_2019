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

Test(move_up, test_dbl_boxes)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_up/map_up_3", &map_stats);
    move_left(&map_stats);
    move_up(&map_stats);
    move_up(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "########\n");
    cr_expect_str_eq(map_stats.map[1], "#OXX  X#\n");
    cr_expect_str_eq(map_stats.map[2], "#OOP   #\n");
    cr_expect_str_eq(map_stats.map[3], "#      #\n");
    cr_expect_str_eq(map_stats.map[4], "########\n");
    free_resources(map_stats);
}

Test(move_up, test_box_wall)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_up/map_up_3", &map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_up(&map_stats);
    move_up(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "########\n");
    cr_expect_str_eq(map_stats.map[1], "#OXX  X#\n");
    cr_expect_str_eq(map_stats.map[2], "#OO   P#\n");
    cr_expect_str_eq(map_stats.map[3], "#      #\n");
    cr_expect_str_eq(map_stats.map[4], "########\n");
    free_resources(map_stats);
}

Test(move_up, test_box_box)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_up/map_up_4", &map_stats);
    move_up(&map_stats);
    cr_expect_str_eq(map_stats.map[0], "########\n");
    cr_expect_str_eq(map_stats.map[1], "#O X  X#\n");
    cr_expect_str_eq(map_stats.map[2], "#OOX   #\n");
    cr_expect_str_eq(map_stats.map[3], "#  P   #\n");
    cr_expect_str_eq(map_stats.map[4], "########\n");
    free_resources(map_stats);
}
