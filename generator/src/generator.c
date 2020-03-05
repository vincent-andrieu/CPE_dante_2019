/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include "generator.h"

void make_maze(char **maze, int x, int y, char **av)
{
    maze[y][x] = EMPTY;
    if (x == atoi(av[1]) - 1 && y == atoi(av[2]) - 1)
        return;
    if (x == atoi(av[1]) - 1) {
        make_maze(maze, x, y + 1, av);
        return;
    }
    if (y == atoi(av[2]) - 1) {
        make_maze(maze, x + 1, y, av);
        return;
    }
    if (rand() % 2 == 0)
        make_maze(maze, x + 1, y, av);
    else
        make_maze(maze, x, y + 1, av);
}