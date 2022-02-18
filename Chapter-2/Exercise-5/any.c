/*
 * Exercise 2-5.
 * Write the function any(s1, s2), which returns the first location in the
 * string s1 where any character from the string s2 occurs, or -1 if s1 contains
 * no characters from s2. (The standard library function strpbrk does the same
 * job but returns a pointer to the location.
 */

#include <stdio.h>

#define MAXLINE 1000

int any(char s1[], char s2[]);
void getln(char s[]);

int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}

void getln(char s[]) {
    int i;
    char c;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    s[i] = '\0';
}

int main(void) {
    int result;

    char s1[MAXLINE];
    char s2[MAXLINE];

    getln(s1);
    getln(s2);

    result = any(s1, s2);
    if (result >= 0) {
        printf("char: %c, pos: %d\n", s1[result], result);
    } else {
        printf("No chars found\n");
    }

    return 0;
}
