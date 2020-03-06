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

/*void graph_to_map(char **maze, data_t **graph, vector scale)
{
    int x_map = 0;
    int y_map = 0;

    for (int y = 0; y < scale.y; y++, y_map += 2) {
        x_map = 0;
        for (int x = 0; x < scale.x; x++, x_map += 2) {
            printf("__________________________\n");

                if (graph[y][x].visited)
                    printf("visited ok\n");
                else printf("visited no\n");
                if (graph[y][x].left)
                    printf("left ok\n");
                else printf("left no\n");
                if (graph[y][x].right)
                    printf("right ok\n");
                else printf("right no\n");
                if (graph[y][x].up)
                    printf("up ok\n");
                else printf("up false\n");
                if (graph[y][x].down)
                    printf("down ok\n");
                else printf("down no\n");
            maze[y_map][x_map] = EMPTY;
            if (x_map - 1 >= 0)
                maze[y_map][x_map - 1] = (graph[y][x].left) ? EMPTY : maze[y_map][x_map - 1];
            if (x_map + 1 < scale.x)
                maze[y_map][x_map + 1] = (graph[y][x].right) ? EMPTY : maze[y_map][x_map + 1];
            if (y_map - 1 >= 0)
                maze[y_map - 1][x_map] = (graph[y][x].up) ? EMPTY : maze[y_map - 1][x_map];
            if (y_map + 1 < scale.y)
                maze[y_map + 1][x_map] = (graph[y][x].down) ? EMPTY : maze[y_map + 1][x_map];
        }
    }
}*/