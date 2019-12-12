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

Test(move_left, left_by_key)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left", &map_stats);
    get_input(&map_stats, &close, KEY_LEFT);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#   O X    P  #\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_right, right_by_key)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_left/map_left", &map_stats);
    get_input(&map_stats, &close, KEY_RIGHT);
    cr_expect_str_eq(map_stats.map[0], "###############\n");
    cr_expect_str_eq(map_stats.map[1], "#   O X      P#\n");
    cr_expect_str_eq(map_stats.map[2], "###############\n");
    free_resources(map_stats);
}

Test(move_up, up_by_key)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_up/map_up", &map_stats);
    get_input(&map_stats, &close, KEY_UP);
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

Test(move_down, down_by_key)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/move_down/map_down", &map_stats);
    get_input(&map_stats, &close, KEY_DOWN);
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

Test(restart, restart_key)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_input(&map_stats, &close, ' ');
    cr_expect_eq(close, 1);
}