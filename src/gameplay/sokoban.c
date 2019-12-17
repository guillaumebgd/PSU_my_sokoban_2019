/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** main control of what happens in the window
*/

#include "sokoban.h"
#include <ncurses.h>
#include <unistd.h>

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
        if (close == 0)
            check_lose(map_stats, &close);
        get_input(map_stats, &close, getch());
    }
    print_map(map_stats);
    usleep(500);
    refresh();
    endwin();
}