/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mimics the game sokoban
*/

#include <ncurses.h>
#include <unistd.h>
#include "sokoban.h"
#include "my.h"

void sokoban(map_stats_t *map_stats)
{
    int close = 0;

    initscr();
    timeout(500);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    while (close == 0) {
        print_map(map_stats);
        check_win(map_stats, &close);
        get_input(map_stats, &close, getch());
    }
    print_map(map_stats);
    usleep(500);
    refresh();
    endwin();
}