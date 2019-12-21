/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** tests the write of the usage function
*/

#include "sokoban.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(usage, prints_how_to_use_the_program)
{
    char cmp[] = "USAGE\n"
            "     ./my_sokoban map\n"
            "DESCRITION\n"
            "     map  file representing the warehouse map, "
            "containing '#' for walls,\n"
            "          'P' for the player, 'X' for boxes"
            " and 'O' for storage locations.\n";

    cr_redirect_stdout();
    usage();
    cr_assert_stdout_eq_str(cmp);
}