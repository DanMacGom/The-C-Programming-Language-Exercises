/*
 * Exercise 2-7.
 * Write a function invert(x, p, n) that returns x with the n bits that begin
 * at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
 * others unchanged.
*/

#include <stdio.h>

#define BYT_BIN_PAT "%c%c%c%c%c%c%c%c"
#define BYT_BIN(byte)   \
        (byte & 128 ? '1' : '0'), \
        (byte & 64 ? '1' : '0'),  \
        (byte & 32 ? '1' : '0'),  \
        (byte & 16 ? '1' : '0'),  \
        (byte & 8 ? '1' : '0'),   \
        (byte & 4 ? '1' : '0'),   \
        (byte & 2 ? '1' : '0'),   \
        (byte & 1 ? '1' : '0')

unsigned int invert(unsigned int x, int p, int n);

unsigned int invert(unsigned int x, int p, int n) {
	return x ^ (~(~0 << n) << (p + 1 - n));
}

int main(void) {
	printf(BYT_BIN_PAT"\n", BYT_BIN(invert(20, 4, 3)));
}
