/*
** EPITECH PROJECT, 2019
** dante
** File description:
** solver
*/

#include <stdio.h>
#include "dante.h"
#include "solver.h"

static void free_tabs(char **map, bool **neighbors)
{
    int i = 0;

    for (; map[i] != NULL; i++) {
        free(map[i]);
        free(neighbors[i]);
    }
    free(map);
    free(neighbors[i]);
    free(neighbors[i + 1]);
    free(neighbors);
}

static bool **init_neighbors(vector const end)
{
    bool **neighbors = malloc(sizeof(bool *) * (end.y + 3));

    if (neighbors == NULL)
        return NULL;
    for (int i = 0; i < end.y + 3; i++) {
        neighbors[i] = malloc(sizeof(bool) * end.x + 3);
        if (neighbors[i] == NULL)
            return NULL;
        for (int k = 0; k < end.x + 3; k++)
            neighbors[i][k] = false;
    }
    for (int i = 0; i < end.y + 3; i++) {
        neighbors[i][0] = true;
        neighbors[i][end.x + 2] = true;
    }
    for (int i = 0; i < end.x + 3; i++) {
        neighbors[0][i] = true;
        neighbors[end.y + 2][i] = true;
    }
    return neighbors;
}

static int check_nodes(char **map, bool **neighbors,
                        vector const end, vector coord)
{
    vector const coords[4] = {(vector) {coord.x, coord.y - 1},
                            (vector) {coord.x + 1, coord.y},
                            (vector) {coord.x, coord.y + 1},
                            (vector) {coord.x - 1, coord.y}};

    if (coord.x == end.x && coord.y == end.y) {
        map[coord.y][coord.x] = PATH;
        return EXIT_SUCCESS;
    }
    neighbors[coord.y + 1][coord.x + 1] = true;
    for (int i = 0; i < 4; i++)
        if (!neighbors[coords[i].y + 1][coords[i].x + 1]
        && map[coords[i].y][coords[i].x] != WALL)
            if (check_nodes(map, neighbors, end, coords[i]) == EXIT_SUCCESS) {
                map[coord.y][coord.x] = PATH;
                return EXIT_SUCCESS;
            }
    return EXIT_FAILURE;
}

int main(int argc, char **argv)
{
    vector end;
    char **map = get_map(argc, argv, &end);
    bool **neighbors = map == NULL ? NULL : init_neighbors(end);

    if (neighbors == NULL)
        return EXIT_ERROR;
    if (check_nodes(map, neighbors, end, (vector) {0, 0}) == EXIT_SUCCESS)
        for (int i = 0; map[i] != NULL; i++)
            printf("%s\n", map[i]);
    else
        printf("no solution found\n");
    free_tabs(map, neighbors);
    return EXIT_SUCCESS;
}