/* 
 * Exercise 1-9.
 * Write a program to copy its input to its output, replcing each string of one or more
 * blanks by a single blank.
*/

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
