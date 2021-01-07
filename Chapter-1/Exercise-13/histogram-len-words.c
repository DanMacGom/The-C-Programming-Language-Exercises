/*
 * Exercise 1-13.
 * Write a program to print a histogram of the lengths of words in its input. It is
 * easy to draw the histogram with the bars horizontal; a vertical orientation is 
 * more challenging.
*/

#include <stdio.h>

#define IN 1
#define OUT 0

#define MAX_WORD_LENGTH 15

int main() {
  int histogram[MAX_WORD_LENGTH];
  int c, state;
  int currentWordCount = 0;
  int max_char_word_reached = 0;

  int i, j;
  for (i = 0; i <= MAX_WORD_LENGTH; ++i) {
    histogram[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      state = IN;
      ++currentWordCount;
    }
    else if (state == IN && currentWordCount <= MAX_WORD_LENGTH) {
      state = OUT;
      histogram[currentWordCount] += 1;
      currentWordCount = 0;
    }
    else if (currentWordCount > MAX_WORD_LENGTH) {
      max_char_word_reached = 1;
    }
  }

  if (max_char_word_reached == 0) {
    printf("\nHistogram of length of words in input\n");
    printf("---------------------------------------\n");

    for (i = 0; i <= MAX_WORD_LENGTH; ++i) {
      printf("%2d ", i);
      for (j = 1; j <= histogram[i]; ++j) {
        printf("=");
      }
      printf("\n");
    }
    printf("---------------------------------------\n");
  } else {
    printf("Your input contained a word with length longer than %d", MAX_WORD_LENGTH);
    printf("\nTry again with a shorter word because the histogram gets too long otherwise!\n");
  }

}
