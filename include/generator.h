/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** header generator
*/

#ifndef GEN_DANTE_H_
#define GEN_DANTE_H_

#include "dante.h"

typedef struct data_s
{
    char type;
    bool visited;
    bool up;
    bool down;
    bool left;
    bool right;
} data_t;

int make_maze(char **maze, vector pos, vector scale);
void graph_to_map(char **map, data_t **node, vector scale);

#endif