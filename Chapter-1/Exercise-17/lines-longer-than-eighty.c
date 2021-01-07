/*
 * Exercise 1-17.
 * Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAXLINE 1000
#define NCHARS 80

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

  char line[MAXLINE];

  while ((len = obtainline(line, MAXLINE)) > 0) {
    if (len > NCHARS) {
      printf("%s", line);
    }
  }

  return 0;
}
