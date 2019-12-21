/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** tests special cases of the get map function
*/

#include "sokoban.h"
#include <criterion/criterion.h>

Test(get_map, get_no_return_line_at_the_end)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/get_map/no_return_line", &map_stats);
    cr_expect_str_eq(map_stats.map[0], "##########\n");
    cr_expect_str_eq(map_stats.map[1], "# P      #\n");
    cr_expect_str_eq(map_stats.map[2], "##### X O#\n");
    cr_expect_str_eq(map_stats.map[3], "    ######\n");
    free_resources(map_stats);
}