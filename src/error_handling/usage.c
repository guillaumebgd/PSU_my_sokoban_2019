/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** prints the usage of the my_sokoban function onto the terminal
*/

#include <unistd.h>

void usage(void)
{
    write(1, "USAGE\n"
            "     ./my_sokoban map\n"
            "DESCRITION\n"
            "     map  file representing the warehouse map, "
            "containing '#' for walls,\n"
            "          'P' for the player, 'X' for boxes"
            " and 'O' for storage locations.\n", 187);
}