/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** tests the sokoban winning condition
*/

#include "sokoban.h"
#include <criterion/criterion.h>

Test(check_win, all_holes_filled)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/win_conditions/easy_win", &map_stats);
    move_down(&map_stats);
    move_right(&map_stats);
    check_win(&map_stats, &close);
    if (map_stats.game_res == 0 && close == 1)
        cr_expect_eq(1, 1);
    else
        cr_expect_eq(1, 0);
    free_resources(map_stats);
}

Test(check_win, all_holes_not_filled)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/win_conditions/easy_not_yet_win", &map_stats);
    check_win(&map_stats, &close);
    if (map_stats.game_res == 0 && close == 1)
        cr_expect_eq(1, 0);
    else
        cr_expect_eq(1, 1);
    free_resources(map_stats);
}