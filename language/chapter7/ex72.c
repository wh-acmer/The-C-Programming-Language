/*
 * exercise 7-2
 *
 * print arbitrary input in a sensible way.
 * print non-graphic characters in octal or hexadecimal.
 * break long text lines.
 */

#include <stdio.h>
#include <ctype.h>

#define LINELEN 80

int main(void) {
    int c, n;

    n = 0;
    while ((c = getchar()) != EOF) {
        n++;
        if (isprint(c)) {
            putchar(c);
        } else {
            printf("0x%x", c);
        }
        if ( n == LINELEN) {
            printf("\n");
            n = 0;
        }
    }

    return 0;
}
