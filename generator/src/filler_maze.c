/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include "generator.h"

void graph_to_map(char **map, data_t **node, vector scale)
{
    int x_s = 0;
    int y_s = 0;

    for (int y = 0; y < scale.y / 2 + 1; y++, y_s += 2) {
        x_s = 0;
        for (int x = 0; x < scale.x / 2 + 1; x++, x_s += 2) {
            map[y_s][x_s] = EMPTY;
            if (x_s - 1 >= 0)
                map[y_s][x_s - 1] = (node[y][x].left) ? EMPTY :
            map[y_s][x_s - 1];
            map[y_s][x_s + 1] = (node[y][x].right) ? EMPTY : map[y_s][x_s + 1];
            if (y_s - 1 >= 0)
                map[y_s - 1][x_s] = (node[y][x].up) ? EMPTY : map[y_s - 1][x_s];
            if (y + 1 < scale.y / 2 + scale.y % 2)
                map[y_s + 1][x_s] = (node[y][x].down) ? EMPTY :
            map[y_s + 1][x_s];
        }
    }
}