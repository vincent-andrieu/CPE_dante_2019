/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include <stdlib.h>
#include "generator.h"

static data_t **get_graph(vector scale)
{
    data_t **graph = malloc(sizeof(data_t *) * (scale.y / 2 + 1));

    if (!graph)
        return NULL;
    for (int y = 0; y < scale.y / 2 + 1; y++) {
        graph[y] = malloc(sizeof(data_t) * (scale.x / 2  + 1));
        if (!graph[y])
            return NULL;
        for (int x = 0; x < scale.x / 2 + 1; x++) {
            graph[y][x].type = '?';
            graph[y][x].visited = false;
            graph[y][x].up = false;
            graph[y][x].down = false;
            graph[y][x].left = false;
            graph[y][x].right = false;
        }
    }
    return graph;
}

static vector get_pos(data_t **graph, vector pos, vector scale)
{
    bool tab[4] = {false, false, false, false};

    if (pos.x - 1 >= 0)
        if (!graph[pos.y][pos.x - 1].visited)
            tab[0] = true;
    if (pos.x + 1 < scale.x / 2 + 1)
        if (!graph[pos.y][pos.x + 1].visited)
            tab[1] = true;
    if (pos.y - 1 >= 0)
        if (!graph[pos.y - 1][pos.x].visited)
            tab[2] = true;
    if (pos.y + 1 < scale.y / 2 + 1)
        if (!graph[pos.y + 1][pos.x].visited)
            tab[3] = true;
    return get_rand(tab, pos);
}

static void move(data_t **graph, vector pos, vector scale)
{
    vector futur_pos;

    graph[pos.y][pos.x].visited = true;
    graph[pos.y][pos.x].type = EMPTY;
    while (1) {
        futur_pos = get_pos(graph, pos, scale);
        if (futur_pos.x < 0)
            return;
        if (pos.x - futur_pos.x < 0)
            graph[pos.y][pos.x].right = true;
        else if (pos.x - futur_pos.x > 0)
            graph[pos.y][pos.x].left = true;
        else {
            if (pos.y - futur_pos.y < 0)
                graph[pos.y][pos.x].down = true;
            else if (pos.y - futur_pos.y > 0)
                graph[pos.y][pos.x].up = true;
        }
        move(graph, futur_pos, scale);
    }
}

static void clean_maze(char **maze, vector scale)
{
    for (int y = 0; y < scale.y; y++)
        for (int x = 0; x < scale.x; x++)
            maze[y][x] = (maze[y][x] == '?') ? WALL : maze[y][x];
}

int make_maze_perfect(char **maze, vector pos, vector scale)
{
    data_t **graph = get_graph(scale);

    if (!graph)
        return EXIT_ERROR;
    move(graph, pos, scale);
    graph_to_map(maze, graph, scale);
    for (int y = 0; y < scale.y / 2 + 1; y++)
        free(graph[y]);
    free(graph);
    clean_maze(maze, scale);
    return 0;
}