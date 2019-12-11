/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** header linking c files
*/

#ifndef SOKOBAN_H_

#define SOKOBAN_H_

typedef struct map_stats_s {
    char **map;
    char **obs_pos;
    int *player_pos;
    int map_lines;
} map_stats_t;

int init_map_stats(map_stats_t *);

void get_map(char const *, map_stats_t *);
void check_map_and_lines(char *, int *);

void sokoban(map_stats_t *);
void get_input(map_stats_t *, int *);

void swap_char(char *, char *);
void move_left(map_stats_t *);
void move_right(map_stats_t *);
void move_up(map_stats_t *);
void move_down(map_stats_t *);

void error_handler(void);
void usage();

void free_resources(map_stats_t);

#endif /* SOKOBAN_H_ */