/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** swaps two chars
*/

void swap_char(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}