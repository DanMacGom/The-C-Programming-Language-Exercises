/*
 * Exercise 3-4.
 * In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to
 * -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly,
 * regardless of the machine on which it runs.
 */

/*
 * Wordsize means the width of the integer we can store in a variable.
 * In a two's complement number representation, integers range from -(2^(n-1))
 * to 2^(n-1) - 1. So if we input n = -2(^(n-1)) and flip its sign, it's going
 * to integer overflow (outputs garbage).
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
int absfn(int x);
void itoa(int n, char s[]);

/* reverse string s in place */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int absfn(int x) { return (x < 0) ? -x : x; }

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    int i, sign;

    /* Remove the sign flip */
    //	if ((sign = n) < 0)
    //		n = -n;

    sign = n;

    i = 0;
    do {                              /* generate digits in reverse order */
        s[i++] = absfn(n % 10) + '0'; /* get next digit */
    } while ((n /= 10) != 0);         /* delete it */

    if (sign < 0) {
        s[i++] = '-';
        s[i] = '\0';

        reverse(s);
    }
}

int main(void) {
    char s1[MAXLINE];
    char s2[MAXLINE];

    // Test overflow.
    itoa(INT_MIN, s1);
    printf("%d => %s\n", INT_MIN, s1);

    itoa(INT_MAX, s2);
    printf("%d => %s\n", INT_MAX, s2);
    return 0;
}
