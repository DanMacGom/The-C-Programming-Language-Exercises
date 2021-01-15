#include <stdio.h>

#define MAXLINE 1000

void getln(char s[]);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

void getln(char s[]){
	int i, c;

	for (i=0; (c = getchar()) != EOF && i < MAXLINE - 1; i++){
		s[i] = c;
	}
	
	s[i] = '\0';
}

/* Copies from s to t. */
void escape(char s[], char t[]) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++, j++) {
		switch (s[i]) {
			case '\n':
				t[j] = '\\';
				t[++j] = 'n';
				break;
			case '\\':
				t[j] = '\\';
				t[++j] = '\\';
				break;
			case '\t':
				t[j] = '\\';
				t[++j] = 't';
				break;
			case '\"':
				t[j] = '\\';
				t[++j] = '\"';
				break;
			case '\'':
				t[j] = '\\';
				t[++j] = '\'';
				break;
			default:
				t[j] = s[i];
				break;
		}
	}

	t[j] = '\0';
}

void unescape(char s[], char t[]) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++, j++) {
		switch (s[i]) {
			case '\\':
				switch (s[++i]) {
					case 't':
						t[j] = '\t';
						break;
					case 'n':
						t[j] = '\n';
						break;
					case '\"':
						t[j] = '\"';
						break;
					case '\'':
						t[j] = '\'';
						break;
					default:
						t[j] = '\\';
						break;
				}
				/* Easy to forget a break here. */
				break;
			
			default:
				t[j] = s[i];
				break;
		}	
	}

	t[j] = '\0';
}

int main(void) {
	char s[MAXLINE];
	char t[MAXLINE];

	getln(s);
//	escape(s, t);
	unescape(s, t);

	printf("%s\n", t);
	return 0;
}
