#include <criterion/criterion.h>
#include "../src/tinyprintf.h"

Test(tinyprintf, no_directive)
{
    int expected = 11;
    int actual = tinyprintf("Do I work ?");
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}

Test(tinyprintf, simple_case)
{
    int expected = 17;
    int actual = tinyprintf("%s [%d] %s", "Hello", 42, "world!");
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}


Test(tinyprintf, hexadecimal_case)
{
    int expected = 17;
    int actual = tinyprintf("%s [%x] %s", "Hello", 42, "world!");
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}


Test(tinyprintf, percent_case)
{
    int expected = 2;
    int actual = tinyprintf("%%s", "in your head");
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}


Test(tinyprintf, unknown)
{
    char expected = 39;
    char actual = tinyprintf("Good morning ACU! %t Tinyprintf is cool", 12);
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}


Test(tinyprintf, tricky)
{
    int expected = 26;
    int actual = tinyprintf("%c%c is %s... %d too.", '4', '2', "the answer", '*');
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}
