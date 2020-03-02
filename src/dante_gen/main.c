/*
** EPITECH PROJECT, 2019
** dante
** File description:
** dante
*/

#include <string.h>
#include <stdbool.h>

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

int main(int ac, char **av)
{
    if (error_gest(ac, av))
        return 84;
    printf("OK\n");
    return 0;
}