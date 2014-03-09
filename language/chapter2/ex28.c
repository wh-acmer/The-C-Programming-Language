/*
 * Ex2.8
 * Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n positions.
 */

#include <stdio.h>

int rightrot(int x, int n);

int main(void) {
    int x = 0xf;
    int n = 4;

    printf ("0x%x\n", rightrot(x, n));
    return 0;
}

int rightrot(int x, int n) {
    int x1 = ~(~0 << n);
    int x2 = x1 & x; /* right n bits of x */
    int int_size = sizeof(int) * 8;
    int x3 = x2 << (int_size - n);

    int x4 = x >> n;
    int x5 = x1 << (int_size - n);
    int x6 = ~x5 & x4;

    int r = x6 | x3;

    return r;
}
