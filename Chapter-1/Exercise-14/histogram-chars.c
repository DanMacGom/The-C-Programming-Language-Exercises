/*
 * Exercise 1-14.
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 */

#include <stdio.h>

#define IN 1
#define OUT 0

#define CHAR_NUM 256

int main() {
    int histogram[CHAR_NUM];
    int c, state;
    int currentWordCount = 0;
    int maxCharWordReached = 0;

    int i, j;
    for (i = 0; i <= CHAR_NUM; ++i) {
        histogram[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++histogram[c];
    }

    printf("\nHistogram: frequency of characters\n");
    printf("---------------------------------------\n");

    for (i = 32; i <= 126; ++i) {
        printf("%3d - %c ", i, i);
        for (j = 1; j <= histogram[i]; ++j) {
            printf("=");
        }
        printf("\n");
    }
    printf("---------------------------------------\n");
}
