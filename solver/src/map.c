/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** get solver dante map
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "dante.h"

static char **str_to_array(char *buffer, vector *end)
{
    char **map;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] != WALL && buffer[i] != EMPTY && buffer[i] != '\n') {
            free(buffer);
            return NULL;
        }
    map = my_str_to_array(buffer, "\n", false);
    free(buffer);
    if (map == NULL || map[0] == NULL)
        return NULL;
    end->y = my_strlen(map[0]);
    for (end->x = 1; map[end->x] != NULL; end->x++)
        if (my_strlen(map[end->x]) != end->y)
            return NULL;
    if (map[0][0] != EMPTY || map[--end->x][--end->y] != EMPTY)
        return NULL;
    return map;
}

char **get_map(int argc, char **argv, vector *end)
{
    struct stat st;
    char *buffer;
    int fd;
    int read_size;

    if (argc != 2 || stat(argv[1], &st) == -1)
        return NULL;
    fd = open(argv[1], O_RDONLY);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    if (fd == -1 || buffer == NULL)
        return NULL;
    read_size = read(fd, buffer, st.st_size);
    if (read_size == -1)
        return NULL;
    buffer[read_size] = '\0';
    return str_to_array(buffer, end);
}