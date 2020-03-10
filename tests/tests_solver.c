/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** criterion tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "solver.h"

Test(solver, test_success)
{
    char *argv[] = {"./solver/solver", "maps/map_broken"};

    cr_assert_eq(dante_solver(2, argv), EXIT_SUCCESS);
}

Test(solver, test_map_failure)
{
    char *argv[] = {"./solver/solver", "maps/computerphile_failure"};

    cr_assert_eq(dante_solver(2, argv), EXIT_SUCCESS);
}

Test(solver, test_map_line)
{
    char *argv[] = {"./solver/solver", "maps/line"};

    cr_assert_eq(dante_solver(2, argv), EXIT_SUCCESS);
}

Test(solver, test_map_bad)
{
    char *argv[] = {"./solver/solver", "maps/map_bad"};

    cr_assert_eq(dante_solver(2, argv), EXIT_ERROR);
}

Test(solver, test_bad_args)
{
    char *argv[] = {"./solver/solver"};

    cr_assert_eq(dante_solver(1, argv), EXIT_ERROR);
}

Test(solver, test_invalid_map)
{
    char *argv[] = {"./solver/solver", "invalid_map"};

    cr_assert_eq(dante_solver(2, argv), EXIT_ERROR);
}

Test(solver, test_map_bad_size)
{
    char *argv[] = {"./solver/solver", "maps/bad_size"};

    cr_assert_eq(dante_solver(2, argv), EXIT_ERROR);
}

Test(solver, test_map_bad_start)
{
    char *argv[] = {"./solver/solver", "maps/invalid_start"};

    cr_assert_eq(dante_solver(2, argv), EXIT_ERROR);
}

Test(solver, test_map_bad_finish)
{
    char *argv[] = {"./solver/solver", "maps/invalid_finish"};

    cr_assert_eq(dante_solver(2, argv), EXIT_ERROR);
}