/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** header linking c files
*/

#ifndef SOKOBAN_H_

#define SOKOBAN_H_

typedef struct obj_count_s {
    int count_player;
    int count_boxes;
    int count_holes;
} obj_count_t;

typedef struct map_stats_s {
    char **map;
    char **obs_pos;
    int *player_pos;
    int map_lines;
    int game_res;
    int longest_line;
    int boxes_nb;
} map_stats_t;

typedef struct point_s {
    int x;
    int y;
} point_t;

int init_map_stats(map_stats_t *);

int get_map(char const *, map_stats_t *);
int allocate_maps(char *, map_stats_t *);
int check_map_and_lines(map_stats_t *, char **, int *);

int game_handler(char **);

void sokoban(map_stats_t *);
void handle_resize(map_stats_t *);
void print_map(map_stats_t *);
void check_win(map_stats_t *, int *);
void check_lose(map_stats_t *, int *);
void get_input(map_stats_t *, int *, int);

void swap_char(char *, char *);
void move_left(map_stats_t *);
void move_right(map_stats_t *);
void move_up(map_stats_t *);
void move_down(map_stats_t *);

void usage(void);

void free_resources(map_stats_t);

#endif /* SOKOBAN_H_ */