/*
 * Exercise 1-8.
 * Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

int main() {
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;

    char c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        }

        if (c == '\t') {
            ++tabs;
        }

        if (c == '\n') {
            ++newlines;
        }
    }

    printf("Number of blanks: %d\n", blanks);
    printf("Number of tabs: %d\n", tabs);
    printf("Number of newlines: %d\n", newlines);
}

// To test this code the user could three one-character words and count that
// the number of characters is 6 (e. g.: "a a a" three a's, two spaces and
// a newline with the Enter key).
// Also check that multiple lines are counted until you hit the EOF key.
// Try to input tabs between words (e. g.: "a   a   a").
