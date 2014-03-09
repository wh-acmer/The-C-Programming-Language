/*
 * Ex 2.1
 *
 * Prlong range of char, short, long, long, float, double
 * From standard headers and by direct computation.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

long get_max_by_size(long size);
long get_min_by_max(long min);
long xpow(long base, long exp);
float fpow(float base, int exp);
float get_max_float();

int main(void){
    long char_min, short_min, int_min; 
    long long_min;
    float float_min;

    long char_max, short_max, int_max;
    long long_max;
    float float_max;

    /* range of char */
    printf ("header:range of char is %d - %d\n", CHAR_MIN, CHAR_MAX);
    char_max = get_max_by_size(sizeof(char));
    char_min = get_min_by_max(char_max);
    printf ("compute:range of char is %ld - %ld\n", char_min, char_max);

    /* range of int */
    printf ("header:range of int is %d - %d\n", INT_MIN, INT_MAX);
    int_max = get_max_by_size(sizeof(int));
    int_min = get_min_by_max(int_max);
    printf ("compute:range of int is %ld - %ld\n", int_min, int_max);

    /* range of short */
    printf ("header:range of short is %d - %d\n", SHRT_MIN, SHRT_MAX);
    short_max = get_max_by_size(sizeof(short));
    short_min = get_min_by_max(short_max);
    printf ("compute:range of long is %ld - %ld\n", short_min, short_max);

    /* range of long */
    printf ("header:range of long is %ld - %ld\n", LONG_MIN, LONG_MAX);
    long_max = get_max_by_size(sizeof(long));
    long_min = get_min_by_max(long_max);
    printf ("compute:range of long is %ld - %ld\n", long_min, long_max);

    /* range of float */
    printf ("header:range of float is %f - %f\n", FLT_MIN, FLT_MAX);
    float_max = get_max_float();
    printf ("header:range of float is %f - %f\n", FLT_MIN, float_max);

    return 0;
}


long get_max_by_size(long size) {
    long bits = size * CHAR_BIT;
    long max = xpow(2, bits - 1) - 1;
    return max;
}

long get_min_by_max(long max) {
    long min = -1 - max;
    return min;
}

long xpow(long base, long exp) {
    long r, i;

    r = 1;
    for (i=0; i<exp; i++) {
        r *= base;
    }

    return r;
}

float get_max_float() {
    /*
     * IEEE 754
     * 
     * float:
     * sign: 1bit, exp: 8bit, frac: 23bit
     *
     * F = (-1)^sign * frac * 2^exp
     */
    int exp_bit = 8;
    int frac_bit = 23;

    float frac = 1 - fpow(0.5, frac_bit);
    float true_frac = 1 + frac;

    int exp = xpow(2, exp_bit - 1) - 1;
    float times = fpow(2.0, exp);

    float max = true_frac * times;

    return max;
}

float fpow(float base, int exp) {
    float r;
    int i;

    r = 1.0;
    for (i=0; i<exp; i++) {
        r *= base;
    }

    return r;
}
