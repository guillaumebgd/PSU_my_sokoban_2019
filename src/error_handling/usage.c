/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include <unistd.h>
#include <stdlib.h>

void usage(void)
{
    write(1, "USAGE\n", 6);
    write(1, "     ./my_sokoban map\n", 22);
    write(1, "DESCRITION\n", 11);
    write(1, "     map file representing the warehouse map,", 45);
    write(1, " containing ‘#’ for walls,\n", 31);
    write(1, "     ‘P’ for the player, ‘X’ for boxes", 45);
    write(1, " and ‘O’ for storage locations.\n", 36);
}