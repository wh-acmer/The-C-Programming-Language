/*
 * Using functions
 */

#include <stdio.h>

long power(long x, long y);

int main(void) {
    long x, y;

    x = 2;
    y = 5;

    printf ("pow(%ld, %ld) is %ld.\n", x, y, power(x, y));

    return 0;
}

long power(long x, long y) {
    long result;
    int index;

    result = 1;
    for (index = 0; index < y; index ++) {
        result = result * x;
    }
    
    return result;
}
