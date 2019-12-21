/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** main control of what happens in the window
*/

#include "sokoban.h"
#include <ncurses.h>
#include <unistd.h>

static void print_last_frame(map_stats_t *map_stats)
{
    clear();
    print_map(map_stats);
    usleep(460000);
    refresh();
}

static int game_state(map_stats_t *map_stats, int *close)
{
    check_win(map_stats, close);
    if ((*close) == 1)
        return (0);
    check_lose(map_stats, close);
    if ((*close) == 1)
        return (0);
    return (1);
}

void sokoban(map_stats_t *map_stats)
{
    int close = 0;

    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    while (close == 0) {
        handle_resize(map_stats);
        print_map(map_stats);
        if (game_state(map_stats, &close) == 0)
            break;
        get_input(map_stats, &close, getch());
    }
    print_last_frame(map_stats);
    endwin();
}