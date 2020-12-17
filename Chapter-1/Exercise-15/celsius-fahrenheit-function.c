#include <stdio.h>

float fahrCelsius(int fahr);

float fahrCelsius(int fahr) {
  return (5.0/9.0) * (fahr - 32.0);
}

int main() {
  float celsius;
  int fahr, lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  printf("  Fº    Cº\n");
  printf("-----------\n");
  while(fahr <= upper) {
    celsius = fahrCelsius(fahr);
    printf("%3d %6.1f\n", fahr, celsius);
    fahr += step;
  }

return 0;
}
