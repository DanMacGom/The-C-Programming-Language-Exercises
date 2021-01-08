/*
 * Exercise 2-3.
 * Write the function htoi(s), which converts a string of hexadecimal digits (including
 * an optional 0x or 0X) into its equivalent integer value. The allowable digits are
 * 0 through 9, a through f, and A through F.
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000
#define HEXBASE 16.0

int htoi(char hex[]);
int strLength(char s[]);
void getln(char s[]);

int htoi(char hex[]) {
	int i, result, radix;

	int strlen = strLength(hex);

	i = result = 0;
	
	// This will not break because we input an array of length MAXLINE to htoi.
	if (hex[0] == '0' && tolower(hex[1]) == 'x') {
		i = 2;
	}  
	
	for ( ; i < strlen; i++) {
		// The base's power starts from right to left.
		radix = (int)pow(HEXBASE, strlen-i-1);

		if (isdigit(hex[i])) {
			// Transform character digits to their integer values.
			result += (hex[i] - '0') * radix;
		} else if (tolower(hex[i]) >= 'a' && tolower(hex[i]) <= 'f') {
			// Transform a-f chars to 10-15 values. +10 is for the 0-9 digits.
			result += (tolower(hex[i]) - 'a' + 10) * radix;
		} else {
			// Invalid input.
			return -1;
		}	
	}

	return result;	
}

int strLength(char s[]) {
	int i = 0;

	while (s[i] != '\0') {
		i++;
	}

	return i;
}

void getln(char s[]) {
	char c;
	int i;
	
	for (i = 0; i < MAXLINE-1 && (c = getchar()) != '\n' && c != EOF; ++i) {
		s[i] = c;
	}
	
	s[i] = '\0';
}

int main(void) {
	char s[MAXLINE];

	getln(s);

	if (htoi(s) == -1) {
		printf("Invalid input. Try again!\n");
		return 0;
	}
	
	printf("%d\n", htoi(s));
	return 0;
}
