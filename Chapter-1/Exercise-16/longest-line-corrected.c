/*
 * Exercise 1-16.
 * Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrarily long input lines, and as much as possible of
 * the text.
 */

// #############################################################################
// IMPORTANT: getline() is a standard library function, changed the name of the
// function to obtainline().
// #############################################################################

// Maximum input line size.
#define MAXLINE 5
// IMPORTANT: lower this constant to test (1000 chars is too much to input in
// console). If your string is longer than MAXLINE then this program should
// print your string up to MAXLINE-1 index since you have an extra '\n' from
// entering the input.

#include <stdio.h>

int obtainline(char line[], int maxline);
void copy(char to[], char from[]);

// obtainline: read a line into s, return length
int obtainline(char s[], int lim) {
    int c, i;

    // if s = '\0' the returned length will be 0.
    // if s = '\n' the returned length will be 1.
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

// copy: copy "from" into "to"; assume to is big enough
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

int main() {
    int len;         // Current line length.
    int max;         // Maximum length seen so far.
    int lenOfChunk;  // Length of the current slice of string if len > MAXLINE.
    char line[MAXLINE];     // Current input line.
    char longest[MAXLINE];  // Longest line saved here.
    char lineChunk[MAXLINE];

    max = 0;
    // Obtain length of the string until EOF (len = 0).
    while ((len = obtainline(line, MAXLINE)) > 0) {
        // If real length of string is > MAXLINE, then read up until MAXLINE
        // - 1.
        // https://github.com/cdude996/The-C-Programming-Language/blob/master/chapter01/1-16.c
        if (len == MAXLINE - 1) {
            lenOfChunk = len;

            // This will add multiples of (MAXLINE - 1) to len until len <
            // MAXLINE, which will correspond to the last chunk of the line and
            // will not go through this if but the next one.
            while (lenOfChunk == MAXLINE - 1) {
                lenOfChunk = obtainline(lineChunk, MAXLINE);
                len += lenOfChunk;
            }
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {  // There was a line
        printf("%s\n", longest);
        printf("Real maximum length of the strings: %d\n", max);
    }

    return 0;
}
