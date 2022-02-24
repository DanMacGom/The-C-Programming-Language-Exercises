/*
 * Exercise 2-10.
 * Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else.
 */

#include <stdio.h>

char lower(char c);

char lower(char c) { return (c >= 'A' || c <= 'a') ? c + 'a' - 'A' : c; }

int main(void) {
    printf("%c\n", lower('Z'));
    return 0;
}
