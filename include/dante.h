/*
** EPITECH PROJECT, 2019
** Dante's star
** File description:
** header dante
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef DANTE_H_
#define DANTE_H_

#define EXIT_ERROR 84
#define WALL 'X'
#define EMPTY '*'
#define PATH 'o'

typedef struct vector_s
{
    int x;
    int y;
} vector;

#endif