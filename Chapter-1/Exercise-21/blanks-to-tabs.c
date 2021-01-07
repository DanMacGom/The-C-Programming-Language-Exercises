#include <stdio.h>

#define MAXLINE 1000
#define BLANKSPERTAB 8

void entab(char init[], char outp[]);
int obtainline(char s[], int lim);

void entab(char init[], char outp[]) {
  int i; // init's index.
  int j; // outp's index.
  int numTabs;
  int numBlanks;

  for (i = j = 0; init[i] != '\0'; ++i) {
    if (init[i] == ' ') {
      for (numBlanks = numTabs = 0; init[i] == ' '; ++i) {
        if ((i + 1) % BLANKSPERTAB == 0) {
          ++numTabs;
          numBlanks = 0;
        } else {
          ++numBlanks;
        }
      }
      --i;
      while (numTabs-- > 0) {
        outp[j++] = '\t';
      }
      while (numBlanks-- > 0) {
        outp[j++] = '-';
      }
    } else {
      outp[j++] = init[i];
    }
  }
  outp[j] = '\0';
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

  char init[MAXLINE];
  char outp[MAXLINE];

  while ((len = obtainline(init, MAXLINE)) > 0) {
    entab(init, outp);
    printf("%s", outp);
  }
}
