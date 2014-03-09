/*
 * Ex29
 * In a two’s complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of bitcount
 */

#include <stdio.h>

int bitcount(int x);

int main(void) {
    int x0 = 0xf;
    int x1 = 0x1f;
    int x2 = 0x0;

    printf ("0x%x has %d bit 1\n", x0, bitcount(x0));
    printf ("0x%x has %d bit 1\n", x1, bitcount(x1));
    printf ("0x%x has %d bit 1\n", x2, bitcount(x2));

    return 0;
}

int bitcount(int x) {
    int count = 0;
    while (x != 0) {
        x &= (x-1);
        count ++;
    }
    return count;
}
