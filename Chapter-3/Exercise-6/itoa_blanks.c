/*
 * Exercise 3-6.
 * Write a version of itoa that accepts three arguments instead of two.
 * The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
void itoa(unsigned int n, char s[], int min);

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(unsigned int n, char s[], int min) {
    int i, sign, str_len;

    if ((sign = n) < 0) n = -n;

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) s[i++] = '-';

    while (min > i) {
        s[i++] = ' ';
    }

    s[i] = '\0';

    reverse(s);
}

int main(void) {
    char s[MAXLINE];

    itoa(1234567890, s, 15);

    printf("%s\n", s);

    return 0;
}
