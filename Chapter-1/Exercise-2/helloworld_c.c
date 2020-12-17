#include <stdio.h>

int main() {
  printf("hello, world\c\n");
  return 0;
}

// warning: unknown escape sequence: '\c'.
// If you print the result it will display a "c" after the string.
