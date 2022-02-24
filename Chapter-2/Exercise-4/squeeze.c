/*
 * Exercise 2-4.
 * Write an alternate version of squeeze(s1, s2) that deletes each character
 * in s1 that matches any character in the string s2.
 */

#include <stdio.h>

#define MAXLINE 1000

void squeeze(char s1[], char s2[]);
void getln(char s[]);

void squeeze(char s1[], char s2[]) {
    int i, j, k;

    k = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++) {
            ;
        }

        // When s1[i] == s2[j] then s2[j] is never '\0' so k does not increase
        // in this case.
        if (s2[j] == '\0') {
            s1[k++] = s1[i];
        }
    }

    // When we add the terminator '\0' to a string, C ignores what comes after.
    // So even if there are characters after the '\0', they will not be printed.
    s1[k] = '\0';
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
    char s1[MAXLINE], s2[MAXLINE];

    printf("s1: ");
    getln(s1);
    printf("s2: ");
    getln(s2);

    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}
