#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/navy.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, Char, .init=redirect_all_stdout)
{
    my_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
}

Test(my_printf, Percentage, .init=redirect_all_stdout)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, Str, .init=redirect_all_stdout)
{
    my_printf("%s", "tests");
    cr_assert_stdout_eq_str("tests");
}

Test(my_printf, Nbr, .init=redirect_all_stdout)
{
    my_printf("%d", 42);
    cr_assert_stdout_eq_str("42");
}