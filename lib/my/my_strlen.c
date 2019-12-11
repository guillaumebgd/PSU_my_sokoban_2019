/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** gets a string size
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i += 1;
    return (i);
}