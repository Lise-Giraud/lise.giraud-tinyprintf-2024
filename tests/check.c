#include <criterion/criterion.h>
#include "../src/tinyprintf.h"

Test(tinyprintf, no_directive)
{
    char *expected = "Do I work ?";
    char *actual = tinyprintf("Do I work ?");
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}

Test(tinyprintf, simple case)
{
    char *expected = "Hello [42] world!";
    char *actual = tinyprintf("%s [%d] %s", "Hello", 42, "world!");
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}


Test(tinyprintf, hexadecimal_case)
{
    char *expected = "Hello [2a] world!";
    char *actual = tinyprintf("%s [%x] %s", "Hello", 42, "world!");
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}


Test(tinyprintf, percent_case)
{
    char *expected = "%s";
    char *actual = tinyprintf("%%s". "in your head");
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}


Test(tinyprintf, unknown)
{
    char *expected = "Good morning ACU! %t Tinyprintf is cool";
    char *actual = tinyprintf("Good morning ACU! %t Tinyprintf is cool", 12);
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}


Test(tinyprintf, tricky)
{
    char *expected = "42 is the answer... 42 too.";
    char *actual = tinyprintf("%c%c is %s... %d too.", '4', '2', "the answer", '*');
    cr_assert_eq(actual, expected, "Expected %s. Got %s", expected, actual);
}
