/* 
 * Exercise 2-1.
 * Write a program to determine the ranges of char, short, int, and long variables, both
 * signed and unsigned, by printing appropriate values from standard headers and by direct
 * computation. Harder if you compute them: determine the ranges of the various floating-
 * point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
	printf("--CHAR--\n");
	printf("Bits in a char: %d\n", CHAR_BIT);
	printf("Range of signed char: %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("Range of unsigned char: 0 to %d\n", UCHAR_MAX);
	
	printf("\n--INT--\n");
	printf("Range of int: %d to %d\n", INT_MIN, INT_MAX);	
	printf("Range of unsigned int: 0 to %u\n", UINT_MAX);
	printf("Range of long int: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("Range of unsigned long int: 0 to %lu \n", ULONG_MAX);
	printf("Range of short int: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("Range of unsigned short int: 0 to %d\n", USHRT_MAX);
	
	printf("\n--FLOAT--\n");
	printf("Range of float: %g to %g\n", FLT_MIN, FLT_MAX);
	printf("Range of double: %lg to %lg\n", DBL_MIN, DBL_MAX);
	printf("Range of long double: %Lg to %Lg\n", LDBL_MIN, LDBL_MAX);
	return 0;
}
