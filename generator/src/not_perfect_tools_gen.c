/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include "generator.h"

static bool what_is_next(bool *is_wall)
{
    bool gen = rand() % 50;

    if (*is_wall)
        return false;
    if (gen)
        *is_wall = true;
    return gen;
}

void start_maze(char **maze, int x, int y, vector scale)
{
    maze[y][x] = '$';
    if (x == scale.x - 1 && y == scale.y - 1)
        return;
    if (x == scale.x - 1) {
        start_maze(maze, x, y + 1, scale);
        return;
    }
    if (y == scale.y - 1) {
        start_maze(maze, x + 1, y, scale);
        return;
    }
    if (rand() % 2 == 0)
        start_maze(maze, x + 1, y, scale);
    else
        start_maze(maze, x, y + 1, scale);
}

static void break_wall(char **maze, vector scale, vector pos)
{
    vector rm;
    bool tab[4] = {false, false, false, false};

    bool_tab_filler(maze, scale, pos, tab);
    rm = get_rand(tab, pos);
    if (rm.x < 0)
        return;
    maze[pos.y][pos.x] = EMPTY;
    break_wall(maze, scale, rm);
}

void move_not_perfect(char **maze, vector pos, vector scale)
{
    bool is_wall = false;
    vector futur_pos= get_futur_pos(maze, pos, scale);

    maze[pos.y][pos.x] = EMPTY;
    while (!(futur_pos.x < 0)) {
        if (what_is_next(&is_wall)) {
            if (maze[futur_pos.y][futur_pos.x] == '$')
                move_not_perfect(maze, futur_pos, scale);
            else
                maze[futur_pos.y][futur_pos.x] = WALL;
        }
        else
            move_not_perfect(maze, futur_pos, scale);
        futur_pos = get_futur_pos(maze, pos, scale);
    }
}

void finish_maze(char **maze, vector scale)
{
    for (int y = 0; y < scale.y; y++)
        for (int x = 0; x < scale.x; x++)
            if (maze[y][x] == '?') {
                break_wall(maze, scale, (vector) {x, y});
                move_not_perfect(maze, (vector) {x, y}, scale);
                y = -1;
                break;
            }
}
