#include <stdio.h>

#define IN 1 // Inside word
#define OUT 0 // Outside word

int main() {
  int numlines, numwords, numchars, state;

  char c;
  state = OUT;
  numlines = numwords = numchars = 0;

  while ((c = getchar()) != EOF) {
    ++numchars;
    if (c == '\n') {
      ++numlines;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    }
    else if (state == OUT) {
      state = IN;
      ++numwords;
    }
  }
  printf("Number of lines: %d\n", numlines);
  printf("Number of words: %d\n", numwords);
  printf("Number of characters: %d\n", numchars);
}
