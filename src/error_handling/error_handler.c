/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include "sokoban.h"
#include <stdlib.h>

void error_handler(void)
{
    usage();
    exit(84);
}