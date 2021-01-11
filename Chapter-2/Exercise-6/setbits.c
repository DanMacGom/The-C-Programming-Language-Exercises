/*
 * Exercise 2-6.
 * Write a function setbits(x, p, n, y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits unchanged.
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

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
	// Taken from: https://www.youtube.com/watch?v=YIF-ARTIRLE 
	// 1. Get the rightmost n bits of y.
	//	1.1 Shift left the complement of 0 by n.
	//	 	~0 << n	(11110000) 
	//	1.2 Complement the result.
	//		~(~0 << n) (00001111)
	// 	1.3 AND the result to y.
	//		y & ~(~0 << n) --> rightmost n bits of y
	// 2. Shift left the result to position p.
	// 		(y & ~(~0 << n)) << p + 1 - n
	// 3. OR the result with x whose n bits starting at position p are
	// masked to zero.
   	
	// 4. Get the masked x
	//	4.1 Shift left the complement of 0 by n
	//		~0 << n				(11110000)
	//	4.2 Complement the result
	//		~(~0 << n)			(00001111)
	//	4.3 Shift left the result to p
	//		~(~0 << n) << p + 1 - n 	(00111100)
	//	4.4 Complement the result
	//		~(~(~0 << n) << p + 1 - n)	(11000011)
	//	4.5 AND the result with x
	//		x & ~(~(~0 << n) << p + 1 - n) -> masked x
	//	4.6 OR the result to the result of Procedure 2.
	//		(x & ~(~(~0 << n) << p+1-n)) | ((y & ~(~0 << n)) << p+1-n)
	
	return (y & ~(~0 << n)) << (p + 1 - n) | (x & ~(~(~0 << n) << (p + 1 - n)));	
}

int main(void) {
	unsigned int x = 50, y = 30;
	int p = 4, n = 3;
	printf("x="BYT_BIN_PAT"\ny="BYT_BIN_PAT"\n", BYT_BIN(x), BYT_BIN(y));
	printf("Result="BYT_BIN_PAT"\n", BYT_BIN(setbits(x, p, n, y)));	
}
