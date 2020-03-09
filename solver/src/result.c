/*
** EPITECH PROJECT, 2019
** dante
** File description:
** solver result
*/

#include "dante.h"

static void empty_map(char **map, vector const end)
{
    for (int y = 0; y <= end.y; y++)
        for (int x = 0; x <= end.x; x++)
            map[y][x] = map[y][x] == PATH ? EMPTY : map[y][x];
}

int get_result(char **map, vector const end, vector coord)
{
    vector const coords[4] = {(vector) {coord.x, coord.y - 1},
                            (vector) {coord.x - 1, coord.y},
                            (vector) {coord.x, coord.y + 1},
                            (vector) {coord.x + 1, coord.y}};

    if (coord.x == 0 && coord.y == 0) {
        empty_map(map, end);
        map[coord.y][coord.x] = PATH;
        return EXIT_SUCCESS;
    }
    map[coord.y][coord.x] = EMPTY;
    for (int i = 0; i < 4; i++)
        if (coords[i].y >= 0 && coords[i].y <= end.y
        && coords[i].x >= 0 && coords[i].x <= end.x
        && map[coords[i].y][coords[i].x] == PATH)
            if (get_result(map, end, coords[i]) == EXIT_SUCCESS) {
                map[coord.y][coord.x] = PATH;
                return EXIT_SUCCESS;
            }
    return EXIT_FAILURE;
}