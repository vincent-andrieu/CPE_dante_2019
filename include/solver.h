/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** header solver
*/

#include "dante.h"

#ifndef SOL_DANTE_H_
#define SOL_DANTE_H_

int dante_solver(int argc, char **argv);
char **get_map(int argc, char **argv, vector *end);
int get_result(char **map, vector const end, vector coord);

#endif