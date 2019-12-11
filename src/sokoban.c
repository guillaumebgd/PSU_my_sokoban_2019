/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include <curses.h>
#include "sokoban.h"
#include "my.h"

void sokoban(map_stats_t *map_stats)
{
    int close = 0;
    int i = 0;

    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    while (close == 0) {
        while (i < map_stats->map_lines) {
            printw(map_stats->map[i]);
            i += 1;
        }
        switch (getch()) {
            case KEY_UP:
                break;
            case KEY_DOWN:
                break;
            case KEY_LEFT:
                break;
            case KEY_RIGHT:
                break;
            case ' ':
                close = 1;
                break;
            default:
                refresh();
                break;
        }
    }
    refresh();
    getch();
    endwin();
}