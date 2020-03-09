/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "generator.h"

static int set_overflow(void)
{
    struct rlimit limit = {0};

    if (getrlimit(RLIMIT_STACK, &limit) == -1)
        return EXIT_ERROR;
    printf ("Stack Limit = %ld|%ld max\n", limit.rlim_cur, limit.rlim_max);
    limit.rlim_cur = (size_t) 1024 * 1024 * (16 * 1000);
    if (setrlimit(RLIMIT_STACK, &limit) == -1)
        return EXIT_ERROR;
    printf ("Stack Limit = %ld|%ld max\n", limit.rlim_cur, limit.rlim_max);
    return EXIT_SUCCESS;
}

static bool error_gest(int ac, char **av)
{
    if (ac == 3)
        return false;
    else if (ac == 4) {
        if (strcmp(av[3], PERFECT) == 0)
            return false;
        else
            return true;
    }
    else
        return true;
}

static char **get_empty_maze(vector scale)
{
    int size_y = scale.y;
    int size_x = scale.x;
    char **maze = malloc(sizeof(char *) * (size_y + 2));

    if (!maze)
        return NULL;
    maze[size_y + 1] = NULL;
    for (int i = 0; i < size_y + 1; i++) {
        maze[i] = malloc(sizeof(char) * (size_x + 2));
        if (!maze[i])
            return NULL;
        maze[i][size_x + 1] = '\0';
        for (int u = 0; u < size_x + 1; maze[i][u] = '?', u++);
    }
    return maze;
}

static int display_maze(char **maze, vector scale)
{
    for (int u = 0; maze[u] && u < scale.y; u++) {
        write(1, maze[u], scale.x);
        if (u < scale.y - 1)
            write(1, "\n", 1);
    }
    for (int u = 0; maze[u]; u++)
        free(maze[u]);
    free(maze);
    return 0;
}

int main(int ac, char **av)
{
    vector scale = {0};
    char **maze;

    if (error_gest(ac, av) || set_overflow() == EXIT_ERROR)
        return EXIT_ERROR;
    scale = (vector) {atoi(av[1]), atoi(av[2])};
    if (scale.x <= 0 || scale.y <= 0)
        return EXIT_ERROR;
    srand(time(NULL));
    maze = get_empty_maze(scale);
    if (!maze)
        return EXIT_ERROR;
    if (ac == 3)
        make_maze_not_perfect(maze, (vector) {0, 0}, scale);
    else if (strcmp(av[3], PERFECT) == 0)
        make_maze_perfect(maze, (vector) {0, 0}, scale);
    else
        return EXIT_ERROR;
    return display_maze(maze, scale);
}