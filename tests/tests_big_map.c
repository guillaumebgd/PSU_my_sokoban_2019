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

static void solver_first_big_map(map_stats_t map_stats)
{
    move_right(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_left(&map_stats);
    move_up(&map_stats);
    move_right(&map_stats);
    move_down(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_up(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
    move_right(&map_stats);
}

Test(all_moves, big_map_test)
{
    map_stats_t map_stats;

    init_map_stats(&map_stats);
    get_map("./tests/tests_files/big_maps/big_map", &map_stats);
    solver_first_big_map(map_stats);
    cr_expect_str_eq(map_stats.map[0], "#####################\n");
    cr_expect_str_eq(map_stats.map[1], "#    X       PX     #\n");
    cr_expect_str_eq(map_stats.map[2], "#         X         #\n");
    cr_expect_str_eq(map_stats.map[3], "#####################\n");
    free_resources(map_stats);
}