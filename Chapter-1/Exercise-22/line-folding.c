/*
 * Exercise 1-22.
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define MAXLINE 1000
#define FOLDCOLS 5

void fold(char line[], char fold_line[]);
int obtainline(char s[], int lim);

void fold(char line[], char fold_line[]) {
    int i, j, lastBlankPos, inBlank;

    for (i = 0; line[i] != '\0'; ++i) {
        if (line[i] == ' ' || line[i] == '\t') {
            if (!inBlank) {
                lastBlankPos = i;
            }
            inBlank = 1;
        } else {
            inBlank = 0;
        }
        if (i + 1) % FOLDCOLS == 0) {

    }
    }
}

int obtainline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

int main() {
    char line[MAXLINE];
    char fold_line[MAXLINE];

    obtainline(line, MAXLINE);
    fold(line, fold_line);

    printf("%s\n", fold_line);
}
