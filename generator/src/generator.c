/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include "generator.h"

void make_maze(char **maze, vector pos, char **av)
{
    maze[pos.y][pos.x] = EMPTY;
    if (pos.x == atoi(av[1]) - 1 && pos.y == atoi(av[2]) - 1)
        return;
    if (pos.x == atoi(av[1]) - 1) {
        make_maze(maze, (vector) {pos.x, pos.y + 1}, av);
        return;
    }
    if (pos.y == atoi(av[2]) - 1) {
        make_maze(maze, (vector) {pos.x + 1, pos.y}, av);
        return;
    }
    if (rand() % 2 == 0)
        make_maze(maze, (vector) {pos.x + 1, pos.y}, av);
    else
        make_maze(maze, (vector) {pos.x, pos.y + 1}, av);
}