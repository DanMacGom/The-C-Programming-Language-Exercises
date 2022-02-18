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
    char string[] = "1421.231e6";
    printf("%f", atof(string));
}

double atof(char s[]) {
    double val, power;
    int i = 0, sign;

    while (isspace(s[i])) {
        i++;
    }

    sign = (s[i] == '-') ? -1 : 1;
    printf("sign=%d\n", sign);

    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        printf("val=%f\n", val);
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        printf("val=%f, ", val);
        power *= 10.0;
        printf("power=%f\n", power);
    }

    return sign * val / power;
}
