/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** prints the usage of the my_sokoban function onto the terminal
*/

#include <unistd.h>

void usage(void)
{
    write(1, "USAGE\n", 6);
    write(1, "     ./my_sokoban map\n", 22);
    write(1, "DESCRITION\n", 11);
    write(1, "     map file representing the warehouse map, ", 46);
    write(1, "containing '#' for walls,\n", 32);
    write(1, "         'P' for the player, 'X' for boxes", 50);
    write(1, " and 'O' for storage locations.\n", 36);
}