/*
 * Exercise 3-3.
 * Write a function expand(s1, s2) that expands shorthand notation like a-z in the
 * string s1 into the equivalent complete list abc...xyz in s2. Allow for letters
 * of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9
 * and -a-z. Arrange that a leading or trailing '-' is taken literally.
*/

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int getln(char s[]);
void expand(char s1[], char s2[]);

int getln(char s[]) {
	int i, c;

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}

	s[i] = '\0';

	return i;
}

int isValidInterval(char start, char end) {
	return end > start 
		&& (
			(islower(start) && islower(end)) 
			|| (isupper(start) && isupper(end))
			|| (isdigit(start) && isdigit(end))
		);
}

void expand(char s1[], char s2[]) {
	int i, j, dif;

	for (i = j = 0; s1[i] != '\0'; i++) {
		if (i != 0 && s1[i] == '-' && isValidInterval(s1[i-1], s1[i+1])) {
			dif = s1[i+1] - s1[i-1]; 		

			while (dif > 1) {
				s2[j++] = ++(s1[i-1]);
				--dif;		
			}

		} else {
			s2[j++] = s1[i];
		}
	}

	s2[j] = '\0';
}

int main(void) {
	char s1[MAXLINE], s2[MAXLINE];

	getln(s1);

	expand(s1, s2);
	printf("%s\n", s2);
	return 0;
}
