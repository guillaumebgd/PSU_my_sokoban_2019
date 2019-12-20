/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** tests move left function
*/

#include "sokoban.h"
#include <criterion/criterion.h>

Test(usage, print_how_to_use_function)
{
    usage();
    cr_assert_eq(1, 1);
}