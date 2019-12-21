/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** copies a string into another one
*/

char *my_strcpy(char *template, char *dest)
{
    int i = 0;

    while (template[i] != '\0') {
        dest[i] = template[i];
        i += 1;
    }
    dest[i] = '\n';
    dest[i + 1] = '\0';
    return (dest);
}