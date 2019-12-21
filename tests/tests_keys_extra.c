/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** tests an input that should do nothing
*/

#include "sokoban.h"
#include "ncurses.h"
#include <criterion/criterion.h>

Test(get_input, classic_reflesh_if_any_other_key_pressed)
{
    map_stats_t map_stats;
    int close = 0;

    init_map_stats(&map_stats);
    get_input(&map_stats, &close, KEY_ENTER);
    cr_expect_eq(close, 0);
}