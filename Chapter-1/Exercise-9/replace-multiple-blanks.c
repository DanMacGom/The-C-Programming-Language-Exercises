#include <stdio.h>

int main() {
  char c;
  int intNumBlanks = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' && intNumBlanks == 0) {
      ++intNumBlanks;
      putchar(c);
    }
    if (c != ' ') {
      putchar(c);
      intNumBlanks = 0;
    }
  }
}
