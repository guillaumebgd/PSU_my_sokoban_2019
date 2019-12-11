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
    int key;

    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    while (close == 0) {
        while (i < map_stats->map_lines) {
            printw(map_stats->map[i]);
            i += 1;
        }
        key = getch();
        switch (key) {
            case KEY_UP:
                printf("up\n");
                break;
            case KEY_DOWN:
                printf("down\n");
                break;
            case KEY_LEFT:
                printf("left\n");
                break;
            case KEY_RIGHT:
                printf("right\n");
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