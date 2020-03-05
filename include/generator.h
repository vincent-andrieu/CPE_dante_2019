/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** header generator
*/

#include <stdlib.h>
#include <stdbool.h>

#ifndef GEN_DANTE_H_
#define GEN_DANTE_H_

#define EXIT_ERROR 84

#define WALL 'X'
#define EMPTY '*'

void make_maze(char **maze, int x, int y, char **av);

#endif