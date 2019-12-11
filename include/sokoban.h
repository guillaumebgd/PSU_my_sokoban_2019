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
    int map_lines;
} map_stats_t;

void init_map_stats(map_stats_t *);

void get_map(char const *, map_stats_t *);
void check_map_and_lines(char *, int *);

void sokoban(map_stats_t *);

void error_handler(void);
void usage();

void free_resources(map_stats_t);

#endif /* SOKOBAN_H_ */