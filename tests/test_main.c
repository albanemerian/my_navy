/*
** EPITECH PROJECT, 2024
** B-PSU-100-NAN-1-1-navy-albane.merian
** File description:
** test_main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/navy.h"


Test(check_lines, valid_range)
{
    cr_assert(check_lines('A', 'A', 'H'));
    cr_assert(check_lines('5', '2', '5'));
}

Test(check_lines, invalid_range)
{
    cr_assert_not(check_lines('I', 'A', 'H'));
    cr_assert_not(check_lines('1', '2', '5'));
}

Test(check_buffer, valid_buffer)
{
    char line[] = "2:A1:B2";
    cr_assert_eq(check_buffer(line, '2'), 0);
}

Test(check_buffer, invalid_buffer)
{
    char line[] = "2:A1:V2";
    cr_assert_eq(check_buffer(line, '2'), 84);
}

Test(check_filepath, invalid_filepath)
{
    char filepath[] = "invalid_positions.txt";
    cr_assert_eq(check_filepath(filepath), 84);
}
