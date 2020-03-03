/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WALL 'X'
#define EMPTY '*'

static bool error_gest(int ac, char **av)
{
    if (ac == 3)
        return false;
    else if (ac == 4) {
        if (strcmp(av[3], "PERFECT") == 0)
            return false;
        else
            return true;
    }
    else
        return true;
}

static char **get_empty_maze(char **av)
{
    int size_y = atoi(av[2]);
    int size_x = atoi(av[1]);
    char **maze = malloc(sizeof(char *) * (size_y + 1));

    if (!maze)
        return NULL;
    maze[size_y] = NULL;
    for (int i = 0; i < size_y; i++) {
        maze[i] = malloc(sizeof(char) * (size_x + 1));
        if (!maze[i])
            return NULL;
        maze[i][size_x] = '\0';
        for (int u = 0; u < size_x;maze[i][u] = WALL, u++);
    }
    return maze;
}

static int display_maze(char **maze)
{
    for (int u = 0; maze[u]; u++) {
        printf("%s\n", maze[u]);
        free(maze[u]);
    }
    free(maze);
    return 0;
}

static void make_maze(char **maze, int x, int y, char **av)
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

int main(int ac, char **av)
{
    char **maze;

    srand(time(NULL));
    if (error_gest(ac, av))
        return 84;
    maze = get_empty_maze(av);
    make_maze(maze, 0, 0, av);
    return display_maze(maze);
}