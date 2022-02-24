/*
 * Exercise 4-1.
 * Write the function strrindex(s, t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main(void) {
    char s[] = "ola";
    char t[] = "ola";

    int index = strrindex(s, t);

    printf("First letter is %c at index %d.\n", s[index], index);

    return 0;
}

int strrindex(char s[], char t[]) {
    for (int i = strlen(s) - 1; i > -1; i--) {
        if (s[i] == t[strlen(t) - 1]) {
            for (int j = strlen(t) - 1, k = i; s[k] == t[j]; j--, k--) {
                if (j == 0) {
                    return i - (strlen(t) - 1);
                }
            }
        }
    }

    return -1;
}
