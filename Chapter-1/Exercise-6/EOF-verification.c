/*
 * Exercise 1-6.
 * Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

int main() {
    int c;
    c = getchar() != EOF;

    printf("%d\n", c);
}

// In unix machines, CTRL-D is the End Of File character.
// This program prints 1 for any character except CTRl-D,
// which prints 0.
