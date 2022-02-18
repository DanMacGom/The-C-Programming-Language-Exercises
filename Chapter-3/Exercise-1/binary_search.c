/*
 * Exercise 3-1.
 * Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run-time.
 */

#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 20

int binsearchKR(int x, int v[], int n, int *interations);
int binsearch(int x, int v[], int n, int *iterations);

/* binearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearchKR(int x, int v[], int n, int *iterations) {
    int low, high, mid;

    *iterations = 0;
    low = 0;
    high = n - 1;

    while (low <= high) {
        ++(*iterations);

        mid = (low + high) / 2;

        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int binsearch(int x, int v[], int n, int *iterations) {
    int low, high, mid;

    *iterations = 0;
    low = 0;
    high = n - 1;

    mid = (low + high) / 2;
    while (low < high && v[mid] != x) {
        ++(*iterations);

        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        mid = (low + high) / 2;
    }

    return (v[low] == x) ? mid : -1;
}

int main(void) {
    int v[ARRAY_SIZE] = {2,  4,  8,  10, 12, 15, 17, 25, 26, 29,
                         35, 36, 37, 39, 48, 49, 55, 60, 62, 97};

    int i, res;
    int iterations = 0;
    clock_t beginKR = clock();

    for (i = 2; i <= 100; i++) {
        res = binsearchKR(i, v, ARRAY_SIZE, &iterations);
        printf("Iterations: %d - Match: %d\n", iterations,
               (v[res] > 0) ? v[res] : -1);
    }

    clock_t endKR = clock();

    clock_t begin = clock();

    for (i = 2; i <= 100; i++) {
        res = binsearch(i, v, ARRAY_SIZE, &iterations);
        printf("Iterations: %d - Match: %d\n", iterations,
               (v[res] > 0) ? v[res] : -1);
    }

    clock_t end = clock();

    double time_spentKR = (double)(endKR - beginKR) / CLOCKS_PER_SEC;
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time in seconds binsearchKR: %lf\n", time_spentKR);
    printf("Time in seconds binsearch: %lf\n", time_spent);

    return 0;
}

// Minimal performance increase, and reduced readability. 0.236 ms vs 0.379 ms.
