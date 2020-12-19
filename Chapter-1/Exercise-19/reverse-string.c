#include <stdio.h>

#define MAXLINE 1000

int obtainline(char line[], int maxline);
int length(char line[]);
void reverse(char line[]);

int obtainline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

int length(char s[]) {
    int i;

    i = 0;
    while (s[i] != '\0') {
      ++i;
    }

    return i;
}

void reverse(char s[]) {
  int temp, i, j;
  int len = length(s);

  // Reverse string in place.
  for (i = 0, j = len - 1; i < j; ++i, --j) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

int main() {
    int len;
    char line[MAXLINE];

    while ((len = obtainline(line, MAXLINE)) > 0) {
      // Remove last '\n'.
      line[--len] = '\0';
      reverse(line);
      printf("%s\n", line);
    }

    return 0;
}
