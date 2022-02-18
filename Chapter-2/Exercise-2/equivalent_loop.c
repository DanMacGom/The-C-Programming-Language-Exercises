/*
 * Exercise 2-2.
 * Write a loop equivalent to the for loop above without using && or ||.
 */

#include <stdio.h>

#define MAXLINE 1000

int main(void) {
    // for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    // 	s[i] = c;

    int i = 0;
    int loop = 1;
    char s[MAXLINE];

    while (loop) {
        char c = getchar();

        if (i >= MAXLINE - 1) {
            loop = 0;
        } else if (c == '\n') {
            loop = 0;
        } else if (c == EOF) {
            loop = 0;
        }

        s[i++] = c;
    }

    s[i] = '\0';

    printf("Input line: %s", s);

    return 0;
}
