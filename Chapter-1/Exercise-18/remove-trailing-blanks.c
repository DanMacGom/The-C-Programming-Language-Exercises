#include <stdio.h>

#define MAXLINE 1000

int obtainline(char line[], int maxline);

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

int main() {
  int len;
  int j;

  char line[MAXLINE];

  while ((len = obtainline(line, MAXLINE)) > 0) {
    j = len - 2;
    while (line[j] == '\t' || line[j] == ' ') {
      --j;
    }

    line[j + 1] = '\n';
    line[j + 2] = '\0';
    printf("%s", line);
  }
}
