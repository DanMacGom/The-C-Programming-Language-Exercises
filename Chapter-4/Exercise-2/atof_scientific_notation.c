/*
 * Exercise 4-2.
 * Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally
 * signed exponent.
 */
#include <ctype.h>
#include <stdio.h>

/* atof: convert string s to double */
double atof(char s[]);

int main(void) {
    char string[] = "123.45e-0";
    printf("%f", atof(string));
}

double atof(char s[]) {
    double val, power, exponent;
    int i = 0;
    int sign = 1;
    int exponent_sign = 1;

    while (isspace(s[i])) {
        i++;
    }

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
    }

    if (s[i++] == '-') {
        exponent_sign = -1;
    }

    for (; isdigit(s[i]); i++) {
        exponent = 10.0 * exponent + (s[i] - '0');
    }

    for (int j = 1; j <= (int)exponent; j++) {
        power *= exponent_sign == -1 ? 10.0 : (1 / 10.0);
    }

    return sign * val / power;
}
