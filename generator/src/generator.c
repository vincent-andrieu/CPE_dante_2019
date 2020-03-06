/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include <stdlib.h>
#include "generator.h"

typedef struct data_s
{
    char type;
    bool visited;
    bool up;
    bool down;
    bool left;
    bool right;
} data_t;

static data_t **get_graph(vector scale)
{
    data_t **graph = malloc(sizeof(data_t *) * scale.y);

    if (!graph)
        return NULL;
    for (int y = 0; y < scale.y; y++) {
        graph[y] = malloc(sizeof(data_t) * scale.x);
        if (!graph[y])
            return NULL;
        for (int x = 0; x < scale.x; x++) {
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

static vector get_futur_pos(data_t **graph, vector pos, vector scale)
{
    int nb = rand() % 4;
    bool tab[4] = {false, false, false, false};

    if (pos.x - 1 >= 0)
        if (!graph[pos.y][pos.x - 1].visited)
            tab[0] = true;
    if (pos.x + 1 < scale.x)
        if (!graph[pos.y][pos.x + 1].visited)
            tab[1] = true;
    if (pos.y - 1 >= 0)
        if (!graph[pos.y - 1][pos.x].visited)
            tab[2] = true;
    if (pos.y + 1 < scale.y)
        if (!graph[pos.y + 1][pos.x].visited)
            tab[3] = true;
    for (int cnt = 0; !tab[nb % 4]; nb++, cnt++)
        if (cnt > 4)
            return (vector) {-1, -1};
    if (nb % 4 == 0)
        return (vector) {pos.x - 1, pos.y};
    if (nb % 4 == 1)
        return (vector) {pos.x + 1, pos.y};
    if (nb % 4 == 2)
        return (vector) {pos.x, pos.y - 1};
    if (nb % 4 == 3)
        return (vector) {pos.x, pos.y + 1};
    return (vector) {-1, -1};
}

static void move(data_t **graph, vector pos, vector scale)
{
    static int cnt = 0;
    cnt++;
    printf("cnt: %i\n", cnt);
    vector futur_pos;

    graph[pos.y][pos.x].visited = true;
    graph[pos.y][pos.x].type = EMPTY;
    while (1) {
        futur_pos = get_futur_pos(graph, pos, scale);
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

static void graph_to_map(char **maze, data_t **graph, vector scale)
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
                maze[y_map + 1][x_map] = (graph[y][x].up) ? EMPTY : maze[y_map + 1][x_map];
        }
    }
}

int make_maze(char **maze, vector pos, vector scale)
{
    data_t **graph = get_graph(scale);

    if (!graph)
        return EXIT_ERROR;
    move(graph, pos, scale);
    graph_to_map(maze, graph, scale);
    for (int y = 0; y < scale.y; y++)
        free(graph[y]);
    free(graph);
    return 0;
}