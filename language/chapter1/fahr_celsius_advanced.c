/*
 * Print Fahrenheit temperatures and their centigrade or Celsius equivalents
 * With float data type and print format
 * 
 * Formula:
 *      C = (5 / 9) * (F - 32)
 *
 */

#include <stdio.h>

int main(void) {
    int fahr_lower, fahr_upper, step;
    float cur_fahr, cur_celsius;

    fahr_lower = 0;
    fahr_upper = 300;
    step = 20;

    cur_fahr = fahr_lower;
    while (cur_fahr <= fahr_upper) {
         cur_celsius = (5.0 / 9.0) * (cur_fahr - 32);
        printf("%3.0f %6.1f\n", cur_fahr, cur_celsius);

        cur_fahr = cur_fahr + step;
    }

    return 0;
}
