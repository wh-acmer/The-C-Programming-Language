/*
 * Ex2.7
 * Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed
 * into 0 and vice versa), leaving the others unchanged.
 */

#include <stdio.h>

int invert(int x, int p, int n);

int main(void) {
    int x = 0;
    int p = 7;
    int n = 4;

    printf ("0x%x\n", invert(x, p, n));
    return 0;
}

int invert(int x, int p, int n) {
    int y1 = ~0 << (p + 1);
    int y2 = ~(~0 << (p - n + 1));
    int y3 = ~(y1 | y2);
    
    int r = x ^ y3;

    return r;
}
