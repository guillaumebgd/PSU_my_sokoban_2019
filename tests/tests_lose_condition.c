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

Test(check_lose, corners_boxes)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/lose_conditions/lost_corners", &map_stats);
    move_left(&map_stats);
    check_lose(&map_stats, &close);
    if (map_stats.game_res == 1 && close == 1)
        cr_expect_eq(1, 1);
    else
        cr_expect_eq(1, 0);
    free_resources(map_stats);
}

Test(check_lose, lines_boxes)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/lose_conditions/lost_lines", &map_stats);
    move_left(&map_stats);
    check_lose(&map_stats, &close);
    if (map_stats.game_res == 1 && close == 1)
        cr_expect_eq(1, 1);
    else
        cr_expect_eq(1, 0);
    free_resources(map_stats);
}

Test(check_lose, columns_boxes)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/lose_conditions/lost_columns", &map_stats);
    move_left(&map_stats);
    check_lose(&map_stats, &close);
    if (map_stats.game_res == 1 && close == 1)
        cr_expect_eq(1, 1);
    else
        cr_expect_eq(1, 0);
    free_resources(map_stats);
}

Test(check_lose, not_lost_yet)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/lose_conditions/lost_corners", &map_stats);
    check_lose(&map_stats, &close);
    if (map_stats.game_res == 1 && close == 1)
        cr_expect_eq(1, 0);
    else
        cr_expect_eq(1, 1);
    free_resources(map_stats);
}