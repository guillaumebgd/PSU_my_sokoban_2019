/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include <curses.h>

void get_input(int *close)
{
    switch (getch()) {
        case KEY_UP:
            clear();
            break;
        case KEY_DOWN:
            clear();
            break;
        case KEY_LEFT:
            clear();
            break;
        case KEY_RIGHT:
            clear();
            break;
        case ' ':
            (*close) = 1;
            break;
        default:
            refresh();
            break;
    }
}