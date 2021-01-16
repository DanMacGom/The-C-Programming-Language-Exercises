/*
 * Exercise 3-5.
 * Write the function itob(n, s, b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n, s, 16) formats
 * n as a hexadecimal integer in s.
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
int absfn(int x);
int itob(int n, char s[], int b);

void reverse(char s[]) {
	int i, j, c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int absfn(int x) {
	return (x < 0) ? -x : x;
}

int itob(int n, char s[], int b) {
	int i, sign;
	const char baseDigits[16] = { 
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
		'A', 'B', 'C', 'D', 'E', 'F'			
	};

//	if ((sign = n) < 0 && b == 10) 
//		n = -n;
	sign = n;		

	i = 0;

	do {
		s[i++] = baseDigits[absfn(n % b)];	
	} while ((n/= b) != 0);

	if (sign < 0 && b == 10) 
		s[i++] = '-';

	s[i] = '\0';

	reverse(s);
}

int main(void) {
	int i, n, b;
	char s[MAXLINE];

	for (i=2; i <= 16; i++) {
		printf("Base %d: \n", i);
		itob(INT_MIN, s, i);
		printf("%s\n", s);
		itob(INT_MAX, s, i);	
		printf("%s\n\n", s);
	}

	return 0;
}
