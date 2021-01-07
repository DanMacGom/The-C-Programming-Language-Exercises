#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
	printf("--CHAR--\n");
	printf("Bits in a char: %d\n", CHAR_BIT);
	printf("Range of signed char: %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("Range of unsigned char: 0 to %d\n", UCHAR_MAX);
	printf("--INT--\n");
	printf("Range of int: %d to %d\n", INT_MIN, INT_MAX);	
	printf("Range of unsigned int: 0 to %u\n", UINT_MAX);
	printf("Range of long: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("Range of unsigned long: 0 to %lu \n", ULONG_MAX);
	printf("Range of short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("Range of unsigned short: 0 to %d\n", USHRT_MAX);
	return 0;
}
