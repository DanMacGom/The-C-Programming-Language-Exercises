// IMPORTANT: the tabstops are defined so that when you press tab you add up to
// the default multiple of the default value (8).
// So input line of aa + '\t' -> '\t' = 6 * ' '.
// aaaaa + '\t' -> '\t' = 3 * ' '.
// '\0' + '\t' -> '\t' = 8 * ' '.
#include <stdio.h>

#define MAXLINE 1000
#define BLANKSPERTAB 8

void detab(char tabbed[], char detabbed[]);
int obtainline(char s[], int lim);

void detab(char tabbed[], char detabbed[]) {
  int i, j, nextTabStop;

  j = 0;
  for (i = 0; tabbed[i] != '\0'; ++i) {
    if (tabbed[i] == '\t') {
      nextTabStop = BLANKSPERTAB - (j % BLANKSPERTAB);
      printf("Blanks: %d\n", nextTabStop);
      while (nextTabStop-- > 0) {
        // Use '-' easier to see than ' '.
        detabbed[j++] = '-';
      }
    } else {
      // Increase j when we don't find a '\t' so we move its origin alongside i.
      detabbed[j++] = tabbed[i];
    }
  }

  detabbed[j] = '\0';
}

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

  char tabbed[MAXLINE];
  char detabbed[MAXLINE];

  while ((len = obtainline(tabbed, MAXLINE)) > 0) {
    detab(tabbed, detabbed);
    printf("%s", detabbed);
  }
}

// n should be a symbolic parameter (#define) because that value should be cons-
// tant throughout the program.
