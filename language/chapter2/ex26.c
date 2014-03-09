/*
 * Ex 2.6
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged
 */

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(void) {
    int x = 0;
    int y = 0xF;
    int p = 7;
    int n = 4;

    printf ("0x%x\n", setbits(x, p, n, y));

    return 0;
}

int setbits(int x, int p, int n, int y) {
    /*
     *  xxx 000 xxx
     *       ^
     *  000 yyy 000
     *  -----------
     *  xxx yyy xxx
     *
     */
    int x1 = ~0 << (p + 1);
    int x2 = ~(~0 << (p - n + 1));
    int x3 = x1 | x2;
    int x4 = x & x3;

    int y1 = y << (p - n + 1);

    int r = x4 ^ y1;

    return r;
}
