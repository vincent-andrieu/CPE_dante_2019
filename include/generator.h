/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** header generator
*/

#ifndef GEN_DANTE_H_
#define GEN_DANTE_H_

#include "dante.h"

#define PERFECT "perfect"

typedef struct data_s
{
    char type;
    bool visited;
    bool up;
    bool down;
    bool left;
    bool right;
} data_t;

int make_maze_perfect(char **maze, vector pos, vector scale);
void graph_to_map(char **map, data_t **node, vector scale);

vector get_rand(bool *tab, vector pos);
int make_maze_not_perfect(char **maze, vector pos, vector scale);
void start_maze(char **maze, int x, int y, vector scale);
void move_not_perfect(char **maze, vector pos, vector scale);
void finish_maze(char **maze, vector scale);
vector get_futur_pos(char **maze, vector pos, vector scale);
void bool_tab_filler(char **maze, vector scale, vector pos, bool *tab);

#endif