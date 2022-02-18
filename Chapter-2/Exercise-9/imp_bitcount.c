/*
 * Exercise 2-9.
 * In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of
 * bitcount.
 */

/* In binary subtraction, when you 0 - 1, you borrow from the next higher
 * significant bit. Which is translated in change the next 1 you encounter to 0
 * while changing all 0 to 1's you encounter. This has the effect of masking the
 * remainder of the number up until that bit.
 *
 *            1111 1000
 * 	    - 0000 0001
 * 	      ---------
 * 	      1111 0111
 *
 * After subtracting we can see that 1111 1000 & 1111 0111 = 1111 0000
 *
 *
 *            1100 0000
 *          - 0000 0001
 *	      ---------
 *            1011 1111
 *
 * We have the same number up until the last 1 where all the bits are flipped.
 * ANDing them together means the 1's cancel with the 0's.
 */

#include <stdio.h>

#define BYT_BIN_PAT "%c%c%c%c%c%c%c%c"
#define BYT_BIN(byte)                                     \
    (byte & 128 ? '1' : '0'), (byte & 64 ? '1' : '0'),    \
        (byte & 32 ? '1' : '0'), (byte & 16 ? '1' : '0'), \
        (byte & 8 ? '1' : '0'), (byte & 4 ? '1' : '0'),   \
        (byte & 2 ? '1' : '0'), (byte & 1 ? '1' : '0')

unsigned int impBitcount(unsigned int x);

unsigned int impBitcount(unsigned int x) {
    int b = 0;

    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }

    return b;
}

int main(void) {
    unsigned int x = 255;
    printf(BYT_BIN_PAT "\n", BYT_BIN(x));
    printf("%d\n", impBitcount(x));

    return 0;
}
