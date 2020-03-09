/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include "generator.h"

vector get_rand(bool *tab, vector pos)
{
    int nb = rand() % 4;

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

vector get_futur_pos(char **maze, vector pos, vector scale)
{
    bool tab[4] = {false, false, false, false};

    if (pos.x - 1 >= 0)
        if (maze[pos.y][pos.x - 1] == '?' || maze[pos.y][pos.x - 1] == '$')
            tab[0] = true;
    if (pos.x + 1 < scale.x)
        if (maze[pos.y][pos.x + 1] == '?' || maze[pos.y][pos.x + 1] == '$')
            tab[1] = true;
    if (pos.y - 1 >= 0)
        if (maze[pos.y - 1][pos.x] == '?' || maze[pos.y - 1][pos.x] == '$')
            tab[2] = true;
    if (pos.y + 1 < scale.y)
        if (maze[pos.y + 1][pos.x] == '?' || maze[pos.y + 1][pos.x] == '$')
            tab[3] = true;
    return get_rand(tab, pos);
}

int make_maze_not_perfect(char **maze, vector pos, vector scale)
{
    start_maze(maze, 0, 0, scale);
    move_not_perfect(maze, pos, scale);
    finish_maze(maze, scale);
    return 0;
}

void bool_tab_filler(char **maze, vector scale, vector pos, bool *tab)
{
    if (pos.x - 1 >= 0) {
        if (maze[pos.y][pos.x - 1] == WALL)
            tab[0] = true;
    }
    if (pos.x + 1 < scale.x) {
        if (maze[pos.y][pos.x + 1] == WALL)
            tab[1] = true;
    }
    if (pos.y - 1 >= 0) {
        if (maze[pos.y - 1][pos.x] == WALL)
            tab[2] = true;
    }
    if (pos.y + 1 < scale.y) {
        if (maze[pos.y + 1][pos.x] == WALL)
            tab[3] = true;
    }
}